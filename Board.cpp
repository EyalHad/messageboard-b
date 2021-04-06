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

    int Board::checkValid(unsigned int row, unsigned int column, const string &input)
    {
        unsigned int len = input.length();
        if(len == 0) {return -1;}
        int count = 0;
        if (row > this->_MaxR || column > this->_MaxC)
        {
            for (ulong i = 0; i < len; i++)
            {
            if(input.at(i) != '_'){ break;}
            count++;
            }

            if(count == len) {return -1;} // Avoid empty string under cover
        }
        return 0;
    }

    void Board::reSize()
    {
        this->board.resize(this->_MaxR);
        for (unsigned int i = 0; i < this->_MaxR; i++)
        {
            this->board.at(i).resize(this->_MaxC,'_');
        }  
    }

    void Board::post(unsigned int row, unsigned int column, Direction way, const string &input)
    {   
        int vaild = checkValid(row,column,input);
        if(vaild < 0) {return;}

        unsigned int len = input.length();

        if(way == ariel::Direction::Horizontal)
        {
                //Minimum 
            if(this->_MinR > row){ setMinR(row); }
            if(this->_MinC > column){ setMinC(column); }
                //Maximums
            if(this->_MaxR < row+1){ setMaxR(row+1); }
            if(this->_MaxC < column+len+1){ setMaxC(column+len+1); }

            Board::reSize();
            
            for (unsigned int i = 0; i < len; i++)
            {
                this->board.at(row).at(column) = input[i];
                column++;     
            }
            
        }else{
                //Minimum 
            if(this->_MinR > row){ setMinR(row); }
            if(this->_MinC > column){ setMinC(column); }
                //Maximums
            if(this->_MaxR < row+len+1){ setMaxR(row+len+1); }
            if(this->_MaxC < column+1){ setMaxC(column+1); }

            Board::reSize();

            for (unsigned int i = 0; i < len; i++)
            {
                this->board.at(row).at(column) = input[i];
                row++;     
            }
        }
    }
    std::string Board::read(unsigned  int row, unsigned int column, Direction way, unsigned int length){

        string output;

        if(way == ariel::Direction::Horizontal)
        {
            while(column < this->_MaxC && length > 0)
            {    
                output += this->board.at(row).at(column);
                column++;
                length--;     
            }

        } else {
            while(row < this->_MaxR && length > 0)
            {    
                output += this->board.at(row).at(column);
                row++;
                length--;     
            }
        }
        // In case of reading more than there is -> will read Empty Posts
        while (length > 0){ output += '_'; length--;}  
        return output;
    }


    void Board::show()
    {
        char p;
        for(unsigned int i = this->_MinR ; i < this->_MaxR; i++){
            cout << i << ":";
            for (unsigned int j = _MinC; j < _MaxC; j++)
            {
                p = board.at(i).at(j);
                cout << p ;
            }
            cout << endl;         
        }
    }

    
}