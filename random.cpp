#include "random.hpp"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void random_seed(int seed){                         //generate a seed for a psuedo-random generator

    if(seed > 0){                                   //if argument is a greater than zero,
        srand(seed);                                //use argument to seed psuedo-random generator
    }
    else if(seed == 0){                             //if value is zero,
        srand(time(NULL));                          //use time to seed psuedo-random generator
    }
    else{
        printf("INVALID SEED VALUE: %d", seed);     //if seed value is not greater than or equal to zero,
        exit(EXIT_FAILURE);                         //exit program
    }
    return;
}

double random_exponential(double mean){             //generates random numbers that are exponentially distributed
    double uni = (double)rand() / RAND_MAX;         //first we generate a uniformly distributed random number between 0 and 1
    double lambda = 1/mean;                         //next we define lambda as 1 divided by given mean argument
    double randomNum = (-log(uni))/lambda;          //next we take the natural logarithm of our uniformly random point and negate the resulting value
    return randomNum;                               //finally we divide by lambda, resulting in a random number that is
}                                                   //exponentially distributed with given mean argument
                                                    //https://en.wikipedia.org/wiki/Exponential_distribution#Generating_exponential_variates (source we referenced)
