#include <vector>
#include <iostream>
using namespace std;

class Checkers{
    public:
        
        bool Winner(vector<vector<char>> board);
        bool Move(vector<vector<char>> &board, int row1, int col1, int row2, int col2, int turn);
        void Jump(vector<vector<char>> &board, int row1, int col1, int row2, int col2);
        bool Kinged(vector<vector<char>> board,int row1,int col1);
        void Display(vector<vector<char>> board);
};