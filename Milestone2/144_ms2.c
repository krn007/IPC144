/*Name - Karan Shah*/
#include <stdio.h>
#include <stdlib.h>
#define LINEAR 1
#define FORM 0
const double TAX = 0.13;
#define TEXTA "SKU"
#define TEXTB "Name"
#define TEXTC "Price"
#define TEXTD "Quantity"
#define TEXTE "Minimum Qty"
#define TEXTF "Is Taxed"

/* ms1*/
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void pause(void);
void flushKeyboard(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
int yes(void);

/* ms2*/
struct Item
{
   double price;
   int sku;
   int isTaxed;
   int quantity;
   int minQuantity;
   char name[21];
};


double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int NoOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);




int main()
{
   struct Item I[21] =
   {
      { 4.4,275,0,10,2,"Royal Apples" },
      { 5.99,386,0,20,4,"Watermelon" },
      { 3.99,240,0,30,5,"Blueberries" },
      { 10.56,916,0,20,3,"Seedless Grapes" },
      { 2.5,385,0,5,2,"Pomegranate" },
      { 0.44,495,0,100,30,"Banana" },
      { 0.5,316,0,123,10,"Kiwifruit" },
      { 4.49,355,1,20,5,"Chicken Alfredo" },
      { 5.49,846,1,3,5,"Veal Parmigiana" },
      { 5.29,359,1,40,5,"Beffsteak Pie" },
      { 4.79,127,1,30,3,"Curry Checken" },
      { 16.99,238,1,10,2,"Tide Detergent" },
      { 10.49,324,1,40,5,"Tide Liq. Pods" },
      { 10.99,491,1,50,5,"Tide Powder Det." },
      { 3.69,538,1,1,5,"Lays Chips S&V" },
      { 3.29,649,1,15,5,"Joe Org Chips" },
      { 1.79,731,1,100,10,"Allen's Apple Juice" },
      { 6.69,984,1,30,3,"Coke 24 Pack" },
      { 7.29,350,1,50,5,"Nestea 24 Pack" },
      { 6.49,835,1,20,2,"7up 24 pack" }
   };
   double val;
   int ival;
   int searchIndex;
   val = totalAfterTax(I[0]);
   printf("totalAfterTax:\n"
      "    yours=%lf\n"
      "program's=44.000000\n", val);
   val = totalAfterTax(I[7]);
   printf("totalAfterTax:\n"
      "    yours=%lf\n"
      "program's=101.474000\n", val);
   ival = isLowQuantity(I[0]);
   printf("isLowQuantity:\n"
      "    yours=%d\n"
      "program's=0\n", ival);
   ival = isLowQuantity(I[14]);
   printf("isLowQuantity:\n"
      "    yours=%d\n"
      "program's=1\n", ival);
   pause();

   printf("itemEntry, enter the following values:\n");
   printf("        SKU: 999\n"
      "       Name: Red Apples\n"
      "      Price: 4.54\n"
      "   Quantity: 50\n"
      "Minimum Qty: 5\n"
      "   Is Taxed: n\n");
   printf("Enter the values:\n");
   I[20] = itemEntry(999);
   printf("displayItem, Linear:\nYours: ");//note
   displayItem(I[20], LINEAR);
   printf(" Prog: |999|Red Apples          |    4.54|   No|  50 |   5 |      227.00|\n");
   printf("displayItem, Form:\nYours:\n");
   displayItem(I[20], FORM);
   printf("Programs: \n");
   printf("        SKU: 999\n"
      "       Name: Red Apples\n"
      "      Price: 4.54\n"
      "   Quantity: 50\n"
      "Minimum Qty: 5\n"
      "   Is Taxed: No\n");
   I[20].quantity = 2;
   I[20].isTaxed = 1;
   pause();

   printf("displayItem, Linear with low value and taxed:\nYours: ");
   displayItem(I[20], LINEAR);
   printf(" Prog: |999|Red Apples          |    4.54|  Yes|   2 |   5 |       10.26|***\n");
   printf("displayItem, Form with low value:\nYours:\n");
   displayItem(I[20], FORM);
   printf("Programs: \n");
   printf("        SKU: 999\n"
      "       Name: Red Apples\n"
      "      Price: 4.54\n"
      "   Quantity: 2\n"
      "Minimum Qty: 5\n"
      "   Is Taxed: Yes\n"
      "WARNING: Quantity low, please order ASAP!!!\n");
   //pause();

   printf("Listing Items: \n");
   listItems(I, 21);
   pause();
   printf("Locate Item, successful search:\n");
   printf("program: Found the item 999 at index: 20\n");
   printf("  Yours: ");
   if (locateItem(I, 21, 999, &searchIndex)) {
      printf("Found the item 999 at index: %d\n", searchIndex);
   }
   else {
      printf("No item with the sku 999 is in the array!\n");
   }

   printf("Locae Item, unsuccessful search:\n");
   printf("Progam: No item with the sku 732 is in the array!\n");
   printf(" Yours: ");
   if (locateItem(I, 21, 732, &searchIndex)) {
      printf("Found the item at index: %d\n", searchIndex);
   }
   else {
      printf("No item with the sku 732 is in the array!\n");
   }
   pause();
   return 0;
}
//MILESTONE 1
void welcome(void)
{
   printf("---=== Grocery Inventory System ===---");
   printf("\n");
}
void printTitle(void)
{
   printf("Row |SKU| Name               | Price  |Taxed| Qty.| Min |    Total   |Atn");
   printf("\n");
   printf("----+---+--------------------+--------+-----+-----+-----+------------+---");
   printf("\n");
}
void printFooter(double grandTotal)
{
   printf("--------------------------------------------------------+-----------------");
   if (grandTotal > 0)
      printf("                                                                                         Grand Total: | %12.2lf", grandTotal);
   printf("\n");
}
void flushKeyboard(void)
{
   char c;
   while ((c = getchar()) != '\n' && c != EOF) {}
}
void pause(void)
{
   printf("Press <ENTER> to continue...");
   flushKeyboard();
}
int getInt(void)
{
   int iVal = 0;
   char c = 'x';
   while (c != '\n')
   {
      scanf("%d%c", &iVal, &c);
      if (c != '\n')
      {
         flushKeyboard();
         printf("Invalid interger, please try again: ");
      }
   }

   return iVal;
}
int getIntLimited(int lowerLimit, int upperLimit)
{
   int iVal = 0;
   iVal = getInt();
   while (iVal < lowerLimit || iVal > upperLimit)
   {
      printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
      iVal = getInt();
   }
   return iVal;
}
double getDouble(void)
{
   double dVal = 0;
   char c = 'x';
   while (c != '\n')
   {
      scanf("%lf%c", &dVal, &c);
      if (c != '\n')
      {
         flushKeyboard();
         printf("Invalid number, please try again: ");
      }
   }

   return dVal;
}
double getDoubleLimited(double lowerLimit, double upperLimit)
{
   double dVal;
   dVal = getDouble();
   while (dVal < lowerLimit || dVal > upperLimit)
   {
      printf("Invalid value, %lf < value < %lf: ", lowerLimit, upperLimit);
      dVal = getDouble();
   }
   return dVal;
}

int yes(void)
{
   char sel[2];
   scanf("%s", &sel);
   flushKeyboard();
   while (!(sel[0] == 'y' || sel[0] == 'Y' || sel[0] == 'n' || sel[0] == 'N'))
   {
      printf("Only (Y)es or (N)o are acceptable: ");
      scanf("%s", &sel);
   }

   if (sel[0] == 'n' || sel[0] == 'N')
      return 0;
   else
      return 1;
}
void GroceryInventorySystem(void)
{
   int usrSel;
   int test = 0, end = 0;
   welcome();
   printf("\n");
   do
   {
      printf("1- List all items\n");
      printf("2- Search by SKU\n");
      printf("3- Checkout an item\n");
      printf("4- Stock an item\n");
      printf("5- Add new item or update item\n");
      printf("6- delete item\n");
      printf("7- Search by name\n");
      printf("0- Exit program\n");
      printf("> ");
      scanf("%d", &usrSel);
      if (usrSel <0 || usrSel >7)
      {
         printf("Invalid value, 0 < value < 7: ");
         scanf("%d", &usrSel);
         test++;
      }
      switch (usrSel)
      {
      case 0:

         printf("Exit the program? (Y)es/(N)o): ");
         int t;
         t = yes();
         if (t == 1)
            end = 1;
         break;
      case 1:
         printf("List Items under construction!\n");
         flushKeyboard();
         pause();
         break;
      case 2:
         printf("Search Items under construction!\n");
         flushKeyboard();
         pause();
         break;
      case 3:
         printf("Checkout Item under construction!\n");
         flushKeyboard();
         pause();
         break;
      case 4:
         printf("Stock Item under construction!\n");
         flushKeyboard();
         pause();
         break;
      case 5:
         printf("Add/Update Item under construction!\n");
         flushKeyboard();
         pause();
         break;
      case 6:
         printf("Delete Item under construction!\n");
         flushKeyboard();
         pause();
         break;
      case 7:
         printf("Search by name under construction!\n");
         flushKeyboard();
         pause();
         break;
      }
   } while (end == 0);

}
//MILESTONE 2
double totalAfterTax(struct Item item)
{
   double ttlAfterTax, tax;
   if (item.isTaxed == 1)
   {
      tax = item.price * TAX;
      ttlAfterTax = (tax + item.price) * item.quantity;
   }
   else
   {
      ttlAfterTax = item.price * item.quantity;
   }

   return ttlAfterTax;
}
int isLowQuantity(struct Item item)
{
   int low;
   if (item.quantity < item.minQuantity)
      low = 1;
   else
      low = 0;
   return low;
}
struct Item itemEntry(int sku)
{
   struct Item itemEntry;
   itemEntry.sku = sku;
   printf("SKU: %d", sku);
   printf("\n");
   printf("Name: ");
   scanf("%20[^\n]", itemEntry.name);
   flushKeyboard();
   printf("Price: ");
   itemEntry.price = getDouble();
   printf("Quantity: ");
   itemEntry.quantity = getInt();
   printf("Minimun Qty: ");
   itemEntry.minQuantity = getInt();
   printf("Is Taxed: ");
   itemEntry.isTaxed = yes();

   return itemEntry;
}
void displayItem(struct Item item, int linear)
{
   double ttlAfterTax, tax;//TOTAL COST FUNCTION
   if (item.isTaxed == 1)
   {
      tax = item.price * TAX;
      ttlAfterTax = (tax + item.price) * item.quantity;
   }
   else
   {
      ttlAfterTax = item.price * item.quantity;
   }

   int low;//LOW QUANTITY STARS***
   if (item.quantity < item.minQuantity)
      low = 1;
   else
      low = 0;

   if (linear == 1)
   {
      printf("|%d|%-20s|%8.2lf| %4s| %3d |%4d |%12.2lf|%s", item.sku, item.name, item.price, (item.isTaxed == LINEAR ? "Yes" : "No"), item.quantity, item.minQuantity, ttlAfterTax, (low == 1 ? "***" : ""));
      printf("\n");
   }

   else
   {
      printf("%11s: %d", TEXTA, item.sku); printf("\n");
      printf("%11s: %s", TEXTB, item.name); printf("\n");
      printf("%11s: %.2lf", TEXTC, item.price); printf("\n");
      printf("%11s: %d", TEXTD, item.quantity); printf("\n");
      printf("%11s: %d", TEXTE, item.minQuantity); printf("\n");
      printf("%11s: %s", TEXTF, (item.isTaxed == LINEAR ? "Yes" : "No")); printf("\n");
      if (low == 1)
         printf("WARNING: Quantity low, please order ASAP!!!");
      printf("\n");
   }

}
void listItems(const struct Item item[], int NoOfItems)
{
   int count = 0;
   double gTotal = 0;
   printTitle();
   while (count < NoOfItems)
   {
      gTotal = gTotal + totalAfterTax(item[count]);
      printf("%4d", count + 1);
      displayItem(item[count], LINEAR);
      count++;
   }
   printFooter(gTotal);
}
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index)
{
   int count = 0, temp = 0;
   while (count < NoOfRecs)
   {
      //printf("\nsku at index: %d is: %d", count, item[count].sku);
      if (item[count].sku == sku)
      {
         *index = count;
         temp = 1;

      }

      count++;
   }
   return temp;
}


