#include "engine.h"
#include "malphoi.h"
#include <climits>

using namespace std;

malphoi::malphoi(char ch,engine& map)
{
     set_finish(false);
     //Malphoi is represented by givven character "ch"
     symbol=ch;
     //check for empty places
     int random_row=0;
     int random_col=0;
     while (map.game[random_row][random_col]!='.')
     {
        random_row= rand() % map.maze.size();
        random_col= rand() % map.maze[0].size();
     }
     x=random_row;
     y=random_col;
     //Put Malphoi in the map
     map.game[x][y]=symbol;
}

//malphoi's movement
void malphoi::move_it(engine& map)
{
    int px = map.get_x();
    int py = map.get_y();

    //store possible directions and their effects
    vector<pair<int, int>> directions = {
        {-1, 0}, // UP
        {1, 0},  // DOWN
        {0, -1}, // LEFT
        {0, 1}   // RIGHT
    };

    pair<int, int> best_move = { 0, 0 };
    int min_distance = INT_MAX;

    for (auto dir : directions) {
        int nx = x + dir.first;
        int ny = y + dir.second;

        //check bounds
        if (nx >= 0 && nx < map.maze.size() && ny >= 0 && ny < map.maze[0].size()) {
            char target = map.game[nx][ny];
            if (target == '.' || target == '#') {
                int dist = abs(nx - px) + abs(ny - py);
                if (dist < min_distance) {
                    min_distance = dist;
                    best_move = dir;
                }
            }
        }
    }

    int new_x = x + best_move.first;
    int new_y = y + best_move.second;

    if (map.game[new_x][new_y] == '#') {
        set_finish(true);
    }

    //move Malphoi
    map.game[new_x][new_y] = symbol;
    map.game[x][y] = '.';
    x = new_x;
    y = new_y;
}

//malphoi's setter and getter for his character letter
void malphoi::set_symbol(char ch){
	symbol=ch;
}

char malphoi::get_symbol(){
	return symbol;
}

//setters and getters for row and column
void malphoi::set_x(int num){
	x=num;
}

int malphoi::get_x(){
	return x;
}

void malphoi::set_y(int num){
	y=num;
}

int malphoi::get_y(){
	return y;
}

//setter and getter for flag finish
void malphoi::set_finish(bool f)
{
    finish=f;
}

bool malphoi::get_finish()
{
    return finish;
}
