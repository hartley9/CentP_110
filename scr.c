#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define DELAY 80000




int main(int argc, char *argv[])
{
	int x = 0, y = 0;
	int delay = 80000;
	int max_y = 0, max_x = 0;
	int next_x = 0;
	
	int direction = 1;
	
	char catPill[] = "OOOOOOOOOO";
	char player[] = "W";

	initscr();
	curs_set(FALSE);
	
	//Color
	if(has_colors() == FALSE)
	{
		endwin();
		printf("Color is not supported in this terminal\n");
		exit(1);
	}
	
	
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	printw("Welcome to Centipede!\n");
	printw("<--Press Any Key to Start-->");
	attroff(COLOR_PAIR(1));
	getch(); //Waits for user to press a key
	clear(); //Clears the screen
	
	//move(0,0);
	
	//printw("It works");
	
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	while(1)
	{
		getmaxyx(stdscr, max_y, max_x);
		
		clear();
		mvprintw(y, x, catPill);
		mvprintw((max_y-(max_y/3)), (max_x/2), player);
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
