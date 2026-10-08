#include <stdio.h>
int main()
{
   int i = 10;
   if (i < 1)
   {
       printf("否");
   }
   else
   {
       while (i % 2 == 0)
       {
           i = i / 2;
       }
       if (i == 1)
           printf("是");
       else
           printf("否");
   }
   return 0;
}
