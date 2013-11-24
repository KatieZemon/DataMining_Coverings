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
#include "dataset.h"
#include "attribute.h"
#include "partition.h"

#ifndef RICO_H
#define RICO_H
bool isSubset (Vector<Vector<unsigned int> > v1,Vector<unsigned int> v2);
//**************************************************************************
// @class RICO
// @brief Finds and prints the set of minimal coverings associated with
//        the particular Dataset given
//**************************************************************************
class RICO
{
  public:
    //**********************************************************************
    // @fn     operator ()
    // @brief  This operator performs the RICO algorithm and prints the
    //         minimal coverings
    // @param  db - The Dataset which we use to find the minimal coverings
    // @pre
    //
    // @post
    //**********************************************************************
    void operator()(Dataset<std::string> &db);


};

// Member function definitions of the RICO class
#include "rico.hpp"
#endif

