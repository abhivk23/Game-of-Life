/**
 * Runner file for Conway's Game of Life. 
 * Parameters of note include interaction radius 'r' , board dimension 'grid_size' , and max frame count 'MAX_ITER'.
 * Commment out games to save time on compilation.
 * @file main.cpp
 * @author Abhiram Kakuturu
 * @version 1.2 12/9/2020  
*/
#include "life.hpp"
#include <iostream>
using std::cout;

/* Some pre-defined game boards */
// BLINKER
set<pair<int,int>> blinker = {make_pair(40, 40),make_pair(40, 41),make_pair(40, 42)};
// GLIDER
set<pair<int,int>> glider = {make_pair(10,10),make_pair(11,10),make_pair(11,9),make_pair(10,8),make_pair(9,10)};
// TETRIS
set<pair<int,int>> tetris = {make_pair(39, 40),make_pair(39, 41),make_pair(40, 39),make_pair(40, 40),make_pair(41, 40)};
// 4 BLINKERS
set<pair<int,int>> four_blinkers = {make_pair(40, 44),make_pair(40, 43),make_pair(40, 42),make_pair(40, 40),make_pair(40, 41)};
// 4 BEEHIVES
set<pair<int,int>> four_beehives = {make_pair(40, 40),make_pair(41, 39),make_pair(42, 39),make_pair(43, 40),make_pair(41, 41),make_pair(42, 41),make_pair(40,41)};

int main(void){
    // Setup conifg
    cout << "Setup...";
    // Global parameters
    int grid_size = 50;
    int MAX_ITER=1000; // keep to < 10e6
    int r = 1; // range of interaction

/**********************************************************
    // Game 1: Blinker
    State init1(grid_size,blinker);
    Game blinker_run(r, init1);

    // Game 2: Glider
    State init2(grid_size,glider);
    Game glider_run(r, init2);

    // Game 3: Tetris
    State init3(grid_size,tetris);
    Game tetris_run(r, init3);

    // Game 4: 4 Blinkers
    State init4(grid_size, four_blinkers);
    Game four_blinkers_run(r, init4);

    // Game 5: 4 Beehives
    State init5(grid_size, four_beehives);
    Game four_beehives_run(r, init5);
**********************************************************/

    // Glider
    State init2(grid_size,glider);
    Game glider_run(r, init2);

    cout << "complete." << endl;

    // Generate ppms and store in appropriate directories
    cout << "Game 1...";
    vector<State> prog = glider_run.run_game(MAX_ITER);
    cout << "complete." << endl;

    std::string dir = "Glider_Output";
    make_ppm(prog, dir);
/**********************************************************
    cout << "Game 1...";
    vector<State> prog = blinker_run.run_game(MAX_ITER);
    cout << "complete." << endl;

    std::string dir = "Blinker_Output";
    make_ppm(prog, dir);

    cout << "Game 2...";
    prog = glider_run.run_game(MAX_ITER);
    cout << "complete." << endl;

    dir = "Glider_Output";
    make_ppm(prog, dir);

    cout << "Game 3...";
    prog = tetris_run.run_game(MAX_ITER);
    cout << "complete." << endl;

    dir = "Tetris_Output";
    make_ppm(prog, dir);

    cout << "Game 4...";
    prog = four_blinkers_run.run_game(MAX_ITER);
    cout << "complete." << endl;

    dir = "Four_Blinker_Output";
    make_ppm(prog, dir);

    cout << "Game 5...";
    prog = four_beehives_run.run_game(MAX_ITER);
    cout << "complete." << endl;

    dir = "Four_Beehives_Output";
    make_ppm(prog, dir);
*********************************************************/

    cout << "Animation Part 1/2..." << "complete." << endl;

    return 0;
}