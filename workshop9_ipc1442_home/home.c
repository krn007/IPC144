/*Name- Karan Shah*/
#include <stdio.h>

#define MAX_TITLE_SIZE 20


struct Book {
   int _isbn;
   float _price;
   int _year;
   int _qty;
   char _title[MAX_TITLE_SIZE + 1];
};

int readRecord(FILE *fp, struct Book *b2read);
int searchInventory(FILE *fp, const int isbn2find);
void menu();
void displayInventory(const char filename[]);
float calculateCapital(const char filename[]);
void addBook(const char filename[], struct Book *b2Add);
void checkPrice(const char filename[], const int isbn2find);



int main()
{

   int option;
   char filename[] = "144_w9_inventory.txt";
   int nISBN;
   struct Book mybook;


   printf("Welcome to the Book Store\n");
   printf("=========================\n");

   do {
      menu();
      scanf("%d", &option);
      switch (option) {

      case 0:
         printf("Goodbye!\n");
         break;

      case 1:
         displayInventory(filename);
         break;

      case 2:
         printf("ISBN:");
         scanf("%d", &mybook._isbn);
         printf("Title:");
         scanf("%*c%20[^\n]", mybook._title);
         printf("Year:");
         scanf("%d", &mybook._year);
         printf("Price:");
         scanf("%f", &mybook._price);
         printf("Quantity:");
         scanf("%d", &mybook._qty);
         addBook(filename, &mybook);
         break;


      case 3:
         printf("Please input the ISBN number of the book:\n\n");
         scanf("%d", &nISBN);
         checkPrice(filename, nISBN);
         break;



      case 4:
         calculateCapital(filename);
         break;

      default:
         printf("Invalid input, try again:\n");

      }
   } while (option != 0);


   return 0;
}

void menu() {
   printf("Please select from the following options:\n");
   printf("1) Display the inventory.\n");
   printf("2) Add a book to the inventory.\n");
   printf("3) Check price.\n");
   printf("4) Calculate total capital of the store.\n");
   printf("0) Exit.\n\n");

   printf("Select: ");
}

void displayInventory(const char filename[])
{
   struct Book mybook;


   FILE *fp = NULL;
   fp = fopen(filename, "r");
   if (fp != NULL) {

      printf("\n\nInventory\n");
      printf("===================================================\n");
      printf("ISBN      Title               Year Price  Quantity\n");
      printf("---------+-------------------+----+-------+--------\n");
      while (readRecord(fp, &mybook) == 5) {
         printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", mybook._isbn, mybook._title, mybook._year, mybook._price, mybook._qty);
      }
      printf("===================================================\n\n");
      fclose(fp);
   }
}


void addBook(const char filename[], struct Book *b2Add)
{
   FILE *fp = NULL;
   int nFILE;
   fp = fopen(filename, "a+");
   if (fp != NULL) {
      nFILE = searchInventory(fp, b2Add->_isbn);
      if (nFILE != -1) {
         printf("The book exists in the repository!\n\n");
      }

      else {
         fprintf(fp, "%d;%.2f;%d;%d;%s\n", b2Add->_isbn, b2Add->_price, b2Add->_year, b2Add->_qty, b2Add->_title);
         printf("The book is successfully added to the inventory.\n\n");
      }
      fclose(fp);
   }
}

void checkPrice(const char filename[], const int isbn2find)
{
   struct Book book;
   int isbn;


   FILE *fp = NULL;
   fp = fopen(filename, "r");
   isbn = searchInventory(fp, isbn2find);
   fclose(fp);
   if (fp != NULL) {
      fp = fopen(filename, "r");
      while (readRecord(fp, &book) == 5) {
         if (isbn != -1 && isbn2find == book._isbn) {
            printf("Book %d costs $%.2lf\n\n", isbn2find, book._price);
         }
      }
      fclose(fp);
   }
   else {
      printf("Book does not exist.\n");
   }
}

int searchInventory(FILE *fp, const int isbn2find) {
   struct Book book;

   int ind = -1;


   if (fp != NULL) {

      while (readRecord(fp, &book) == 5) {
         if (book._isbn == isbn2find) {
            ind = 1;
         }
      }
   }
   return ind;
}

float calculateCapital(const char filename[])
{


   struct Book mybook;

   float capital = 0;

   FILE *fp = NULL;


   fp = fopen(filename, "r");
   if (fp != NULL) {
      while (readRecord(fp, &mybook) == 5) {
         capital = capital + mybook._price * mybook._qty;
      }
   }
   printf("The total capital is: $%.2f.\n", capital);


   fclose(fp);

   return capital;
}

int readRecord(FILE *fp, struct Book *b2read)
{
   int rv = 0;

   rv = fscanf(fp, "%d;%f;%d;%d;%20[^\n]", &b2read->_isbn, &b2read->_price, &b2read->_year, &b2read->_qty, b2read->_title);

   return rv;
}
