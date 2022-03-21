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
#pragma once
extern bool containsElement(char name[]);

extern int addCat(char name[],enum : char catgender gender,enum : char catbreed breed,bool isCatFixed,float weight,enum : char Color collarColor1,enum : char Color collarColor2, unsigned long long license);

