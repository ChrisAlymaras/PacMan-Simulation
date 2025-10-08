#ifndef potter_h
#define potter_h

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

#define UP 119
#define DOWN 115
#define RIGHT 100
#define LEFT 97
#define ESC 27
#define SPACE 32

class potter{
	private:
		//set a boolean finish to check if potter won the game
    		bool finish;
    		char symbol;
    		//potter's position in the map. x=row y=column
    		int x;
    		int y;
	public:
		//constructor
		potter(char,engine&);	
		//give potter character in the game
		void set_symbol(char);
		char get_symbol();
		//set and get row
		void set_x(int);
		int get_x();
		//set and get column
		void set_y(int);
		int get_y();
		//set and get flag finish
		void set_finish(bool);
    		bool get_finish();
    		//potter's movement
    		void move_it(int,engine&);
				
};

#endif
