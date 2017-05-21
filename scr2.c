#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define DELAY 80000
#define MAX_BULLETS 100

WINDOW *createWindow(int height, int width, int startx, int starty);

int main()

{
	WINDOW *mainWindow;
	
	int width = 50;
	int height = 150;
	int startx, starty;
	
	
	initscr();
	cbreak();
	
	keypad(stdscr, TRUE);
	
	mainWindow = createWindow(height, width, 5, 5);
	
	int c;
	c = getch();	
	if (c)	
	{endwin();}
	return 0;
	
}

WINDOW *createWindow(int height, int width, int startx, int starty)
{
	WINDOW *localWindow;
	
	localWindow = newwin(height, width, startx, starty);
	box(localWindow, 0, 0);
	
	wrefresh(localWindow);
	
	return localWindow;
	
}
