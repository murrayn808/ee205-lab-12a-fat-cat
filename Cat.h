///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 1.0
///
/// @author <murrayn@hawaii.edu>
/// @date   07_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CAT_H
#define EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CAT_H
#include <cstdio>
#include <cstring>
#include "newTypeDef.h"
#include "config.h"
#pragma once
#define MAX_NAME_LENGTH 50

class Cat{
protected:
    char name[MAX_NAME_LENGTH];
    enum Gender gender;
    enum Breed breed;
    bool isCatFixed;
    Weight weight;

public:

    Cat* next;

public:
    Cat();

    Cat(const char* newName, const Gender newGender, const Breed newBreed, const Weight newWeight);

    virtual ~Cat();

    const char* getName() const noexcept;

    void setName(const char *newName);

    Gender getGender() const noexcept;

    Breed getBreed() const noexcept;

    bool isFixed() const noexcept;

    void fixCat() noexcept;

    Weight getWeight() const noexcept;

    void setWeight(Weight newWeight);

    void setGender(Gender newGender);

    void setBreed(Breed newBreed);

    bool print() const noexcept;

    bool validate() const noexcept;

    static bool validateName(const char *newName);

    static bool validateGender(const Gender newGender);

    static bool validateBreed(const Breed newBreed);

    static bool validateWeight(const Weight newWeight);


private:

    void zeroOutMemberData();

};


#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CAT_H
