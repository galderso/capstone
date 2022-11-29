//checkers
#include<iostream>
#include<vector>

using namespace std;

bool move(int row1,int col1,int row2, int col2){
    if(kinged()==false){

    }


}


bool winner(vector<vector<char>> board){
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

int main(){
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
         while(winner(board)!=false){
            do{
         cout<<"  0 1 2 3 4 5 6 7"<<endl;
         for(int i =0;i<8;i++){
            cout<< i<<'|';
          
            for(int j = 0;j<8;j++){
                cout<<board[i][j]<<'|';
            }
            cout<<endl;
         }
    
    cout<< "Enter the piece you want to move"<<endl;
    int row1,col1,row2,col2;
    cin>>row1>>col1;
    cout<< "Enter the place you want to move to"<<endl;
    cin>>row2>>col2;

    if(move(row1,col1,row2,col2)){
        swap(board[row1][col1],board[row2][col2]);
    }
    }while(jumpAgain());   
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
