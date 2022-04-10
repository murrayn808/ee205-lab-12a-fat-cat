///////////////////////////////////////////////////////////////////////////////
/// University of Hawaii, College of Engineering
/// @brief Lab 08d - animal farm 1 to Clion - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Nathaniel Murray <murrayn@hawaii.edu>
/// @date 3_20_2022
//////////////////////////////////////////////////////////////////////////
#include <cstdio>
#include "Cat.h"
#include "reportCats.h"
#include "deleteCats.h"
#include "config.h"
#define ILLEGAL_NAME "12345678901234567890123456789012345678901234567890"
#define MAX_NAME1 "1234567890123456789012345678901234567890123456789"

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
    printf("Starting Animal Farm 2\n");

    Cat loki("Loki", MALE , PERSIAN, 1.0 );
    Cat milo("Milo", MALE, MANX, 1.1);
    Cat bella("Bella", FEMALE, MAINE_COON, 1.2);
    Cat kali("Kali", FEMALE, SHORTHAIR, 1.3);
    Cat trin("Trin", FEMALE, MANX, 1.4);
    Cat chili("Chili", MALE, SHORTHAIR, 1.5);

    addCat(&loki);
    addCat(&milo);
    addCat(&bella);
    addCat(&kali);
    addCat(&trin);
    addCat(&chili);

    printAllCats();
    deleteAllCats();
    printAllCats();

    printf("Done with Animal Farm 2\n");

    return 0;
}