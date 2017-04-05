#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include "Game.h"
#include <ctime>
using namespace std;

int main()
{

srand(time(NULL));

Game t;            //object instantiation of class Game


t.showRules();
t.reset();                              //Empty the board for the players
t.ChooseMode();                         //Asks the user to choose a mode
t.player = t.whoGoesFirst();




do{


    t.Display();                       // Displays the board
    int m = t.getMove();               //gets the move from the player and Computer
    t.Go(m);                           //Marks the move with X or O

    if(t.isWinner(t.player)) break;    //check for the winner and breaks if there IS one.
    t.switchTurn();                    //switches the mark for other player


}while(!t.isFull());


 t.Display();

 if(t.isFull() && !t.isWinner(t.player))
    cout << "\n GAME DRAW.";
 else if(t.isWinner(t.X))
    cout << "\n\n Player X wins. Smart moves!!" << endl;
 else
    cout << "\n\n Player O wins. Smart moves!!" << endl;



    return 0;
}
