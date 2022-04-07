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

typedef float Weight;
int updateCatName(int index, char newName[]);
int fixCat(int index);
int updateCatWeight(int index, Weight newWeight);
int updateCatCollar1(int index, enum Color collarColor1);
int updateCatCollar2(int index, enum Color collarColor2);
int updateLicense(int index, unsigned long long license);
