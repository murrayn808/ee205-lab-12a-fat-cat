///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Project - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author <murrayn@hawaii.edu>
/// @date   30_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cstring>
#include "catDatabase.h"
#define MAX_CATS 1024
#define MAX_NAME_LENGTH 50

struct Cat catArray[MAX_CATS];

char* colorName (enum Color color){
    switch (color) {
        case BLACK: return "Black";
        case WHITE: return "White";
        case RED:   return "Red";
        case BLUE:  return "Blue";
        case GREEN: return "Green";
        case PINK:  return "Pink";
    }

    return nullptr;
}

int numberOfCats = 0;
int initializeDatabase(){
    numberOfCats = 0;
    memset(&catArray[0],0,sizeof(catArray));
    return 0;
}
