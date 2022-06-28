/*
Author:     Billy Gene Ridgeway
Purpose:    Learn about memory allocation using malloc and sizeof in C.
Date:       June 27th. 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Very simple allocation of memory and changing something in the newly allocated memory.

int main()
{
    char* s;            // Create a char pointer to an address in memory.
    int stringsize;

    stringsize = sizeof("hello");                           // Initialize the variable stringsize to the size of "hello".
                                                            // Sizeof is an operator that calculates the size of the data, variable, array or structure placed between the parenthese.
                                                            // The value returned is an integer representing the number of bytes needed to store the object.
    printf("The size of \"hello\" is: %d\n", stringsize);   // Stringsize will be 6 because it counts the null character.

    s = (char*)malloc(stringsize);  // Malloc will allocate the number of bytes stored in "stringsize" to char pointer 's'.
                                    // Notice the cast (char*)which is required to cast the generic pointer returned by "malloc"
                                    // to the specific pointer type pointed to char.
    if(s == NULL)                   // Checks to see if the first element in string 's' is NULL.
    {
        printf("Malloc failed!\n");
        exit(0);
    }

    // Now copy the string into the newly allocated memory.
    strncpy(s, "hello", stringsize);    // Copies a string into an array.
                                        // 1st. argument is the array to copy into.
                                        // 2nd. argument is the source array or the string you want to copy into the array.
                                        // 3rd. argument is the number of characters to be coppied.

    // Now change the first character( Just to show that we can ).
    printf("s is: %s\n", s);
    s[0] = 'c';                         // Changes the first character in the string to 'c'.
    printf("s is now: %s\n", s);

    return 0;
}
