#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <thread>
#include <panel.h>

#include "engine.h"
#include "potter.h"
#include "malphoi.h"

using namespace std;

#define UP 119
#define DOWN 115
#define RIGHT 100
#define LEFT 97
#define ESC 27
#define SPACE 32


int main(int argc, char *argv[])
{	// Initialize ncurses
	initscr();
    	start_color();
    	//ignore all keys except W A S D ESC
    	keypad(stdscr, TRUE);
    	noecho();
    	curs_set(0);
    	//define colors
    	init_pair(1,COLOR_RED,COLOR_BLACK);
    	init_pair(2,COLOR_GREEN,COLOR_BLACK);
    	init_pair(3,COLOR_YELLOW,COLOR_BLACK);
    	init_pair(4,COLOR_BLUE,COLOR_BLACK);
	//take argument from cmd and pass it to engine class in order to
	//create game table
	engine game_table=engine(argv[1]);
	//add potter into the game table. Letter "M" represents potter
	potter pt=potter('M',game_table);
	//add malphoi into the game table. Letter "L" represents malphoi
	malphoi malph=malphoi('L',game_table);
	//add winning pergamine into the game. Character "#" represents pergamine
	game_table.put_pergamine();
    	int ch=97;
    	//begin loop where M is moved by the keyboard and L autonomously
	while (ch!=ESC && pt.get_finish()==false && malph.get_finish()==false){
		if (ch==UP || ch==DOWN || ch==LEFT || ch==RIGHT || ch==SPACE){
		clear();
		game_table.print_maze();
		game_table.print_menu();
		refresh();
		ch=getch();
		pt.move_it(ch,game_table);
		malph.move_it(game_table);
		game_table.change_pergamine();
		}else{
			ch=getch();
		}
	}  
	endwin();
	//print winner
	if (pt.get_finish()==true){
		cout<<"M won the game\n";
	}else{
		cout<<"L won the game\n";
	}
	return 0;
}
