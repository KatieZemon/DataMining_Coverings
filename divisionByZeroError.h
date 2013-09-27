//**********************************************************************
//  Name:        Katie Isbell
//  File:        divisionByZeroError.h
//  Assignment:  Assignment 6
//  Date:        4/22/2013        
//  Course:      CS328
//  Purpose:     Exception handling for division by zero
//**********************************************************************

#ifndef DIVIDE_BY_ZERO_H
#define DIVIDE_BY_ZERO_H

//**********************************************************************
// @class DivisionByZeroError
// @brief Throws an exception when division by zero is attempted
//**********************************************************************
class DivisionByZeroError
{
  public:
    //******************************************************************
    // @fn     DivisionByZeroError
    // @brief  Exception handling for when you try to divide by zero
    // @pre    Division by zero is attempted
    // @post   Prints error to screen
    //******************************************************************
    DivisionByZeroError() {}
};
  
#endif

