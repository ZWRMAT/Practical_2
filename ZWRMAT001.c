#include <stdio.h>
#include <math.h>
#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Mathew Zwarts"
#define YEAR "2022"

void main(){
    printf("*****************************\n");
    printf(" %s\n", TITLE);
    printf(" Written by: %s\n", AUTHOR);
    printf(" Date: %s\n", YEAR);
    printf("*****************************\n");

    int decimalnum=0;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalnum);

    //Continuously prompts for new inputs until a negative number is inputted//
    while(decimalnum>=0){
        printf("The number you entered is %d\n", decimalnum);
        int rad=0;
        printf("Enter a radix for the converter between 2 and 16: ");
        scanf("%d", &rad);
        printf("The radix you have entered is %d\n", rad);

        double log2=0;
        log2 = log(decimalnum)/log(2);
        printf("The log2 of the number is %.2f\n", log2);

        int quotient=0;
        quotient = decimalnum/rad;
        printf("The integer result of the number divided by %d is %d\n", rad, quotient);

        int rem=0;
        rem = decimalnum%rad;
        printf("The remainder is %d\n", rem);

        printf("The radix-%d value is ", rad);

        //Calls a function to convert the given decimal number into radix-i//
        Dec2Radix(decimalnum, rad);

        //Promts user to enter a new input - determines if while loop should continue//
        printf("\nEnter a decimal number: ");
        scanf("%d", &decimalnum);
    }
    printf("EXIT");
}

void Dec2Radix(int decValue, int radValue){
    //determine length of output//
    int len = ceil(log(decValue)/log(radValue));

    //checks if len is a whole integer value, and adds 1 to len if it is//
    float lenfloat = log(decValue)/log(radValue);
    if(len = lenfloat){len += 1;}

    //Solves error when input is 0 or 1//
    if(decValue < 2){len = 1;}

    //Create int type array to store remainders//
    int results[len];
    int rem = 0;
    int quotient = decValue;

    //Inserts the remainder values into an array called rem//
    for(int i=0; i<len; i++){
        rem = quotient%radValue;
        results[i] = rem;
        quotient = ceil(quotient/radValue);
    }
    for(int i=len; i>0; i--){
        //Prints the elements of the array rem in reverse order according to their ASCII hex representation//
        printf("%X", results[i-1]);
    }
}
