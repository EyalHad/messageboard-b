
#include <string>
#include <array>
using namespace std;

enum {ONE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN};
enum {H = 0, N, L, R, X, Y, T, B} ;

const array<string,5> Hat = {"", "     \n _===_", "  ___ \n .....", "   _  \n  /_\\ ","  ___ \n (_*_)"};

const array<string,5> Left = {"", "(.", "(o", "(O", "(-"};

const array<string,5> Nose = {"", ",", ".", "_", " "};

const array<string,5> Right = {"", ".)", "o)", "O)", "-)"};

const array<string,5> XUp = {"", " ", "\\", " ", " "};

const array<string,5> XDown = {"", "<", " ", "/", " "};

const array<string,5> YUp = {"", " ", "/", " ", " "};

const array<string,5> YDown = {"", ">", " ", "\\", " "};

const array<string,5> Torso = {"", "( : )", "(] [)", "(> <)", "(   )"};

const array<string,5> Base = {"", "( : )", "(\" \")", "(___)", "(   )"};

namespace ariel
{
  string snowman(int number); 

};
/*

Example for a simple Snowman

             HHHHH
  _===_      HHHHH
  (.,.)     X(LNR)Y
  ( : )     X(TTT)Y
  ( : )      (BBB)

HERE IS A STORAGE:

H, represent = hat 
X, represent = left arm
L, represent = left eye
N, represent = nose
R, represent = right eye
Y, represent = right arm
T, represent = torso 
B, represent = base

For more details:
https://codegolf.stackexchange.com/q/49671/12019

The building procedure will be LINE by LINE
 
LINE\n      First 2 lines will be H only
LINE\n      Two with First
LINE\n      Third line is a bit complex, right\left arms will appear if it upwards " " else
LINE\n      Forth line same as third just downwards for right\left arms.
LINE\n      Fifth line will be B only

*/   

