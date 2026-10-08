#include <stdio.h>
int main() {
   int i = 1000;  
   if (i <= 1500) {
       printf("70元\n");
   } else {
       int extra = i - 1500;
       int fee = 70 + ((extra + 99) / 100) * 10; 
       printf("%d元\n", fee);
   }
   return 0;
}
