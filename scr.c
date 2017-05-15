#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define DELAY 80000
#define MAX_BULLETS 100

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
	printw("Version 1.0.0\n");
	printw("<--Press Any Key to Start-->");
	
	attroff(COLOR_PAIR(1));
	
	getch(); //Waits for user to press a key
	clear(); //Clears the screen
	
	}

void displayScore()
{
	mvprintw(0,0,"Score: ");
	
}


int add_bullet(int player_x, int player_y){
	
	int bullet_x, bullet_y;
	
	bullet_x = player_x - 5;
	bullet_y = player_y - 5;
	
	
	mvprintw(bullet_x, bullet_y, "|");
	
	
	//bullet_present = TRUE;
	
	return bullet_x;
	return bullet_y;
//	return bullet_present;
	
	}

/*
void update_bullet(){
	
	bullet_x -= 1;
	bullet_y -= 1;
	
	}
	**/


int main(int argc, char *argv[])
{
	int cent_x = 0, cent_y = 2, player_x = 0, player_y = 0, play_init = 0;
	int delay = 80000;
	int max_y = 0, max_x = 0;
	
	int next_x_centP = 0;
	int cent_direction = 1;
	
	int next_x_playr = 0;
	int next_y_playr = 0;
	
	int bullet_x = player_x - 1;
	int bullet_y = player_y - 1;

	int player_direction = 1;
	int score = 0;
	char catPill[] = "OOOOOOOOOO";
	char player[] = "W";

	initscr();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	
	startScreen();
	
	

	
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	
	getmaxyx(stdscr, max_y, max_x);
	player_x = max_x/2;
	player_y = max_y-5;
	while(1)
	{
		getmaxyx(stdscr, max_y, max_x);
		
		displayScore();
		
		mvprintw(cent_y, cent_x, catPill);
		
		mvprintw(player_y, player_x, player);
		
		
		
		
		//update_bullet();
		
		refresh();
		
		usleep(DELAY);
		
		next_x_centP = cent_x + cent_direction;
		
		
		
		if (next_x_centP >= (max_x - strlen(catPill)) || next_x_centP < 0)
			{
			cent_direction *= -1;
			cent_y++;
			}
		else 
			{
			cent_x += cent_direction;
			}
		
		//next_x_playr = play
		//Key presses
		//int playerMove;
		halfdelay(2); 
		int ch;
		int c;
		ch = getch();
		switch(ch)
		{
				
			case KEY_RIGHT:
				if ((player_x + 2) > max_x)
				{player_x -= 2;}
				else {player_x += 1;}
				break;
				
			case KEY_LEFT:
				if ((player_x -2) <= 0)
				{player_x += 1;}
				else {player_x -= 1;}
				break;
				
			case KEY_UP:
				//add_bullet(bullet_x, bullet_y, bullet_present);
				break;
		}
	
	/*	if(ch == KEY_UP)
		{	
			
			fire();
			
		}*/
		
		clear();
			
	}
				
		cbreak(); //Close window when ctrl + c is pressed
	

	
	getch();
	endwin();	
	return 0;


}
