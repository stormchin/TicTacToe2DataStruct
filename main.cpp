/* ************************************ */
//   Storm Chin   (Feb 10th 2020)        //
//   Dr.Ung Data Struct and Algorithims //
//         1-1:50pm Spring MWF          //
/* ************************************ */

//Tic Tac Toe Asg 2
#include <iostream>
#include "Player.h"
#include "Board.h"
#include <string>
#include <limits>
#include <iomanip>

using namespace std;


//function used for testing cases code
// void hello(int pos) {
//     cout << "HELLO " << pos << endl;
// }


/*       ************************************           */
//  Prompts the user to enter the number of players     //
//    validates the input (must be integer 2-5)         //
//      if input is valid will return 2-5               //
//      if input is invalid will return 0               //
/*      ************************************            */

int amountOfPlayersPrompt();



/*              ************************************            */
//          Loops the prompt that asks how many players         //
//      there will be if the input is not what is expected.     //
//              returns the player count (int)                  //
/*             ************************************            */

int returnPlayerCount();




/*              ************************************            */
//          Asks the user the first and last name of Players    //
//      Saves this information in the player array               //
/*             ************************************            */
void getPlayerInfo(int, Player*);


/*                ************************************                   */
//                                                                      //
//  capitalizes first character in a string if it is a lowercase letter //
//         will not work if a non letter is input                       //
/*             ************************************                     */

string capitalizeFirstChar(string);






/*              ************************************                 */
//  Prompts the user to enter the dimensions of Tic Tac Toe Board   //
//                          Validates the input                     //
//              Returns the dimensions in an integer array          //
//         First is element is the row the second is the column     //
/*              ************************************                */

int* getBoardDimensions();


/******************************************************************/
//           Prompts the user to enter their move                 //      //             Validates the input                                //
//    Returns the a valid move and the player who took the turn   //
//         First is element is the move the second is the         //
//                          player position in array              //
/******************************************************************/ 

int* getMove(Player*, int, Board, int);

/**************************************************************/
// Assigns the next player in the sequence if no win or draw. //
/**************************************************************/
void nextPlayer(Player*, int );

/**************************************************************/
// Updates stats based on the fact there was a win            //
/**************************************************************/
void updateStatsWin(Player* , int );

/**************************************************************/
// Updates stats based on the fact there was a draw           //
/**************************************************************/
void updateStatsDraw(Player* , int );

/**************************************************************/
// Prints statistics for all players in the proper format     //
/**************************************************************/
void printStats(Player* ,int ,int);


/**************************************************************/
// Assigns the next player based on if there was a draw       //
/**************************************************************/
void nextPlayerDraw (Player*, int);

/**************************************************************/
// Assigns the next player based on if there was a win.      //
/**************************************************************/
void nextPlayerDraw (Player*, int);

/**************************************************************/
// Updates player start variable based on win                 //
/**************************************************************/
void updateStartBcWin (Player* players, int numOfPlayer);



int main()
{
  //Variabe to hold total moves
  int totalMoves = 0;
  //Varibale to hold move and player whos moving.
  int* moveAndPlayer = new int[2];

  //Variable to hold the number of players playing the game.
  int  numOfPlayers;
  numOfPlayers = returnPlayerCount();

  //Create an array of that many players
  Player* players;
  players = new Player[numOfPlayers];

  //Sets the first tur]n to player with piece a.
  players[0].turn = 1;
  players[0].start = 1;

  // Asks user how the first and last name of players based of how many people playing.
  getPlayerInfo(numOfPlayers, players);

  //Asks the user to enter dimensions and saves the output in an array. (rows x columns)
  int* dimensions = new int[2];
  
  dimensions = getBoardDimensions();
  int row = dimensions[0];
  int column = dimensions[1];
  //Creates Board based on Dimensions;
  Board b1(row,column);
  
  int games = 0;
  //Plays the Game
  while (true) 
  {
    //Prints the Board
    if (totalMoves == 0)
    {
      b1.printBoard();
    }
    
    //Gets Move from Player
    moveAndPlayer = getMove(players,numOfPlayers,b1,totalMoves);
    
    
    //Changes board based on Move
    b1.changeSpots(moveAndPlayer[0], moveAndPlayer[1], players);


    //Adds to the total moves
    totalMoves++;
    
    
    //Prints Board After Move
    b1.printBoard();

    
    if (b1.checkWin()) 
    {
      cout << endl;
      cout << endl;
      b1.printBoard();
      games++;
      updateStatsWin(players,  numOfPlayers);
      printStats(players, numOfPlayers,games);
      if(b1.anotherGame())
      {
        b1.reset();
        updateStartBcWin(players, numOfPlayers);
        totalMoves = 0;
        nextPlayer(players, numOfPlayers);
        continue;
      }
      else
      {
        return 0;
      }
      return 0;
    }
    else if(b1.checkDraw(totalMoves))
    {
      cout << endl;
      cout << endl;
      b1.printBoard();
      games++;
      updateStatsDraw(players, numOfPlayers);
      printStats(players, numOfPlayers,games);

      if(b1.anotherGame())
      {
        b1.reset();
        totalMoves = 0;
        nextPlayerDraw(players, numOfPlayers);
        continue;
      }
      else
      {
        return 0;
      }
      
    }
    else
    {
      nextPlayer(players, numOfPlayers);
    }
      
      
  }


    

    return 0;
}




string capitalizeFirstChar(string name)
{
    char firstChar = name.at(0);
    string newName = "";

    if (firstChar >= 97)
    {
        firstChar = firstChar - 32;
        newName = newName + firstChar;
        for (auto i : name)
        {
            if (i == name.at(0)) {
                continue;
            }
            else {
                newName = newName + i;

            }
        }
        return newName;
    }
    else
    {
        return name;
    }
}

int amountOfPlayersPrompt()
{
    int numOfPlayers;
    cout << "How many players are going to play?  Enter a number (2-5):" << endl;
    cin >> numOfPlayers;
    
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter something valid please. A number 2-5." << endl;
        
        return 0;
    }
    else
    {
      cout << endl;
      if ((numOfPlayers == 2) || (numOfPlayers == 3) || (numOfPlayers == 4) || (numOfPlayers == 5))
      {
          
          return numOfPlayers;
      }
      else
      {
          cout << "Enter something valid please. A number 1-5." << endl;
         
          return 0;
      }
  }
}

int returnPlayerCount() {
    int  numOfPlayers = 0;
    while (numOfPlayers == 0)
    {
        numOfPlayers = amountOfPlayersPrompt();
    }
    return numOfPlayers;
}

void getPlayerInfo(int numOfPlayers, Player* players)
{
    for (int i = 0; i < numOfPlayers; i++)
    {
        //Variable to hold full, first, and last name of each Player
        string playerName = "";
        string firstName = "";
        string lastName = "";
        //Bool for error
        bool error = false;
        cout << "Enter the full name separated by a space for player " << i + 1 << ": "<<endl;
        cin >> firstName >> lastName;
        playerName = firstName + " " + lastName;
        //Validation of first name. No special charcters
        for (auto x : firstName)
        {
            if (!(isalpha(x)))
            {
                cout << "Enter a valid name with just letters (No special Characters or Numbers)." << endl;
                i--;
                error = true;
                break;
            }
        }
        //Validation of second name. No special characters
        int spaceCount;
        for (auto x : lastName)
        {
          if (!(isalpha(x)))
          {
              cout << "Enter a valid name with just letters (No special Characters or Numbers)." << endl;
              i--;
              error = true;
              break;
          }
        }
        //if Special characters then restart loop
        if (error)
        {
            continue;
        }
        else
        {
            //Capitalize First and Last Name
            firstName = capitalizeFirstChar(firstName);
            lastName = capitalizeFirstChar(lastName);
            playerName = firstName + " " + lastName;
            (players + i)->fullName = playerName;
            (players + i)->first = firstName;
            (players + i)->last = lastName;

            //sets the players piece a-e
            (players + i)->piece = 97 + i;
            cout << endl;


        }



    }
}

int* getBoardDimensions()
{
    int* dimensions = new int[2];
    cout << "Enter the board dimensions." << endl;
    int rows, columns;

    while (true)
    {
        cout << endl;
        cout << "Enter the rows of the board (3-11) ---->  ";
        cin >> rows;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a number." << endl;
            continue;
        }
        else
        {
            if (rows < 3 || rows > 11)
            {
                cout << "Enter an amount of rows between 3 and 11." << endl;
                continue;
            }
            else {
                break;
            }
        }
    }

    while (true)
    {
        cout << endl;
        cout << "Enter the columns of the board (3-16) ---->  ";
        cin >> columns;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a number." << endl;
            continue;
        }
        else
        {
            if (columns < 3 || columns > 16)
            {
                cout << "Enter an amount of rows between 3 and 16." << endl;
                continue;
            }
            else {
                break;
            }
        }
    }
    dimensions[0] = rows;
    dimensions[1] = columns;
    return dimensions;

};

int* getMove(Player* players, int numOfPlayer, Board b1, int totalMoves)
{

    //Holds the position of the player playing in the array  of players
    int positionOfPlayer;
    // Holds the input of the player move.
    string playerMove;
    //temporary holds the new player move after the first letter has been made lowercase
    string newPlayerMove;
    // Holds the integer value of digits entered after the letter
    int rawNum;
    //Holds the string version of the digits enterd after the letter
    string num = "";

    int* moveAndPlayer = new int [2];



    
    for (int i = 0; i < numOfPlayer; i++)
    {
        if (players[i].turn == 1)
        {
            positionOfPlayer = i;
        }

    }
    
    cout << players[positionOfPlayer].first << " it is your turn." << endl;
    while (true) {
        num = "";
        newPlayerMove = "";

        cout << "Choose where you would like to play. (Ex: a1 or A1) ----->  " << endl;
      
        cin >> playerMove;
        // Checks to see if move is less than 3 in length
        if (!(playerMove.length() <= 3 && playerMove.length() > 1))
        {
            //hello(1);
            cout << "Please enter a valid move." << endl;
            continue;
        }

        //Checks to see if the first character in the string is a letter.
        if ((playerMove.at(0) >= 65 && playerMove.at(0) <= 90) || (playerMove.at(0) >= 97 && playerMove.at(0) <= 122))
        {
            
            //if move first letter is capital make it lowercase.
            if ((playerMove.at(0) >= 65 && playerMove.at(0) <= 90))
            {
                newPlayerMove = char(playerMove.at(0) + 32);

                for (auto x : playerMove)
                {
                    if(playerMove.at(0) != x)
                    {
                        newPlayerMove = newPlayerMove + x;
                    }
                    
                }
                playerMove = newPlayerMove;
                
            }


        }
        else
        {
            //hello(2);
            cout << "Please enter a valid move." << endl;
            continue;
        }

       






        //Checks to see if this is valid first letter based on the board drawn
        if ((playerMove.at(0) >= 97 && playerMove.at(0) <= 97 + b1.row))
        {
            //check to see if the followin characters are numbers
            if (playerMove.length() == 3)
            {
                if ((playerMove.at(1) >= 49 && playerMove.at(1) <= 57) && (playerMove.at(2) >= 48 && playerMove.at(2) <= 57))
                {

                }
                else
                {
                    //hello(4);
                    cout << "Please enter something valid." << endl;
                    continue;
                }

            }
            //checks to see if the following characters are numbers
            else if (playerMove.length() == 2)
            {
                if ((playerMove.at(1) >= 49 && playerMove.at(1) <= 57))
                {

                }
                else
                {
                    //hello(5);
                    cout << "Please enter something valid." << endl;
                    continue;
                }
            }

        }
        else
        {
            //hello(6);
            cout << "Please enter something valid. You did not enter a valid letter." << endl;
            continue;

        }
 
        // At this point in input validation. The first character is a lowercase letter. 
        // The player move is length two or three. 
        // The first letter is apropriate for the baord drawn.
        // The following characters are numbers.
        // This move has not been played before.

        //We now have to check if the numbers following the letter are valid based on the board drawn.

        if (playerMove.length() == 3)
        {

            
            num = num + playerMove.at(1);
            num = num + playerMove.at(2);

        }
        else
        {
        
            num = num + playerMove.at(1);

        }
 
        //Raw Num holds the integer value of whatever number the user entered after the letter.
        rawNum = stoi(num);

        //Check to see if the number is valid based on the board drawn.
        if (rawNum > b1.column)
        {
            //hello(7);
            cout << "Please enter something valid." << endl;
            continue;
        }
        

        
        


       


        // converts letter to row
        int actualMoveRow = playerMove.at(0) - 97;
        // holds the column of the move
        int actualMoveColumn = rawNum;
        if (actualMoveRow == 0)
        {

            moveAndPlayer[0] = actualMoveColumn - 1;

        }
        else
        {
            moveAndPlayer[0] = actualMoveRow * b1.column + actualMoveColumn - 1;
        }
        
        moveAndPlayer[1] = positionOfPlayer;
        
        // Check to see if the move has been played before.
        bool badMove = false;
        for (int i = 0; i < b1.row * b1.column; i++)
        {
            if (b1.playedSpots[i] == moveAndPlayer[0])
            {
                //hello(3);
                cout << "Please enter move where someone hasn't played." << endl;
                badMove = true;
                break;
            }
        }
        if (badMove) 
        {
            continue;
        }
        
        //This move is now valid
        break;
        

    }
    //This move is now valid
        // Then add it to moves played
    b1.playedSpots[totalMoves] = moveAndPlayer[0];
    
    return moveAndPlayer;
}


void printStats(Player* players,int playerCount ,int numOfGames)
{
  int longestName = 0;
  for(int i=0; i<playerCount; i++)
  {
    if( longestName <= players[i].fullName.length() )
    {
      longestName = players[i].fullName.length();
    }
  }
  cout << "Total Games Played = " << numOfGames << endl;

  cout << right << setw(longestName+2);
  cout <<" ";
  cout << "______ ______ ______" <<endl;
  cout << right <<setw(longestName+1);
  cout << " ";
  cout << "|  WIN | LOSS | DRAW |" <<endl;
  cout << right << setw(longestName+2);
  cout<<" ";
  cout << "______ ______ ______" <<endl;

  for (int i = 0; i < playerCount; i++)
  {
    cout << right << setw(longestName) ;
    cout << players[i].fullName <<" |    "<< players[i].wins 
    <<" |    " 
    << players[i].losses 
    <<" |    "<<players[i].draws 
    <<" |" << endl;
    cout << right << setw(longestName+2);
    cout << " ";
    cout << "______ ______ ______" <<endl;
  }

}

void nextPlayer(Player* players, int numOfPlayers)
{
  for(int i = 0; i < numOfPlayers; i++)
  {
    if(!(i == numOfPlayers-1)){
      if(players[i].turn == 1)
      {
        players[i].turn = 0;
        players[i+1].turn = 1;
        break;
      }
    }
    else
    {
      players[i].turn = 0;
      players[0].turn = 1;
      break;
    }
  }

}

void updateStatsWin(Player* players, int numOfPlayers)
{
  
  for(int i = 0; i < numOfPlayers; i++)
  {
    if(players[i].turn == 1)
    {
      players[i].wins += 1;
      
    }
    else
    {
      players[i].losses += 1;
    }
  }
  
}

void updateStatsDraw(Player* players, int numOfPlayers)
{
  for(int i = 0; i < numOfPlayers; i++)
  {
    
    players[i].draws += 1;
    
  }
}

void nextPlayerDraw (Player* players, int numOfPlayer)
{
  int position;
  //Finding Who started last round
  for(int i=0;i<numOfPlayer;i++)
  {
    if(players[i].start == 1)
    {
      position = i;
    }
  }
  //If last player in ary make first person start next
  if(position == numOfPlayer-1)
  {
    players[position].start = 0;
    players[0].start = 1;
  }
  else
  {
    players[position].start = 0;
    players[position+1].start = 1;

  }
  for(int i=0;i<numOfPlayer;i++)
  {
    if(players[i].start == 1)
    {
      players[i].turn = 1;
    }
    else
    {
      players[i].turn = 0;
    }
  }

}

void updateStartBcWin (Player* players, int numOfPlayer)
{
  int position;
  //Finding Who started last round
  for(int i=0;i<numOfPlayer;i++)
  {
    if(players[i].start == 1)
    {
      position = i;
    }
  }
  //If last player in ary make first person start next
  if(position == numOfPlayer-1)
  {
    players[position].start = 0;
    players[0].start = 1;
  }
  else
  {
    players[position].start = 0;
    players[position+1].start = 1;

  }
}
