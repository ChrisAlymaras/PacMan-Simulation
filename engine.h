#ifndef engine_h
#define engine_h

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <panel.h>

using namespace std;

class engine
{
private:
    vector<string>maze;
    char **game;
    //pergamine in the map
    bool pergamine_is_added;
    //hold row and col of pergamine
    int per_x;
    int per_y;
    //counter change holds a number of movements to change the pergamine after
    //some moves
    int counter;
public:
    //print menu
    void print_menu();
    //print maze
    void print_maze();
    //CONSTRUCTOR
    engine(const string& file_path);
    //PUT RANDOM GEMS
    //void put_gems();
    //Put pergamine
    void put_pergamine();
    //set and get pergamine
    void set_pergamine(bool);
    bool get_pergamine();
    //row and col for pergamine
    void set_x(int);
    int get_x();
    void set_y(int);
    int get_y();
    //change position of the pergamine
    void change_pergamine();
    void set_counter(int);
    friend class potter;
    friend class malphoi;
};

#endif
