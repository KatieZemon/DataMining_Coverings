//**************************************************************************
//  Name:        Katie Isbell
//  File:        rico.h
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     Header file for the RICO algorithm used to determine minimal
//               coverings in order to produce the association rules for
//               a dataset
// *************************************************************************
#include <string>
#include "vector.h"
#include "database.h"
#include "attribute.h"
#include "partition.h"

#ifndef RICO_H
#define RICO_H
bool isSubset (Vector<Vector<unsigned int> > v1,Vector<unsigned int> v2);
//**************************************************************************
// @class Thomas
// @brief Computes the solution set for a set of n equations with n unknown
//        variables, where n is some integer greater than zero. It uses the
//        gauss-seidel iteration method.
//**************************************************************************
class RICO
{
  public:
    //**********************************************************************
    // @fn     operator ()
    // @brief  This is the thomas algorithm for solving a linear system
    //         of equations that can be represented using a tridiagonal
    //         matrix
    // @param  M is a tridiagonal matrix, V is a Vector
    // @pre    M should be an nxn tridiagonal matrix
    //         V is a column vector with n elements
    // @post   Returns a vector x representing the solution set
    //**********************************************************************
    void operator()(Database<std::string> &db);


};

// Member function definitions of thomas class
#include "rico.hpp"
#endif

