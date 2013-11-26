//**************************************************************************
//  Name:        Katie Isbell
//  File:        partition.h
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     Create a class to describe a partition
// *************************************************************************
#ifndef PARTITION_H
#define PARTITION_H
#include "vector.h"
#include <map>
#include "dataset.h"
using namespace std;

// *************************************************************************
// @class Partition
// @brief Functions used for creating a Partition
// *************************************************************************
class Partition
{
  public:
    // *********************************************************************
    // @fn     Partition
    // @brief  Default Constructor
    // @pre    None
    // @post   The number of groups within the partition is initialized to zero
    // *********************************************************************
    Partition ();

    // *********************************************************************
    // @fn     Partition
    // @brief  Initialize our partition given a Dataset and Vector of attributes
    // @pre    a must be a set of data with no repeating values, and whose
    //         minimum value is zero and maximum value is the size of the
    //         dataset.
    // @param  db is the Dataset
    // @param  a is a list of column indices within our Dataset. Our Dataset will
    //         be partitioned based on these selected attributes
    // @post   A partition will be created based on the selected Dataset
    //         and attributes within that Dataset
    // *********************************************************************
    Partition (const Dataset<std::string>& db, const Vector<unsigned int>& a);

    // *********************************************************************
    // @fn     Partition
    // @brief  Copy Constructor
    // @pre    None
    // @post   The new Partition is an exact copy of the original Partition
    // *********************************************************************
    Partition (const Partition &a);

    // *********************************************************************
    // @fn     print
    // @brief  Prints the association rules for the coverings found
    // @pre    None
    // @post   The rule sets for the covering is printed to the screen
    // *********************************************************************
    void printAssociationRules (Dataset<std::string>& db);

    // *********************************************************************
    // @fn     printAllDistributionCombos
    // @brief  Prints the distributions of all possible combinations of
    //         decision attributes
    // @pre    None
    // @post   The distributions for all combinations of decision attributes
    //         are printed to the screen
    // *********************************************************************
    void printAllDistributionCombos (Dataset<std::string>& db);

    // *********************************************************************
    // @fn     printDistribution
    // @brief  This function prints the distribution of a single given
    //         partition. It is used in printAllDistributionCombos()
    // @pre    None
    // @param db- The database we are studying
    // @param attrs- The attribute or set of attributes for which we are using
    //        to print the distribution
    // @post   The rule sets for the covering is printed to the screen
    // *********************************************************************
    void printDistribution (Dataset<std::string>& db, Vector<unsigned int> attrs);

    // *********************************************************************
    // @fn     operator <=
    // @brief  p2 <= p1. Check if P2 is a subset of P1
    // @pre    none
    // @post   Returns true if P2 is a subset of P1
    // *********************************************************************
    bool operator<= (const Partition &p1) const;

    // *********************************************************************
    // @fn     getNumGroups
    // @brief  returns the total number of groups within our partition
    // @pre    none
    // @post   Returns the size of our m_partitionGroup Vector
    // *********************************************************************
    map<std::string, Vector<unsigned int> > getMap () const;

  private:
    map<std::string, Vector<unsigned int> > m_map;
    Vector<unsigned int> m_attrs; // Each partition is associated with one or more attributes
};

#include "partition.hpp"
#endif

