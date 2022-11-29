//checkers
#include "checkers.h"
#include<iostream>
#include<vector>

using namespace std;
bool Checkers::Kinged(vector<vector<char>> board,int row1,int col1){
    if(board[row1][col1]!='X'&&board[row1][col1]!='O'){
        return false;
    }
    return true;
}
//Checks if the move it valid
void Checkers::Move(vector<vector<char>> &board,int row1,int col1,int row2, int col2){
    if(Kinged(board,row1,col1)==false){
        if((row2==row1+1&&row2==row1+1)&&(col2==col1+1&&col2==col1-1&&col2==col1+2&&col2==col1-2)){
            //if move is valid. Make the swap. Since we are passing by refrence, it would make the swap more permanent
        }

    }
}


bool Checkers::Winner(vector<vector<char>> board){
    int count1=0,count2=0;
    for(int i =0 ;i<8;i++){
        for(int j = 0;j<8;j++){
            if((board[i][j]=='x')&&(board[i][j]=='X')){
                count1++;
            }
            else if((board[i][j]=='o')&&(board[i][j]=='O')){
                count2++;
            }
        }
    }
    if(count1==0||count2==0){
        return true;
    }
    return false;
}

void Checkers::Display(vector<vector<char>> board){
    cout << "  0 1 2 3 4 5 6 7" << endl;
    for(int i = 0; i < 8; i++){
        cout << i << '|';
        for(int j = 0; j < 8; j++){
            cout << board[i][j] << "|";
        }
        cout << endl;
    }
}



/*

   void swap(int i,int j){
    int temp = i;
    i=j;
    j=temp;
   }
*/
    //swap :swaps element when player moves
    //move:checks if a move is valid
    //jump: checks if move is a jump and if jump is possible(inbetween is opposite)and removes inbetween
    //jumpAgain: checks if jump again is possible
    //winner: checks if x or o is no longer on the board
    //kinged:checks if current piece is kinged
