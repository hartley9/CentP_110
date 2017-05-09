#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define DELAY 80000

void startScreen(){
	
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
	
	}

void centipede_movement(int cent_x, int cent_y, int delay, int max_x, int max_y,
						int next_x_centP, int direction, char catPill){
	
		
	
	}


int main(int argc, char *argv[])
{
	int cent_x = 0, cent_y = 0, play_x = 0, play_y = 0, play_init = 0;
	int delay = 80000;
	int max_y = 0, max_x = 0;
	int next_x_centP = 0;
	int next_x_playr = 0;
	int direction = 1;
	char catPill[] = "OOOOOOOOOO";
	char player[] = "W";
	

	initscr();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	
	startScreen();
	
	
	

	
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	
	getmaxyx(stdscr, max_y, max_x);
	play_x = max_x/2;
	play_y = max_y-(max_y/3);
	while(1)
	{
		getmaxyx(stdscr, max_y, max_x);
		
		
		mvprintw(cent_y, cent_x, catPill);
		
		
		mvprintw(play_y, play_x, player);
		
		refresh();
		
		usleep(DELAY);
		
		next_x_centP = cent_x + direction;
		
		if (next_x_centP >= (max_x - strlen(catPill)) || next_x_centP < 0)
			{
			direction *= -1;
			cent_y++;
			}
		else 
			{
			cent_x += direction;
			}
		
		//next_x_playr = play
		//Key presses
		int playerMove;
		halfdelay(1); 
		int ch;
		ch = getch();
		if(ch == KEY_UP)
		{	
			
			if (next_x_playr >= (max_y - strlen(player)) || next_x_playr < 0)
			{}
			else{play_y = play_y - 0.25;}
			
		}
		
		clear();
			
	}
				
		cbreak(); //Close window when ctrl + c is pressed
	

	
	getch();
	endwin();	
	return 0;


}
