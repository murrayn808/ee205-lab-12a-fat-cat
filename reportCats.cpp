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


#include <stdio.h>
#include "catDatabase.h"
#include "config.h"

int printCat(int index){
    if(index<0||index>=numberOfCats){
        fprintf(stderr, "animalFarm0: Bad cat [%d]", index);
    }

    printf("cat index=[%d] name=[%s] gender=[%d] breed=[%d] isFixed=[%d] weight=[%f] collarColor1=[%s] collarColor2=[%s] license=[%llu]\n", index, catArray[index].name, catArray[index].gender, catArray[index].breed, catArray[index].isFixed, catArray[index].weight, colorName(catArray[index].collarColor1), colorName(catArray[index].collarColor2), catArray[index].license);
    return 0;
}

int printAllCats(){
    for(int i=0;i<numberOfCats;i++){
        printCat(i);
    }
    return 0;
}

int findCat(char name[]){
    for(int i=0;i<numberOfCats;i++){
        if(strcmp(name,catArray[i].name)==0){
            return i;
        }
    }
    return -1;
}
