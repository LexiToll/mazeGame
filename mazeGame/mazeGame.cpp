/***********************************************
* mazeGame.cpp
* Lexi Toll
*
* This program emulates a mouse running through
* a maze
***********************************************/

#include "mazeGame.h"

//This changes most of the arrays characters to special ascii characters

MazeGame::MazeGame(char maze[MAZE_ROWS][MAZE_COLS + 1], int startRow, int startCol)
{
  this->startRow = startRow; 
  this->startCol = startCol;

  for (int i=0; i<MAZE_ROWS; i++)
  {
    for (int j=0; j<MAZE_COLS; j++)
    {
      if (maze[i][j] == 'X')
      {
        maze[i][j] = 219;
      }
      if (maze[i][j] == '|')
      {
        maze[i][j] = 186;
      }
      if (maze[i][j] == '-')
      {
        maze[i][j] = 205;
      }
      if (i == 0 && j == 0 )
      {
        maze[i][j] = 201;
      }
      if (i == MAZE_ROWS-1 && j == 0)
      {
        maze[i][j] = 200;
      }
      if (i == 0 && j == MAZE_COLS-1)
      {
        maze[i][j] = 187;
      }
      if (i == MAZE_ROWS-1 && j == MAZE_COLS-1)
      {
        maze[i][j] = 188;
      }

      this->maze[i][j] = maze[i][j];
    } // end for Columns
  } // end for Rows
} // end MazeGame 

//***************************************************************

// This member function plays the game

void MazeGame::play()
{
  for (int i=0; i<MAZE_ROWS; i++)
  {
    for (int j=0; j<MAZE_COLS; j++)
    {
      cout << maze[i][j];
    } // end for
  cout << '\n';
  } // end for

  search(startRow, startCol);
  gotoRowCol(MAZE_ROWS, 1);
  cout << "The mouse has failed to finish the maze. :(\n";
  exit(0);
} // end play

//***************************************************************

// This member function causes the cursor to jump to the given row and
// column coordinate positions within the console window.

void MazeGame::gotoRowCol(int row, int col) const
{
  COORD pos;
  pos.X = col;
  pos.Y = row;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
} // end gotoRowCol

//***************************************************************

//This will clear out previous mice and replace paths with hidden walls

void MazeGame::clearMouse(int row, int col)
{
  char clear = ' '; 

  if (maze[row][col] != 'S' )
  {
    maze[row][col] = 'X';
    gotoRowCol(row, col);
    cout << clear;
  } // end if
} // end clearMouse

//***************************************************************

//This will check for the win condition

void MazeGame::checkForWin(int row, int col) const
{
  if (maze[row][col] == 'F')
  {
    gotoRowCol(MAZE_ROWS, 1);
    cout << "The mouse has survived the maze!!!\n";
    exit(0);
  }
} // checkForWin

//***************************************************************

//this will search North, East, West, and South for a clear path
//and then use recursion to backtrack if it's a dead end

void MazeGame::search(int r, int c)
{
  const char MOUSE = 153;  // sets the mouse to a fancy O

  gotoRowCol(r, c);
  maze[r][c] = MOUSE;
  checkForWin(r, (c-1));

  if (maze[r][c-1] == ' ')
  {
    Sleep(100);
    gotoRowCol(r, c-1);
    cout << MOUSE;
    clearMouse(r, c);
    search(r, c-1);
    Sleep(100);
    gotoRowCol(r, c);
    cout << MOUSE;
    clearMouse(r, c-1);
  } // end if

  checkForWin((r-1), c);

  if (maze[r-1][c] == ' ')
  {
    Sleep(100);
    gotoRowCol(r-1, c);
    cout << MOUSE;
    clearMouse(r, c);
    search(r-1, c);
    Sleep(100);
    gotoRowCol(r, c);
    cout << MOUSE;
    clearMouse(r-1, c);
  } // end if

  checkForWin(r, (c+1));

  if (maze[r][c+1] == ' ')
  {
    Sleep(100);
    gotoRowCol(r, c+1);
    cout << MOUSE;
    clearMouse(r, c);
    search(r, c+1);
    Sleep(100);
    gotoRowCol(r, c);
    cout << MOUSE;
    clearMouse(r, c+1);
  } // end if

  checkForWin((r+1), c);

  if (maze[r+1][c] == ' ')
  {
    Sleep(100);
    gotoRowCol(r+1, c);
    cout << MOUSE;
    clearMouse(r, c);
    search(r+1, c);
    Sleep(100);
    gotoRowCol(r, c);
    cout << MOUSE;
    clearMouse(r+1, c);
  } // end if
} // end search



