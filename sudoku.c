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
	int match;
	struct UserSelection userpicks;
	struct GoodPickWithPuzzle goodPick;
	goodPick.puzzleUpdated = 'N';
	goodPick.correctPick = 0;
	gametype = introduceGame();
	printPuzzle(puzzle);
	//printf("what is goodPick.puzzleUpdated %c\n", goodPick.puzzleUpdated);
	//ask user for input
	userpicks = makeSelection();
	//try to update the puzzle checking the userpicks is valid
	//goodPick = updateSudoku2(puzzle, userpicks);
	//printPuzzle(puzzle); 
	/*TAKE OUT*/
				printf("\n");
				printf("\n***************completePuzzle************\n");
				printPuzzle(completePuzzle);
	/*TAKE OUT*/
    //userpicks = makeSelection();
	//try to update the puzzle checking the userpicks is valid
	goodPick = updateSudoku2(puzzle, userpicks, goodPick);
	//printf("what is goodPick.puzzleUpdated %c\n", goodPick.puzzleUpdated);
	//Need to ask again for selection
	while (goodPick.puzzleUpdated == 'N')
	{
		printPuzzle(puzzle);
		userpicks = makeSelection();
		goodPick = updateSudoku2(puzzle, userpicks, goodPick);
		printPuzzle(puzzle);
	}
	match = checkPuzzle(puzzle, completePuzzle, userpicks);
	printPuzzle(puzzle);
	//checkPuzzleComplete(completePuzzle);
	//check the puzzle
	//printf("what is userpicks.row in main %d \n", userpicks.row);
	//printf("what is userpicks.col in main %d \n", userpicks.col);
	//match = checkPuzzle(puzzle, completePuzzle, userpicks);
	printf("what is match %d\n", match);
	


    return 0;
}