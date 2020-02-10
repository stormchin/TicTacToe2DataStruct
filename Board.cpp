/* ************************************ */
//   Storm Chin   (Feb 2nd 2020)        //
//   Dr.Ung Data Struct and Algorithims //
//         1-1:50pm Spring MWF          //
/* ************************************ */
#include <iostream>
#include<string>
#include "Board.h"
#include <limits>
using namespace std;



/*      ************************************         */
//      Constructor                                  //
//      Intializes the board based off how many rows //
//      and columns there needs to be.               //
/*      ************************************         */


Board::Board(int rows, int columns)
{
    row = rows;
    column = columns;

    spots = new char[row * column];

    spots2 = new char* [row];

    playedSpots = new int [row*column];

    for (int i = 0; i < row * column; i++)
    {
        spots[i] = ' ';
    }

    for (int i = 0; i < row * column; i++)
    {
        playedSpots[i] = -1;
    }
    
    for (int i = 0; i < row; i++)
    {
        spots2[i] = new char [column];
    }
    
    for (int i = 0; i < row ; i++)
    {
        for (int j = 0; j <  column; j++)
      {
        spots2[i][j]= ' ';
      }
    }

  
}

/*      ************************************         */
//                                                  //
//      prints the tic tac toe board to the screen  //
//                                                  //
/*      ************************************         */
void Board::printBoard()
{
    cout << endl;
    cout << "     ";
    for (int i = 0; i <column; i++) 
    {

        if (i > 8)
        {
            cout <<char(49) <<char(49 + i-10) << "  ";
        }
        else 
        {
            cout << char(49 + i) << "   ";

        }
        
    }

    cout << endl;

    cout << "    ";
    for (int j = 0; j < column; j++)
    {
        cout << "--- ";



    }
    cout << endl;

    
    for (int i = 0; i < row; i++)
    {
        cout << " "<<char(65+i) <<" ";


        for (int j = 0; j < column; j++)
        {
            cout << "| "<<spots[i*column + j ] << " ";



        }

        cout <<"| "<<char(65+i) <<endl;

        cout << "    ";
        for (int j = 0; j < column; j++)
        {
            cout << "--- ";



        }
        cout << endl;

    }










    cout << "     ";
    for (int i = 0; i < column; i++)
    {

        if (i > 8)
        {
            cout << char(49) << char(49 + i - 10) << "  ";
        }
        else
        {
            cout << char(49 + i) << "   ";

        }

    }

    cout << endl;


 
}











char Board::winningUpper(char lowercase)
{

    char uppercase = lowercase - 32;
    return uppercase;

}


void Board::changeSpots(int spot, int position, Player* players)
{

    int spotss = spot;
    spots[spotss] = players[position].piece;

    if(spot < column)
    {
        spots2[0][spotss] = players[position].piece;
        
    }
    else
    {
      int columnz = spot%column;
      int rowz = (spot - columnz)/column;
      
      spots2[rowz][columnz] = players[position].piece;
      
    }
}





bool Board::anotherGame()
{
    // Variable to keep track of if they want to play again.
    char yesOrNo;
    


    while (true)
    {
      cout << "Would you like to play again? Enter y/n: " << endl;
      cin >> yesOrNo;
      if (cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter something valid please." << endl;
        continue;
        
      }
      else
      {
         if (yesOrNo == 'y' || yesOrNo == 'n')
        {
          return yesOrNo == 'y';
        }
        else
        {
          cout << "Enter something valid please." << endl;
          continue;
        }
      }
    }
    
    
}


void Board::printSpots() {

    for (int i = 0; i < row * column; i++) {


        cout << spots[i] << endl;
    
    }

}

void Board :: printPlayedSpots()
{
  for (int i = 0; i < row*column; i++)
  {
    cout << playedSpots[i] << endl;
  }
  cout << "done" << endl;
}


bool Board::checkWin()
{
  
  //Horizontal Win
    for (int i = 0; i < row ; i++)
    {
        for (int j = 2; j <  column; j++)
      {
        
        if( (spots2[i][j] != ' ' && spots2[i][j-1] == spots2[i][j-2] && spots2[i][j-1] == spots2[i][j]))
        {
          spots[i* column + (j-1)] -= 32;
          spots[i* column + (j-2)] -= 32;
          spots[i* column + j] -= 32;
            return true;
        }

      }
    }

    //Vertical Win
    for (int i = 2; i < row ; i++)
    {
        for (int j = 0; j <  column; j++)
      {
        
        if( spots2[i][j] != ' ' && spots2[i-1][j] == spots2[i-2][j] && spots2[i-1][j] == spots2[i][j]    )
        {
          spots[(i-1)*column +j] -= 32;
          spots[(i-2)* column +j] -= 32;
          spots[i*column +j] -= 32;
            return true;
        }

      }
    }

    //Diagonal win to the right corner
    for (int i = 2; i < row ; i++)
    {
        for (int j = 0; j <  column-2; j++)
      {
       
        if( (spots2[i][j] != ' ' && spots2[i-1][j+1] == spots2[i][j] && spots2[i-2][j+2] == spots2[i][j]))
        {
          
          spots[(i-1)*column + (j+1)] -= 32; 
          spots[i*column + j] -= 32;
          spots[(i-2)*column + (j+2)] -= 32;

            return true;
        }

      }
    }

    //Diagonal win to the left corner
    for (int i = 2; i < row ; i++)
    {
        for (int j = 2; j <  column; j++)
      {
        
        if( (spots2[i][j] != ' ' && spots2[i-1][j-1] == spots2[i-2][j-2] && spots2[i-1][j-1] == spots2[i][j]))
        {
          spots[(i-1)*column +(j-1)] -= 32;
          spots[(i-2)*column + (j-2)] -= 32;
          spots[i*column + j] -= 32;
            return true;
        }

      }
    }
  return false;

}

void Board:: reset()
{
  for (int i = 0; i < row * column; i++)
    {
        spots[i] = ' ';
    }

    for (int i = 0; i < row * column; i++)
    {
        playedSpots[i] = -1;
    }

    for (int i = 0; i < row ; i++)
    {
        for (int j = 0; j <  column; j++)
      {
        spots2[i][j]= ' ';
      }
    }


}

bool Board :: checkDraw(int moves)
{
  return moves == row*column;
}
