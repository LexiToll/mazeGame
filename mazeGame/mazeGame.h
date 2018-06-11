/***********************************************
* mazeGame.h
* Lexi Toll
*
* This program emulates a mouse running through
* a maze
***********************************************/

#pragma once
#include<iostream>
#include<stdio.h>
#include<windows.h>

using namespace std;

const int MAZE_ROWS = 20;
const int MAZE_COLS = 30;

class MazeGame
{
public:

  // sets the maze game & changes characters to fancy ones
  MazeGame(char maze[MAZE_ROWS][MAZE_COLS + 1], int startRow, int startCol);
  void gotoRowCol(int row, int col) const;  // sets the cursor's position 
  void play();                              // play's the MazeGame
  void search(int row, int col);            // Searche's for next move
  void clearMouse(int row, int col);        // clears old mouse characters
  void checkForWin(int row, int col) const; // checks if the win condition has happend

private:
  int startRow;                         // the starting row for 'S'
  int startCol;                         // the starting column for 'S'
  char maze[MAZE_ROWS][MAZE_COLS + 1];  // this is the maze
};
