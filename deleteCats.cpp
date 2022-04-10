///////////////////////////////////////////////////////////////////////////////
/// University of Hawaii, College of Engineering
/// @brief Lab 08d - animal farm 1 to Clion - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 1.0
///
/// @author Nathaniel Murray <murrayn@hawaii.edu>
/// @date 3_20_2022
//////////////////////////////////////////////////////////////////////////
#include "catDatabase.h"
#include <stdexcept>
#include "Cat.h"
bool deleteCat(Cat* deleteThisCat){
    Cat* catToLookAt = catDatabaseHeadPointer;

    //If the cat we want to delete is the first cat
    if(deleteThisCat == catDatabaseHeadPointer){
        catDatabaseHeadPointer = catDatabaseHeadPointer->next;
        numberOfCats = numberOfCats - 1;
        return true;
    }

    //Removing cat from the linked list. Rerouting pointer to the cat after the cat to delete.
    //While the next cat to look at is not empty and if the cat we want to delete is the "next" cat, set that cat equal to the cat after the cat we want to delete.
    //If the cat we want to delete isn't the "next" cat, go through the list until we find it.
    //If the cat isn't in the database, the last iteration will be that the "next" cat is empty, so an invalid argument will be thrown
    while(catToLookAt->next != nullptr){
        if(deleteThisCat == catToLookAt->next){
         catToLookAt->next = deleteThisCat->next;
         numberOfCats = numberOfCats -1;
         return true;
        }
        catToLookAt = catToLookAt->next;
    }
    throw std::invalid_argument("Cat is not in the database.");
}

bool deleteAllCats(){
    //Keep deleting the first cat in the list while the first cat is not empty
    while(catDatabaseHeadPointer != nullptr) {
        deleteCat(catDatabaseHeadPointer);
    }
    return true;
}