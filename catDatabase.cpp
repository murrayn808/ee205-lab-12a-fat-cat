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

#include <stdexcept>
#include "config.h"
#include "catDatabase.h"
#include "Cat.h"
#define MAX_NAME_LENGTH 50

Cat* catDatabaseHeadPointer = nullptr;

extern bool isCatInDatabase(const Cat* aCat){
    Cat* catToLookAt = catDatabaseHeadPointer;
    //first iteration: while first cat not empty check if that cat is the cat we're adding if not set the next cat to look at = to second cat
    //while second cat is not null keep searching, if the second cat is the same as new cat return true stop searching
    while(catToLookAt != nullptr){
        if(aCat == catToLookAt){
            return true;
        }
        catToLookAt = catToLookAt->next;
    }
    return false;
}

extern bool validateDatabase(){
    Cat* catToLookAt = catDatabaseHeadPointer;
    while(catToLookAt != nullptr) {
        if (!catToLookAt->validate()) {
            return false;
        }
        catToLookAt = catToLookAt->next;
    }
    return true;
}

int numberOfCats = 0;

void initializeDatabase(){
    if(catDatabaseHeadPointer != nullptr){
        throw std::logic_error("Old database not empty.");
    }
}
