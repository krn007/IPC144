/*Name- Karan Shah*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void formatJediPhoneRecord(char formattedRecord[], const char fullName[],
   const char npa[], const char co[], const char number[]);
int isJediMaster(const char name[]);
int main(void) {
   FILE* fp = fopen("starwars_directory.csv", "r");
   char name[31];
   char npa[4];
   char co[4];
   char number[5];
   char edited[45];
   
   if (fp)
   {
      while (fscanf(fp, "%[^,],%s%s%s\n", name, npa, co, number) == 4)
      {
         formatJediPhoneRecord(edited, name, npa, co, number);
         printf("%s\n", edited);
      }
      fclose(fp);
   }
   else {
      printf("File not found!\n");
   }
   return 0;
}
void formatJediPhoneRecord(char formattedRecord[], const char fullName[],
   const char npa[], const char co[], const char number[])
{
   char dot[] = "..";
   char Lbrac[] = " (";
   char Rbrac[] = ") ";
   char dash[] = "-";
   char blank[] = " ";
   char jediMaster[] = " Jedi Master";
   int sp;
   memset(formattedRecord, 0, 45);
   if (strlen(fullName) > 16)
   {
      strncat(formattedRecord, fullName, 14);
      strcat(formattedRecord, dot);
   }
   else
   {
      sp = 16 - strlen(fullName);
      strcat(formattedRecord, fullName);
      int i;
      i = 0;
      while ( i < sp)
      {
         strcat(formattedRecord, blank);
         i++;
      }
   }
   strcat(formattedRecord, Lbrac);
   strcat(formattedRecord, npa);
   strcat(formattedRecord, Rbrac);
   strcat(formattedRecord, co);
   strcat(formattedRecord, dash);
   strcat(formattedRecord, number);
   if (isJediMaster(fullName) == 1)
   {
      strcat(formattedRecord, jediMaster);
   }
}
int isJediMaster(const char name[])
{
   FILE* fp = fopen("jedi_master.txt", "r");
   char master[31];
   if (fp)
   {
      while (fscanf(fp, "%[^\n]\n", master) == 1)
      {
         if (strcmp(name, master) == 0)
         {
            return 1;
            fclose(fp);
         }

      }
      fclose(fp);
      return 0;
   }
   else
   {
      printf("File not found!\n");
   }

}

