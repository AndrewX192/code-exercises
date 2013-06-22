/* 
 * Reverses a string.
 * 
 * File:   reverseString.c
 * Author: Andrew Sorensen
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Prototype for reversing a string.
 * 
 * @param string
 * @param result
 * 
 * @return 
 */
int reverseString(char* string, char* result, int length);

int arrayLen(const char* array);

/*
 * The main method.
 */
int main(int argc, char** argv) {
    char* input;

    if (argc < 2) {
        input = "Hello World!";
    } else {
        input = argv[1];
    }
    
    int length = arrayLen(input);
    char result[length];
    
    reverseString(input, result, length);
    
    printf("%s\n", result);

    return (EXIT_SUCCESS);
}

/**
 * Returns the length of an array in O(n) time.
 * 
 * @param array
 * 
 * @return the size.
 */
int arrayLen(const char* array) {
    int size = 0;
    while (array[size])  {
        size++;
    }
    return size;
}


/**
 * Reverses a string.
 * 
 * @param input the string to reverse.
 * @param result the reversed string.
 * 
 * @return whether or not it worked.
 */
int reverseString(char* input, char* result, int length) {
    int i = 0;
    
    while (input[i] != '\0') {
        result[length - 1 - i] = input[i];
        i++;
    }
    
    result[length] = '\0';
    
    return 0;
}
