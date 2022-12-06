#include <iostream>
#include <vector>
#include <cctype>
using namespace std;
//checkers

bool Kinged(vector<vector<char>> board,int row1,int col1){//checks if a piece is kinged or not
    if(board[row1][col1]!='X'&&board[row1][col1]!='O'){
        return false;
    }
    return true;
}
//Remove the opponent's piece when jumping over it
bool Jump(vector<vector<char>> &board, int row1, int col1, int row2, int col2){//removes element between where piece starts and ends up
    //Could check to make sure the piece removed is not the current player's piece
    //Up and right
    if(row1 > row2 && col1 < col2){
        if(toupper(board[row1 - 1][col1 + 1]) != toupper(board[row1][col1])){ //accomadates for pieces that could be kings
            board[row1 - 1][col1 + 1] = ' ';
            return true;
        }
        else{
            return false;
        }
        //check if can jump again
        //if not, then return true
    }
    //Up and left
    else if(row1 > row2 && col1 > col2){
        if(toupper(board[row1 - 1][col1 - 1]) != toupper(board[row1][col1])){
            board[row1 - 1][col1 - 1] = ' ';
            return true;
        }
        else{
            return false;
        }
    }

    //Make sure the piece is a king or x
    if(Kinged(board, row1, col1) || board[row1][row2] == 'x'){
        //Down and right
        if(row1 < row2 && col1 > col2){
            if(toupper(board[row1 + 1][col1 - 1]) != toupper(board[row1][col1])){
                board[row1 + 1][col1 - 1] = ' ';
                return true;
            }
            else{
                return false;
            }
        }
        //Down and left
        else if(row1 < row2 && col1 < col2){
            if(toupper(board[row1 + 1][col1 + 1]) != toupper(board[row1][col1])){
                board[row1 + 1][col1 + 1] = ' ';
                return true;
            }
            else{
                return false;
            }
        }
    }

    return false;
}

bool Move(vector<vector<char>> &board,int row1,int col1,int row2, int col2,int turn){//checks all conditions for moving a piece and moves it
    bool jump = false;
    if(board[row2][col2]==' '&& row2 <8 && row2>=0 && col2<8 && col2>=0){// checks if spot not occupied
    if(Kinged(board,row1,col1)==false){// if not kinged
            if(board[row1][col1]=='x'){//checks if moving piece is x
                if((row2==row1+1||row2==row1+2)&&(col2==col1+1||col2==col1-1||col2==col1+2||col2==col1-2)){
                    if(row2==row1+2||col2==col1+2||col2==col1-2){//jumping
                        if(Jump(board,row1,col1,row2,col2)==false){
                            return false;
                        }
                        
                        if(row2==7){//kings
                            board[row2][col2]='X';
                        }else{
                        board[row2][col2]='x';
                        }
                        board[row1][col1]=' ';
                        return true;
                    }else{//not jumping
                        if(row2==7){
                            board[row2][col2]='X';
                        }else{
                        board[row2][col2]='x';
                        }
                        board[row1][col1]=' ';
                        return true;
                    }
            } 
        }
        else if(board[row1][col1]=='o' && turn % 2 == 1){//checks piece o
            if((row2==row1-1||row2==row1-2)&&(col2==col1+1||col2==col1-1||col2==col1+2||col2==col1-2)){// validplace to move
                if(row2==row1-2||col2==col1+2||col2==col1-2){//jumping
                    if(Jump(board,row1,col1,row2,col2)==false){
                        return false;
                    }
                    if(row2==0){//kings
                            board[row2][col2]='O';
                            cout<<"enter 13";
                        }else{
                        board[row2][col2]='o';
                        }
                    board[row1][col1]=' ';
                    return true;

                }
                else{//not jumping   
                    if(row2==0){
                        board[row2][col2]='O';
                    }else{
                    board[row2][col2]='o';
                    }
                    board[row1][col1]=' ';
                    return true;
                }
            }
        }
        else{
            cout << "Invalid piece."<<endl;
        }
    }else{//has been kinged
    if(board[row1][col1]=='X'){//checks if moving piece is X
                if((row2==row1+1||row2==row1+2||row2==row1-1||row2==row1-2)&&(col2==col1+1||col2==col1-1||col2==col1+2||col2==col1-2)){
                    if(row2==row1+2||col2==col1+2||col2==col1-2){//jumping
                        if(Jump(board,row1,col1,row2,col2)==false){
                            return false;
                        }
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
        }else if(board[row1][col1]=='O' && turn % 2 == 1){//checks piece O
            if((row2==row1-1||row2==row1-2||row2==row1+1||row2==row1+2)&&(col2==col1+1||col2==col1-1||col2==col1+2||col2==col1-2)){// validplace to move
                if(row2==row1-2||col2==col1+2||col2==col1-2){//jumping
                    if(Jump(board,row1,col1,row2,col2)==false){
                        return false;
                    }
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
            cout << "Invalid piece."<<endl;
            return false;
        }
    }
}
cout<<"Invalid move."<<endl;
return false;
}

bool Winner(vector<vector<char>> board){//checks for winner
    int count1=0,count2=0;
    for(int i =0 ;i<8;i++){
        for(int j = 0;j<8;j++){
            if((board[i][j]=='x')||(board[i][j]=='X')){
                count1++;
            }
            else if((board[i][j]=='o')||(board[i][j]=='O')){
                count2++;
            }
        }
    }
    if(count1==0){
        cout<<"O is the winner!!"<<endl;
        return true;
    }
    if(count2==0){
                cout<<"X is the winner!!"<<endl;
        return true;
    }
    return false;
}

void Display(vector<vector<char>> board){
    cout << "  0 1 2 3 4 5 6 7" << endl;
    for(int i = 0; i < 8; i++){
        cout << i << '|';
        for(int j = 0; j < 8; j++){
            cout << board[i][j] << "|";
        }
        cout << endl;
    }
}

bool JumpAgain(vector<vector<char>> &board,int row2,int col2){
    cout<<"enter5";
    if(Kinged(board,row2,col2)==false){
        if(board[row2][col2]=='o'){
            cout<<"enter4";
            if(board[row2-2][col2+2]==' '&& (board[row2-1][col2+1]=='x'||board[row2-1][col2+1]=='X')){
                cout<<"enter2";
                return true;
            }else if(board[row2-2][col2-2]==' '&&(board[row2-1][col2-1]=='x'||board[row2-1][col2-1]=='X')){
                cout<<"enter3";
                return true;
            }else{
                cout<<"enter12";
                return false;
            }
        }else if(board[row2][col2]=='x'){//if x
            if(board[row2+2][col2+2]==' '&& (board[row2+1][col2+1]=='o'||board[row2+1][col2+1]=='O')){
                return true;
            }else if(board[row2+2][col2-2]==' '&&(board[row2+1][col2-1]=='o'||board[row2+1][col2-1]=='O')){
                return true;
            }else{
                cout<<"enter12";
                return false;
            }

        }
    }else{
        if(board[row2][col2]=='O'){
            cout<<"enter1";
            if((board[row2-2][col2+2]==' '||board[row2+2][col2+2]==' ')&& ((board[row2-1][col2+1]=='x'||board[row2+1][col2+1]=='x')||(board[row2-1][col2+1]=='X'||board[row2+1][col2+1]=='X'))){
                return true;
            }else if((board[row2-2][col2-2]==' '||board[row2+2][col2-2]==' ')&&((board[row2-1][col2-1]=='x'||board[row2+1][col2-1]=='x')||(board[row2-1][col2-1]=='X'||board[row2+1][col2-1]=='X'))){
                return true;
            }
        }else{//if 'X'
            if((board[row2+2][col2+2]==' '||board[row2+2][col2-2]==' ')&& ((board[row2+1][col2+1]=='o'||board[row2+1][col2-1]=='o')||(board[row2+1][col2+1]=='O'||board[row2+1][col2-1]=='O'))){
                return true;
            }else if((board[row2+2][col2-2]==' '||board[row2+2][col2+2]==' ')&&((board[row2+1][col2-1]=='o'||board[row2+1][col2+1]=='o')||(board[row2+1][col2-1]=='O'||board[row2+1][col2+1]=='O'))){
                return true;
            }

        }
        }
        cout<<"enter 9";
    return false;
    }

int main(){
    
    int turn = 1,count=0; // Tracks turns
    
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
    Display(board);
    while((Winner(board))==false){
        
        bool jumpAgain =false;
        count =0;
        do{

            do{//loops again if piece was not valid
            int row1=0,col1=0,row2=0,col2=0;
            if(turn % 2 == 1) cout << "It's Player 1 (o's) turn. " << endl;
            else cout << "It's Player 2 (x's) turn. " << endl; 
            cout << "Enter the piece you want to move:" << endl;
            cin >> row1 >> col1;
            cout << "Enter the place you want to move to:" << endl;
            cin >> row2 >> col2;
            if(Move(board,row1,col1,row2,col2,turn)==true){
                cout<<"enter11";

                Display(board);
                
                
                
                if(row1==row2+2||row1==row2-2){//checks if jumped
                if(count==0){
                if(JumpAgain(board,row2,col2)!=false){
                    jumpAgain =true;
                    count++;
                }
                }else{
                    jumpAgain =false;
                }
                }
                cout<<"enter10";
            break;
            }
            }while(true);
       } while(jumpAgain);   //loops if jump again is possible
       turn+=1;
       cout<<"enter7";
    }
    cout<<"exiting";
    return 0;
}