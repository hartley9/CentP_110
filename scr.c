#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>

#define DELAY 30000

int main(int argc, char *argv[])
{
	int x = 0, y = 0;
	int max_y = 0, max_x = 0;
	int next_x = 0;
	
	int direction = 1;
	
	char catPill[] = "ooooo";

	initscr();
	cbreak();
	curs_set(FALSE);
	
	
	
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
			}
		else 
			{
			x += direction;
			}
	}
	
	
	getch();
	endwin();
	
	return 0;
}
