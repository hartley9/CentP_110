#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>	

#define MAX_BULLETS 100


void draw_borders(WINDOW *screen);
char cent_pill[] = "0000000000";
char player[] = "W";

int cent_x = 0;
int cent_y = 2;

int next_x_cent = 0;
int cent_direction = 1;

int player_x = 0;
int player_y = 0;
int player_init = 0;

int next_x_player = 0;
int next_y_player = 0;

char bullet_array [MAX_BULLETS];
int b = 0;
char current_bullet;




int main(){
	int max_y = 0, max_x = 0;

	int score_size = 3;
	initscr();
	noecho();
	curs_set(FALSE);
	getmaxyx(stdscr, max_y, max_x);

	WINDOW *field = newwin((max_y - score_size), max_x, 0, 0);
	WINDOW *score = newwin(score_size, max_x, (max_y - score_size), 0);

	

	while(1){

		mvwprintw(field, 1, 1, "Field");
		mvwprintw(score, 1, 1, "Score");

		draw_borders(field);
		draw_borders(score);

		wrefresh(field);
		wrefresh(score);
	}

	getch();	
	delwin(field);
	delwin(score);
	endwin();

}

void draw_borders(WINDOW *screen){
	int max_x, max_y, i;
	getmaxyx(screen, max_y, max_x);
	mvwprintw(screen, 0, 0, "+");
	mvwprintw(screen, max_y-1, 0, "+");
	mvwprintw(screen, 0, max_x-1, "+");
	mvwprintw(screen, max_y-1, max_x-1, "+");

	//Loop for the sides
	for(i=1; i<(max_y-1); i++){
		mvwprintw(screen,i,0,"|");
		mvwprintw(screen, i, max_x-1, "|");
	}	
		
	for(i=1; i<(max_x-1); i++){
		mvwprintw(screen, 0, i, "-");
		mvwprintw(screen, max_y-1, i, "-");
	}
	
}	