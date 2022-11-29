#include "checkers.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    Checkers c; //Object when calling functions

    cout <<"Welcome to checkers"<<endl;

   vector<vector<char>> board{
         {' ','x',' ','x',' ','x',' ','x'},
         {'x',' ','x',' ','x',' ','x',' '},
         {' ',' ',' ',' ',' ',' ',' ',' '},
         {' ',' ',' ',' ',' ',' ',' ',' '},
         {' ',' ',' ',' ',' ',' ',' ',' '},
         {' ',' ',' ',' ',' ',' ',' ',' '},
         {' ','o',' ','o',' ','o',' ','o'},
         {'o',' ','o',' ','o',' ','o',' '}
         };
         while((c.Winner(board))!=false){
            do{
         c.Display(board);
    
    cout<< "Enter the piece you want to move"<<endl;
    int row1,col1,row2,col2;
    cin>>row1>>col1;
    cout<< "Enter the place you want to move to"<<endl;
    cin>>row2>>col2;

    if(c.Move() == true){
        swap(board[row1][col1],board[row2][col2]);
    }
            }while(c.JumpPiece(Player1, Player2));   //FIX THIS!!!
        }
}