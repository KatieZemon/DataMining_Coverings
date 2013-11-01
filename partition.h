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
#include <map>
#include "database.h"
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
    // @post   The number of sets within the partition is initialized to zero
    // *********************************************************************
    Partition();

    // *********************************************************************
    // @fn     Partition
    // @brief  Initialize our partition given a database and Vector of attributes
    // @pre    a must be a set of data with no repeating values, and whose
    //         minimum value is zero and maximum value is the size of the
    //         dataset.
    // @param  db is the database
    // @param  a is a list of column indices within our database. Our database will
    //         be partitioned based on these selected attributes
    // @post   A partition will be created based on the selected database
    //         and attributes within that database
    // *********************************************************************
    Partition (const Database<std::string>& db, const Vector<unsigned int>& a);

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

    // Print our rule sets
    void print (Database<std::string>& db)
    {
      std::string key;
      Vector<unsigned int> groupVals;
      Vector<unsigned int> decisionAttrs = db.getDecisionAttrs();

      std::cout << "Rules for covering [";
      // Print out the names of the attributes for this partition
      for (unsigned int i = 0; i < m_attrs.getSize(); ++i)
      {
        std::cout << db.getAttr( m_attrs[i] ).getName();
        if (i < m_attrs.getSize() - 1)
          std::cout << ", ";
      }
      std::cout << "]:" << std::endl;

      for (map<std::string, Vector<unsigned int> >::const_iterator it = m_map.begin(); it != m_map.end(); ++it)
      {
        key = it->first;
        groupVals = it->second;

        std::cout << "[[" << key;

        // Print the decision attributes for this instance
        for (unsigned int i = 0; i < decisionAttrs.getSize(); i++)
        {
          std::cout << ", " << db[ groupVals[0] ][ decisionAttrs[i] ];
        }
        std::cout << "], " << groupVals.getSize() << "]";

        // Remove Later
        for (int i = 0; i < groupVals.getSize(); i++)
                cout << groupVals[i] << " ";
        std::cout<< std::endl;
      }

    }

    void printDistribution (Database<std::string>& db)
    {
      std::string key;
      Vector<unsigned int> groupVals;

      cout << "Distribution of values for attribute ";
      for (unsigned int i = 0; i < m_attrs.getSize(); ++i)
      {
        std::cout << db.getAttr( m_attrs[i] ).getName();
        if (i < m_attrs.getSize() - 1)
          std::cout << ", ";
      }
      std::cout << ":" << std::endl;

      for (map<std::string, Vector<unsigned int> >::const_iterator it = m_map.begin(); it != m_map.end(); ++it)
      {
        key = it->first;
        groupVals = it->second;
        //std::cout << "  Value: " << key << "\tOccurrences: " << groupVals.getSize(); << std::endl;

        // Remove LAter
        std::cout << "  Value: " << key << "\tOccurrences: ";
        for (int i = 0; i < groupVals.getSize(); i++)
          cout << groupVals[i] << " ";
        std::cout<< std::endl;
      }

    }
    /*
     friend std::ostream& operator<<(std::ostream &os, const Partition &p)
     {
     std::string key;
     Vector<int> groupVals;

     for (map<std::string, Vector<int> >::const_iterator it = p.getMap().begin(); it != p.getMap().end(); ++it) {
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
    // @post   Returns the size of our m_partitionGroup Vector
    // *********************************************************************
    map<std::string, Vector<unsigned int> > getMap () const;

  private:
    map<std::string, Vector<unsigned int> > m_map;
    Vector<unsigned int> m_attrs; // Each partition is associated with one or more attributes
};

#include "partition.hpp"
#endif














