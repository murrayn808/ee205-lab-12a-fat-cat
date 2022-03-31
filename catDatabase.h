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
#pragma once
#define MAX_CATS 1024
#define MAX_NAME_LENGTH 50

enum catgender{UNKNOWN_GENDER,MALE,FEMALE};
enum catbreed{UNKNOWN_BREED,MAINE_COON,MANX,SHORTHAIR,PERSIAN,SPHYNX};
enum Color{BLACK,WHITE,RED,BLUE,GREEN,PINK};
char* colorName (enum Color color);
struct Cat {

    enum catgender gender;
    enum catbreed breed;
    enum Color collarColor1;
    enum Color collarColor2;
    unsigned long long license;
    bool isFixed;
    float weight;
    char name[MAX_NAME_LENGTH];
};



extern struct Cat catArray[MAX_CATS];

extern int initializeDatabase();
extern int numberOfCats;


