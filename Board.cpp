#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;
#include "Direction.hpp"
#include "Board.hpp"
using ariel::Direction;


namespace ariel {
    void Board::setMinR(unsigned int newR){ _MinR = newR;}
    void Board::setMinC(unsigned int newC){ _MinC = newC;}
    void Board::setMaxR(unsigned int newR){ _MaxR = newR;}
    void Board::setMaxC(unsigned int newC){ _MaxC = newC;}

    void Board::reSize(uint rows,uint columns)
    {
        this->board.resize(rows);
        for (unsigned int i = 0; i < rows; i++)
        {
            this->board[i].resize(columns,'_');
        }
        
    }

    void Board::post(unsigned int row, unsigned int column, Direction way, const string &input)
    {
        //Minimum 
        if(this->_MinR > row){ _MinR = row ;}
        if(this->_MinC > column){ _MinC = column ;}
        //Maximums
        if(this->_MaxR < row){ _MaxR = row ;}
        if(this->_MaxC < column){ _MaxC = column ;}

        unsigned int len = input.length();
        unsigned int hor = column; // in case we post Horizontal
        unsigned int ver = row;    // in case we post Vertical
        if(way == ariel::Direction::Horizontal)
        {
            reSize(this->_MaxR,this->_MaxC + len + 1);
            for (unsigned int i = 0; i < len; i++)
            {
                this->board.at(row).at(hor) = input[i];
                hor++;     
            }
            
        }else{
            reSize(this->_MaxR + len + 1,this->_MaxC ); 
            for (unsigned int i = 0; i < len; i++)
            {
                this->board.at(ver).at(column) = input[i];
                ver++;     
            }
        }


    }
    std::string Board::read(unsigned  int row, unsigned int column, Direction way, unsigned int length){

        string output;
        unsigned len = length;
        unsigned int hor = column; // in case we post Horizontal
        unsigned int ver = row;    // in case we post Vertical
        if(way == ariel::Direction::Horizontal)
        {
            reSize(this->_MaxR,this->_MaxC + len + 1);
            for (unsigned int i = 0; i < len; i++)
            {
                output += this->board.at(row).at(hor);
                hor++;     
            }
            
        }else{
            reSize(this->_MaxR + len + 1,this->_MaxC ); 
            for (unsigned int i = 0; i < len; i++)
            {
                output += this->board.at(ver).at(column);
                ver++;     
            }
        }
        return output;
    }


    void Board::show(){

        for(unsigned int i = this->_MinR ; i < this->_MaxR; i++){
            cout << i << ":";
            for (unsigned int j = _MinC; j < _MaxC; j++)
            {
                char p = board.at(i).at(j);
                cout << p ;
            }
            cout << endl;         
        }

    }

    
}