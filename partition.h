//**************************************************************************
//  Name:        Camero Walker and Katie Isbell
//  File:        partition.h
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     Create a class to describe a partition
// *************************************************************************
#ifndef PARTITION_H
#define PARTITION_H
#include "vector.h"
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
    // @post   The number of sets within the partition is initialized to zero
    // *********************************************************************
    Partition();

    // *********************************************************************
    // @fn     Partition
    // @brief  Copy Constructor.
    // @pre    None
    // @post   The new Partition is an exact copy of the original Partition
    // *********************************************************************
    Partition(const Partition &a);

    // *********************************************************************
    // @fn     ~Partition
    // @brief  Destructor that clears the Partition
    // @pre    None
    // @post   The size of the Vector is set to zero and the data has been
    //         cleared
    // *********************************************************************
    ~Partition();

    // *********************************************************************
    // @fn     operator <=
    // @brief  p2 <= p1. Check if P2 is a subset of P1
    // @pre    none
    // @post   Returns true if P2 is a subset of P1
    // *********************************************************************
    bool operator<= (const Partition &p1) const
    {
      return true;
    }

    // *********************************************************************
    // @fn     operator []
    // @brief  Returns the vector of values within a particular group
    // @pre    None
    // @post   The name of the Partition has been returned
    // *********************************************************************
    const std::vector<int> operator[](const unsigned int rowIndex) { return m_group[rowIndex]; }

    // *********************************************************************
    // @fn     getNumGroups
    // @brief  returns the total number of groups within our partition
    // @pre    none
    // @post   Returns the size of our m_partitionGroup vector
    // *********************************************************************
    const unsigned int getNumGroups() { return m_group.size(); }

    void addGroup(){ std::vector<int> v; m_group.push_back(v); }

    // insert a row value into a specified group number
    void insert(int rowNum, int groupNum) { m_group[groupNum].push_back(rowNum); }

    void setPattern(const std::string pattern) { m_pattern = pattern; }
    const std::string getPattern() { return m_pattern; }

  private:
   std::string m_pattern;
   std::vector<std::vector<int> > m_group;
};

#include "partition.hpp"
#endif
