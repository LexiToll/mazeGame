/***********************************************
* mazeGameDriver.cpp
* Lexi Toll
*
* This program emulates a mouse running through
* a maze
***********************************************/

#include "mazeGame.h"

int main()
{
  // One extra column is needed for the null character.
  char maze[MAZE_ROWS][MAZE_COLS + 1] =
  { " ---------------------------- ",
    "|XXXXXXXXXXXXXXXXXXXXXXXXXXXX|",
    "|XXX                         |",
    "|XXX XXXXX XXXXXXXXXXXXXXXXXX|",
    "|XXX       XXXXXXXXXXXXXXXXXX|",
    "|XXX XXXXX XXXXXXXXXXXXXXXXXX|",
    "|XXX XXXXX                  X|",
    "|S   XXXXXXXXXXXXXXXXXXXXXX X|",
    "| XX XXXXXXXXXXXXXXXXXXXXXX X|",
    "| XXXXXXXXXXXXX    FXXXXXXX X|",
    "|    XXXXXXXXXXXXXX XXXXXXXXX|",
    "|XXX XXXXXXXXXXXXXX XXXXXXXXX|",
    "|XXX         XXXXXX   XXXXXXX|",
    "|XXX XXXXXXX XXXXXX   XXXXXXX|",
    "|XXX XXXXXXX XXXXXXXX XXXXXXX|",
    "|XXX     XXX XXXXXXXX       X|",
    "|XXX XXX XXX XXXXXXXX XXXXXXX|",
    "|XXX     XXX          XXXXXXX|",
    "|XXXXXXXXXXXXXXXXXXXXXXXXXXXX|",
    " ---------------------------- " };

  MazeGame mazeGame(maze, 7, 1);
  mazeGame.play();
} // end main
