
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <stdbool.h>


struct Box
{
    int position;
    int neighbourMines;
    char content;
    bool isMine;
    bool visited;
};

//Fuction definitions
int isInMinePositions(int random,  int randomArray[] );
int generateMinePostions(int minePositions[],int noOfMines, int max );
void printGrid(int row, int column, struct Box* BoxArray[row][column] );
int generateBoxes(int row, int column, int noOfMines, struct Box* BoxArray[row][column] );
int generateNeighbours( int row, int column, struct Box* BoxArray[row][column] );

int main()
{
    int row, column, noOfMine, inputRow, inputColumn,visited = 0;

    system("cls");
    printf("\nNote : max-grid size(1000 Tiles) & No of mines < grid:(row X column)\n");

    printf("\nEnter no of rows :",&row);
    scanf("%d",&row);

    printf("\nEnter no of columns :",&column);
    scanf("%d",&column);


    printf("\nEnter no of mines :",&noOfMine);
    scanf("%d",&noOfMine);

    struct Box* BoxArray[row][column];

    if( ( ( row * column ) > 1000 ) || ( noOfMine > (row * column ) ) )
    {
        printf("\n invalid input");
        return 0;
    }

    system("cls");
    printf("\n\n!.........MINESWEEPER.........!\n\n");

    generateBoxes( row, column, noOfMine, BoxArray);
    generateNeighbours( row, column, BoxArray);

    printGrid(row, column, BoxArray);

    do
    {
        printf("\nEnter your Choice (row column):");
        scanf("%d %d", &inputRow, &inputColumn);
	while(getchar() != '\n');

        inputRow -= 1;
        inputColumn -= 1;
	    
	if(inputColumn < 0 || inputColumn >= column || inputRow < 0 || inputRow >= row)
        {
            system("cls");
            printGrid(row, column, BoxArray);
            printf("\n\tInvalid input\n\tTry again ?[y] :");
            if(getch() == 'y')
            {
                continue;
            }
        }

        if( (BoxArray[inputRow][inputColumn]->visited == 0) && (BoxArray[inputRow][inputColumn]->isMine == 0) )
        {
            BoxArray[inputRow][inputColumn]->visited = 1;
            visited++;
            BoxArray[inputRow][inputColumn]->content = BoxArray[inputRow][inputColumn]->neighbourMines + '0';

            printGrid(row, column, BoxArray);
        }
	    
        if(BoxArray[inputRow][inputColumn]->isMine == 1)
        {
            BoxArray[inputRow][inputColumn]->content = 'X';

            printGrid(row, column, BoxArray);
            printf("\n..........GameOver..........\n");
            break;
        }

        if( ( (column * row) - noOfMine ) <= visited )
        {
            printGrid(row, column, BoxArray);
            printf("\n..........You Won..........\n");
            break;
        }
        

    }while(1);

    return 0;
}

int isInMinePositions(int random,  int randomArray[])
{
    for(int index = 0; randomArray[index]; index++)
    {
        if ( random == randomArray[index] )
        {
            return 1;
        }
    }

    return 0;
}
	
int generateMinePostions(int minePositions[],int noOfMines, int max)
{

	int index = 0, random;

    	srand(time(0));

	while(index < noOfMines)

    	{
       		random = (rand() % max ) + 1;

       		if( isInMinePositions(random, minePositions) )
       		{
          		continue;
      		}
       		minePositions[index] = random;
       		index++;
    	}

    return 0;
}

void printGrid(int row, int column, struct Box* BoxArray[row][column])
{
    system("cls");
    printf("\n\n!.........MINESWEEPER.........!\n\n");
    printf("\n C  |");
	
    for(int columnIndex = 0; columnIndex < column; columnIndex++)
    {
            printf(" %2d ",columnIndex + 1);
    }
    printf("\n R  |");
	
    for(int columnIndex = 0; columnIndex < column; columnIndex++)
    {
             printf("____");
    }

    printf("\n    |");

    for(int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        printf("\n %2d |",rowIndex + 1);
	    
        for(int columnIndex = 0; columnIndex < column; columnIndex++)
        {
            printf(" %2c ",BoxArray[rowIndex][columnIndex]->content);
        }
        printf("\n    |");
    }
}

int generateBoxes(int row, int column, int noOfMines, struct Box* BoxArray[row][column])
{
    int sizeOfBoxArray = 0, totalBoxes, minePositions[noOfMines];

    totalBoxes =  row * column;

    generateMinePostions(minePositions, noOfMines, totalBoxes);

    for(int rowIndex = 0; rowIndex < row; rowIndex++)
    {

        for(int columnIndex = 0; columnIndex < column; columnIndex++)
        {
            struct Box* box = (struct Box*) calloc(1,sizeof(struct Box));
		
            box->position = sizeOfBoxArray++;
            box->content = '*';
            box->isMine = isInMinePositions(box->position + 1, minePositions);
            box->visited = 0;
            box->neighbourMines = 0;
            BoxArray[rowIndex][columnIndex] = box;

        }
    }

    return 0;
}

int generateNeighbours( int row, int column, struct Box* BoxArray[row][column])
{
    int left, right, up, down,  neighbourMines;

    for(int rowIndex = 0; rowIndex < row; rowIndex++)
    {

        for(int columnIndex = 0; columnIndex < column; columnIndex++)
        {

            neighbourMines = 0;
            left = columnIndex - 1;
            right = columnIndex + 1;
            up = rowIndex - 1;
            down = rowIndex + 1;

            if(left >= 0)
            {
                if(BoxArray[rowIndex][left]->isMine)
                {
                  neighbourMines++;
                }
            }
            if(right < column)
            {
                if(BoxArray[rowIndex][right]->isMine)
                {
                  neighbourMines++;
                }
            }
            if(up >= 0)
            {
                if(BoxArray[up][columnIndex]->isMine)
                {
                  neighbourMines++;
                }
                if(left >= 0)
                {
                    if(BoxArray[up][left]->isMine)
                    {
                        neighbourMines++;
                    }
                }
                if(right < column)
                {
                    if(BoxArray[up][right]->isMine)
                    {
                        neighbourMines++;
                    }
                }
            }
            if(down < row)
            {
                if(BoxArray[down][columnIndex]->isMine)
                {
                  neighbourMines++;
                }
                 if(left >= 0)
                {
                    if(BoxArray[down][left]->isMine)
                    {
                        neighbourMines++;
                    }
                }
                if(right < column)
                {
                    if(BoxArray[down][right]->isMine)
                    {
                        neighbourMines++;
                    }
                }
            }

            BoxArray[rowIndex][columnIndex]->neighbourMines = neighbourMines;

        }
    }


    return 0;
}




