/* ************************************ */
//   Storm Chin   (Feb 10th 2020)        //
//   Dr.Ung Data Struct and Algorithims //
//         1-1:50pm Spring MWF          //
/* ************************************ */

#include <iostream>
#include "Board.h"
using namespace std;

#ifndef UNTITLED_PLAYER_H
class Player {
public:

    //String Variable for Player to keep track of Name and piece choose
    string fullName;
    string first = "";
    string last = "";
    //Char to keep track of who is x and who is o.
    char piece = ' ';
    //int to keep track of who is going first
    int turn = 0;

    //Integer Variables for Player to access their wins and losses
    int  wins = 0;
    int losses = 0;
    int draws = 0;
    int start = 0;



};


#define UNTITLED_PLAYER_H

#endif //UNTITLED_PLAYER_H
