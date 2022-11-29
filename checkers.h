#include <vector>
#include <iostream>
using namespace std;

class Checkers{
    private:
        char Player1;
        char Player2;

    public:
        bool Winner(vector<vector<char>> board);
        bool Move();
        void JumpPiece(char piece1, char piece2);
        bool Check_for_King(char piece, vector<vector<char>> board);


};