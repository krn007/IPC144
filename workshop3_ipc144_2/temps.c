/*Name: Karan Shah
Email Id: khshah2@myseneca.ca
Student Id: 129965166 */
#include <stdio.h>
#define NUMS 3
int main(void) {
   double  sum, mean;
   int hvalue[3], lvalue[3];
   sum = 0;
   printf("---=== IPC Temperature Calculator ===---\n");
   for (int i = 0;i < NUMS;i++) {
      printf("Enter the high value for day %d: ", i+1);
      scanf("%d", &hvalue[i]);
      printf("Enter the low value for day %d: ", i+1);
      scanf("%d", &lvalue[i]);
      while (lvalue[i] > hvalue[i] || hvalue[i] > 40 || lvalue[i] < -40) {
         printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
         i = i--;
         
      }
   }
   for(int j=0;j<NUMS;j++){
      sum = sum + lvalue[j] + hvalue[j];
   }
   mean = sum/6;
   printf("The average (mean) temperature was: %.2lf\n", mean);
   return 0;
}


