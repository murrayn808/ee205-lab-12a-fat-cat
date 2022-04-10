///////////////////////////////////////////////////////////////////////////////
/// University of Hawaii, College of Engineering
/// @brief Lab 08d - animal farm 1 to Clion - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author Nathaniel Murray <murrayn@hawaii.edu>
/// @date 3_20_2022
//////////////////////////////////////////////////////////////////////////


#include "catDatabase.h"
#include "config.h"

const char* breedName(const enum Breed breed){
    //unknown breed MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX
    switch(breed){
        case UNKNOWN_BREED: return "Unknown Breed";
        case MAINE_COON: return "Maine Coon";
        case MANX: return "Manx";
        case SHORTHAIR: return "Shorthair";
        case PERSIAN: return "Persian";
        case SPHYNX: return "Sphynx";
    }
    return nullptr;
}

const char* genderName(const enum Gender gender){
    switch(gender){
        case UNKNOWN_GENDER: return "Unknown Gender";
        case MALE: return "Male";
        case FEMALE: return "Female";
    }
    return nullptr;
}

Cat* findCatByName(const char* name){
    Cat* catToLookAt = catDatabaseHeadPointer;
    while(catToLookAt != nullptr) {
        if (strcmp(name,catToLookAt->getName())==0){
            return catToLookAt;
        }
        catToLookAt = catToLookAt->next;
    }
    return nullptr;
}

bool printAllCats(){
    Cat* catToLookAt = catDatabaseHeadPointer;
    while(catToLookAt != nullptr) {
        catToLookAt->print();
        catToLookAt = catToLookAt->next;
    }
    return true;
}