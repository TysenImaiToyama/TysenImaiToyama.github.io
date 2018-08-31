/***************************************************************************
//
//    Name: Tysen Imai-Toyama
//    
//    Homework: 1
//    
//    Class: ICS 212
//
//    Instuctor: Ravi Narayan
//    
//    Date: January 18 , 2018
//
//    File: homework1.c
//
//    Description: This file contains the code that will take in an integer
//    and print out a list of its factors
//
****************************************************************************/

#include <stdio.h>

/*******************************************************************
//
//  Functon Name: isDivisible
//
//  Description: Takes two  integers  and checks to see if the first 
//  one is is divisible by the second one
//
//  Parameters: dividend (int) : The dividend number to be divided by the divisor.
//  divisor (int) : The number the dividend is divided by.
//
// Return Values : 0 : The dividend is a whole number that is a factor
//                                 of the divisor
//              -1 : The divisor is not a possible factor.
//
*********************************************************************/

int isDivisible(int dividend, int divisor)
{
    int retVal;
    if (dividend % divisor != 0)
    {
        retVal = -1;
    }
    else if (dividend % divisor == 0)
    {
        retVal = 0;
    }
    return retVal;
}

int main(void)
{
    int num;
    int letters;
    int aboveZero = -1;
    char charDump;
    int factor[20];
    int i;
    int z;
    int size = 0;
    printf("Enter an integer greater than zero.\n ");
    
    /*While loop to detect and erase wrong inputs*/  

    while (aboveZero == -1)    
    {
        while((letters = scanf("%d", &num)) != 1)
        {
            if (letters != 1)
            {
                charDump = getchar();
                printf("\n%c removed! Enter an integer greater than zero\n", charDump);
            }
        }
        if (num > 0)
        {
            aboveZero = 1;
        }
        else
        {
            printf("\nERROR : Integer %d is not greater than zero!\nEnter an integer greater than zero!\n", num);
        }
    }

    /*Loop to fill the array with factors*/

    for (i = 1; i < num + 1; i++)
    {
        if (isDivisible(num, i) == 0)
        {
        size++;
        factor[size] = num/(num/i);
        }       
    }

    /*Prints factors*/

    printf("\nNUMBER : %d\n", num);
    printf("\t\tNo.\t\tFactor\n");
    for (z = 1; z < size + 1; z++)
    {
        printf("\t\t %d\t\t %d\n", z, factor[z]);
    }
    return 0;
}
