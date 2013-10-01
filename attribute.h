//**************************************************************************
//  Name:        Camero Walker and Katie Isbell
//  File:        attribute.h
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     Create a class to describe an attribute
// *************************************************************************
#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include "vector.h"
// *************************************************************************
// @class Attribute
// @brief Functions used for creating an Attribute
// *************************************************************************
class Attribute
{
  public:
    // *********************************************************************
    // @fn     Attribute
    // @brief  Default Constructor
    // @pre    None
    // @post   The size of the Attribute is initialized to zero
    // *********************************************************************
    Attribute();

    // *********************************************************************
    // @fn     Attribute
    // @brief  Copy Constructor.
    // @pre    None
    // @post   The new Attribute is an exact copy of the original Attribute
    // *********************************************************************
    Attribute(const Attribute &a);

    // *********************************************************************
    // @fn     ~Attribute
    // @brief  Destructor that clears the Attribute
    // @pre    None
    // @post   The size of the Vector is set to zero and the data has been
    //         cleared
    // *********************************************************************
    ~Attribute();

    // *********************************************************************
    // @fn     operator ==
    // @brief  Performs a1 == a2, where a1 and a2 are Attributes
    // @pre    none
    // @post   Returns true if the Attributes are equal, else it returns false
    // *********************************************************************
    bool operator== (const Attribute &rhs) const;

    // *************************************************************************
    // @fn     Operator !=
    // @brief  Performs a1 != a2 where a1 and a2 are Attributes
    // @pre    none
    // @post   Returns true if the Attributes are not equal, else it returns false
    // *************************************************************************
    bool operator!= (const Attribute &rhs) const;

    // *********************************************************************
    // @fn     operator =
    // @brief  Assigns one attribute to another
    // @pre    None
    // @post   The resulting attribute on the lhs will be a copy of the
    //         attribute on the rhs
    // *********************************************************************
    Attribute& operator= (const Attribute &rhs);

    // *********************************************************************
    // @fn     getName
    // @brief  Returns the Attribute name
    // @pre    None
    // @post   The name of the Attribute has been returned
    // *********************************************************************
    std::string getName() const { return m_name; }

    // *********************************************************************
    // @fn     getPossibleVals
    // @brief  Returns a Vector of the Attribute's possible values
    // @pre    The attribute values are of type nominal
    // @post   The name of the Attribute has been returned
    // *********************************************************************
    std::string getPossibleVals() const;

    // *********************************************************************
    // @fn     isDecision
    // @brief  Returns true if it is a decision attribute
    // @pre    None
    // @post   Returns whether or not it is a decision attribute
    // *********************************************************************
    bool isDecision() const { return m_typeIsDecision; }

    // *********************************************************************
    // @fn     isNominal
    // @brief  Returns true if Attribute values are nominal (not numeric)
    // @pre    None
    // @post   Returns whether or not its values are nominal
    // *********************************************************************
    bool isNumeric() const { return m_valuesAreNumeric; }

    // *********************************************************************
    // @fn     setName
    // @brief  set the Attribute name
    // @pre    None
    // @post   The name of the Attribute has been set
    // *********************************************************************
    void setName(const std::string name);

    // *********************************************************************
    // @fn     setPossibleVals
    // @brief  set the Attribute possible values
    // @pre    The values in the string are delimited by commas
    // @post   The Attribute possible values have been set
    // *********************************************************************
    void setPossibleVals(const string possibleVals);

    // *********************************************************************
    // @fn     setPossibleVals
    // @brief  set the Attribute possible values
    // @pre    None
    // @post   The Attribute possible values have been set
    // *********************************************************************
  //  void setPossibleVals(const Vector<string> possibleVals);

    // *********************************************************************
    // @fn     setDecision
    // @brief  Specify whether the attribute is a decision attribute
    // @pre    None
    // @post   true will set the attribute as a decision attribute, false
    //         will set the attribute as a nondecision attribute
    // *********************************************************************
    void setDecision(const bool isDecision);

    // *********************************************************************
    // @fn     setNominal
    // @brief  Specify whether the attribute is nominal or numerical
    // @pre    None
    // @post   true will set the attribute as nominal, false
    //         will set the attribute as being numerical
    // *********************************************************************
    void setNumeric(const bool isNumeric);

  private:
   std::string m_name;
   std::string m_possibleVals;
   bool m_valuesAreNumeric;
   bool m_typeIsDecision;
};

#include "attribute.hpp"
#endif
