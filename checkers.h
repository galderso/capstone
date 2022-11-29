#include <vector>
#include <iostream>
using namespace std;

class Checkers{
    private:
        char Player1;
        char Player2;

    public:
        bool winner(vector<vector<char>> board);
        bool move(vector<vector<char>> board,int row1,int col1,int row2, int col2);
        void jump(char piece1, char piece2);
        bool kinged(vector<vector<char>> board,int row1,int col1);


};