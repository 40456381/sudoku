#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

//GLOBAL variable
extern int UNSOLVED ; /*000000000*/
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;


/*
typedef struct Sudoku 
{
	struct Square *** squares;
	struct Box ** boxes;
} Sudoku;
*/
/*
typedef struct Box
{
	struct Square ** squares;
	int numbers;
	int possible[9];
	int solvable;
	struct Box * next;
} Box;
*/
/*
typedef struct Square
{
	int number;
	//[0] [0] [0] [0] [0] [0] [0] [0] [0]
	//  [9] [8] [7] [6] [5] [4] [3] [2] [1] index
	int possible[9];
	int solvable;
	Box * box;
	int row;
	int column;
	
} Square;
*/
typedef struct UserSelection
{
	int row;
	int col;
	int numberChoice;
	
} UserSelection;

void  introduceGame();
int ** createPuzzle();
void ** printPuzzle(int ** puzzle);
int ** getCompletePuzzle();
//Sudoku * setUpPuzzle(int ** puzzle);

//Sudoku * createSudoku(Square ***, Box ** boxes);

struct UserSelection makeSelection(void);

//int updateSudoku(Square *** sudoku, int row, int column);

int ** updateSudoku2(int ** puzzle, UserSelection);
//returns 1 if correct slot 0 if wrong
int checkPuzzle(int ** puzzle, int ** completePuzzle, UserSelection userpicks);

//int solveSquare(Square * square);


/*
//box functions
Box ** createBoxes();
int updateBoxes(Square *** sudoku, int row, int column);

int checkRows(Square *** sudoku, Box ** boxes);
*/
#endif