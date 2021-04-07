#include "Board.hpp"
#include <iostream>
#include "Direction.hpp"
#include <stdlib.h>
#include <string>
using namespace ariel;
using ariel::Direction;
using ariel::Board;

#include <unistd.h>
#include <array>

const string input = "ERROR";
int main()
{


    ariel::Board board;
    board.post(0,49,Direction::Horizontal,"#");
    board.post(10,49,Direction::Horizontal,"#");
    board.post(0,49,Direction::Horizontal,"_");
    board.post(10,49,Direction::Horizontal,"_");
    for (int i = 0; i < 50; i++)
    {
        board.post(0,i,Direction::Horizontal,"#");
        usleep(25000);
        board.show();
    }
    for (int i = 0; i < 10; i++)
    {
        board.post(i,50,Direction::Vertical,"/");
        usleep(25000);
        board.show();
    }
    for (int i = 49; i >=0 ; i--)
    {
        board.post(9,i,Direction::Horizontal,"#");
        usleep(25000);
        board.show();
    }
    for (int i = 9; i >= 0; i--)
    {
        board.post(i,0,Direction::Vertical,"/");
        usleep(25000);
        board.show();
    }
    string hello = "Welcome to my board Enjoy the show!                              ";
    string p = "";
    for (int i = 0; i <= 50; i++)
    {
        p = hello[i];
        board.post(10,i,Direction::Vertical,p);
        usleep(25000);
        board.show();
    }
    string c17 =  "CCCCCCC";
    string c26 = "CC      CC";
    string c36 = "CC      CC";
    string c46 = "CC        ";
    string c56 = "CC      CC";
    string c66 = "CC      CC";
    string c77 =  "CCCCCCC";

    string p120 = "PPPPPPPP";

    vector<string> line1 = {c17,p120};

    board.post(1,7,Direction::Horizontal,line1[0]);
    board.post(1,20,Direction::Horizontal,line1[1]);

    board.show();
        usleep(75000);
    board.post(2,6,Direction::Horizontal,c26);
        board.show();
        usleep(75000);
    board.post(3,6,Direction::Horizontal,c36);
        board.show();
        usleep(75000);
    board.post(4,6,Direction::Horizontal,c46);
        board.show();
        usleep(75000);
    board.post(5,6,Direction::Horizontal,c56);
        board.show();
        usleep(75000);
    board.post(6,6,Direction::Horizontal,c66);
        board.show();
        usleep(75000);
    board.post(7,7,Direction::Horizontal,c77);
        board.show();

    



    return 0;
}
