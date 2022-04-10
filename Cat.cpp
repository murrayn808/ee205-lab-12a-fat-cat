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
#include <iomanip>
#include "catDatabase.h"
#include "Cat.h"
#include "reportCats.h"
#define FORMAT_LINE(className, member) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

using std::array; using std::fill;

Cat::Cat(){
    memset(name, 0, MAX_NAME_LENGTH);
    gender = UNKNOWN_GENDER;
    breed = UNKNOWN_BREED;
    isCatFixed = false;
    weight = UNKNOWN_WEIGHT;
}

Cat::Cat(const char* newName, const Gender newGender, const Breed newBreed, const Weight newWeight){
    setName(newName);
    gender = newGender;
    breed = newBreed;
    isCatFixed = false;
    weight = newWeight;
}

Cat::~Cat() {
    zeroOutMemberData();
}

const char *Cat::getName() const noexcept {
    return name;
}

void Cat::setName(const char *newName) {
    if(validateName(newName)) {
        memset(name, 0, MAX_NAME_LENGTH);
        strcpy(name, newName);
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
    if(validateWeight(newWeight)){
        weight = newWeight;
    }
}

void Cat::setGender(Gender newGender) {
    if(gender == UNKNOWN_GENDER){
        gender = newGender;
    }
    else {
        throw std::logic_error("Logic error. Can't change gender");
    }
}

void Cat::setBreed(Breed newBreed) {
        if (breed == UNKNOWN_BREED) {
            breed = newBreed;
        }
        else {
            throw std::logic_error("Logic error. Can't change breed");
        }
}

bool Cat::validateGender(const Gender newGender) {
    if(newGender!=UNKNOWN_GENDER){
        return true;
    }
    return false;
}

bool Cat::validateWeight(const Weight newWeight) {
    if(newWeight>0){
        return true;
    }
    else{
        throw std::invalid_argument("newWeight <= 0.");
    }
}

bool Cat::validateBreed(const Breed newBreed) {
    if(newBreed!=UNKNOWN_BREED){
        return true;
    }
    else{
        throw std::invalid_argument("newBreed is UNKNOWN_BREED.");
    }
}

bool Cat::validateName(const char *newName) {
    if(newName != nullptr && strlen(newName)>0 && strlen(newName) < MAX_NAME_LENGTH){
        return true;
    }
    if(newName == nullptr || strlen(newName) == 0){
        throw std::invalid_argument("Invalid Argument.");
    }
    if(strlen(newName) >= MAX_NAME_LENGTH){
        throw std::length_error("Length error.");
    }
    return false;
}
bool Cat::validate() const noexcept {
    if(validateBreed(Cat::breed) && validateName(Cat::name) && validateWeight(Cat::weight) &&
       validateGender(Cat::gender)){
        return true;
    }
    return false;
}

bool Cat::print() const noexcept {

    using namespace std;

    #define FORMAT_LINE(className, member) cout << setw(8) << (className) << setw(20) << (member) << setw(52)
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

void Cat::zeroOutMemberData() {
     memset(name, 0, MAX_NAME_LENGTH);
     gender = UNKNOWN_GENDER;
     breed = UNKNOWN_BREED;
     isCatFixed = false;
     weight = UNKNOWN_WEIGHT;
}

