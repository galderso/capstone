//checkers
#include "checkers.h"
#include<iostream>
#include<vector>
using namespace std;

bool Checkers::Kinged(vector<vector<char>> board,int row1,int col1){//checks ifa piece is kinged or not
    if(board[row1][col1]!='X'&&board[row1][col1]!='O'){
        return false;
    }
    return true;
}
//Remove the opponent's piece when jumping over it
void Checkers::Jump(vector<vector<char>> &board, int row1, int col1, int row2, int col2){//removes element between where piece starts and ends up
    //Could check to make sure the piece removed is not the current player's piece
    //Up and right
    if(row1 > row2 && col1 < col2){
        board[row1 - 1][col1 + 1] = ' ';
        return;
    }
    //Up and left
    else if(row1 > row2 && col1 > col2){
        board[row1 - 1][col1 - 1] = ' ';
        return;
    }

    //Make sure the piece is a king
    if(Kinged(board, row1, col1)){
        //Down and right
        if(row1 < row2 && col1 > col2){
            board[row1 + 1][col1 - 1] = ' ';
            return;
        }
        //Down and left
        else if(row1 < row2 && col1 < col2){
            board[row1  + 1][col1 + 1] = ' ';
            return;
        }
    }
}

bool Checkers::Move(vector<vector<char>> &board,int row1,int col1,int row2, int col2,int turn){//checks all conditions for moving a piece and moves it
    if(board[row2][col2]==' '){// checks if spot not occupied
    if(Kinged(board,row1,col1)==false){// if not kinged
            if(board[row1][col1]=='x'){//checks if moving piece is x
                if((row2==row1+1&&row2==row1+2)&&(col2==col1+1&&col2==col1-1&&col2==col1+2&&col2==col1-2)){
                    if(row2==row1+2||col2==col1+2||col2==col1-2){//jumping
                        Jump(board,row1,col1,row2,col2);
                        board[row2][col2]='x';
                        board[row1][col1]=' ';
                        return true;
                    }else{//not jumping
                        board[row2][col2]='x';
                        board[row1][col1]=' ';
                        return true;
                    }
            } 
        }
        else if(board[row1][col1]=='o' && turn % 2 == 1){//checks piece o
            if((row2==row1-1&&row2==row1-2)&&(col2==col1+1&&col2==col1-1&&col2==col1+2&&col2==col1-2)){// validplace to move
                if(row2==row1-2||col2==col1+2||col2==col1-2){//jumping
                    Jump(board,row1,col1,row2,col2);
                    board[row2][col2]='o';
                    board[row1][col1]=' ';
                    return true;

                }
                else{//not jumping                   
                    board[row2][col2]='o';
                    board[row1][col1]=' ';
                    return true;
                }
            }
        }
        else{
            cout << "Invalid piece"<<endl;
        }
    }else{//has been kinged
    if(board[row1][col1]=='X'){//checks if moving piece is X
                if((row2==row1+1||row2==row1+2||row2==row1-1||row2==row1-2)&&(col2==col1+1||col2==col1-1||col2==col1+2||col2==col1-2)){
                    if(row2==row1+2||col2==col1+2||col2==col1-2){//jumping
                        Jump(board,row1,col1,row2,col2);
                        board[row2][col2]='X';
                        board[row1][col1]=' ';
                        return true;
                    }
                    else{//not jumping
                        board[row2][col2]='X';
                        board[row1][col1]=' ';
                        return true;
                    }
            } 
        }
        else if(board[row1][col1]=='O' && turn % 2 == 1){//checks piece O
            if((row2==row1-1||row2==row1-2||row2==row1+1||row2==row1+2)&&(col2==col1+1||col2==col1-1||col2==col1+2||col2==col1-2)){// validplace to move
                if(row2==row1-2||col2==col1+2||col2==col1-2){//jumping
                    Jump(board,row1,col1,row2,col2);
                    board[row2][col2]='O';
                    board[row1][col1]=' ';
                    return true;
                }
                else{//not jumping                   
                    board[row2][col2]='O';
                    board[row1][col1]=' ';
                    return true;
                }
            }
        }
        else{
            cout << "Invalid piece"<<endl;
        }
    }
}
cout<<"Invalid move";
return false;
}

bool Checkers::Winner(vector<vector<char>> board){//checks for winner
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




    //move:checks if a move is valid
    //jump: checks if move is a jump and if jump is possible(inbetween is opposite)and removes inbetween
    //jumpAgain: checks if jump again is possible
    //winner: checks if x or o is no longer on the board
    //kinged:checks if current piece is kinged
