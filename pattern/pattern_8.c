#include <stdio.h>


int main()
{
    int number = 5;


    for(int i = number; i > 0; i--)
    {
        for(int j = number; j > 0; j--)
        {
            if(j > i)
            {
                printf("%d ",j);
            }
            else
            {
                printf("%d ",i);
            }
        }

        printf("\n");
    }

    return 0;
}
