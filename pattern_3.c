#include <stdio.h>


int main()
{
    int number = 5;

    for(int i = number; i > 0; i--)
    {
        for(int j = number; j > number - i; j--)
        {
            printf("%d ",i);
        }
        printf("\n");
    }

    return 0;
}
