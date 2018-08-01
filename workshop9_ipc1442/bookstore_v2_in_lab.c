/*Name- Karan Shah*/
#include<stdio.h>
#define MAX_TITLE_SIZE 20
#define MAX_BOOKS 10

struct Book {
   int _isbn;
   float _price;
   int _year;
   int _qty;
   char _title[MAX_TITLE_SIZE];
};

void menu();
int readRecord(FILE *fp, struct Book *b2read);
void displayInventory(const char filename[]);
float calculateCapital(const char filename[]);
int searchInventory(FILE *fp, const int isbn2find);
void addBook(const char filename[], struct Book *b2Add);
void checkPrice(const char filename[], const int isbn2find);




int main(void)
{


   char filename[] = "144_w9_inventory.txt";
   int opt;
   float cpt;
   printf("Welcome to the Book Store\n");
   printf("=========================\n");
   do
   {
      menu();
      printf("\nSelect: ");
      scanf("%d", &opt);
      switch (opt)
      {

      case 1:
         displayInventory(filename);
         break;
      case 2:

         break;
      case 3:

         break;
      case 4:
         cpt = calculateCapital(filename);
         printf("The total capital is: $%.2f.\n", cpt);
         break;
      case 0:
         printf("Goodbye!\n");
         break;
      default:
         printf("Invalid input, try again:\n");
      }
   } while (opt != 0);
   return 0;
}



void menu()
{

   printf("Please select from the following opts:\n");
   printf("1) Display the inventory.\n");
   printf("2) Add a book to the inventory.\n");
   printf("3) Check price.\n");
   printf("4) Calculate total capital of the store.\n");
   printf("0) Exit.\n");

}

int readRecord(FILE * fp, struct Book *b2read)
{

   char c;

   fscanf(fp, "%d %c", &(*b2read)._isbn, &c);
   if (c == ';') {

      fscanf(fp, "%f %c", &(*b2read)._price, &c);
   }
   if (c == ';') {

      fscanf(fp, "%d %c", &(*b2read)._year, &c);
   }
   if (c == ';') {

      fscanf(fp, "%d %c", &(*b2read)._qty, &c);
   }
   if (c == ';') {

      fscanf(fp, "%[^\n]", (*b2read)._title);
   }
   return 0;
}

void displayInventory(const char filename[])
{
   struct Book mybook;
   int j = 0;
   FILE *fp;
   fp = fopen(filename, "r");

   if (fp != NULL) {

      printf("\n\nInventory");
      printf("\n");
      printf("===================================================\n");
      printf("ISBN      Title               Year Price  Quantity\n");
      printf("---------+-------------------+----+-------+--------\n");
      j = 0;
      while (j<3) {

         readRecord(fp, &mybook);

         printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", mybook._isbn, mybook._title, mybook._year, mybook._price, mybook._qty);
         j++;
         
      }
      printf("===================================================\n");
      printf("\n");
      fclose(fp);
   }
}

float calculateCapital(const char filename[])
{
   struct Book mybook;
   float capitaltotal = 0;
   int i = 0;
   FILE *fp;
   fp = fopen(filename, "r");
   if (fp != NULL) {
      i = 0;
      while (i<3) {

         readRecord(fp, &mybook);
         capitaltotal = capitaltotal + (mybook._price*mybook._qty);
         i++;
      }
      fclose(fp);
   }
   return capitaltotal;

}

/*FUNCTION IMPLEMENTED in AT HOME PART
int searchInventory(FILE * fp, const int isbn2find)
{

printf("Not Implemented");
}

void addBook(const char filename[], struct Book *b2Add)
{

printf("Not implemented");
}

void checkPrice(const char filename[], const int isbn2find)
{

printf("Not implementdd");
}

*/



