///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Project - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author <murrayn@hawaii.edu>
/// @date   30_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include <cstdio>
#include <cstring>
#include "newTypeDef.h"
#include "config.h"
#include "Cat.h"
#pragma once
#define MAX_CATS 1024
#define MAX_NAME_LENGTH 50

extern Cat* catDatabaseHeadPointer;

extern void initializeDatabase();
extern NumCats numberOfCats;
extern bool isCatInDatabase(const Cat* aCat);
extern bool validateDatabase();



