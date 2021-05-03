/**
 * Implementation header file for Conway's Game of Life. 
 * Object-oriented, sparse matrix implementation of grid arithmetic saves memory and computational resources.
 * @file life.hpp
 * @author Abhiram Kakuturu
 * @version 1.2 12/9/2020  
*/
#ifndef LIFE_H
#define LIFE_H

#include <map>
#include <set>
#include <vector>
#include <fstream>
using std::vector;
using std::map;
using std::pair;
using std::make_pair;
using std::set;
using std::endl;

// Description of current board status
class State {
    public:
        // Dimension of the board and the sparse matrix of filled cells
        int dim;
        set<pair<int,int>> board;

        // Constructor
        State(int dimension,set<pair<int,int>> grid) { dim = dimension; board = grid; }
        
        // Member methods
        bool equals(State s);
        State copy(void);
        set<pair<int,int>> get_neighbors(pair<int, int> cell, int radius);
        State next_state(int r);
};

// 
class Game {
    public:
        // Current configuration of the Game
        State current_state;
        int radius;

        // Constuctor
        Game(int r, State state) : current_state(state.dim, state.board) { radius = r; }

        // Member Methods
        vector<State> run_game(int iterations);
};

// Utility function to 
void make_ppm(vector<State> progress, std::string dir);

// Helper function in make_ppm
void ppm_fromSparse(set<pair<int,int>> board, int dim, std::ofstream ppm_file);

// Utility helper
int digit_count(int x);

#endif