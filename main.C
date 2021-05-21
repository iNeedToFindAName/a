#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <ncurses.h> 
#include <unistd.h>
#include <locale.h>

int L, C;

int TAB[3][3]= { {2,4,3},
                 {1,5,6}, 
                 {8,7,0}};

int reponse[3][3]={ {1,2,3},
                    {4,5,6},
                    {7,8,0}};

void afficherTAB(){
    int x,y;
    for (x=0; x<3; x++)      
    {
        for (y=0; y<3; y++)
        {
            printf("%d ", TAB[x][y]);
        }
        printf("\n");
    }
}


int correction(){
    int x,y;
    for (x=0; x<3; x++)      
    {
        for (y=0; y<3; y++)
        {
            if( TAB[x][y] != reponse[x][y]){
                return 0;
            }
        }
    }
    return 1;
}

void WhereIsEmpty(int *XZero, int *YZero){
    for (int x=0; x<3; x++){
        for (int y=0; y<3; y++){
            if( TAB[x][y] == 0){
                *XZero = x;
                *YZero = y;
                break;
            }
        }
    }
}

void echange(int XClick, int YClick, int niveau){
    int XZero, YZero,temp;
    WhereIsEmpty(&XZero, &YZero);

    if(niveau == 1 && ( (XClick == XZero-1 && YClick == YZero ) || (XClick == XZero+1 && YClick == YZero ) || (YClick == YZero-1 && XClick == XZero ) || (YClick == YZero+1 && XClick == XZero ) || (YClick == YZero+1 && XClick == XZero+1 ) || (YClick == YZero-1 && XClick == XZero+1 ) || (YClick == YZero+1 && XClick == XZero-1 ) || (YClick == YZero-1 && XClick == XZero-1 ) )){
        temp = TAB[XClick][YClick];
        TAB[XClick][YClick] = TAB[XZero][YZero];
        TAB[XZero][YZero] = temp;
    }
    else if(niveau == 2 && ( (XClick == XZero-1 && YClick == YZero ) || (XClick == XZero+1 && YClick == YZero ) || (YClick == YZero-1 && XClick == XZero ) || (YClick == YZero+1 && XClick == XZero ))){
        temp = TAB[XClick][YClick];
        TAB[XClick][YClick] = TAB[XZero][YZero];
        TAB[XZero][YZero] = temp;
    }
    else{
        printf("Erreur tu peux pas faire ça");
    }
}

void ncurses_initialiser() {
  initscr();	      
  cbreak();	       
  noecho();            
  keypad(stdscr, TRUE);	
  refresh();           
  curs_set(FALSE);
}

void ncurses_couleurs() {
  if(has_colors() == FALSE) {
    endwin();
    fprintf(stderr, "Le terminal ne supporte pas les couleurs.\n");
    exit(EXIT_FAILURE);
  }
  start_color();
}

void ncurses_souris() {
  if(!mousemask(ALL_MOUSE_EVENTS, NULL)) {
    endwin();
    fprintf(stderr, "Erreur lors de l'initialisation de la souris.\n");
    exit(EXIT_FAILURE);
  }
}

int click_souris()
{
  MEVENT event ;
  int ch;

  while((ch = getch()) != KEY_F(1)) 
  {
    switch(ch) 
    {
      case KEY_F(2): 
	return 1;
      case KEY_MOUSE:
        if(getmouse(&event) == OK) 
	{
	  C = event.x;
	  L = event.y;
	  if(event.bstate & BUTTON1_CLICKED)
	  {
	    if (L< 51 && C<132)
	    {
	    return 0;
	    }
	  }
	}
    }
  }
  return 0;
}

int main() {  
  setlocale(LC_ALL, "");
  ncurses_initialiser(); 
  ncurses_souris();
  
  scrollok(stdscr, TRUE);
  
  while (1)
  {
    click_souris();
    clear();
    move(2,0);
    printw (" ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════╗ \n");
    printw (" ║                                            JEU DU TAQUIN                                                ║ \n");
    printw (" ╠═════════════════════════════════════════════════════════════════════════════════════════════════════════╣ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ║                                                                                                         ║ \n");
    printw (" ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════╝ \n");

    move(3,10);
    printw("Clique : %d,%d", L,C);

  }
  endwin(); 
  return 0;
}
