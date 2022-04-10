///////////////////////////////////////////////////////////////////////////////
/// University of Hawaii, College of Engineering
/// @brief Lab 08d - animal farm 1 to Clion - EE 205 - Spr 2022
///
/// @file reportCats.h
/// @version 1.0
///
/// @author Nathaniel Murray <murrayn@hawaii.edu>
/// @date 3_20_2022
//////////////////////////////////////////////////////////////////////////

#include <cstdio>
#define REPORT_CATS 1024
#include "Cat.h"
#include "catDatabase.h"
#pragma once

extern const char* breedName(enum Breed breed);
extern const char* genderName(enum Gender gender);
extern Cat* findCatByName(const char* name);
extern bool printAllCats();

