#include "checkers.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    Checkers c; //Object when calling functions

    int turn = 1; // Tracks turns
    
    cout << "Welcome to checkers" << endl;
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
            cout<<"  0 1 2 3 4 5 6 7"<<endl;
            for(int i =0;i<8;i++){
                cout<< i<<'|';
                for(int j = 0;j<8;j++){
                    cout<<board[i][j]<<'|';
                }
                cout<<endl;
            }
            do{//loops again if piece was not valid
            if(turn % 2 == 1) cout << "It's Player 1 (o's) turn. " << endl;
            else cout << "It's Player 2 (x's) turn. " << endl; 
            cout << "Enter the piece you want to move" << endl;
            int row1,col1,row2,col2;
            cin >> row1 >> col1;
            cout << "Enter the place you want to move to" << endl;
            cin >> row2 >> col2;
            if(c.Move(board,row1,col1,row2,col2,turn)==true){
            turn += 1;
            break;
            }
            }while(true);
        } while(c.Jump());   //FIX THIS!!!
    }

    return 0;
}