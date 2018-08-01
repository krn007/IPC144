#include <stdio.h>
#define SIZE 3
void compose(long long phonenumbers, int *area, int *prefix, int *lineno) {
   *area = (int)(phonenumbers / (10000000));
   *prefix = (int)((phonenumbers % (10000000) / 10000));
   *lineno = (int)(phonenumbers % (10000));
}

int main(void) {
   int area, prefix, lineno;
   int t, j = 0, m = 0, l = 0;
   int option;
   long long int number;
   long long int phonenumbers[SIZE];
   phonenumbers[0] = 0LL;
   phonenumbers[1] = 0LL;
   phonenumbers[2] = 0LL;
   printf("---=== Phone Numbers ===---\n\n");
   do {
      printf("1. Display Phone List\n");
      printf("2. Add a Number\n");
      printf("0. Exit\n\n");
      printf("Please select from the above options: ");
      scanf("%d", &option);
      printf("\n");
      switch (option)
      {
      case 1:
      {
         printf("\nPhone Numbers\n==============\n");
         for (t = 0; t < SIZE; t++)
         {
            if (phonenumbers[t] != 0LL)
            {

               compose(phonenumbers[t], &area, &prefix, &lineno);
               printf("(%3d)-%3d-%4d \n", area, prefix, lineno);
            }
         }
         printf("\n");
         break;
      }
      case 2:
      {
         if (j < SIZE)
         {
            printf("\nAdd a Number\n============\n");
            scanf("%d", &phonenumbers[m]);
            printf("\n");
            m++;
            j++;
            break;
         }
         else
         {
            printf("ERROR!!! Phone Number List is Full\n\n");
            break;
         }
      }

      case 0:
      {
         printf("\nExiting Phone Number App. Good Bye!!!\n");
         break;
      }
      default:
      {
         printf("ERROR!!!: Incorrect Option: Try Again\n\n");
         break;
      }
      }
   } while (option != 0);
   return 0;
}