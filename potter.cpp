#include "engine.h"
#include "potter.h"


using namespace std;

potter::potter(char ch,engine& map)
{
     set_finish(false);
     //Potter is represented by givven character "ch"
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
     //Put Potter in the map
     map.game[x][y]=symbol;
}

//potter's movement
void potter::move_it(int a,engine& map)
{
    int random_row=0;
    int random_col=0;
    switch(a)
    {
    case UP:
        if (map.game[x-1][y]=='.')
        {
            map.game[x-1][y]=map.game[x][y];
            map.game[x][y]='.';
            x=x-1;
        }
        else if (map.game[x-1][y]=='#')
        {
            map.game[x-1][y]=map.game[x][y];
            map.game[x][y]='.';
            x=x-1;
            set_finish(true);
        }
        break;
    case DOWN:
        if (map.game[x+1][y]=='.')
        {
            map.game[x+1][y]=map.game[x][y];
            map.game[x][y]='.';
            x=x+1;
        }
        else if(map.game[x+1][y]=='#')
        {
            map.game[x+1][y]=map.game[x][y];
            map.game[x][y]='.';
            x=x+1;
            set_finish(true);
        }
        break;
    case RIGHT:
        if (map.game[x][y+1]=='.')
        {
            map.game[x][y+1]=map.game[x][y];
            map.game[x][y]='.';
            y=y+1;
        }
        else if(map.game[x][y+1]=='#')
        {
            map.game[x][y+1]=map.game[x][y];
            map.game[x][y]='.';
            y=y+1;
            set_finish(true);
        }
        break;
    case LEFT:
        if (map.game[x][y-1]=='.')
        {
            map.game[x][y-1]=map.game[x][y];
            map.game[x][y]='.';
            y=y-1;
        }
        else if(map.game[x][y-1]=='#')
        {
            map.game[x][y-1]=map.game[x][y];
            map.game[x][y]='.';
            y=y-1;
            set_finish(true);
        }
        break;
    default:
    	break;
    }
    
    	
    	
}

//potter's setter and getter for his character letter
void potter::set_symbol(char ch){
	symbol=ch;
}

char potter::get_symbol(){
	return symbol;
}

//setters and getters for row and column
void potter::set_x(int num){
	x=num;
}

int potter::get_x(){
	return x;
}

void potter::set_y(int num){
	y=num;
}

int potter::get_y(){
	return y;
}

//setter and getter for flag finish
void potter::set_finish(bool f)
{
    finish=f;
}

bool potter::get_finish()
{
    return finish;
}


















