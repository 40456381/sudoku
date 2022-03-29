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
	printPuzzle(puzzle);
	struct UserSelection userpicks;
	introduceGame();
	//while (UNSOLVED > 0)
	//{

		 userpicks = makeSelection();

		 //try to update the puzzle checking the userpicks is valid
		 puzzle = updateSudoku2(puzzle, userpicks);
		 
		 //correctMove = checkPuzzle(puzzle, completePuzzle, userpicks);
		 /*if (correctMove = 1)
		 {
			 printPuzzle(puzzle);
		 }
		 else
		 {
			 printf("wrong move one life gone\n");
		 }*/
		 /*
		 int i,j;
		 for(i=0;i<SIZE_ROWS;i++)
			{
				for(j=0;j<SIZE_COLUMNS;j++)
				{
					printf("\t%d" , puzzle[i][j]);
				}
					printf("\n");
			}
			
				//printPuzzle(puzzle);
		
	//test for changes
		

	
/*
    puzzle = createPuzzle();

    sudoku = setUpPuzzle(puzzle);

    printPuzzle(sudoku->squares);

	while (UNSOLVED > 0)
	{
		printf("\n");
		printf("this is shot %d\n", shots);
		progress = checkPuzzle(sudoku->squares, sudoku->boxes);
		printPuzzle(sudoku->squares);
		shots++;
		if (progress == 0)
		{	
			printf("failed to solve the puzzle");
			break;
		}
	}
	

    printf("\n");
	printf("\n");

    //printPuzzle(sudoku->squares);
	if (UNSOLVED == 0)
	{
		printf("\n");
		printf("WINNER");
	}
*/

    return 0;
}