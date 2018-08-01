/*Name- Karan Shah*/
#include <stdio.h>

#define distRate1  0.69			// Rate per Kilometer from 0km to 100km (inclusive)
#define distRate2  0.49			// Rate per Kilometer above 100km 


// Structure Declaration for Vehicle Rentals
struct Rental
{
   int id;						// ID of the Rental Vehicle
   double baseDay;				// Daily Base Price 
   double earnings;			// Total earnings from this rental
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
double taxCalc(double price, double rate);
double taxCalc(double price, double rate)
{
   double tax = price*(rate / 100);
   double sT = price + tax;
   return sT;
}
double subtractPositive(double amount, double newAmount);
double subtractPositive(double amount, double newAmount)
{
   if (newAmount > 0)
   {
     return  amount - newAmount;
   }
   else {
      return amount;
      
   }
}
int main()
{
   int noVehicles = 3;			// Number of Vehicles [ Changed to 3]
   int option;							// Variable to store the option selected
   int flag;							// Flag to support vehicle ID find
   int tempID;							// To hold user input for vehicle ID
   int i = 0,n;							// Variable for "for-loop" counters
   int j, drive, day;
   double price,taxed,diff,gitt;
   double netcost, Total,l=0.00;
   char de;                              // Initialize the struct Vehicle Rental [ New addition for 3 Rentals]
   struct Rental vRent[] = { { 123, 9.95, 0 },{ 124, 19.95, 0 },{ 125, 29.95, 0 } };

   double taxRate = 14;				// Tax rate is 14%
   double discount = 5;    			// Discount amount for rentals (in CAD)

                                    /*Declare Your Variables Here*/


   printf("***** Rental Vehicle Management App *****\n\n");

   do
   {
      // Display the option list
      printf("1.) Rental Status\n");
      printf("2.) Apply Charges\n");
      printf("3.) Apply Taxes to All Rentals\n");
      printf("4.) Apply Gift Card\n");
      printf("0.) Log out\n\n");
      printf("Please enter an option to continue: ");

      scanf("%d", &option);

      switch (option)
      {
      case 0: // Exit the program
         break;

      case 1: // Rental Vehicle Status

         printf("\n-- Rental Vehicle Status --\n\n");
         printf("ID#      Earnings\n");
         printf("-------- ----------\n");
         for (j = 0; j < 3; j++)
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

         // Finding the correct vehicle index
         for (i = 0; i < noVehicles && flag == -1; i++) {
            if (tempID == vRent[i].id) {
               flag = i;
            }
         }
         if (flag == -1)
         {
            printf("ERROR: Vehicle ID does not exist.\n");

            break;
         }
         else
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
               netcost = 100 * distRate1 + distRate2 * (drive - 100);

            }
            Total = price + netcost;
            vRent[flag].earnings = addpositive(vRent[flag].earnings, Total);
            printf("Apply Discount: ");
            scanf(" %c", &de);

            if (de == 'Y' || de == 'y')
            {

               vRent[flag].earnings = subtractPositive(vRent[flag].earnings, discount);
               
            }
            
            printf("\nBase   kmCost   DiscStatus  Total\n====== ======   ==========  ======\n");
            printf("%6.2lf  %6.2lf %10c  %6.2lf \n", price, netcost, de, vRent[flag].earnings);
            break;
         }
      case 3:
      {
         printf("\n-- Apply Taxes To all Accounts--\n\n");
         printf("ID#      Earnings      Taxes\n-------- ----------   ------\n");
         for (int g = 0; g < 3; g++)
         {
            taxed = taxCalc(vRent[g].earnings, 14);
            diff = taxed - vRent[g].earnings;
            vRent[g].earnings = taxed;
            printf("%8d %10.2lf%10.2lf\n", vRent[g].id, vRent[g].earnings, diff);
         }
         break;
      }
      case 4:
      {
         flag = -1;
         printf("\n-- Apply Gift Card --\n\n");
         printf("Enter Vehicle ID: ");
         scanf("%d", &n);
         for (int t = 0; t < 3 && flag == -1; t++ )
         {
            if (tempID == vRent[t].id)
            {
               flag = t;
            }
         }
         if (flag != -1)
         {
            printf("Enter Gift Card Amount: ");
            scanf("%lf", &gitt);
            vRent[flag].earnings = subtractPositive(vRent[flag].earnings,gitt);
           
            printf("Discount Applied\n");
         }
         break;
      }
      default:
         printf("Error: Please enter a valid option to continue\n\n");
         break;
      }


   } while (option != 0);


   return 0;
}