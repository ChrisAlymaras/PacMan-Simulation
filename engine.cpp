
#include "engine.h"
using namespace std;

//constructor for class engine that takes maze from txt and copies it to
//a charr array with the help of a vector
engine::engine(const string& file_path)
{
    
    ifstream file;
    string response="";
    try
    {
        file.open(file_path);
        if(file)
        {
            cout<<"Maze.txt opened successfully\n";
        }
        else
        {
            response="Error opening maze.txt";
            throw(response);
        }
    }
    catch (string response)
    {
        cout<<response;
        exit(1);
    }
  string line;
  while (getline(file,line))
  {
    maze.push_back(line);
  }
  file.close();
  //copy vector's elements to a char array for easier handle
  game = new char*[maze.size()];
  for (int i=0; i<maze.size(); i++)
  {
    game[i]=new char[maze[0].size()];
  }
  //copy
  for (int i=0; i<maze.size(); i++)
    {
        for (int j=0; j<maze[0].size(); j++)
        {
            game[i][j]=maze[i][j];
        }
    }
    set_pergamine(false);
}

void engine::set_pergamine(bool val){
	pergamine_is_added=val;
}

bool engine::get_pergamine(){
	return pergamine_is_added;
}

//put pergamine represented by character "#" into the game
void engine::put_pergamine()
{
    set_counter(0);
    int random_row=0;
    int random_col=0;
    if (pergamine_is_added==false)
    {
        while (game[random_row][random_col]!='.')
        {
            random_row= rand() % maze.size();
            random_col= rand() % maze[0].size();
        }
        game[random_row][random_col]='#';
        set_pergamine(true);
        set_x(random_row);
        set_y(random_col);
    }
}

void engine::change_pergamine(){
	counter+=1;
	if (counter==8){
		int random_row=0;
	    	int random_col=0;
		while (game[random_row][random_col]!='.' && game[random_row][random_col]!='M' && game[random_row][random_col]!='L')
		{
		    random_row= rand() % maze.size();
		    random_col= rand() % maze[0].size();
		}
		game[per_x][per_y]='.';
		game[random_row][random_col]='#';
		set_x(random_row);
		set_y(random_col);
		set_counter(0);
	}
}

void engine::set_counter(int num){
	counter=num;
}

//function to print table of the game
void engine::print_maze()
{
    
    for (int i=0; i<maze.size(); i++)
    {
        for (int j=0; j<maze[i].size(); j++)
        {
        	if(game[i][j]=='M'){
        		attron(COLOR_PAIR(1));
        		mvaddch(i,j,game[i][j]);
        		attroff(COLOR_PAIR(1));
        	}else if(game[i][j]=='L'){
        		attron(COLOR_PAIR(2));
        		mvaddch(i,j,game[i][j]);
        		attroff(COLOR_PAIR(2));
        	}
        	else if (game[i][j]=='*'){
        		attron(COLOR_PAIR(4));
        		mvaddch(i,j,game[i][j]);
        		attroff(COLOR_PAIR(4));
        	}
        	else if (game[i][j]=='.'){
        		attron(COLOR_PAIR(3));
        		mvaddch(i,j,game[i][j]);
        		attroff(COLOR_PAIR(3));
        	}
        	else{
        		mvaddch(i, j, game[i][j]);
        	}
        }
        cout<<"\n";
    }
}

//menu
void engine::print_menu(){
	attron(COLOR_PAIR(3));
        printw("\n");
        printw("Use W A S D to move or ESC to exit");
        attroff(COLOR_PAIR(3));
}

void engine::set_x(int num){
	per_x=num;
}

int engine::get_x(){
	return per_x;
}

void engine::set_y(int num){
	per_y=num;
}

int engine::get_y(){
	return per_y;
}
