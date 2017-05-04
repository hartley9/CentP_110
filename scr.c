#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>

#define DELAY 80000

int main(int argc, char *argv[])
{
	int x = 0, y = 0;
	int delay = 80000;
	int max_y = 0, max_x = 0;
	int next_x = 0;
	
	int direction = 1;
	
	char catPill[] = "OOOOOOOOOO";

	initscr();
	curs_set(FALSE);
	
	//getmaxyx(stdscr, max_y, max_x);
	//move(max_y/2, max_x/2);
	
	printw("Welcome to Centipede!\n");
	printw("<--Press Any Key to Start-->");
	getch(); //Waits for user to press a key
	clear(); //Clears the screen
	
	//move(0,0);
	
	//printw("It works");
	while(1)
	{
		getmaxyx(stdscr, max_y, max_x);
		
		clear();
		mvprintw(y, x, catPill);
		refresh();
		
		usleep(DELAY);
		
		next_x = x + direction;
		
		if (next_x >= (max_x - strlen(catPill)) || next_x < 0)
			{
			direction *= -1;
			y++;
			}
		else 
			{
			x += direction;
			}
			
		cbreak(); //Close window when ctrl + c is pressed
	}
	
	
	getch();
	
	endwin();
	
	return 0;

}
