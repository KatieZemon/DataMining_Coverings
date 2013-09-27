//**********************************************************************
//  Name:        Katie Isbell
//  File:        sizeMismatchError.h
//  Assignment:  Assignment 6
//  Date:        4/22/2013        
//  Course:      CS328
//  Purpose:     Exception handling for size mismatch
//**********************************************************************

#ifndef SIZE_MISMATCH_H
#define SIZE_MISMATCH_H

//**********************************************************************
// @class SizeMismatch
// @brief Throws an exception when division by zero is attempted
//**********************************************************************
class SizeMismatchError
{
  public:
    //******************************************************************
    // @fn     SizeMismatchError
    // @brief  Exception handling for when the number of elements in
    //         a vector or matrix does not match the expected number
    //         of elements required for performing specific calculations
    // @pre    This error can occur after an attempt to add, subtract, or
    //         multiply Vectors and Matrices of incompatible sizes
    //         The error can also occur when attempting to initialize
    //         the number of elements in a Vector or Matrix col/row to 
    //         a negative value
    // @post   Prints an error message to the screen
    //******************************************************************
    SizeMismatchError() {}
};
  
#endif

