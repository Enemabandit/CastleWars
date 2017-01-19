#include "utils.h"

//converts a string with a positive decimal integer to int (returns -1 if the string as anything but digits)
int stringToPositiveInt(std::string s){
    std::string stringValidated;
    for (std::string::iterator it = s.begin(); it < s.end(); it++){
        if(isdigit(*it)){
            stringValidated.push_back(*it);
        } else{
            return -1;
        }
    }
    int validatedNumber = std::stoi(stringValidated);
    return validatedNumber;
}

//generates random set of coordinates
//NOTE:not using <random> library due to problems with my compiler
Point getRandomPosition(int height,int width){
    Point p;
    p.x=random_at_most((long)width);
    p.y=random_at_most((long)height);
    return p;
}

//generates a random long int
// Assumes 0 <= max <= RAND_MAX
// Returns in the closed interval [0, max]
long random_at_most(long max) {
    unsigned long
        // max <= RAND_MAX < ULONG_MAX, so this is okay.
        num_bins = (unsigned long) max + 1,
        num_rand = (unsigned long) RAND_MAX + 1,
        bin_size = num_rand / num_bins,
        defect   = num_rand % num_bins;

    long x;
    do {
        x = random();
    }
    // This is carefully written not to overflow
    while (num_rand - defect <= (unsigned long)x);

    // Truncated division is intentional
    return x/bin_size;
}

