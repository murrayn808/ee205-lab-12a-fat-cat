///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab-12a-fat-cat - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author <murrayn@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_LAB_12A_FAT_CAT_WEIGHT_H
#define EE205_LAB_12A_FAT_CAT_WEIGHT_H


class Weight {
public:
    enum UnitOfWeight {POUND, KILO, SLUG};
    static const float UNKNOWN_WEIGHT;
    static const float KILOS_IN_A_POUND;
    static const float SLUGS_IN_A_POUND;
    static const std::string POUND_LABEL;
    static const std::string KILO_LABEL;
    static const std::string SLUG_LABEL;

private:
    bool blsKnown;
    bool bHasMax;
    enum UnitOfWeight unitOfWeight;
    float weight;
    float maxWeight;

    void setMaxWeight(float newMaxWeight);

public:

    Weight()noexcept;
    Weight(float newWeight);
    Weight(UnitOfWeight, newUnitOfWeight)noexcept;
    Weight(float newWeight, UnitOfWeight newUnitOfWeight);
    Weight(float newWeight, float newMaxWeight);
    Weight(UnitOfWeight newUnitOfWeight, float newMaxWeight);
    Weight(float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight);
    bool isWeightKnown()const noexcept;
    bool hasMaxWeight()const noexcept;
    float getWeight()const noexcept;
    float getWeight(UnitOfWeight weightUnits)const noexcept;
    float getMaxWeight()const noexcept;
    UnitOfWeight getWeightUnit()const noexcept;
    void setWeight(float newWeight);
    void setWeight(float newWeight, UnitOfWeight weightUnits);
    bool isWeightValid(float checkWeight)const noexcept;
    bool validate()const noexcept;
    bool operator== (const Weight &rhs_Weight)const;
    bool operator< (const Weight &rhs_Weight)const;
    Weight& operator+=(float rhs_addToWeight);

    static float fromKilogramToPound(float kilogram)noexcept;
    static float fromPoundToKilogram(float pound)noexcept;
    static float fromSlugToPound(float slug)noexcept;
    static float fromPoundToSlug(float pound)noexcept;
    static float convertWeight(float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit)noexcept;


};


#endif //EE205_LAB_12A_FAT_CAT_WEIGHT_H
