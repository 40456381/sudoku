#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"

UserSelection makeSelection()
{
		struct UserSelection userpicks;
		
		//int row = 0;
		//int col = 0;
		//int numberChoice = 0;
		int correct = 0;
		printf("please select a row between 1 and 9 that you would like to alter: ");
		scanf("%d", &userpicks.row);
		while (correct == 0)
		{	
			if (userpicks.row < 1 ||  userpicks.row > 9)
			{	printf("***************************************\n");
				printf("* row entered must be between 1 and 9 *\n");
				printf("***************************************\n");
				printf("please select a row that you would like to alter: ");
				scanf("%d", &userpicks.row);
			}
			else 
			{
				correct++;
				//scanf("%d", &userpicks.row);
			}
		}
		
		//set correct back to N for next check
		correct = 0;
		//printf("row selection is %d \n", userpicks.row);
		printf("please select a column between 1 and 9 that you would like to alter:  ");
		scanf("%d", &userpicks.col);
		//printf(" col entered is %i \n", col);
		while (correct == 0)
		{	
			if (userpicks.col < 1 ||  userpicks.col > 9)
			{	printf("***************************************\n");
				printf("* col entered must be between 1 and 9 *\n");
				printf("***************************************\n");
				printf("please select a col that you would like to alter: ");
				scanf("%d", &userpicks.col);
			}
			else 
			{
				correct++;
				//scanf("%d", &userpicks.col);
			}
		}
		//set correct back to N for next check
		correct = 0;
		//printf("column selection is %d", userpicks.col);
		printf("\n");
		printf("please enter the number between 1 and 9 that you would like to place in this position:  ");
		scanf("%d", &userpicks.numberChoice);
		printf("\n");
		
		while (correct == 0)
		{	
			if (userpicks.numberChoice < 1 ||  userpicks.numberChoice > 9)
			{	printf("******************************************\n");
				printf("* number entered must be between 1 and 9 *\n");
				printf("******************************************\n");
				printf("please enter the number that you would like to place in this position:  ");
				scanf("%d", &userpicks.numberChoice);
			}
			else 
			{
				correct++;
				//scanf("%d", &userpicks.numberChoice);
				
			}
		}
		printf("the number you want to place on the board at row %d , column %d is ----> %d ", userpicks.row, userpicks.col, userpicks.numberChoice);
		
		printf("\n");

	return userpicks;
}

GoodPickWithPuzzle updateSudoku2(int ** puzzle, UserSelection userpicks, GoodPickWithPuzzle goodPick)
{	
			//struct GoodPickWithPuzzle goodPick;
			goodPick.puzzle = puzzle;
			//goodPick.puzzleUpdated = 'N';
			//goodPick.correctPick = 0;
			
			printf("what is userpicks.numberChoice %d \n", userpicks.numberChoice);
  		
			int x, y;
			int i, j;
			userpicks.row--;
			userpicks.col--;
            //printf("what is userpicks.row  %d \n", userpicks.row);
			//printf("what is userpicks.col  %d \n", userpicks.col);
			// loop through rows 
			for (i = 0; i < SIZE_ROWS; i++)
				
				{ 
					//printf("what row in the loop %i \n", i);
					
					// loop through columns 
					for (j = 0; j < SIZE_COLUMNS; j++)
					{
						//printf("what is i %i \n", i);
						//printf("what is j %i \n", j);
						//printf("what is row   %d \n", i); 
						//printf("what is goodPick.puzzle  %d \n", goodPick.puzzle[i][j]);
						//printf("HERERE %d\n", puzzle[i][j]);				
						x = puzzle[i][j];
						//printf("what is x%d \n", x); 
						y = userpicks.numberChoice;
						//printf("what is col   %d \n", j); 
						//printf("what is x %d\n", x);
						//printf("what is y %d\n", y);

							if(i == userpicks.row && j == userpicks.col && (x == y) || (i == userpicks.row && j == userpicks.col && (x != 0)))
								
							{						
									printf("The selection you have made is already holding a completed number\n");
									//need to ask for the selection again until empty slot found and dont update puzzle	
									//this will happen in the main function
									goodPick.puzzleUpdated = 'N'; 
									goodPick.correctPick = 0;
									return goodPick;
							}
							else if (i == userpicks.row && j == userpicks.col && (x == 0)) //the position is empty so we can update the array
							{
								printf("updating the array\n");
								//update puzzle
								puzzle[userpicks.row][userpicks.col] = userpicks.numberChoice;
								goodPick.correctPick = userpicks.numberChoice;
								goodPick.puzzleUpdated = 'Y';
								
								return goodPick;
								
							}
					
					printf("\n");
					}
					
				}
	
    return goodPick;
	
}	


int checkPuzzle(int ** puzzle, int ** completePuzzle, UserSelection userpicks)
{
	printf("TAP OF checkPuzzle\n"); 
    int i = 0, j = 0, x = 0, y = 0, row = 0, col = 0, match = 0;
	userpicks.row--;
	userpicks.col--;
	//int ** completePuzzle = getCompletePuzzle();
    // loop through rows 
    for (i = 0; i < SIZE_ROWS; i++)
    {
        //loop through columns 
        for (j = 0; j < SIZE_COLUMNS; j++)
        {
			
			x = completePuzzle[i][j];
			row = userpicks.row;
			col = userpicks.col;
			y =  userpicks.numberChoice;
			//printf("what is row %d \n", row); 
			//printf("what is col %d \n", col);
			
			//printf("what is x %d \n", x); 
			//printf("what is y %d \n", y);
            if (i == row && j == col  && x == y)
            {
                //the selection matches
				match = 1;
				row++;
				col++;
				printf("you have found a correct match for row %i and column %i\n", row, col);
				return match;
            }
			else
			{
				row++;
				col++;
				printf("you have found a incorrect match for row %i and column %i reverting back selection\n", row, col);
				puzzle[userpicks.row][userpicks.col] = 0;
				match = 0;
				return match;
			}
			
        }
     
	}
	
	return match;	
    
}


int ** createPuzzle()
{
    int ** puzzle;
    int i, j;
    int array[9][9]= {0, 1, 9,      0, 0, 2,     0, 0, 0,
                      4, 7, 0,      6, 9, 0,     0, 0, 1,
                      0, 0, 0,      4, 0, 0,     0, 9, 0,

                      8, 9, 4,      5, 0, 7,     0, 0, 0,
                      0, 0, 0,      0, 0, 0,     0, 0, 0,
                      0, 0, 0,      2, 0, 1,     9, 5, 8,

                      0, 5, 0,      0, 0, 6,     0, 0, 0,
                      6, 0, 0,      0, 2, 8,     0, 7, 9,
                      0, 0, 0,      1, 0, 0,     8, 6, 0 };

    puzzle = (int**)malloc(sizeof(int*)*9);

    for (i = 0; i < 9; i++)
    {
        puzzle[i] = (int*)malloc(sizeof(int)*9);

        for (j = 0; j < 9; j++)
        {
            puzzle[i][j] = array[i][j];
        }
    }

    return puzzle;
}

int ** getCompletePuzzle()
{
    int ** completePuzzle;
    int i, j;
    int array[9][9]= {3, 1, 9,      7, 8, 2,     6, 4, 5,
                      4, 7, 2,      6, 9, 5,     3, 8, 1,
                      5, 8, 6,      4, 1, 3,     2, 9, 7,

                      8, 9, 4,      5, 3, 7,     1, 2, 6,
                      1, 2, 5,      8, 6, 9,     7, 3, 4,
                      7, 6, 3,      2, 4, 1,     9, 5, 8,

                      2, 5, 8,      9, 7, 6,     4, 1, 3,
                      6, 4, 1,      3, 2, 8,     5, 7, 9,
                      9, 3, 7,      1, 5, 4,     8, 6, 2 };

    completePuzzle = (int**)malloc(sizeof(int*)*9);

    for (i = 0; i < 9; i++)
    {
        completePuzzle[i] = (int*)malloc(sizeof(int)*9);

        for (j = 0; j < 9; j++)
        {
            completePuzzle[i][j] = array[i][j];
        }
    }

    return completePuzzle;
}

void ** printPuzzle(int ** puzzle)
{
    int i, j;

    printf("-------------------------------\n");
    for (i = 0; i < SIZE_ROWS; i++)
    {
        printf("|");
        /* print each row */
        for (j = 0; j < SIZE_COLUMNS; j++)
        {
            printf(" %d ", puzzle[i][j]);

            if (((j + 1) % 3) == 0)
            {
                printf("|");
            }
        }
        printf("\n");
        if (((i + 1) % 3) == 0)
        {
            printf("-------------------------------\n");
        }
    }
	return puzzle;
}

int  checkPuzzleComplete(int ** puzzle)
{
	int x, i, j;
	for (i = 0; i < SIZE_ROWS; i++)
    {
        //loop through columns 
        for (j = 0; j < SIZE_COLUMNS; j++)
        {
			x = puzzle[i][j];

			if (x == 0)
			{
				printf("\npuzzle has empty slot\n");
				return 1; 
			}
			else
			{
				printf("\npuzzle has completed\n");
				return 0;
			}
		}
		
	}
	return 0;	
}

