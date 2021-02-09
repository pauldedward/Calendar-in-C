#include <stdio.h>


int main()
{
    int number = 5;

    for(int i = number; i > 0; i--)
    {
        for(int j = number; j > 0; j--)
        {

           if( j > ((number - i) + 1) )
           {
               printf("  ");
           }
           else
           {
             printf("%d ",j);
           }
        }
        for(int j = 1; j < number; j++)
        {

           if( j < ((number - i) + 1) )
           {
               printf("%d ",j + 1);
           }
           else
           {

             printf("  ");
           }
        }

        printf("\n");
    }

    return 0;
}
