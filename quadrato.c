/* 
 * File:   pallina.c
 * Author: paolo
 *
 * Created on November 4, 2015, 11:02 PM
 */

/*
 * quadrato che rimbalza - versione terminal
 * 
 * compilare con: gcc quadrato.c -lncurses
 *
 */


#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXX 79 /* Numero di colonne dello schermo */
#define MAXY 23 /* Numero di righe dello schermo */


// parametri quadrato lato, coord x, coord y, colore
void quadrato(int, int, int, char);
//int *coord(int,int);
int colore(char);
void delay (int);


void delay (int ritardo){
	// attesa di "ritardo" millisecondi
	ritardo=ritardo*1000;	
	usleep(ritardo);
        
}

void quadrato(int l, int x, int y, char co){
	
	int i,j;
	for (i=0; i<l; i++) {
		 for (j=0;j<l;j++) {
	           mvaddch(y+j,x+i,co);
		   refresh();
		 }
		 
	}
}


int main(){

/*  quadrato che rimbalza sul terminale
 *
 */
    

    printf("Iniziamo ... \n\r");
    initscr(); /* inizializzazione dello schermo */
    noecho(); /* i caratteri corrispondenti ai tasti premuti non saranno */
              /* visualizzati sullo schermo del terminale */
    curs_set(0); /* nasconde il cursore */

	
    //quadrato(3,1,1,'O');
	

    int mossax, mossay, direzionex, direzioney;
    int lato;
    // scelgo un lato per il quadrato
    lato=9;
    mossax=0;
    mossay=0;
    direzionex=0;
    direzioney=0;
   while (1) {
        //mvaddch(mossay,mossax,'o');
	//refresh();	
	quadrato(lato, mossax, mossay, 'O');
        delay(50);
        quadrato(lato, mossax, mossay, ' ');
	//mvaddch(mossay,mossax,' ');
	//refresh();	
      if (direzionex)
    	 mossax=mossax-1;
      else
    	 mossax=mossax+1;
      if (direzioney)
          	 mossay--;
            else
          	 mossay++;

      if (mossax > MAXX-lato)
    	  direzionex=1;
      if (mossax < 1)
    	  direzionex=0;

      if (mossay > MAXY-lato)
         	  direzioney=1;
      if (mossay < 1)
         	  direzioney=0;

      }
 
    endwin();
    return 0;
}
