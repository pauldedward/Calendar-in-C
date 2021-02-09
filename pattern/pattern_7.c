#include <stdio.h>


int main()
{
    int number = 5, count = 0, output = 0, increment = 1;


    for(int i = 0; i < number; i++)
    {
        for(int j = 0; j < number; j++)
        {
            output += increment;
            printf("%d ",output);
        }

        output += number + increment;
        increment = (increment * -1);
        printf("\n");
    }

    return 0;
}
