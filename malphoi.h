#ifndef malphoi_h
#define malphoi_h

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

class malphoi{
	private:
		//set a boolean finish to check if malphoi won the game
    		bool finish;
   		char symbol;
    		//malphois position in the map. x=row y=column
    		int x;
    		int y;
    	public:
		//constructor
		malphoi(char,engine&);	
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
    		//malphoi's movement
    		void move_it(engine&);
};

#endif
