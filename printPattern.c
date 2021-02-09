#include <stdio.h>


int main()

{
    int row,number,increment,count;

    printf("\nEnter n");
    scanf("%d",&number);
    increment = 1;
    count = 1;
    for(int index = 0; index < number ; index++)
    {

        for(int j = 0; j < increment; j++)
        {
            printf("%d ",count++);
        }
        increment++;
        printf("\n");
    }
    return 0;
}
