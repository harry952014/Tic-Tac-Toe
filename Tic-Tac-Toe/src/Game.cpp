#include "Game.h"
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cmath>

using namespace std;


void  Game::reset(){

    for(int i=0; i<9; i++){
        board [i]= BLANK;
    }
}

void Game:: showRules(){    //Displays Rules and Instructions

        cout << "Welcome to the classic Tic Tac Toe game. \n" << endl;
        cout << "RULES:  \nIt is a game for two players. \nThe goal is to be the first player to get 3 in a row." ;
        cout << "\nPlayers choose their signs X or O, and take turns alternating until either one player wins or the game draws. \n" << endl;

        cout << "INSTRUCTIONS TO PLAY: \n"
             << "- In order to make a move the player has to press any number from 1 to 9 depending on the choice. \n"
             << "- The upper left corner of the board corresponds to 1 and the lower right corner to 9. \n\n"
             << "EXAMPLE :\n\n";


    cout << "     |     |     " << endl;
    cout << "  " << 1 << "  |  " << 2 << "  |  " << 3 << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << 4 << "  |  " << 5 << "  |  " << 6 << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << 7 << "  |  " << 8 << "  |  " << 9 << endl;

    cout << "     |     |     " << "\n" << endl;


    cout << "\nPress ENTER to continue...." << endl;
    cin.get();
    system("cls");
}

void Game::Display(){   // it keeps displaying the updated board

        system("cls");


    for (int i = 0; i<9; i++){

        if(i==3 || i==6 ){
            cout << endl;
            cout << "___|_____|____"  << endl;

        }

        cout << board[i];

        if(i==0 || i==1|| i==3 || i==4|| i==6 || i==7)
            cout << "  |  ";

    }
           cout << "\n   |     |"  << endl;

}


bool Game::isFull(){     // checks if the game is draw.

for(int i=0; i<9; i++){
    if(board[i]== BLANK)
        return false;
    }

    return true;
}

bool Game::isFree(int s){      // checks if the move made by player is valid

        if(board[s-1]== BLANK)
        return true;

  return false;
}

bool Game::isWinner(char p){


   //for rows
    if(board[0]== p && board[1] == p && board[2] == p)return true;
    if(board[3]== p && board[4] == p && board[5] == p)return true;
    if(board[6]== p && board[7] == p && board[8] == p)return true;


    //for columns

    if(board[0]== p && board[3] == p && board[6] == p)return true;
    if(board[1]== p && board[4] == p && board[7] == p)return true;
    if(board[2]== p && board[5] == p && board[8] == p)return true;



    //for diagonals
    if(board[0]== p && board[4] == p && board[8] == p)return true;
    if(board[2]== p && board[4] == p && board[6] == p)return true;



    return false;


}


void Game ::ChooseMode(){     //Asks the user in which mode to play

    cout << "Choose the option by pressing the corresponding number:\n" << endl;

    cout << "1. Two-player game." << endl;
    cout << "2. Play with Computer." << endl;
    cin >>  Mode;

     while (Mode!=1 && Mode!=2)
    {
        cout << "You MUST press either 1 or 2. Try again." <<"\n\n";
        ChooseMode();
    }




}

char Game ::whoGoesFirst(){   //Asks the user which player wants to go first depending on the mode.

    if(Mode == 1){
    cout << "1. X goes first. "
         << "\n 2. O goes first." << endl;
    cin >> Choice;

        if(Choice == 1)      return X;
        else if(Choice == 2) return O;
        else if(Choice!=1 && Choice != 2){
            cout << "\nYou MUST press either 1 or 2. Try again." <<"\n\n";
            whoGoesFirst();  }



    }else if(Mode == 2){

        cout << "1.You go first as X.   \n"
             << "2. Computer goes first as X." ;
        cin >> Choice;

        if(Choice!=1 && Choice != 2){
            cout << "\nYou MUST press either 1 or 2. Try again." <<"\n\n";
            whoGoesFirst();
        }

        return X;

    }


}

int Game :: getMove() {   //return the value of user's input which is basically the index of the board array.


   if(Mode == 1){   //Two-Player mode
            if(player==X){
            cout << "\nPlayer X it's your turn. Make a move. " << endl;
            cin >> inputMove;
            return inputMove;

            } else if(player==O){
                cout << "\nPlayer O it's your turn. Make a move. "<< endl;
                cin >> inputMove;
                return inputMove;
            }
        }

    else if(Mode == 2){  // Play with Computer mode

                 if(Choice == 1) {     //You go first as X

                        if(player == X){
                            cout <<  "\nIt's your turn. Make a move. " << endl;
                            cin >> inputMove;
                            return inputMove;
                        }
                        else if(player == O){
                            cout << "\nComputer is making its move..." << endl;
                            Sleep(1000);
                            return moveByComp();

                        }
                 }
                 else if(Choice == 2) {    // Computer goes first as X

                         if(player == X){
                                cout << "\nComputer is making its move..." << endl;
                                Sleep(1000);
                                return moveByComp();

                        }
                        else if(player == O){
                                cout <<  "\nIt's your turn. Make a move. " << endl;
                                cin >> inputMove;
                                return inputMove;

                        }

                 }

    }

}


void Game::Go(int s){     // this function finally makes the move for the player by assigning the marks to the indexes of array

    while(s<1 || s>9){

        cout << "Out of range."<< endl;
        cin >> s;
        }


        if(isFree(s) == true)
           board[s-1] = player;      //  assigns the current mark to index of input minus 1 since index starts at 0
        else if(isFree(s) == false){
            cout << "Slot is not free. Choose a different slot." << endl;
            cin >> s;
            board[s-1] = player;
        }



}


void Game::switchTurn(){   //it switches the marks for the player to make moves alternating

if(player == X )
    player = O;
else
    player = X;

}



int Game::possWin(char b[]){


//   Checks every slot for X. The best move to either make X win or block X win.

        if(((b[1]== X && b[2] == X ) || (b[4]== X && b[8] == X) || (b[3]== X && b[6] == X )) && b[0]==BLANK)  return 1;
        if(((b[0]== X && b[2] == X ) || (b[7]== X && b[4] == X)) && b[1]==BLANK)                              return 2;
        if(((b[0]== X && b[1] == X ) || (b[8]== X && b[5] == X) || (b[6]== X && b[4] == X )) && b[2]==BLANK)  return 3;

        if(((b[0]== X && b[6] == X ) || (b[4]== X && b[5] == X))  && b[3]==BLANK)                             return 4;
        if(((b[1]== X && b[7] == X ) || (b[3]== X && b[5] == X) || (b[2]== X && b[6] == X)) && b[4]==BLANK)   return 5;
        if(((b[3]== X && b[4] == X ) || (b[2]== X && b[8] == X)) && b[5]==BLANK)                              return 6;

        if(((b[7]== X && b[8] == X ) || (b[0]== X && b[3] == X) || (b[2]== X && b[4] == X ))&& b[6]==BLANK)   return 7;
        if(((b[1]== X && b[4] == X ) || (b[6]== X && b[8] == X))&& b[7]== BLANK)                              return 8;
        if(((b[0]== X && b[4] == X ) || (b[2]== X && b[5] == X) || (b[6]== X && b[7] == X ))&& b[8]==BLANK)   return 9;




    //Checks every slot for O. The best move to either make O win or block O win.

        if(((b[1]== O && b[2] == O ) || (b[4]== O && b[8] == O) || (b[3]== O && b[6] == O )) && b[0]==BLANK)  return 1;
        if(((b[0]== O && b[2] == O ) || (b[7]== O && b[4] == O)) && b[1]==BLANK)                              return 2;
        if(((b[0]== O && b[1] == O ) || (b[8]== O && b[5] == O) || (b[6]== O && b[4] == O )) && b[2]==BLANK)  return 3;

        if(((b[0]== O && b[6] == O ) || (b[4]== O && b[5] == O)) && b[3]==BLANK)                              return 4;
        if(((b[1]== O && b[7] == O ) || (b[3]== O && b[5] == O) || (b[2]== O && b[6] == O )) && b[4]==BLANK)  return 5;
        if(((b[3]== O && b[4] == O ) || (b[2]== O && b[8] == O)) && b[5]==BLANK)                              return 6;

        if(((b[7]== O && b[8] == O ) || (b[0]== O && b[3] == O) || (b[2]== O && b[4] == O ))&& b[6]==BLANK)   return 7;
        if(((b[1]== O && b[4] == O ) || (b[6]== O && b[8] == O))&& b[7]== BLANK)                              return 8;
        if(((b[0]== O && b[4] == O ) || (b[2]== O && b[5] == O) || (b[6]== O && b[7] == O ))&& b[8]==BLANK)   return 9;

        if(b[4] == BLANK)               /* Center Move increases winning chances*/                            return 5;



    return -1;
}

int Game::moveByComp(){  //return the input by computer

   if (possWin(board)!=-1)   // checks for the winning possibility

        c = possWin(board);

    else
    {
        do
        {
            c = rand()%10 ; // random move

        }
        while ( !isFree(c) && !isFull() );
    }

    return c;
}





