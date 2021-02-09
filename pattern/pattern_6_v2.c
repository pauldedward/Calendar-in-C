#include <stdio.h>


int main()
{
    int number = 5, increment;

    for(int i = 1; i <= number; i++)
    {
        increment = -1;
        for(int j = number; j <= number && j > 0 ; j += increment)
        {
            if(j <= i)
            {
                printf("%d ",j);
            }
            else
            {
                printf("  ");
            }
            if( j == 1)
            {
                increment =  1;
            }
        }

        printf("\n");
    }

    return 0;
}
