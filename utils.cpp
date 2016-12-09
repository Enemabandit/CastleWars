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
