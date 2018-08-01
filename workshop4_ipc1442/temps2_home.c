/*Name: Karan Shah
  Student ID: 129965166
  Email ID :khshah2@myseneca.ca
*/
#include <stdio.h>
int main(void) {
   int num, i, high[12], low[12], j, a, number=0;
   double sum = 0.00, mean;
   printf("---=== IPC Temperature Analyzer V2.0 ===---\n");
   printf("Please enter the number of days between 3 and 10, inclusive: ");
   scanf("%d", &num);
   printf("\n");
   while (num < 3 || num>10) {
      num = 0;
      sum = 0.00;
      mean = 0.00;
      printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
      scanf("%d", &num);
   }
   printf("\n");
   for (i = 0;i < num;i++) {
      printf("Day %d - High: ", i+1);
      scanf("%d", &high[i]);
      printf("Day %d - Low: ", i+1);
      scanf("%d", &low[i]);
   }
   printf("Day  Hi  Low \n");
   for (j = 0;j < num;j++) {
      printf("%d    %d    %d \n", j+1, high[j], low[j]);
   }
   printf("Enter a number between 1 and 4 to see the average temperature for the entered number of days, enter a negative number to exit: ");
   scanf("%d", &a);
   while (a > 0) {
      sum = 0.00;
      if (a <= num)
      {
         for (int t = 0;t < a;t++)
         {
            sum = sum + low[t] + high[t];
         }
         number = a * 2;
         mean = sum / number;

         printf("The average temperature up to day %d is: %.2lf\n", a, mean);
      }
      else {
         printf("Invalid,");
         sum = 0.00;
         mean = 0.00;
         number = 0;
      }
      printf("Enter a number between 1 and 4 to see the average temperature for the entered number of days, enter a negative number to exit: ");
      scanf("%d", &a);
   }
   if (a < 0)
      printf("Goodbye!\n");
   return 0;
}