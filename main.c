/*
 * This program will convert decimal, binary and hex values.
 * If user enters a decimal num --> binary and hex are computed
 * If user enters a binary num --> decimal and hex are computed
 * If user enters a hex num --> decimal and binary are computed
 * GTK+ w/ Glade GUI will be added later. 
 */


#include <stdio.h>
#include <math.h>
#include "decBinaryConvert.h"


int main()
{
	   /* int resume used for do-while loop */
       	   int resume = 0;
   
   do  {

	   /* Variables for user operations */

   
	   /* This value will be provided by the user */
	   int startValue = 0;
           /* This variable facilitates user choice for base */
	   int base = 0;

           /* Variables for the temporary storage of converted Values */
	   int* binaryPtr = NULL;				
	   int* hexPtr = NULL;
	   char* charPtr = NULL;		
	   int* decPtr = NULL;			
	   int decValue = 0;		
	   int* intPtr = NULL;

	   /* User inputs starting value and is asked its base */
	   printf("What base is the number you want to convert in? Enter 2, 10 or 16\n");
	   scanf("%d", &base);
	   printf("\n"); 

	   /* Switch statement to determine which conversions occur */
	   switch(base)  {
		   case 2 :
			   caseTwoPrompt();
			   decPtr = getBinaryArray();
			   decValue = getBinaryDecValue(decPtr);
			   hexPtr = getDecHexArray(decValue); 
			   charPtr = convertIntChar(hexPtr);
			   printCaseTwoResults(charPtr, decValue);
			   break;
		   case 10 :
			   startValue = caseTenPrompt();
			   binaryPtr = getDecBinaryArray(startValue);
			   hexPtr = getDecHexArray(startValue); 
			   charPtr = convertIntChar(hexPtr);
			   printCaseTenResults(binaryPtr, charPtr);
			   break;
		   case 16 :
			   caseSixteenPrompt();  
			   charPtr = getHexArray();
			   intPtr = convertCharInt(charPtr);
			   decValue = getHexDecValue(intPtr);  
			   binaryPtr = getDecBinaryArray(decValue);
			   printCaseSixteenResults(decValue, binaryPtr);  
			   break;
		   default :
			   printf("Try Again...\n");

	   } // end of switch statement

	printf("\nWould you like to convert more values? Enter 1 for Yes or 0 for No\n");
	scanf("%d", &resume);
	printf("\n");

	} while (resume == 1);  // end of do-while loop

} // end of main method


