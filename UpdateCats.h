///////////////////////////////////////////////////////////////////////////////
/// University of Hawaii, College of Engineering
/// @brief Lab 08d - animal farm 1 to Clion - EE 205 - Spr 2022
///
/// @file UpdateCats.h
/// @version 1.0
///
/// @author Nathaniel Murray <murrayn@hawaii.edu>
/// @date 3_20_2022
//////////////////////////////////////////////////////////////////////////
#include <cstdio>
#include "catDatabase.h"
#include "newTypeDef.h"
#pragma once

typedef int NumCats;
typedef float Weight;
int updateCatName(NumCats index, char newName[]);
int fixCat(int index);
int updateCatWeight(NumCats index, Weight newWeight);
int updateCatCollar1(NumCats index, enum Color collarColor1);
int updateCatCollar2(NumCats index, enum Color collarColor2);
int updateLicense(NumCats index, unsigned long long license);
