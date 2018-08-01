/*Name-Karan Shah
Student ID-129965166
Email ID-khshah2@myseneca.ca
*/

#include <stdio.h>
#define SIZE 4
struct employees {
   int id[10];
   int age[10];
   double sal[10];

};
int main(void) {
   double sy[10];
   int Ed[10];
   int Des[10];
   int k = 0;
   int r = 0;
   int n = 0;
   int option = 0;
   struct employees emp[SIZE];
   int c, t = 0, y = 0;
   int dc;
   int g = 0;
   printf("---=== EMPLOYEE DATA ===---\n");
   do 
   {
      printf("\n");
      printf("1.Display Employee Information\n2.Add Employee\n3.Update Employee Salary\n4.Remove Employee\n0.Exit\n");
      printf("\n");
      printf("Please select from the above options: ");
      scanf("%d", &option);
      switch (option)
      {
      case 0:
      {
         r = 1;

         break;
      }

      case 1:

         printf("EMP ID  EMP AGE EMP SALARY\n======  ======= ==========\n");
         
         for (n = 0; n < k; n++) {
            if (strcmp(emp[n].id, "") == 1)
            printf("  %s       %s   %s\n", emp[n].id, emp[n].age, emp[n].sal);

         }
         break;

      case 2:
         
         printf("\n");
         printf("Adding Employee\n");
         printf("===============\n");
         if (k < SIZE) {
            printf("Enter Employee ID: ");
            scanf("%s", &emp[k].id);
            printf("Enter Employee Age: ");
            scanf("%s", &emp[k].age);
            printf("Enter Employee Salary: ");
            scanf("%s", &emp[k].sal);
            k++;
         }
         else {
            printf("\nERROR!!! Maximum Number of Employees Reached\n");
         }
         break;

      case 3:
         do
         {
            printf("Update Employee Salary \n======================\n");
            printf("Enter Employee ID : ");
            scanf("%s", &Ed);
            for (t = 0; t < SIZE; t++)
            {
               if (strcmp(Ed, emp[t].id) == 0)
               {
                  printf("The current salary is %s", emp[t].sal);
                  printf("Enter new Salary:");
                  scanf("%lf", &sy);
                  strcpy(emp[t].sal, sy);
                  y = 1;
               }
            }

         } while (y < 1);
         break;

      case 4:
         do
         {
            printf("\nRemove Employee\n===============\n");
            printf("Enter Employee ID :");
            scanf("%s", &Des);
            for (dc = 0; dc < SIZE; dc++)
            {
               if (strcmp(Des, emp[dc].id) == 0)
               {
                  printf("\nEmployer with ID %s will be removed\n", Des);
                  strcpy(emp[dc].id, "");
                  strcpy(emp[dc].age, "");
                  strcpy(emp[dc].sal, "");
                  g = 1;

               }

            }
         } while (g < 1);
         break;
      default:
      {
         printf("ERROR: Incorrect Option: Try Again\n");
      }
      break;
      }
   } while (r < 1);
   printf("\nExiting Employee Data Program. Good Bye!!!\n");
   return 0;
}