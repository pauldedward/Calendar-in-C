#include <stdio.h>


int main()
{
    int number = 5,count = 0;

    for(int i = number; i >= 0; i--)
    {
        for(int j = number; j > 0; j--)
        {
           if( j > (number - i) )
           {
               printf("  ");
           }
           else
           {
             printf("%d ",j);
           }
        }
        printf("\n");
    }

    return 0;
}
