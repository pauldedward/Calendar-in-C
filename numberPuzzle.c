//size must be > 2
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>


struct Box
{
    int number;
};

//declarations
void generateBoxArray(int boardSize, struct Box* boxArray[]);
void scrambleBoard(int* blank, int boardSize,struct Box* boxArray[]);
void printTitle();
void printGrid(int size, struct Box* boxArray[]);
void printHorizontalLine(int size);
void printSeperator(char c);
void printInstructions();
int getInput(int size);
void swapBoxes(int boardSize, int size, int input, int* blank, struct Box* boxArray[]);
int checkWin(int boardSize, struct Box* boxArray[]);

//definitions
int main()
{
    int blank, input = 0;
    int size = 4;
    int boardSize = size*size;
    struct Box* boxArray[boardSize];

    generateBoxArray(boardSize, boxArray);
    scrambleBoard(&blank, boardSize, boxArray);


    do
    {

        printTitle();
        printGrid(size, boxArray);
        printInstructions();

        input = getInput(size);
        if(input == 0)
        {   
             printf("\n\tGAME OVER\n\n");
            return 0;
        }
        swapBoxes(boardSize,size, input, &blank, boxArray);
        

        if(checkWin(boardSize, boxArray))
        {
            printTitle();
            printGrid(size, boxArray);
            printf("\n\tY_O_U  W_I_N\n\n");
            return 0;
        }

    }while(1);

  return 0;
}

void generateBoxArray(int boardSize, struct Box* boxArray[])
{
    for(int index = 0; index < boardSize; index++ )
    {
        boxArray[index] = (struct Box*) calloc(1,sizeof(struct Box));
        boxArray[index]->number = index;
    }
};

void scrambleBoard(int* blank, int boardSize,struct Box* boxArray[])
{
    int randomOne, randomTwo, tempNumber;
    srand(time(0));

    for(int index = 0; index < 100; index++ )
    {
        randomOne = rand() % (boardSize - 1);
        randomTwo = rand() % (boardSize - 1);

        if(boxArray[randomOne]->number == 0)
        {
            *blank = randomTwo;
        }
        if(boxArray[randomTwo]->number == 0)
        {
            *blank = randomOne;
        }
        tempNumber = boxArray[randomOne]->number;
        boxArray[randomOne]->number =  boxArray[randomTwo]->number;
        boxArray[randomTwo]->number =  tempNumber;
    }
}

void printTitle()
{
    system("cls");
    printf("\n\n..........N_U_M_B_E_R   P_U_Z_Z_L_E (INVERTED)..........\n\n");
    printf("..........Bring the blank to the TOP LEFT corner with all the numbers aligned..........\n\n\t");
}

void printGrid(int size, struct Box* boxArray[])
{
    int arrayIndex = 0;

    for(int index = 0; index < size; index++)
    {
        printHorizontalLine(size);
        printf("\n\t");

        for(int innerIndex = 0; innerIndex < size; innerIndex++)
        {
            printSeperator('|');
            if(boxArray[arrayIndex]->number != 0)
            {
               printf(" %2d ",boxArray[arrayIndex++]->number);
            }
            else
            {
                printf("    ");
                arrayIndex++;
            }
        }
        printSeperator('|');
        printf("\n\t");


    }

    printHorizontalLine(size);
}

void printHorizontalLine(int size)
{
    for(int index = 0; index < size; index++)
    {
        printf("-----");
    }
}

void printSeperator(char c)
{
    printf("%c",c);
}

void printInstructions()
{
    printf("\n\n");
    printf("........INSTRUCTIONS..........\n\n\t");
    printf("W - [up]\n\tS - [down]\n\tD - [right]\n\tA - [left]\n\n");

}

int getInput(int size)
{
    char input;
    do
    {
        printf("\n\tEnter choice >>");
        scanf("%c",&input);
        while(getchar() != '\n');

        switch(input)
        {
            case 'w' : return -( size );
            case 's' : return  ( size );
            case 'a' : return  -1;
            case 'd' : return   1;
            default  : printf("\n\tNot valid input\tTry Again y [yes] : ");
        }

    }while(getch() == 'y');


    return 0;
}

void swapBoxes(int boardSize, int size, int input, int* blank, struct Box* boxArray[])
{
        int temp = *blank + input;
        int max = temp % size;
        int min = *blank % size;
        int swap = max - min;
        if((temp >= 0) && (temp < boardSize) && ( abs(swap) != (size - 1))  )
        {
            boxArray[*blank]->number = boxArray[*blank + input]->number;
            boxArray[*blank + input]->number = 0;
            *blank += input;
        }

}

int checkWin(int boardSize,struct Box* boxArray[])
{
    int index;
    for( index = 0; index < boardSize; index++ )
    {
        if(boxArray[index]->number != index)
        {
            return 0;
        }
    }

    if(index == boardSize)
    {
        return 1;
    }
}

