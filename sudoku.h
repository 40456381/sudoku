#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

//GLOBAL variable
extern int UNSOLVED ; /*000000000*/
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;


typedef struct UserSelection
{
	int row;
	int col;
	int numberChoice;
	
} UserSelection;

int  introduceGame();
int ** createPuzzle();
void ** printPuzzle(int ** puzzle);
int ** getCompletePuzzle();
struct UserSelection makeSelection(void);
int ** updateSudoku2(int ** puzzle, UserSelection);
//returns 1 if correct slot 0 if wrong
int checkPuzzle(int ** puzzle, int ** completePuzzle, UserSelection userpicks);

#endif