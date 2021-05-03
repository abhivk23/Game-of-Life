/**
 * Implementation file for Conway's Game of Life. 
 * Object-oriented, sparse matrix implementation of grid arithmetic saves memory and computational resources.
 * @file life.cpp
 * @author Abhiram Kakuturu
 * @version 1.2 12/9/2020  
*/
#include "life.hpp"

bool State::equals(State s){
    return (dim==s.dim && board==s.board);
}

State State::copy(void){
    return State(dim, board);
}

set<pair<int,int>> State::get_neighbors(pair<int, int> cell, int radius){
    set<pair<int,int>> neighbors;
    for(int r=-radius; r<radius+1; r++){
        for(int c=-radius; c<radius+1; c++){
            if(r==c && r==0) continue; // this could be cleaner, trying to avoid checking the passed cell
            int y = cell.first+r;
            int x = cell.second+c;
            if (x<dim && y<dim && x>=0 && y>=0) neighbors.insert(make_pair(y,x));
        }
    }
    return neighbors;
}

State State::next_state(int r){
    map<pair<int,int>, int> history;
    for (pair<int, int> cell : board){
        auto search = history.find(cell);
        if(search==history.end()) history.insert(make_pair(cell, 0));

        set<pair<int,int>> neighbors = get_neighbors(cell, r);
        for(pair<int,int> n : neighbors){
            auto search = history.find(n);
            if(search==history.end()) history.insert(make_pair(n, 1));
            else history[n]++;
        }
    }

    set<pair<int,int>> b2 = board;
    for(pair<pair<int,int>, int> kv : history){
        if (kv.second < 2 || kv.second > 3) b2.erase(kv.first);
        if (kv.second==3) b2.insert(kv.first);
    }

    return State(dim,b2);
}

vector<State> Game::run_game(int iterations){
    vector<State> state_history;
    state_history.push_back(current_state);
    State next_state = current_state.next_state(radius);
    State next_next_state = next_state.next_state(radius);

    int t=1;
    while (!next_next_state.equals(current_state) && t<iterations){
        t++;
        current_state = next_state;
        next_state = next_next_state;
        state_history.push_back(current_state);
        next_next_state = (next_state).next_state(radius);
    }
    state_history.push_back(current_state);

    return state_history;
}

int digit_count(int x){
  int l=1;
  x/=10;
  while(x) {
    l++;
    x/=10;
  }
  return l;
}

void ppm_fromSparse(set<pair<int,int>> board, int dim, std::ofstream* ppm_file){
    for (int r=0; r<dim; r++){
            for(int c=0; c<dim; c++){
                pair<int, int> cell = make_pair(r,c);
                auto search = (board).find(cell);
                if(search==board.end()) *ppm_file << "0 0 0"; // black if cell is unoccupied
                else *ppm_file << "255 255 255"; // white if cell is occupied

                if (c!=dim-1) *ppm_file << " ";
            }
            *ppm_file << endl;
        }
}

void make_ppm(vector<State> progress, std::string dir){
    std::ofstream ppm_out;
    int i=0;
    for (State s : progress){
        // define file name with padding (required for ImageMagick conversion)
        std::string name = "../"+dir+"/res";
        name.append(5 - digit_count(i), '0'); // 5 is arbitrary-- can be modified to anticipate MAX_ITER > 10e6
        name.append(std::to_string(i));

        ppm_out.open(name+".ppm");
        ppm_out << "P3 " << s.dim << " " << s.dim << " " << "255" << endl;
        ppm_fromSparse(s.board, s.dim, &ppm_out);
        ppm_out.close();
        i++;
    }
    return;
}