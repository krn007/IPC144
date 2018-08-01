/*Name- Karan Shah */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LINEAR 1
#define FORM 0
#define MAX_ITEM_NO 500
#define DATAFILE "items.txt"
const double TAX = 0.13;
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
int yes(void);
void welcome(void) {
   printf("---=== Grocery Inventory System ===---\n\n");
}
void printTitle(void) {
   printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
   printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}
void printFooter(double grandTotal) {
   printf("--------------------------------------------------------+----------------\n");
   if (grandTotal > 0) {
      printf("\t\t\t\t\t   Grand Total: |%12.2lf\n", grandTotal);
   }
}
void flushKeyboard(void) {
   while (getchar() != '\n')
      ;
}
void pause(void) {
   printf("Press <ENTER> to continue...");
   while (getchar() != '\n')
      ;
}
int getInt(void) {
   int newInput;
   char lineDown;

   scanf("%d%c", &newInput, &lineDown);

   if (lineDown != '\n') {
      do {
         while (getchar() != '\n')
            ;
         printf("Invalid integer, please try again: ");
         scanf("%d%c", &newInput, &lineDown);
      } while (lineDown != '\n');

   }

   return newInput;
}

int getIntLimited(int lowerLimit, int upperLimit) {
   int value;
   do {
      value = getInt();
      if (value < lowerLimit || value > upperLimit) {
         printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
      }
   } while (value < lowerLimit || value > upperLimit);

   return value;
}

double getDouble(void) {
   double newInput;
   char lineDown;

   scanf("%lf%c", &newInput, &lineDown);

   if (lineDown != '\n') {
      do {
         while (getchar() != '\n')
            ;
         printf("Invalid number, please try again: ");
         scanf("%lf%c", &newInput, &lineDown);
      } while (lineDown != '\n');

   }

   return newInput;

}

double getDoubleLimited(double lowerLimit, double upperLimit) {
   double number;

   do {
      number = getDouble();

      if (number < lowerLimit || number > upperLimit) {
         printf("Invalid value, %lf< value < %lf: ", lowerLimit, upperLimit);
      }

   } while (number < lowerLimit || number > upperLimit);

   return number;
}


int yes(void) {
   char character = 'x';

   do {

      scanf("%c", &character);
      flushKeyboard();
      if (character != 'Y' && character != 'y' && character != 'N' && character != 'n') {
         printf("Only (Y)es or (N)o are acceptable: ");
      }

   } while (character != 'Y' && character != 'y' && character != 'N' && character != 'n');

   if (character == 'Y' || character == 'y') {
      return 1;
   }

   else {
      return 0;
   }
}

int menu(void) {
   int choice;

   printf("1- List all items\n");
   printf("2- Search by SKU\n");
   printf("3- Checkout an item\n");
   printf("4- Stock an item\n");
   printf("5- Add new item or update item\n");
   printf("6- delete item\n");
   printf("7- Search by name\n");
   printf("0- Exit program\n");
   printf("> ");

   choice = getIntLimited(0, 7);

   return choice;
}

void GroceryInventorySystem(void) {
   int validInput = '\0';
   int yesInput = '\0';

   welcome();

   do {
      validInput = menu();

      switch (validInput) {
      case 0:
         printf("Exit the program? (Y)es/(N)o: ");
         yesInput = yes();
         break;

      case 1:
         printf("List Items under construction!\n");
         pause();
         break;


      case 2:
         printf("Search Items under construction!\n");
         pause();
         break;


      case 3:
         printf("Checkout Item under construction!\n");
         pause();
         break;


      case 4:
         printf("Stock Item under construction!\n");
         pause();
         break;


      case 5:
         printf("Add/Update Item under construction!\n");
         pause();
         break;


      case 6:
         printf("Delete Item under construction!\n");
         pause();
         break;


      case 7:
         printf("Search by name under construction!\n");
         pause();
         break;



      }
   } while (yesInput != 1);

}





struct Item {
   double price;
   int sku;
   int isTaxed;
   int quantity;
   int minQuantity;
   char name[21];
};



/* ms2*/
double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int NoOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);

double totalAfterTax(struct Item item) {
   double totalPrice = 0;
   if (item.isTaxed == 0) {
      totalPrice = item.price * item.quantity;
      return totalPrice;
   }

   else if (item.isTaxed == 1) {
      totalPrice = item.price * item.quantity;
      totalPrice = totalPrice + (totalPrice * TAX);
      item.isTaxed = 1;
      return totalPrice;
   }

}

int isLowQuantity(struct Item item) {
   if (item.quantity < item.minQuantity) {
      return 1;
   }

   else {
      return 0;
   }
}

struct Item itemEntry(int sku) {
   double price;
   int isTaxed;
   int quantity;
   int minQuantity;
   char name[21];
   int ret;
   printf("        SKU: %d\n", sku);
   printf("       Name: ");
   scanf("%20[^\n]", &name);
   flushKeyboard();
   printf("      Price: ");
   price = getDouble();
   printf("   Quantity: ");
   quantity = getInt();
   printf("Minimum Qty: ");
   minQuantity = getInt();
   printf("   Is Taxed: ");
   ret = yes();
   if ("ret==0")
   {
      isTaxed = "NO";
   }
   else
      isTaxed = "YES";
};

void displayItem(struct Item item, int linear) {
   double priceInclTax;
   priceInclTax = totalAfterTax(item);
   if (linear == 1) {
      if (item.isTaxed == 1) {
         printf("|%3d|%-20s|%8.2lf|  Yes| %3d | %3d |%12.2lf|", item.sku, item.name, item.price, item.quantity, item.minQuantity, priceInclTax);
      }
      else if (item.isTaxed == 0) {
         printf("|%3d|%-20s|%8.2lf|   No| %3d | %3d |%12.2lf|", item.sku, item.name, item.price, item.quantity, item.minQuantity, priceInclTax);
      }
      if (item.quantity < item.minQuantity)
      {
         printf("***\n");
      }
      else if (item.quantity >= item.minQuantity) {
         printf("\n");
      }
   }
   else {
      printf("        SKU: %d\n", item.sku);
      printf("       Name: %s\n", item.name);
      printf("      Price: %.2lf\n", item.price);
      printf("   Quantity: %d\n", item.quantity);
      printf("Minimum Qty: %d\n", item.minQuantity);
      if (item.isTaxed == 1) {
         printf("   Is Taxed: Yes\n");
      }
      else {
         printf("   Is Taxed: No\n");
      }
      if (item.quantity <= item.minQuantity) {
         printf("WARNING: Quantity low, please order ASAP!!!\n");
      }
   }


}
void listItems(const struct Item item[], int NoOfItems) {
   int i = 0;
   float grandTotal = 0;
   printTitle();
   for (i = 0; i < NoOfItems; i++) {
      printf("%-4d", i + 1);
      displayItem(item[i], 1);
      grandTotal += totalAfterTax(item[i]);
   }
   printFooter(grandTotal);
}
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index) {
   int i;
   int count = 0;
   for (i = 0; i < NoOfRecs; i++) {
      if (sku == item[i].sku) {
         *index = i;
         count = 1;
      }
   }
   return count;
}






/* ms 3 */
#define STOCK 1
#define CHECKOUT 0
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100
void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);

void updateItem(struct Item* itemptr) {
   struct Item update;
   printf("Enter new data: ");
   update = itemEntry(itemptr->sku);
   printf("Overwrite old data? (Y)es/(N)o: ");
   int response = yes();
   if (response == 1) {
      *itemptr = update;
      printf("--==Updated!==-- \n");
   }
   else {
      printf("--==Aborted!==-- \n");
   }
}

void addItem(struct Item item[], int *NoOfRecs, int sku) {
   struct Item add;

   if (*NoOfRecs == MAX_ITEM_NO) {
      printf("Can not add item; Storage FULL! \n");
   }
   else {
      add = itemEntry(sku);
      printf("Add Item? (Y)es/(N)o: ");
      int response = yes();
      if (response == 1) {
         add.sku = sku;
         item[*NoOfRecs] = add;
         *NoOfRecs = *NoOfRecs + 1;
         printf("--==Added==-- \n");
      }
      else {
         printf("--==Aborted==-- \n");
      }
   }
}

void addOrUpdateItem(struct Item item[], int* NoOfRecs) {
   int i;
   printf("Please entre the SKU: ");
   int value = getIntLimited(SKU_MIN, SKU_MAX);
   int find = locateItem(item, *NoOfRecs, value, &i);
   if (find == 1) {
      displayItem(item[i], FORM);
      printf("Item already exists,Update? (Y)es / (N)o: ");
      int response = yes();
      if (response == 1) {
         updateItem(&item[i]);
      }
      else {
         printf("--==Aborted==-- \n");
      }
   }
   else {
      addItem(item, NoOfRecs, value);
   }
}

void adjustQuantity(struct Item item[], int NoOfRecs, int stock) {
   int count;
   int quan;
   printf("Please enter the SKU: ");
   int response = getIntLimited(SKU_MIN, SKU_MAX);
   int found = locateItem(item, NoOfRecs, response, &count);
   if (found == 1) {
      char *value[21];
      displayItem(item[count], FORM);
      if (stock == STOCK) {
         *value = "to stock";
         quan = MAX_QTY - item[count].quantity;
      }
      else if (stock == CHECKOUT) {
         *value = "to checkout";
         quan = item[count].quantity;
      }
      printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", *value, quan);
      int input = getIntLimited(0, quan);
      if (input == 0) {
         printf("--==Aborted==-- \n");
      }
      else {
         if (stock == STOCK) {
            item[count].quantity = item[count].quantity + input;
            printf("--==Stocked==-- \n");
         }
         else if (stock == CHECKOUT) {
            item[count].quantity = item[count].quantity - input;
            printf("--==Checked out!==-- \n");
         }
         if (item[count].quantity <= item[count].minQuantity) {
            printf("Quantity is low,please reorder ASAP!!! \n");
         }
      }
   }
   else {
      printf("SKU not found in storage\n");
   }
}


/* ms 4 */


void saveItem(struct Item item, FILE* dataFile);
int loadItem(struct Item* item, FILE* dataFile);
int saveItems(const struct Item item[], char fileName[], int NoOfRecs);
int loadItems(struct Item item[], char fileName[], int* NoOfRecsPtr);
/*Milestone 4 functions*/
#define MAX_ITEM_NO 500 
#define DATAFILE "test.txt" 
void saveItem(struct Item item, FILE* datafile) {
   fprintf(datafile, "%d,%d,%d,%.2lf,%d,%s\n", item.sku, item.quantity, item.minQuantity, item.price, item.isTaxed, item.name);
}
int loadItem(struct Item* item, FILE* datafile) {
   int return_value = 0;
   if (fscanf(datafile, "%d,%d,%d,%lf,%d,%20[^\n]", &item->sku, &item->quantity, &item->minQuantity, &item->price, &item->isTaxed, item->name) == 6) {
      return_value = 1;
   }
   return return_value;
}
int saveItems(struct Item* item, char fileName[], int NoOfRecs) {
   int ret_value = 1;
   int i;
   FILE *file = NULL;
   file = fopen(fileName, "w");
   if (file != NULL)
   {
      for (i = 0; i<NoOfRecs; i++) {
         saveItem(item[i], file);
      }
      fclose(file);
   }
   else if (file == NULL) {
      ret_value = 0;
   }
   return ret_value;
}
int loadItems(struct Item* item, char fileName[], int * NoOfRecsPtr) {
   int i = 0;
   int end = 2;
   struct Item duplicate;
   FILE *file = NULL;
   file = fopen(fileName, "r");
   if (file == NULL) {
      end = 0;
   }
   else {
      while (loadItem(&duplicate, file)) {
         item[i] = duplicate;
         i++;
         *NoOfRecsPtr = i;
      }
      fclose(file);
   }
   return end;
}
/**************************************************************************
TTTTTTTTT   EEEEEEEE   SSSSSSSS   TTTTTTTTTT   EEEEEEEEE   RRRRRRRR
TT       EE         SS             TT       EE          RR     RR
TT       EEEEEEEE   SSSSSSSS       TT       EEEEEEEEE   RRRRRRRR
TT       EE               SS       TT       EE          RR  RR
TT       EEEEEEEE   SSSSSSSS       TT       EEEEEEEEE   RR    RR
*************************************************************************** */



void prnFile() {
   FILE* tp = fopen("test.txt", "r");
   char ch;
   if (tp) {
      for (; fscanf(tp, "%c", &ch) == 1; putchar(ch));
      fclose(tp);
   }
   else {
      printf("text.txt not found\n");
   }
}
int main(void) {
   int i, n;
   struct Item GI[3] = {
      { 4.4,275,0,10,2,"Royal Gala Apples" },
      { 5.99,386,0,20,4,"Honeydew Melon" },
      { 3.99,240,0,30,5,"Blueberries" },
   };
   struct Item I;
   struct Item IN[3];
   printf("***********Testing saveItem:\n");
   printf("Your saveItem saved the following in test.txt: \n");
   FILE* tp = fopen("test.txt", "w");
   if (tp) {
      for (i = 0; i < 3; i++) saveItem(GI[i], tp);
      fclose(tp);
      prnFile();
   }
   printf("*******************************\nThey have to match the following:\n");
   printf("275,10,2,4.40,0,Royal Gala Apples\n");
   printf("386,20,4,5.99,0,Honeydew Melon\n");
   printf("240,30,5,3.99,0,Blueberries\n");
   printf("***********END Testing saveItem!\n\n\n");
   pause();
   printf("***********Testing loadItem:\n");
   printf("Your loadItem loaded the following from test.txt: \n");
   tp = fopen("test.txt", "r");
   if (tp) {
      for (i = 0; i < 3; i++) {
         loadItem(&I, tp);
         displayItem(I, LINEAR);
      }
      fclose(tp);
      tp = fopen("test.txt", "w");
      fclose(tp);
   }
   printf("*******************************\nThey have to match the following:\n");
   printf("|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|\n");
   printf("|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|\n");
   printf("|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|\n");
   printf("***********END Testing loadItem!\n\n\n");
   pause();
   printf("***********Testing saveItems:\n");
   printf("Your saveItems saved the following in test.txt: \n");
   saveItems(GI, "test.txt", 3);
   prnFile();
   printf("*******************************\nThey have to match the following:\n");
   printf("275,10,2,4.40,0,Royal Gala Apples\n");
   printf("386,20,4,5.99,0,Honeydew Melon\n");
   printf("240,30,5,3.99,0,Blueberries\n");
   printf("***********END Testing saveItems!\n\n\n");
   pause();
   printf("***********Testing loadItems:\n");
   printf("Your loadItems loaded the following from test.txt: \n");
   loadItems(IN, "test.txt", &n);
   for (i = 0; i < n; i++) {
      displayItem(IN[i], LINEAR);
   }
   printf("*******************************\nThey have to match the following:\n");
   printf("|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|\n");
   printf("|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|\n");
   printf("|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|\n");
   printf("***********END Testing loadItems!\n\n\n");
   pause();
   printf("Done!\n");
   return 0;
}
/* End MS4 functions' tester
***************************************************************************
***************************************************************************
***************************************************************************/