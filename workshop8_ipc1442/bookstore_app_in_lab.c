/*Name-Karan Shah*/
#include <stdio.h>

#define MAX_BOOKS 10
#define MAX_TITLE_SIZE 20

struct Book
{
   int isbn;
   float price;
   int year;
   char title[MAX_TITLE_SIZE];
   char title1[MAX_TITLE_SIZE];
   char title3[MAX_TITLE_SIZE];
   int qty;
};

void flush()
{
   char chu;
   do
   {
      scanf("%c", &chu);
   } while (chu != '\n');
}
void menu()
{
   printf("Please select from the following options:\n");
   printf("1) Display the inventory.\n");
   printf("2) Add a book to the inventory.\n");
   printf("3) Check price.\n");
   printf("0) Exit.\n\n");
}
void displayInventory(struct Book book[], int size)
{
   int krn = 0;
   if (size != 0)
   {
      printf("\n\nInventory\n");
      printf("===================================================\n");

      printf("ISBN      Title               Year Price  Quantity\n");
      printf("---------+-------------------+----+-------+--------\n");


      do
      {
         printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book[krn].isbn, book[krn].title, book[krn].year, book[krn].price, book[krn].qty);
         krn++;
      } while (krn < size);

      printf("===================================================\n\n");
   }
   else
   {
      printf("The inventory is empty!\n");
      printf("===================================================\n\n");
   }
}
int searchInventory(const struct Book *book, const int isbn1, const int size)
{
   // Not implemented
}
void addBook(struct Book book[], int *size)
{
   int boo = -1, qty, isbn1;
   if (*size < MAX_BOOKS)
   {
      if (boo == -1)
      {
         printf("ISBN:");
         scanf("%d", &isbn1);


         book[*size].isbn = isbn1;

         printf("Title:");
         flush();
         scanf("%[^\n]s", book[*size].title);
         printf("Year:");
         scanf("%d", &book[*size].year);
         printf("Price:");
         scanf("%f", &book[*size].price);
         printf("Quantity:");
         scanf("%d", &book[*size].qty);
         printf("The book is successfully added to the inventory.\n\n");
         *size = *size + 1;
      }

   }
   else
   {
      printf("the inventory is full\n");
   }
}
void checkPrice(const struct Book *book, const int size)
{
   //Not implemented
}
int main(void)
{
   int sage = 0, option;
   struct Book book1[MAX_BOOKS];
   printf("Welcome to the Book Store\n");
   printf("=========================\n");
   do
   {
      menu();
      printf("Select: ");
      scanf("%d", &option);
      switch (option)
      {
      case 1:
         displayInventory(book1, sage);
         break;
      case 2:
         addBook(book1, &sage);
         break;
      case 3:
         checkPrice(book1, sage);
         break;
      case 0:
         printf("Goodbye!\n");
         break;

      default:
         printf("Invalid input,try again!\n");
      }
   } while (option != 0);
   return 0;
}

