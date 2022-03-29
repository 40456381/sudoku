/*
 * Clark Bolan 40456381 Connect 4 C Program
 * SET09417 Algorithms & Data Structures
 */
 
#include <stdio.h>
#include "sudoku.h"
#include <stdlib.h>

int UNSOLVED = 81;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main()
{
	int ** puzzle = createPuzzle();
	int ** completePuzzle = getCompletePuzzle();
	int correctMove;
	int gametype;
	printPuzzle(puzzle);
	struct UserSelection userpicks;
	gametype = introduceGame();
    userpicks = makeSelection();

		 //try to update the puzzle checking the userpicks is valid
		 puzzle = updateSudoku2(puzzle, userpicks);
		 


    return 0;
}