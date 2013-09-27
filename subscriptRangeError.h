//**********************************************************************
//  Name:        Katie Isbell
//  File:        subscriptRangeError.h
//  Assignment:  Assignment 6
//  Date:        4/22/2013        
//  Course:      CS328
//  Purpose:     Exception handling when out of range
//**********************************************************************

#ifndef SUBSCRIPT_RANGE_ERROR_H
#define SUBSCRIPT_RANGE_ERROR_H

//**********************************************************************
// @class SubscriptRangeError
// @brief throws an exception if the subscript is out of range
//**********************************************************************
class SubscriptRangeError : public std::exception
{
  public:
    //******************************************************************
    // @fn     SubscriptRangeError(int i);
    // @brief  Check for the subscript range
    // @pre    We made an attempt to access an index out of range
    // @post   An exception is thrown
    //******************************************************************
    SubscriptRangeError(short i) { subscript = i; }
    short badSubscript() { return subscript; }
        
  private:
    short subscript;
};

#endif


