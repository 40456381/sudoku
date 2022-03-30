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
	struct GoodPickWithPuzzle goodPick;
	goodPick.puzzleUpdated = 'N';
	goodPick.correctPick = 0;
	gametype = introduceGame();
	//keep asking for user input and checking if valid slot
	printf("what is goodPick.puzzleUpdated %c\n", goodPick.puzzleUpdated);
	userpicks = makeSelection();
	//try to update the puzzle checking the userpicks is valid
	//goodPick = updateSudoku2(puzzle, userpicks);
	printPuzzle(puzzle); 
    //userpicks = makeSelection();
	//try to update the puzzle checking the userpicks is valid
	goodPick = updateSudoku2(puzzle, userpicks, goodPick);
	printf("what is goodPick.puzzleUpdated %c\n", goodPick.puzzleUpdated);
	//Need to ask again for selection
	while (goodPick.puzzleUpdated == 'N')
	{
		printPuzzle(puzzle);
		userpicks = makeSelection();
		goodPick = updateSudoku2(puzzle, userpicks, goodPick);
	}
	printPuzzle(puzzle);
	


    return 0;
}