#ifndef  _BOARD
#define _BOARD

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;
#include "Direction.hpp"
using ariel::Direction;


const int DEFAULT_SIZE = 10000;
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
        void setMinR(unsigned );
        void setMinC(unsigned );
        void setMaxR(unsigned );
        void setMaxC(unsigned );
    public:    
        Board(){
            _MinR = UINT32_MAX;
            _MinC = UINT32_MAX;
            _MaxR = 0;
            _MaxC = 0;
            board = vector<vector<char>>(DEFAULT_SIZE , vector<char> (DEFAULT_SIZE, '_'));
        }
        void post(unsigned int row, unsigned int column, Direction,const string &input);
        std::string read(unsigned  int row, unsigned int column, Direction, unsigned int length);
        void show();
        void reSize(uint rows, uint columns);
        ~Board(){
            cout << "Delete" << endl;
        }
    };
}
#endif // ! _BOARD