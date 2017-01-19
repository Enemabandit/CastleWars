#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <stdlib.h>

//structure to represent coodinates
typedef struct {
    int x;
    int y;
} Point;

//converts a positive decimal integer in a string to int (returns -1 if the number is negative or not decimal)
int stringToPositiveInt(std::string s);

//generates random set of coordinates
Point getRandomPosition(int height,int width);

//returns a random number in range [0,max]
long random_at_most(long max);
#endif
