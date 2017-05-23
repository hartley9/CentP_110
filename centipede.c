//Imports all the libraries necessary for the program to run
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

//Constands defined 
#define DELAY 80000
#define MAX_BULLETS 100

char centipede[] = "OOOOOOOOOO"; //Array of zeros which holds the centipede
char player[] = "W"; //Player ship is a W

int cent_x = 0, cent_y = 2, player_x = 0, player_y = 0, play_init = 0;
int delay = 80000;
int max_y = 0, max_x = 0;

int next_x_cent = 0;
int cent_direction = 1;
  
int next_x_playr = 0;
int next_y_playr = 0;
  
char bullet_array [] = {'|', '|', '|', '|', '|', '|', '|', '|', '|', '|'};
int bullet_array_initialised = 0;
int bullet_x[10] = {}; 
int bullet_y[10] = {};
void init_bullet_position(){
  for (int i = 0; i < sizeof(bullet_y); ++i)
  {
    bullet_y[i] = player_y;
  }
}
  
int b = 0; //Used as a counter for the number of bullets present
char bull;

int player_direction = 1;
int score = 0;



//Contains all the code for the start screen of the game
void startScreen(){
  
  //Checks if the players terminal supports colours
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

/*
//initialises the array holding the bullets
void init_bullet_array(char *bullet_array)
{
  for (int i=0; i<10; i++)
  {
    bullet_array[i] = '|';
  }
}
**/

int main(int argc, char *argv[])
{ 

  //Initialises screen for ncurses
  initscr();
  curs_set(FALSE);
  keypad(stdscr, TRUE);
  
  startScreen();
  
 // init_bullet_array(bullet_array); 
  mvprintw(0, 0, &bullet_array[b]);
  
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  
  //Function that returns the dimensions of the game window
  getmaxyx(stdscr, max_y, max_x);
 
  player_x = max_x/2;
  player_y = max_y-5;
 
  //Main game loop 
  int b = -1;
  while(1)
  {


    if (bullet_array_initialised<1){
      init_bullet_position();
    }

    if (b>0){
      int i;
      for (i=0;i<=b;i++){
        bullet_y[i] = bullet_y[i] - 1;
      }

      for (i=0; i<=b; i++){
        mvprintw(bullet_y[b], bullet_x[b], &bullet_array[b]);
      }
    }



    getmaxyx(stdscr, max_y, max_x);
    
    //Displays the score on screen
    displayScore(score);

    //Displays the centipede in the relevent place on the screen
    mvprintw(cent_y, cent_x, centipede);

    //Displays the player ship in the relevent place on the screen
    mvprintw(player_y, player_x, player);
    
    //Updates all the elements present on screen
    refresh();
    
    //Slows game execution so more easily playable
    usleep(DELAY);
    
    next_x_cent = cent_x + cent_direction;
    
    //Checks to see if the next 
    if (next_x_cent >= (max_x - strlen(centipede)) || next_x_cent < 0)
      {
      
        
        cent_direction *= -1;
        cent_y++;
      }
    else 
      {
      cent_x += cent_direction;
      }
      
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
        b++;
        break;
    }

    
    clear();
      
  }
  
  bullet_array_initialised += 1;

  cbreak(); //Close window when ctrl + c is pressed
  getch();
  endwin(); 
  return 0;


}
 