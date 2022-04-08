///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author <murrayn@hawaii.edu>
/// @date   07_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <cstring>
#include <stdexcept>
#include <iostream>
#include <cassert>
#include <array>
#include "catDatabase.h"
#include "Cat.h"
#include "reportCats.h"
#define FORMAT_LINE(className, member) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

using std::array; using std::fill;

Cat::Cat(){
    char name[MAX_NAME_LENGTH] = "";
    enum Gender gender = UNKNOWN_GENDER;
    enum Breed breed = UNKNOWN_BREED;
    bool isCatFixed = false;
    Weight weight = UNKNOWN_WEIGHT;
}

Cat::Cat(const char* newName, const Gender newGender, const Breed newBreed, const Weight newWeight){
    char name[MAX_NAME_LENGTH];
    strncpy(name, newName, sizeof(name) );
    name[MAX_NAME_LENGTH-1]='\0';
    enum Gender gender = newGender;
    enum Breed breed = newBreed;
    bool isCatFixed = false;
    Weight weight = newWeight;
}

Cat::~Cat() {
    char name[MAX_NAME_LENGTH];
    memset(name, 0, sizeof (name));
    enum Gender gender = UNKNOWN_GENDER;
    enum Breed breed = UNKNOWN_BREED;
    bool isCatFixed = false;
    Weight weight = UNKNOWN_WEIGHT;
}

const char *Cat::getName() const noexcept {
    return name;
}

void Cat::setName(const char *newName) {
    if((strlen(name)<=MAX_NAME_LENGTH)&& strlen(name)>0){
        for(int i=0;i<MAX_NAME_LENGTH;i++){
            name[i]='\0';
        }
        strcpy(catArray[numberOfCats].name,name);
        int j=0;
        while(newName[j]!='\0') {
            name[j] = newName[j];
            j++;
        }
    }
}

Gender Cat::getGender() const noexcept {
    return gender;
}

Breed Cat::getBreed() const noexcept {
    return breed;
}

bool Cat::isFixed() const noexcept {
    return isCatFixed;
}

void Cat::fixCat() noexcept {
    isCatFixed = true;
}

Weight Cat::getWeight() const noexcept {
    return weight;
}

void Cat::setWeight(Weight newWeight) {
    if(newWeight>0){
        weight = newWeight;
    }
}

void Cat::setGender(Gender newGender) {
    if(gender == UNKNOWN_GENDER){
        gender = newGender;
    }
    throw std::logic_error("Logic error. Can't change gender");
}

void Cat::setBreed(Breed newBreed) {
        if (breed == UNKNOWN_BREED) {
            breed = newBreed;
        }
        throw std::logic_error("Logic error. Can't change breed");
}

bool Cat::validateGender(const Gender newGender) {
    if(newGender!=UNKNOWN_GENDER){
        return true;
    }
    return false;
}

bool Cat::validateWeight(const Weight newWeight) {
    if(newWeight!=UNKNOWN_WEIGHT){
        return true;
    }
    return false;
}

bool Cat::validateBreed(const Breed newBreed) {
    if(newBreed!=UNKNOWN_BREED){
        return true;
    }
    return false;
}

bool Cat::validateName(const char *newName) {
    if((newName != nullptr || strlen(newName) !=0) && strlen(newName)>0){
        return true;
    }
    if(newName == nullptr /* || strlen(newName) = 0 */){
        throw std::invalid_argument("Invalid Argument.");
    }
    if(strlen(newName) >= MAX_NAME_LENGTH){
        return false;
        //return std::length_error
    }
}
bool Cat::validate() const noexcept {
    if(validateBreed(Cat::breed) && validateName(Cat::name) && validateWeight(Cat::weight) &&
       validateGender(Cat::gender)){
        return true;
    }
}

bool Cat::print() const noexcept {

    assert( validate() ) ;
    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Cat", "name" ) << getName() << endl ;
    FORMAT_LINE( "Cat", "gender" ) << genderName( getGender() ) << endl ;
    FORMAT_LINE( "Cat", "breed" ) << breedName( getBreed() ) << endl ;
    FORMAT_LINE( "Cat", "isFixed" ) << isFixed() << endl ;
    FORMAT_LINE( "Cat", "weight" ) << getWeight() << endl ;
    return true ;
}
