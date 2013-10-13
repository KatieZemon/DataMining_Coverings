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
#include <vector>
#include <map>
#include "database.h"
using namespace std;

bool isSubset (const std::vector<int>& a, const std::vector<int>& b);
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
    Partition ();

    // *********************************************************************
    // @fn     Partition
    // @brief  Initialize our partition given a database and vector of attributes
    // @pre    a must be a set of data with no repeating values, and whose
    //         minimum value is zero and maximum value is the size of the
    //         dataset.
    // @param  db is the database
    // @param  a is a list of column indices within our database. Our database will
    //         be partitioned based on these selected attributes
    // @post   A partition will be created based on the selected database
    //         and attributes within that database
    // *********************************************************************
    Partition (const Database<std::string>& db, const std::vector<int>& a);

    // *********************************************************************
    // @fn     Partition
    // @brief  Copy Constructor.
    // @pre    None
    // @post   The new Partition is an exact copy of the original Partition
    // *********************************************************************
    Partition (const Partition &a);

    // *********************************************************************
    // @fn     ~Partition
    // @brief  Destructor that clears the Partition
    // @pre    None
    // @post   The size of the Vector is set to zero and the data has been
    //         cleared
    // *********************************************************************
    // ~Partition();

    void print ()
    {
      std::string key;
      vector<int> groupVals;

      for (map<std::string, vector<int> >::const_iterator it = m_map.begin(); it != m_map.end(); ++it)
      {
        key = it->first;
        groupVals = it->second;

        std::cout << "{";
        for (unsigned int i = 0; i < groupVals.size(); i++)
          std::cout << " " << groupVals[i] << ",";
        std::cout << " (" << key << ") }" << std::endl;
      }
    }

    void printDistribution (Database<std::string> &db)
    {
      std::string key;
      vector<int> groupVals;

      cout << "Distribution of values for attribute ";
      for (unsigned int i = 0; i < m_attrs.size(); ++i)
      {
        std::cout << db.getAttr(i).getName();
        if (i <  m_attrs.size() - 1)
          std::cout << ", ";
      }
      std::cout << ":" << std::endl;

      for (map<std::string, vector<int> >::const_iterator it = m_map.begin(); it != m_map.end(); ++it)
      {
        key = it->first;
        groupVals = it->second;
        std::cout << "\tValue: " << key << "\tOccurrences: " << groupVals.size() << std::endl;
      }


    }
    /*
     friend std::ostream& operator<<(std::ostream &os, const Partition &p)
     {
     std::string key;
     vector<int> groupVals;

     for (map<std::string, vector<int> >::const_iterator it = p.getMap().begin(); it != p.getMap().end(); ++it) {
     key = it->first;
     groupVals = it->second;

     os << "{";
     for (unsigned int i = 0; i < groupVals.size(); i++)
     {
     os << " " << groupVals[i] << ",";
     cout << "hi: " << groupVals[i] << endl;
     }5
     os<< " (" << key << ") }" << std::endl;
     }
     return os;
     }
     */

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
    // @post   Returns the size of our m_partitionGroup vector
    // *********************************************************************
    map<std::string, vector<int> > getMap () const;

  private:
    map<std::string, vector<int> > m_map;
    vector<int> m_attrs; // Each partition is associated with one or more attributes
};

#include "partition.hpp"
#endif

bool isSubset (const std::vector<int>& a, const std::vector<int>& b)
{
  bool found;
  for (std::vector<int>::const_iterator i = a.begin(); i != a.end(); i++)
  {
    found = false;
    for (std::vector<int>::const_iterator j = b.begin(); j != b.end() && (found == false); j++)
    {
      if (*i == *j)
      {
        found = true;
      }
    }
    if (!found)
      return false;
  }
  return true;
}
