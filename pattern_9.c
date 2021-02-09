#include <stdio.h>


int main()
{
    int number = 5, increment;

    for(int i = number; i > 0; i--)
    {
        increment = 1;
        for(int j = 1; j <= number && j > 0 ; j += increment)
        {
            if(j >= i)
            {
                printf("%d ",j);
            }
            else
            {
                printf("  ");
            }
            if( j == number)
            {
                increment = - 1;
            }
        }

        printf("\n");
    }

    return 0;
}
