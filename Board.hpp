#ifndef  _BOARD
#define _BOARD
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;
#include "Direction.hpp"
using ariel::Direction;


const int DEFAULT_SIZE = 10;
namespace ariel {

    class Board
    {
    private:
        // 4 Integers for a reasonable show -> so we will not print unneeded lines.
        unsigned int _MinR = UINT32_MAX;
        unsigned int _MinC = UINT32_MAX;
        unsigned int _MaxR = 0;
        unsigned int _MaxC = 0;
        vector<vector<char>> board;
    public:
        void setMinR(unsigned );
        void setMinC(unsigned );
        void setMaxR(unsigned );
        void setMaxC(unsigned );
        Board(){
            board = vector<vector<char>>(DEFAULT_SIZE,vector<char>(DEFAULT_SIZE,'_'));
        }
        void post(unsigned int row, unsigned int column, Direction,const string &input);
        std::string read(unsigned  int row, unsigned int column, Direction, unsigned int length);
        void show();

        void reSize(uint rows, uint columns);
    };
}
#endif // ! _BOARD