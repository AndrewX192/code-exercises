/* 
 * Finds prime numbers.
 * 
 * File:   findPrimes.c
 * Author: Andrew Sorensen
 */

#include <stdio.h>
#include <stdlib.h>

int *findPrimes(int max);

/*
 * The main method.
 */
int main(int argc, char** argv) {
    int max = 15;
    
    if (argc > 1) {
        max = atof(argv[1]);
    }

    int * primes = findPrimes(max);
    
    int i = 0;
    while (primes[i]) {
        printf("%d ", primes[i]);
        i++;
    }
    
    printf("\n");
    
    return EXIT_SUCCESS;
}

/**
 * Finds all the prime numbers given.
 * Implemented using the Sieve of Eratosthenes algorithm. 
 * 
 * @param max the upper limit on searching.
 * 
 * @return  an array of primes.
 */
int *findPrimes(int max) {
    int* numbers = malloc(sizeof(int) * max);
    int* primes  = malloc(sizeof(int) * max);

    unsigned int i, j = 0;
    for (i = 2; i < max; i++) {
        numbers[i] = 1;
    }

    for (i = 2; i < max; i++) {
        for (j = i; i * j < max; j++) {
            numbers[i * j] = 0;
        }
    }

    for (i = 2, j = 0; i < max; i++) {
        if (numbers[i] == 1) {
            primes[j] = i;
            j++;
        }
    }

    return primes;
}
