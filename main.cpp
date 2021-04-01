#include "Board.hpp"
#include <iostream>
#include "Direction.hpp"
#include <stdlib.h>
#include <string>
using namespace ariel;
using ariel::Direction;
using ariel::Board;

const string input = "ERROR";
int main()
{
    int n = 30;
    uint j;

    ariel::Board board;
    srand(clock());
    for (unsigned int i = 15; i < n; i++)
    {   
        j = rand()%n;
        board.post(i, j, Direction::Horizontal, input);
        j+=2;

    }
        for (unsigned int i = 15; i < n; i++)
    {   
        j = rand()%n;
        board.post(i, j, Direction::Vertical, "PERROR");
        j+=2;

    }

    // for (unsigned int i = 15; i < 30; i++)
    // {
    // for (unsigned int j = 15; j < 30; j++)
    //     {
    //         cout << board.read(i,j,ariel::Direction::Horizontal,3) << endl;
    //     }
    // }
    board.show();

    return 0;
}
// #include "Board.hpp"
// using namespace ariel;

// int main() {

//     Board b;
//     b.post(0,0, Direction::Horizontal, "Hello");
//     return 0;
// }