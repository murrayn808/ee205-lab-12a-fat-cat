///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab-12a-fat-cat - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author <murrayn@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Weight.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <cassert>
const float Weight::UNKNOWN_WEIGHT = -1;
const float Weight::KILOS_IN_A_POUND = 0.453592;
const float Weight::SLUGS_IN_A_POUND = 0.031081;
const string Weight::POUND_LABEL = "Pound";
const string Weight::KILO_LABEL = "Kilo";
const string Weight::SLUG_LABEL = "Slug";

Weight::Weight()noexcept{
    unitOfWeight = POUND;
    weight = UNKNOWN_WEIGHT;
    maxWeight = UNKNOWN_WEIGHT;
}

Weight::Weight(float newWeight){
    unitOfWeight = POUND;
    weight = newWeight;
    maxWeight = UNKNOWN_WEIGHT;
    blsKnown = true;
    if(isWeightValid(newWeight)==false){
        throw std::out_of_range("Weight is <= 0.");
    }
}

Weight::Weight(const Weight::UnitOfWeight newUnitOfWeight)noexcept{
   unitOfWeight = newUnitOfWeight;
   weight = UNKNOWN_WEIGHT;
   maxWeight = UNKNOWN_WEIGHT;
}


Weight::Weight(float newWeight, const Weight::UnitOfWeight newUnitOfWeight){
    weight = newWeight;
    unitOfWeight = newUnitOfWeight;
    blsKnown = true;
    if(isWeightValid(newWeight)==false){
        throw std::out_of_range("Weight is <= 0.");
    }
    maxWeight = UNKNOWN_WEIGHT;
}

Weight::Weight(float newWeight, float newMaxWeight) {
    weight = newWeight;
    unitOfWeight = POUND;
    maxWeight = newMaxWeight;
    blsKnown = true;
    bHasMax = true;
    if(isWeightValid(newWeight)==false){
        throw std::out_of_range("Weight is <= 0.");
    }
    if(newMaxWeight <= 0){
        throw std::out_of_range("Max weight is <= 0.");
    }
}

Weight::Weight(UnitOfWeight newUnitOfWeight, float newMaxWeight){
    weight = UNKNOWN_WEIGHT;
    unitOfWeight = newUnitOfWeight;
    maxWeight = newMaxWeight;
    bHasMax = true;
    if(newMaxWeight <= 0){
        throw std::out_of_range("Max weight is <= 0.");
    }
}

Weight::Weight(float newWeight, const Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight){
    weight = newWeight;
    unitOfWeight = newUnitOfWeight;
    maxWeight = newMaxWeight;
    blsKnown = true;
    bHasMax = true;
    if(isWeightValid(newWeight)==false){
        throw std::out_of_range("Weight is <= 0.");
    }
    if(newMaxWeight <= 0){
        throw std::out_of_range("Max weight is <= 0.");
    }
}

void Weight::dump()const noexcept{
    using namespace std;

#define FORMAT_LINE(className, member) cout << setw(8) << (className) << setw(20) << (member) << setw(52)
    assert( validate() ) ;
    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Weight", "this" ) << this << endl ;
    FORMAT_LINE( "Weight", "isKnown" ) << blsKnown << endl ;
    FORMAT_LINE( "Weight", "weight" ) << getWeight() << endl ;
    FORMAT_LINE( "Weight", "unitOfWeight" ) << unitOfWeight << endl ;
    FORMAT_LINE( "Weight", "hasMax" ) << bHasMax << endl ;
    FORMAT_LINE( "Weight", "maxWeight" ) << maxWeight << endl;
}

bool Weight::hasMaxWeight() const noexcept{
    if(blsKnown == true){
        return true;
    }
    return false;
}

bool Weight::hasMaxWeight() const noexcept{
    if(bHasMax == true){
        return true;
    }
    return false;
}

bool Weight::validate() const noexcept{
    if(isWeightValid(weight)&&isWeightKnown()){
        return true;
    }
    return false;
}

float Weight::getMaxWeight() const noexcept{
    if(hasMaxWeight()){
        return maxWeight;
    }
    return UNKNOWN_WEIGHT;
}

float Weight::getWeight() const noexcept{
    if(isWeightKnown()){
        return weight;
    }
    return UNKNOWN_WEIGHT;
}

bool Weight::isWeightValid(float checkWeight) const noexcept{
    if(checkWeight <= 0){
        return false;
    }
    if(bHasMax && checkWeight > maxWeight){
        return false;
    }
return true;
}

Weight & Weight::operator+=(float rhs_addToWeight) {
    if(weight == UNKNOWN_WEIGHT) {
        throw std::out_of_range("Weight is unknown.");
    }
    weight = weight + rhs_addToWeight;
}

bool Weight::operator<(const Weight &rhs_Weight) const {
    float rhsWeightInPounds = 0;
    float lhsWeightInPounds = 0;

    if(rhs_Weight.getWeight() != UNKNOWN_WEIGHT){
        rhsWeightInPounds = Weight::convertWeight(rhs_Weight.weight, rhs_Weight.unitOfWeight, POUND);
    }

    if(getWeight() != UNKNOWN_WEIGHT){
        lhsWeightInPounds = Weight::convertWeight(weight, unitOfWeight, POUND);
    }

    if(lhsWeightInPounds<rhsWeightInPounds){
        return true;
    }
    return false;
}

bool Weight::operator==(const Weight &rhs_Weight) const {
    float rhsWeightInPounds = 0;
    float lhsWeightInPounds = 0;

    if(rhs_Weight.getWeight() != UNKNOWN_WEIGHT){
        rhsWeightInPounds = Weight::convertWeight(rhs_Weight.weight, rhs_Weight.unitOfWeight, POUND);
    }

    if(getWeight() != UNKNOWN_WEIGHT){
        lhsWeightInPounds = Weight::convertWeight(weight, unitOfWeight, POUND);
    }

    if(lhsWeightInPounds==rhsWeightInPounds){
        return true;
    }
    return false;
}

void Weight::setMaxWeight(float newMaxWeight) {
    if(newMaxWeight <= 0){
        throw std::out_of_range("Max weight is <= 0.");
    }
    if (bHasMax == false) {
        maxWeight = newMaxWeight;
        bHasMax = true;
    }
}

void Weight::setWeight(float newWeight) {
    if(isWeightValid(newWeight)){
        throw std::out_of_range("Weight is <=0 or > maxWeight.");
    }
    if(blsKnown == false){
        weight = newWeight;
        blsKnown = true;
    }
}

float Weight::fromKilogramToPound(float kilogram)noexcept{
    return kilogram/KILOS_IN_A_POUND;
}

float Weight::fromPoundToKilogram(float pound)noexcept{
    return pound*KILOS_IN_A_POUND;
}

float Weight::fromPoundToSlug(float pound)noexcept{
    return pound*SLUGS_IN_A_POUND;
}

float Weight::fromSlugToPound(float slug)noexcept{
    return slug/SLUGS_IN_A_POUND;
}

float Weight::convertWeight(float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit)noexcept{
    double commonValue;

    switch (fromUnit) {

        case POUND : commonValue = fromWeight;
        break;

        case KILO : commonValue = fromKilogramToPound(fromWeight);
        break;

        case SLUG : commonValue = fromSlugToPound(fromWeight);
        break;
    }

    double toValue;

    switch (toUnit) {

        case POUND :
        toValue = commonValue;
        break;

        case KILO :
        toValue = fromPoundToKilogram(commonValue);
        break;

        case SLUG :
        toValue = fromPoundToSlug(commonValue);
        break;
    }

    return toValue;
}






