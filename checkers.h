#include <vector>
#include <iostream>
using namespace std;

class Checkers{
    private:
        char Player1;
        char Player2;

    public:
        bool Winner(vector<vector<char>> board);
<<<<<<< HEAD
        void Move(vector<vector<char>> &board,int row1,int col1,int row2, int col2);
=======
        bool Move(vector<vector<char>> board,int row1,int col1,int row2, int col2);
<<<<<<< HEAD
        void jump(char piece1, char piece2);
=======
>>>>>>> f13c1044051c689d672f9d58d4164bdadca8aa1d
        void Jump(char piece1, char piece2);
>>>>>>> 53d83c8ae4b234c7809240da6cac1433cf16ccbe
        bool Kinged(vector<vector<char>> board,int row1,int col1);
        bool Winner(vector<vector<char>> board);
        void Display(vector<vector<char>> board);
};