/*Name - Karan Shah */
#include <stdio.h>

#define distRate1  0.69			
#define distRate2  0.49			
struct Rental
{
   int id;
   double baseDay;
   double earnings;
};
double addpositive(double amount, double newamount);
double addpositive(double amount, double newamount) {

   if (newamount > 0)
   {
      return amount + newamount;
   }
   else
   {
      return amount;
   }
}
int main()
{
   int noVehicles = 2;			// Number of Vehicles
   int option;							// Variable to store the option selected
   int flag = -1;						// Flag to support vehicle ID find
   int tempID;							// To hold user input for vehicle ID
   int i = 0;							// Variable for "for-loop" counters
   int j, drive, day;
   double price;
   double netcost,Total;
   struct Rental vRent[] = { { 123, 9.95, 0 },{ 124, 19.95, 0 } };





   printf("***** Rental Vehicle Management App *****\n\n");

   do
   {
      printf("1.) Rental Status\n");
      printf("2.) Apply Charges\n");
      printf("0.) Log out\n\n");
      printf("Please enter an option to continue: ");

      scanf("%d", &option);

      switch (option)
      {
      case 0:
         break;

      case 1: // Rental Vehicle Status

         printf("\n-- Rental Vehicle Status --\n\n");
         printf("ID#      Earnings\n");
         printf("-------- ----------\n");

         for (j = 0; j < 2; j++)
         {
            printf("%8d %10.2lf\n", vRent[j].id, vRent[j].earnings);
         }
         printf("\n");

         break;

      case 2: // Calculate Rental Charges

         flag = -1;
         printf("\n-- Rental Charges --\n\n");
         printf("Enter vehicle ID: ");
         scanf("%d", &tempID);


         for (i = 0; i < noVehicles && flag == -1; i++) {
            if (tempID == vRent[i].id) {
               flag = i;
            }
         }

         if (flag != -1) {
            printf("Enter Rental Period (in Days): ");
            scanf("%d", &day);
            price = day * vRent[flag].baseDay;

            printf("Enter kilometers driven: ");
            scanf("%d", &drive);
            if (drive <= 100)
            {
               netcost = drive*distRate1;

            }
            else {
               netcost = 100 * distRate1 + distRate2 * (drive-100);
               
            }

            Total = price + netcost;
            vRent[flag].earnings = addpositive(vRent[flag].earnings, Total);
            printf("\nBase   kmCost Total\n");
            printf("====== ====== ======\n");
            printf("%6.2lf %6.2lf %6.2lf\n ", price, netcost, vRent[flag].earnings);

         }
         else {
            printf("ERROR: Vehicle ID does not exist.\n\n");
         }

         break;


      default:
         printf("Error: Please enter a valid option to continue\n\n");
         break;
      }
   } while (option != 0);


   return 0;
}
