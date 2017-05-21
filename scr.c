#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define DELAY 80000
#define MAX_BULLETS 100

char catPill[] = "OOOOOOOOOO";
char player[] = "W";

int cent_x = 0, cent_y = 2, player_x = 0, player_y = 0, play_init = 0;
int delay = 80000;
int max_y = 0, max_x = 0;

int next_x_centP = 0;
int cent_direction = 1;
	
int next_x_playr = 0;
int next_y_playr = 0;
	
int bullet_x = player_x - 1;
int bullet_y = player_y - 1;
	
char bullet_array [10];
	
	int b = 0;
	char current_bullet;

	int player_direction = 1;
	int score = 0;

//Contains all the code for the start screen of the game
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

//Displays and updates the score of the game
void displayScore(int score)


{
	mvprintw(0,0,"Score: %d", score);
	
}

//Contains all the code responsible for the movement of the centipede	
int moveCentipede(char *catPill, int cent_y, int cent_x, int next_x_centP, int max_y, int max_x, int cent_direction)
{
	
	
	mvprintw(cent_y, cent_x, catPill);
	
	if (next_x_centP >= (max_x - strlen(catPill)) || next_x_centP < 0)
			{
			cent_direction *= -1;
			cent_y++;
			}
		else 
			{
			cent_x += cent_direction;
			}
	return cent_y, cent_x, next_x_centP, max_y, max_x, cent_direction;		
	
}

//initialises the array holding the bullets
void init_bullet_array(char *bullet_array)
{
	for (int i=0; i<10; i++)
	{
		bullet_array[i] = '|';
	}
}




int main(int argc, char *argv[])
{
	
	
	
	

	initscr();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	
	startScreen();
	
	init_bullet_array(bullet_array);
	
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	
	getmaxyx(stdscr, max_y, max_x);
	player_x = max_x/2;
	player_y = max_y-5;
	while(1)
	{
		getmaxyx(stdscr, max_y, max_x);
		
		displayScore(score);
		
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
			
			
		//moveCentipede(catPill, cent_y, cent_x, next_x_centP, max_y, max_x, cent_direction);	
		
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
				
			case KEY_UP :
				if (b >= 10){break;}
				current_bullet = bullet_array[b];
				//mvprintw((player_x - 1), (player_y -1), current_bullet);
				b++;
				
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
