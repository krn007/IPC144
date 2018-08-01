/*Name-Karan Shah
Student ID-129965166
Email ID-khshah2@myseneca.ca 
*/
#include <stdio.h>
#include<conio.h>
#define SIZE 2
struct employees {
   int id;
   int age;
   double sal;

};
int main(void) {
   int k = 0;
   int r = 0;
   int n = 0;
   int option = 0;
   struct employees emp[SIZE];
   printf("---=== EMPLOYEE DATA ===---\n");
   do {
      printf("\n");
      printf("1.Display Employee Information\n2.Add Employee\n0.Exit\n");
      printf("\n");
      printf("Please select from the above options: ");
      scanf("%d", &option);
      switch (option)
      {
      case 0:

         printf("Exiting Employee Data Program. Good Bye!!!\n");

         break;


      case 1:

         printf("EMP ID  EMP AGE EMP SALARY\n======  ======= ==========\n");

         for (n = 0; n < k; n++) {
            printf("  %d       %d   %.2lf\n", emp[n].id, emp[n].age, emp[n].sal);

         }
         break;

      case 2:


         printf("\n");
         printf("Adding Employee\n");
         printf("===============\n");
         if (k < SIZE) {
            printf("Enter Employee ID: ");
            scanf("%d", &emp[k].id);
            printf("Enter Employee Age: ");
            scanf("%d", &emp[k].age);
            printf("Enter Employee Salary: ");
            scanf("%lf", &emp[k].sal);
            k++;
         }
         else {
            printf("\nERROR!!! Maximum Number of Employees Reached\n");
         }
         break;

      default:

         printf("Invalid\n");

         break;
      }
   } while (option != 0);
   return 0;
}