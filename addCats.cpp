///////////////////////////////////////////////////////////////////////////////
/// University of Hawaii, College of Engineering
/// @brief Lab 08d - animal farm 1 to Clion - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author Nathaniel Murray <murrayn@hawaii.edu>
/// @date 3_20_2022
//////////////////////////////////////////////////////////////////////////
#include <stdexcept>
#include "catDatabase.h"
#include "addCats.h"
#include "Cat.h"
#include "config.h"
#define MAX_CATS 1024
//if true contains element that is the same

bool addCat(Cat* newCat){
    if(newCat != nullptr && isCatInDatabase(newCat)==false){
        newCat->next = catDatabaseHeadPointer;
        catDatabaseHeadPointer = newCat;
        numberOfCats = numberOfCats + 1;
        return true;
    }
    throw std::logic_error("newCat is already in database.");
}

