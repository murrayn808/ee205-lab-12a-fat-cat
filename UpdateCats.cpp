///////////////////////////////////////////////////////////////////////////////
/// University of Hawaii, College of Engineering
/// @brief Lab 08d - animal farm 1 to Clion - EE 205 - Spr 2022
///
/// @file UpdateCats.cpp
/// @version 1.0
///
/// @author Nathaniel Murray <murrayn@hawaii.edu>
/// @date 3_20_2022
//////////////////////////////////////////////////////////////////////////
#include <cstdio>
#include "catDatabase.h"
#include "addCats.h"
#include "config.h"
#include "newTypeDef.h"

int updateCatName(int index, char newName[]){
    if(index<0||index>=numberOfCats){
        return -1;
    }
    if(isCatInDatabase(newName)){
        fprintf(stderr, "\e[0;31m" "[ERROR]" "\e[0m"  "Can't update cat name. There is already a cat named %s.\n", newName);
        return -2;
    }
    strcpy(catArray[index].name,newName);
    return 0;
}

int fixCat(int index){
    if(index<0||index>=numberOfCats){
        return -1;
    }
    catArray[index].isCatFixed=true;
    return 0;
}

int updateCatWeight(int index, Weight newWeight){
    if(index<0||index>=numberOfCats){
        return -1;
    }
    catArray[index].weight=newWeight;
    return 0;
}

int updateCatCollar1(int index, enum Color newCollarColor1){
    if(index<0||index>=numberOfCats){
        return -1;
    }
    catArray[index].collarColor1=newCollarColor1;
    return 0;
}

int updateCatCollar2(int index, enum Color newCollarColor2){
    if(index<0||index>=numberOfCats){
        return -1;
    }
    catArray[index].collarColor2=newCollarColor2;
    return 0;
}

int updateLicense(int index, unsigned long long newLicense){
    if(index<0||index>=numberOfCats){
        return -1;
    }
    catArray[index].license=newLicense;
    return 0;
}
