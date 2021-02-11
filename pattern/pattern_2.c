#include <stdio.h>


int main()
{
    int number = 5;

    for(int i = number; i > 0; i--)
    {
        for(int j = number; j >= i; j--)
        {
            printf("%d ",j);
        }
        printf("\n");
    }

    return 0;
}
