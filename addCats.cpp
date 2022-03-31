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
#define MAX_CATS 1024
#include "config.h"
//if true contains element that is the same
bool containsElement(char name[]){
    for(int i=0;i<numberOfCats;i++){
        if(strcmp(name,catArray[i].name)==0){
            return true;
        }
    }
    return false;
}

int addCat(char name[],enum catgender gender,enum catbreed breed,bool isCatFixed,float weight,enum Color collarColor1,enum Color collarColor2, unsigned long long license){
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
    catArray[numberOfCats].isFixed = isCatFixed;
    catArray[numberOfCats].weight = weight;
    strcpy(catArray[numberOfCats].name,name);
    catArray[numberOfCats].collarColor1 = collarColor1;
    catArray[numberOfCats].collarColor2 = collarColor2;
    catArray[numberOfCats].license = license;
    int locationOfCat = numberOfCats;
    numberOfCats++;
    return locationOfCat;
}

