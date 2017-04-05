#ifndef GAME_H
#define GAME_H


class Game
{
public:
   const char X = 'X';
   const char O = 'O';
   const char BLANK = '.';
   char player = X;

    char board[9] ;
    void showRules();
    int Mode;
    int Choice;
    //int turn;
    int inputMove;
   // char mark;
    void reset();
    void Display();
    char whoGoesFirst();
    int getMove();
    bool isWinner(char);
    bool isFull();
    void switchTurn();
    void Go(int);
  //  char GetTurn();
    bool isFree(int);
    void ChooseMode();

/////////////////////////////////////////////////
////////////Computer AI//////////////////////////
/////////////////////////////////////////////////
    int c;
    int moveByComp();
    int possWin(char b[]);

};


#endif // GAME_H
