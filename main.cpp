#include "Board.hpp"
#include <iostream>
#include "Direction.hpp"
#include <stdlib.h>
#include <string>
#include "snowman.hpp"
using namespace ariel;
using ariel::Direction;
using ariel::Board;

#include <unistd.h>
#include <array>

const string input = "ERROR";
int main()
{


    ariel::Board board;
    
    for (size_t i = 0; i < 28; i++)
    {
        board.post(0,i,Direction::Vertical,"########");
        usleep(55000);
        board.show();
    }
    for (size_t i = 0; i < 10; i++)
    {
        board.post(i,0,Direction::Horizontal,"____________________________");
        board.show();
        usleep(55000);
    }
    string line6 = " Hello EveryOne   ";
    string line7 = " This is My Board ";
    while(1){
        for(int k = 1; k < 22; k+=10){
            usleep(10000);
            srand(clock());
            array<int,4> arr = {1,2,3,4};  
            int value = 0;
            
            for (int i = 0; i < 8; i++)
            {
                int digit = rand()%4;
                int n = arr[digit];

                value += n;
                if(i != 7)
                value*=10;
            }
            string sm = ariel::snowman(value);
            string app = "";
            int line = 1;
            for (size_t s = 0; s < sm.length(); s++)
            {
                char p = sm.at(s);
                if(p == '\n'){
                    board.post(line,k,Direction::Horizontal,app);
                    line++;
                    app = "";
                    s++;
                    p = sm.at(s);
                }
                app += p;
                if(s == sm.length()-1){
                    board.post(line,k,Direction::Horizontal,app);
                }
            }
            
            // cout << ariel::snowman(value) << endl;
            // board.post(1,k,Direction::Horizontal,ariel::snowman(value));
            usleep(750000);
            board.show();
        }
        for (size_t i = 0; i < 10; i++)
        {
            board.post(i,0,Direction::Horizontal,"____________________________");
            board.post(6,6,Direction::Horizontal,line6);
            board.post(7,6,Direction::Horizontal,line7);
            board.show();
            usleep(75000);
        }
        

    }
    



    return 0;
}
