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
#include <stdexcept>
#include <iostream>
#include <cassert>
#include "config.h"
#include "catDatabase.h"
#include "Cat.h"
#include "reportCats.h"
#define MAX_CATS 1024
#define MAX_NAME_LENGTH 50

struct Cat catArray[MAX_CATS];

Cat* catDatabaseHeadPointer = nullptr;

extern bool isCatInDatabase(Cat* newCat){
    for(int i=0;i<numberOfCats;i++){
        if(strcmp(name,catArray[i].name)==0){
            return true;
        }
    }
    return false;
}

int numberOfCats = 0;
int initializeDatabase(){
    numberOfCats = 0;
    memset(&catArray[0],0,sizeof(catArray));
    return 0;
}
