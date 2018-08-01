/*Name-Karan Shah*/
#include <stdio.h>

#define MAX_BOOKS 10
#define MAX_TITLE_SIZE 20

struct Book
{
   int isbn;
   float price;
   int year;
   char TITLE[MAX_TITLE_SIZE];
   char TITLE1[MAX_TITLE_SIZE];
   char TITLE3[MAX_TITLE_SIZE];
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

      printf("ISBN      TITLE               Year Price  Quantity\n");
      printf("---------+-------------------+----+-------+--------\n");


     do
      {
         printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book[krn].isbn, book[krn].TITLE, book[krn].year, book[krn].price, book[krn].qty);
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
   int i, b00 = -1;
   for (i = 0; i<size; i++)
   {
      if (isbn1 == book[i].isbn)
      {
         b00 = i;
      }
   }
   return b00;
}
void addBook(struct Book book[], int *size)
{
   int boo = -1, qty, isbn1;
   if (*size < MAX_BOOKS)
   {
      printf("ISBN:");
      scanf("%d", &isbn1);
      boo = searchInventory(book, isbn1, *size);
      if (boo == -1)
      {
         book[*size].isbn = isbn1;
         printf("Quantity:");
         scanf("%d", &book[*size].qty);
         printf("TITLE:");
         flush();
         scanf("%[^\n]s", book[*size].TITLE);
         printf("Year:");
         scanf("%d", &book[*size].year);
         printf("Price:");
         scanf("%f", &book[*size].price);
         printf("The book is successfully added to the inventory.\n\n");
         *size = *size + 1;
      }
      else
      {
         printf("Quantity:");
         scanf("%d", &qty);
         book[boo].qty = book[boo].qty + qty;
         printf("The book exists in the repository, quantity is updated.\n\n");
      }
   }
   else
   {
      printf("the inventory is full\n");
   }
}
void checkPrice(const struct Book *book, const int size)
{
   int isbn, b;
   printf("Please input the ISBN number of the book:\n\n");
   scanf("%d", &isbn);
   b = searchInventory(book, isbn, size);
   if (b == -1)
   {
      printf("Book does not exist in the bookstore! Please try again.\n\n");
   }
   else
   {
      printf("Book %d costs $%.2f\n\n", book[b].isbn, book[b].price);
   }
}
int main(void)
{
   int size1 = 0, option;
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
         displayInventory(book1, size1);
         break;
      case 2:
         addBook(book1, &size1);
         break;
      case 3:
         checkPrice(book1, size1);
         break;
      case 0:
         printf("Goodbye!\n");
         break;

      default:
         printf("Invalid input, try again!\n");
      }
   } while (option != 0);
   return 0;
}
