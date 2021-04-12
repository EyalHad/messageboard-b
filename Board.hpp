#ifndef  _BOARD
#define _BOARD

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;
#include "Direction.hpp"
using ariel::Direction;


const int START_SIZE = 1;
namespace ariel {

    class Board
    {
    private:
        // 4 Integers for a reasonable show -> so we will not print unneeded lines.
        unsigned int _MinR;
        unsigned int _MinC;
        unsigned int _MaxR;
        unsigned int _MaxC;
        vector<vector<char>> board;
    public:    
        Board(){
            _MinR = _MinC = UINT32_MAX;
            _MaxR = _MaxC = 0;
            board = vector<vector<char>>(START_SIZE , vector<char> (START_SIZE, '_'));
        }
        void post(unsigned int row, unsigned int column, Direction,const string &input);
        std::string read(unsigned  int row, unsigned int column, Direction, unsigned int length);
        void show();
        ~Board(){ cout << "Delete" << endl;}
        void reSize();
        int checkValid(unsigned int row, unsigned int column, const string &input) const;
        void setMinMax(unsigned int row,unsigned int column, unsigned int length, Direction way);
    };
}
#endif // ! _BOARD