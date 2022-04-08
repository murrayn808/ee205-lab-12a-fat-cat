///////////////////////////////////////////////////////////////////////////////
/// University of Hawaii, College of Engineering
/// @brief Lab 08d - animal farm 1 to Clion - EE 205 - Spr 2022
///
/// @file addCats.h
/// @version 1.0
///
/// @author Nathaniel Murray <murrayn@hawaii.edu>
/// @date 3_20_2022
//////////////////////////////////////////////////////////////////////////
#include <cstdio>
#include "newTypeDef.h"
#include "catDatabase.h"
#include "Cat.h"
#pragma once
extern bool containsElement(char name[]);

extern int addCat(char name[], enum Gender gender, enum Breed breed, bool isCatFixed, Weight weight, enum Color collarColor1, enum Color collarColor2, unsigned long long license);