#include<stdio.h>

int main() {

   int number = 6, odd = 1, even = 2,output = 2 ;

   for(int i = 1; i <= number; i++)
   {
       if( (i % 2) == 0)
       {
           odd = output;
           output = even;
       }
       else
       {
           even = output;
           output = odd;
       }
       for(int j = 0; j < i; j++)
       {
           printf("%d ",output);
           output += 2;
       }
       printf("\n");
   }

}
