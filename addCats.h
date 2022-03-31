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
#include "catDatabase.h"
#pragma once
extern bool containsElement(char name[]);

extern int addCat(char name[],enum catgender gender,enum catbreed breed,bool isCatFixed,float weight,enum Color collarColor1,enum Color collarColor2, unsigned long long license);