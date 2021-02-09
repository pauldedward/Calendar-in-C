#include <stdio.h>


int main()
{
    int number = 5,count = 0;

    for(int i = 0; i < number; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            printf("%d ",++count);
        }
        printf("\n");
    }

    return 0;
}
