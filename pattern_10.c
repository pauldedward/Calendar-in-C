#include <stdio.h>


int main()
{
    int number = 5, increment, output;

    for(int i = 1; i <= number; i++)
    {
        output = i % 2;

        for(int j = 1; j <= number ; j++)
        {
            printf("%d ",output);
            output = !(output);
        }

        printf("\n");
    }

    return 0;
}
