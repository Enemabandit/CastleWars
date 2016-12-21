#ifndef UTILS_H
#define UTILS_H

#include <iostream>

//structure to represent coodinates
typedef struct {
    int x;
    int y;
} Point;

//converts a positive decimal integer in a string to int (returns -1 if the number is negative or not decimal)
int stringToPositiveInt(std::string s);
#endif
