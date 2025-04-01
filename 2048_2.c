// ldd: -lncurses
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>

// legende 
//   ?? =  pas  totalement compris 
//   !! =  assez importants 

void INIT_2048 () {
  initscr();// ligne !! , ca initilialise les parametre et les fonctions
  // de la bibliotheque NCurses??
  raw();// active le mode brut , ca permet d'ecrire sans mettre entrée ??
 keypad(stdscr, TRUE);// nrml c pour utiliser les touche de direction duc laviers ( mais bizzaremebts qd je la supprime ca marche tjr ) 
  noecho();//désactive l'affichage des caractères saisis au clavier.??
  srand(time(NULL));// initialise le tps actuelle 
}
// en gros c'est une fonction !! , qui donne les outils de base pour bien commencer le jeu , mais plus generalements 
// elle prepare intialise les valeurs et les variables au bon fonctionemens de la'ffichage de l'ecran 
// elle prepare l'ecran pour que nous on on ecris du txt et que ellle affiche 
// "" En résumé, la fonction INIT_2048 prépare l'interface utilisateur en 
//			utilisant la bibliothèque NCurses pour pouvoir y afficher du texte et 
//			répondre aux entrées de l'utilisateur via le clavier."" 

// ___ img = chefs qui prepare ses ingredients et ses couteaux 





void DONE_2048() {
  endwin();// tt suppr et repartir à 0
  exit(0);// quitter le jeu , le 0 ca permet de savoir si le programme est sorti ss erreur ( si c 0 ) ??
}
// variable globale non signé (1possible negatifs ) 
unsigned int board[4][4];// matrice à 4 ligne et 4 collone 
// [ ligne ] [ collone ] 
unsigned int score = 0;

void init_board()
{
    for (int row = 0; row < 4; row++)// ligne 
    {
        for (int col = 0; col < 4; col++)// collone 
        {
            board[row][col] = 0;
        }
    }
}

void display_board () {
  move(0,0);
  printw("== 2048 =============================\n", score);
  printw("====================== score: %7i\n", score);
  printw("\n");
  printw("+--------+--------+--------+--------+\n");
  for (int row=0; row<4; row++) {
    printw("|        |        |        |        |\n");
    printw("|");
    for (int col=0; col<4; col++) {
      if (board[row][col]) {
        printw(" %5i  |", board[row][col]);
      } else {
        printw("        |");
      }
    }
    printw("\n");
    printw("|        |        |        |        |\n");
    printw("+--------+--------+--------+--------+\n");
  }
  printw("\n");
  refresh();
}

int main() {
  INIT_2048();
  init_board();
  display_board();
  getch();
  DONE_2048();
}