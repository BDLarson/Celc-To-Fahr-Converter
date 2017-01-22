/******************************************************************************
//
// NAME:          Blake Larson
//
// HOMEWORK:      1
//
// CLASS:         ICS 212
//
// INSTRUCTOR:    Ravi Narayan
//
// DATE:          August 28, 2016
//
// FILE:          Homework1.c
//
// DESCRIPTION:   This file contains the user-interface for Homework 1 - the
//                temperature conversion program
//
*****************************************************************************/

#include <stdio.h>

float convertFtoC(int);
int getUserInput();
int roundUp(int);
void getTempTable(int);

int main()
{
  getUserInput();
}

/******************************************************************************
// Function name: getUserInput
//
// DESCRIPTION:   A user-interface funtion that takes an integer input, else
//                gives an error till one is provided
//
// Parameters:    None needed as its purely user-input
//
// Return values: The user's inputed integer
//
*****************************************************************************/

int getUserInput()
{
  int inputValue;
  int validValue = 0;
  char temp[100];

  printf("This program allows you to convert from Celsius C to Fahrenheit F\n\n");

  while(validValue == 0)
  {
    printf("Please enter a maximum temperature in Celsius (C): ");
    if(scanf("%d", &inputValue) != 1) //scanf returns the number of read items
    {
      fgets(temp, 100, stdin);	
      printf("Please enter a valid integer, not a string or character! \n");
      //validValue is still 0
    } else {
      if (inputValue <= 0)
      {
        printf("Only values greater than zero are valid inputs! \n");
        //validValue is still 0
      } else {
        validValue = 1;
      }
    }
  }

  getTempTable(roundUp(inputValue));
  return inputValue;
}


/******************************************************************************
// Function name: convertCtoF
//
// DESCRIPTION:   A function that takes in an integer value, and converts it
//                to a fahrenheit degree instead
//
// Parameters:    celsius(int): The temperature in celsius that needs to be
//                converted to fahrenheit
//
// Return values: fahrenheit(float): The temperature in fahrenheit
//
*****************************************************************************/

float convertCtoF(int celsius)
{
  float fahrenheit = 0.0;
  fahrenheit = ((celsius * (9.0/5.0)) + 32.0);
  return fahrenheit; 
}

/******************************************************************************
// Function name: getTempTable
//
// DESCRIPTION:   A funtion that takes an integer input as the max value, then
//                generates a table of all temperatures less than it with
//                conversions to fahrenheit
//
// Parameters:    inputValue(int): The max value that the table will generate
//
// Return values: Nothing except a printed table
//
*****************************************************************************/

void getTempTable(inputValue)
{
  float outputValue = 0.0;
  printf("\nTemperature in C          Temperature in F\n");
  while(outputValue <= inputValue)
  {
    printf("%16.0f %25.2f\n", outputValue, 
	convertCtoF(outputValue));
    outputValue = outputValue + 5.0; //Increment the counter by 5 degrees
  }

}

/******************************************************************************
// Function name: roundUp
//
// DESCRIPTION:   A function that takes in an integer value; if the value is a
//                multiple of 5 then it is left alone, otherwise the remainder
//                is added to its original value
//
// Parameters:    inputValue(int): The designated number to check for
//                multiplicity of 5
//
// Return values: setNumber(int): the rounded number or else the same input
//
*****************************************************************************/

int roundUp(inputValue)
{
  int setNumber;
  int tempNumber = inputValue;

  if (tempNumber % 5 == 0)
  {
    setNumber = tempNumber;
  } else {
    setNumber = tempNumber + (5 - (tempNumber % 5));
  }
  return setNumber;
}
