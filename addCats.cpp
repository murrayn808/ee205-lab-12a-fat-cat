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
#include <cstring>
#include "catDatabase.h"
#include "newTypeDef.h"
#include "addCats.h"
#include "Cat.h"
#include "config.h"
#define MAX_CATS 1024
//if true contains element that is the same
bool containsElement(char name[]){
    for(int i=0;i<numberOfCats;i++){
        if(strcmp(name,catArray[i].name)==0){
            return true;
        }
    }
    return false;
}

int addCat(char name[], enum Gender gender, enum Breed breed, bool isCatFixed, Weight weight){
    if(numberOfCats>=MAX_CATS){
        return -1;
    }
    if(strlen(name)==0){
        return -2;
    }
    if(strlen(name)>50){
        return -3;
    }
    if(containsElement(name)){
        return -4;
    }
    if(weight<=0){
        return -5;
    }

    catArray[numberOfCats].gender = gender;
    catArray[numberOfCats].breed = breed;
    catArray[numberOfCats].isCatFixed = isCatFixed;
    catArray[numberOfCats].weight = weight;
    strcpy(catArray[numberOfCats].name,name);
    int locationOfCat = numberOfCats;
    numberOfCats++;
    return locationOfCat;
}

