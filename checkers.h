#include <vector>
#include <iostream>
using namespace std;

class Checkers{
    private:
        char Player1;
        char Player2;

    public:
        bool Winner(vector<vector<char>> board);
        bool Move(vector<vector<char>> &board, int row1, int col1, int row2, int col2);
        void Jump(vector<vector<char>> &board, int row1, int col1, int row2, int col2);
        bool Kinged(vector<vector<char>> board,int row1,int col1);
        bool Winner(vector<vector<char>> board);
        void Display(vector<vector<char>> board);
};