#include <stdio.h>
#include <math.h>
#include "decBinaryConvert.h"

/*
 * Functions used for case 2 (user enters binary) ******************
 */



/*	FUNCTION PRINTS INTRODUCTION PROMPT 
 *	IF CASE 2 (BINARY IS SELECTED)
 *
 * Simple program to print introductary prompt
 */ 
void caseTwoPrompt()  {
	
	printf("Converting to Decimal...\n");
	printf("Converting to Hex...\n\n");

}



/*	FUNCTION COLLECTS BINARY ARRAY FROM USER
 *
 * Function is intended to collect a binary array from the user. 
 * Function will be used whenever a user starts in BASE 2.
 */
int* getBinaryArray ()  {
	
	int index;
	static int userBinaryArray[8];
	int userValue = 0;
	printf("Enter your binary value now, (max 11111111)\n");
	printf("Note: Enter 1 or 0 and Enter for each digit\n");
        for (index = 0; index < 8; index++)  {
		scanf("%d", &userValue);
		userBinaryArray[index] = userValue;
	}
	printf("\n");


	return userBinaryArray;

}



/*	FUNTION CONVERTS 2 -> 10
 *
 * Function will convert a binary value (provided by user)
 * that is stored within an array and convert it to a decimal
 * (Base 10) value. Decimal value is then returned to main. 
 * One param:
 *	1. int* decPtr	<-- ptr is the base address to the 
 *			    array to be converted
 */
int getBinaryDecValue (int* decPtr)  {

	int placeHolderArray[] = {128,64,32,16,8,4,2,1};
	int decValue = 0;
	int temp = 0;
	int index;


	for (index = 0; index < 8; index++)  {
		temp = decPtr[index];
		if (temp == 1)  
			decValue += placeHolderArray[index];
	}


	return decValue;
}




/*       FUCTION CONVERTS 10 -> 16
 *
 * Function will intake the Decimal value you wish to convert
 * as param (int startValue) and convert it to an int array
 * (decHexValue[]). Then, function will return a ptr to the 
 * base of the array (decHexValue).
 * One param:
 *	1. int startValue	<-- the num entered by user
 */
int* getDecHexArray (int startValue)   {

	int dividend = startValue;
	/* for the decimal value to be converted to hex, 
	 * the divisor must be set to 16 and it must divide the 
	 * dividend
	 */
	int divisor = 16;
	int remainder = 0;
	
	/***Initialize Array for converted binary number*/
	static int decHexValue[2];
	/*initialize all array values according to SIZE*/
	for (int a = 0; a < 2; a++)  {
		decHexValue[a] = 0;
	}

   
	/** decimal to hex processing**/
	for (int b = 1; b >= 0; b--)  {
		remainder = dividend % divisor;
		decHexValue[b] = remainder;
		dividend = dividend / divisor;
	}


	return decHexValue;

}



/*      FUNCTION TURNS INT ARRAY INTO CHAR ARRAY
 *
 * function will intake int ptr and convert it to hex array. Hex will be 
 * returned as a char ptr. 
 * One param:
 *	1. int* ptr	<-- ptr is the base address to an array
 *			    that needs to be converted to Hex Values
 */
char* convertIntChar(int* ptr)  {

	char intToHexLookupArray[] = {'0','1','2','3','4','5','6','7','8',
		                      '9','A','B','C','D','E','F'};
	static char charHexValue[2];
	int temp = 0;
	int i = 0;
	
	for (i = 0; i < 2; i++)  {
		temp = ptr[i];
		charHexValue[i] = intToHexLookupArray[temp];
	}
	
	return charHexValue;

}



/*	FUNCTION PRINTS RESULTS WHEN BINARY
 *	IS SELECTED
 * 
 * Function prints the Base 10 (Decimal) and Hex value
 * equivalents of the number the user selects.
 * Two params:
 *	1. char* charPtr
 *	2. int decValue
 */
void printCaseTwoResults(char* charPtr, int decValue)  {
	
	printf("Results... \n");
	printf("Decimal (Base 10): %d\n", decValue);
	printCharArray(charPtr, 2);

}



/*
 * Functions for case 10 (user enters decimal) **********************
 */



/*	FUNCTION PROMPTS USER FOR DECIMAL VALUE
 *	AND PRINTS SIMPLE MESSAGE.
 *	FUNCTION ALSO RETURNS THE USERS VALUE TO MAIN
 *
 * Function prompts the user for a Decimal (Base 10) value
 * and collects the response. Afterwards, simple prompt is printed.
 * Users response returned to main. 
 */
int caseTenPrompt()  {
		   
	int userNum = 0;
	printf("Enter your decimal (Base 10) value now.\n");
        scanf("%d", &userNum);
	printf("\n");
	printf("Converting to Binary...\n");
        printf("Converting to Hex...\n");
	printf("\n");


	return userNum;

}



/*     FUNCTION CONVERTS 10 -> 2
 *
 * Function will convert a decimal value (int startValue param) 
 * into a Binary Value (int array). A pointer to the start
 * of the int array (decBinaryValue) is returned.
 * One param:
 *	1. int startValue	<-- the num entered by user
 */
int* getDecBinaryArray (int startValue)  {

	int dividend = startValue;
	/* for the decimal value to be converted to binary
	 * the divisor must be set to 2 and it must divide the 
	 * dividend
	 */
	int divisor = 2;
	int remainder = 0;
	
	/***Initialize Array for converted binary number*/
	static int decBinaryValue[8];
	/*initialize all array values according to SIZE*/
	for (int a = 0; a < 8; a++)  {
		decBinaryValue[a] = 0;
	}
   
	/** decimal to binary processing**/
	for (int b = 7; b >= 0; b--)  {
		remainder = dividend % divisor;
		decBinaryValue[b] = remainder;
		dividend = dividend / divisor;
	}


	return decBinaryValue;
}


/* getDecHexArray() defined within case 2 functionality */



/* convertIntChar() defined within case 2 functionality */




/*	FUNCTION PRINTS CONVERTED RESULTS IF BASE 10
 *	IS SELECTED
 *
 * Function will display the values that were converted 
 * to both Binary and Hex that the user selected. 
 * Two params:
 *	1. int* binaryPtr	<-- ptr to the base address of 
 *				    binary array to be printed
 *	2. char* charPtr	<-- ptr to the base address of
 *				    char array to be printed
 */
void printCaseTenResults(int* binaryPtr, char* charPtr)  {
	
	printf("Results... \n");
	printIntArray(binaryPtr, 8);
	printCharArray(charPtr, 2);

}




/*
 *   Functions are for case 16 (user enters hex)  *************
 */


/*	PRINTS SIMPLE INTRODUCTARY PROMPT
 *	IF USER SELECTS BASE 16
 */
void caseSixteenPrompt()  {
	
	printf("Converting to Decimal...\n");
	printf("Converting to Binary...\n\n");

}


/*	FUNCTION COLLECTS CHAR ARRAY OF USER INPUT
 *
 * Function getHexArray() will collect a hex array from the 
 * user. Once collected, the base address of the array (ptr) is 
 * returned back.
 */
char* getHexArray ()  {
	
	static char userHexArray[2];
	printf("Enter your hex values now, (ex. AE, limit 2 characters)\n");
	printf("Note: Enter two Hex characters and press Enter\n");
	scanf("%s", userHexArray);
	printf("\n");

	return userHexArray;

}



/*	FUNCTION WILL CONVERT HEX ARRAY 
 *	INTO AN INT ARRAY 
 *	EX: A,E --> 10,15
 *
 * Function will convert the array of Hex values into an
 * arry of int values. Array of ints used for conversion 
 * into a decimal (base 10) value. 
 * One param:
 *	1. char* ptr		<-- ptr to the base address
 *				    of the hex array.
 */ 
int* convertCharInt(char* ptr)  {

	int hexToIntLookupArray[] = {'0','1','2','3','4','5','6','7','8',
		                     '9','A','B','C','D','E','F'};
	static int intHexValue[2];
	char temp; 
	
	for (int i = 0; i < 2; i++)  {
		temp = ptr[i];

		for (int j = 0; j < 16; j++)  {
			if (temp == hexToIntLookupArray[j])  
				intHexValue[i] = j;
		}
	}
	
	return intHexValue;

}



/*	TURNS ARRAY OF INT VALUES TO
 *	AN INT (BASE 10)
 *
 * Function will convert array of values 
 * (vales are base 10 equivalent of char values)
 * and convert them to a base 10 value. Base 10
 * value returned back to main. 
 * One param:
 *	1. int* intPtr		<-- ptr to base address
 *				    of array of ints
 */
int getHexDecValue(int* intPtr)  {

	int decimalValue = 0;
	int power = 1;
	int tempValue = 0;
	int baseHex = 16;

	for (int i = 0; i < 2; i++)  {
		tempValue = intPtr[i];
		decimalValue += tempValue * pow(baseHex, power);
		power--;
	}

	return decimalValue;

}


/* getDecBinaryArray() function defined case 10 functionality */




/*	PRINTS BASE 16 RESULTS
 *
 * Function will print the results of conversions if the 
 * user selects base 16. Those conversions are:
 * base 16 --> base 10
 * base 16 --> base 2
 * Two params:
 *	1. int decValue		<-- int value in base 10
 *	2. int* binaryPtr	<-- base address of an array of binary
 */
void printCaseSixteenResults(int decValue, int* binaryPtr)  {
	
	printf("Results... \n");
	printf("Decimal (Base 10): %d\n", decValue);
	printIntArray(binaryPtr, 8);

}



/*
 *   Following functions called within other functions  *************
 */




/*      FUNCTION PRINTS CONTENTS OF INTEGER ARRAY
 *
 * Function will print the contents of an integer array.
 * The function printIntArray must include:
 * 	1. ptr to the int array 
 * 	2. size of the array desired 
 * as params (int* ptr, int size).
 */
void printIntArray (int* ptr, int size)  {

	printf("Binary: ");
	for (int c = 0; c < size; c++)  {
		printf("%d" , *(ptr + c));
	}
	printf("\n");
}



/*	FUNCTION PRINTS CONTENTS OF CHAR ARRAY
 *
 * Function will print contents of char array. 2 params are:
 *	1. the char ptr      <- its contents printed
 *	2. int size		how big the printed array will be
*/
void printCharArray (char* ptr, int size)  {

	printf("Hex: ");
	for (int c = 0; c < size; c++)  {
		printf("%c" , *(ptr + c));
	}
	printf("\n");
}



