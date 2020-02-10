/* ************************************ */
//   Storm Chin   (Feb 10th 2020)        //
//   Dr.Ung Data Struct and Algorithims //
//         1-1:50pm Spring MWF          //
/* ************************************ */

#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H

#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

class Board
{
public:

    //Constructor
    /* ************************************ */
    //         Creates board Object         //
    //                                      //
    /* ************************************ */

    Board(int, int);



 /*      ************************************         */
 //                                                  //
 //      prints the tic tac toe board to the screen  //
 //                                                  //
 /*      ************************************         */
    void printBoard();


    /*              ************************************                      */
    //     Function handles conversion from lower to uppercase.               //
    //   char that's lowercase is input and the output is char uppercase      //
    /*              ************************************                      */
    char winningUpper(char);


    /*              ************************************                      */
    //     function prompts the user if he would like to play another Game    //
    //   if the user wants to play again the function returns true            //
    /*              ************************************                      */
    bool anotherGame();

    /***************************************************************************/
    //Checks the game for a win.  returns true if win                          //
    /***************************************************************************/
    bool checkWin();


    /************************************************************/
    // Resets played spots, spots 1D array, and spots2 2d Array //
    /************************************************************/

    void reset();

    /***************************************************************************/
    //Places the playes validated move in the spots array and the spots2 array //
    /***************************************************************************/

    void changeSpots(int, int, Player *);

    /***************************************************************************/
    //Used for testing. Prints the spots in the spots array.                    //
    /***************************************************************************/


    void printSpots();

    /***************************************************************************/
    //Used for testing. Prints the spots in the PLayed Spots array.            //
    /***************************************************************************/
    void printPlayedSpots();


    /*************************************************************************************************/
    //Checks the game for a draw. Takes the total moves as argument. returns true if draw.           //
    /*************************************************************************************************/
    bool checkDraw(int);

    //Variable that changes the positions on the board. These charters are displayed on the tic tac toe board.
    int row;

    int column;

    char* spots;

    char** spots2;

    int* playedSpots;



};



#endif //UNTITLED_BOARD_H
