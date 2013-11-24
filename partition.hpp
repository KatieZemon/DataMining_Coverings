//**************************************************************************
//  Name:        Katie Isbell
//  File:        partitiongroup.hpp
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     Define operators and functions for groups of integers
//               held within each partition
//**************************************************************************

// Constructor to initialize our map
Partition::Partition (const Dataset<std::string>& db, const Vector<unsigned int>& a)
{
  m_attrs = a;
  std::string key;
  for (unsigned int i = 0; i < db.getNumRows(); i++)
  {
    key = "";
    for (unsigned int j = 0; j < a.getSize(); j++)
    {
      key += db[i][a[j]]; // Cols
      if (j + 1 < a.getSize())
      {
        key += ", ";
      }
    }
    m_map[key].push_back(i);
  }
}

map<std::string, Vector<unsigned int> > Partition::getMap () const
{
  return m_map;
}

// Check if P <= P1
bool Partition::operator<= (const Partition &p1) const
{
  std::string key1, key;
  Vector<unsigned int> groupVals1, groupVals;
  bool subset = true; // Is every block in P a subset of one of the sets in P1?
  map<std::string, Vector<unsigned int> > map1;
  map1 = p1.getMap();

  // Iterate through every block in P
  for (map<std::string, Vector<unsigned int> >::const_iterator it = m_map.begin(); it != m_map.end() && subset == true; ++it)
  {
    subset = false;
    key = it->first;
    groupVals = it->second;

    // Iterate through every set in P1
    for (map<std::string, Vector<unsigned int> >::const_iterator it1 = map1.begin(); it1 != map1.end(); ++it1)
    {
      key1 = it1->first;
      groupVals1 = it1->second;
      // This block in P must be a subset of one of the blocks in P1
      if (groupVals.isSubset(groupVals1))
      {
        subset = true;
        it == map1.end();
      }
    }
  }
  return subset;
}

// Print our rule sets
void Partition::print (Dataset<std::string>& db)
{
  std::string key;
  Vector<unsigned int> groupVals;
  Vector<unsigned int> decisionAttrs = db.getDecisionAttrs();

  std::cout << "Rules for covering [";
  // Print out the names of the attributes for this partition
  for (unsigned int i = 0; i < m_attrs.getSize(); ++i)
  {
    std::cout << db.getAttr(m_attrs[i]).getName();
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
      std::cout << ", " << db[groupVals[0]][decisionAttrs[i]];
    }
    std::cout << "], " << groupVals.getSize() << "]";

    std::cout << std::endl;

  }

}

// Print the distribution for all possible combinations of the decision attributes
void Partition::printDistribution (Dataset<std::string>& db)
{
  Vector<unsigned int> v, right;
  Vector<Vector<unsigned int> > left, newLeft, coverings;

  for (unsigned int i = 0; i < m_attrs.getSize(); i++)
  {
    v.push_back(m_attrs[i]);
    left.push_back(v);
    right.push_back(m_attrs[i]);
    printSingleDistribution(db, v);
    std::cout << std::endl;
    v.clear();
  }
  unsigned int nextLoc = 0;
  unsigned int x = 0;
  for (unsigned int m = 0; m < m_attrs.getSize() + 1; m++)
  {
    for (unsigned int i = 0; i < left.getSize(); i++)
    {
      nextLoc = 0;
      x = left[i][left[i].getSize() - 1]; // Last digit of array

      for (unsigned int y = 0; x != right[y]; y++)
        nextLoc++; // Location of first digit to grab from right

      for (unsigned int j = nextLoc + 1; j < right.getSize(); j++) // Right half
      {
        for (unsigned int k = 0; k < left[i].getSize(); k++)
        {
          v.push_back(left[i][k]);
        }
        v.push_back(right[j]);
        printSingleDistribution(db, v);
        std::cout << std::endl;
        newLeft.push_back(v);

        v.clear();
      }
    }
    left = newLeft;
    newLeft.clear();
  }
}

void Partition::printSingleDistribution (Dataset<std::string>& db, Vector<unsigned int> attrs)
{
  std::string key;
  Vector<unsigned int> groupVals;

  cout << "Distribution of values for attribute ";
  for (unsigned int i = 0; i < attrs.getSize(); ++i)
  {
    std::cout << db.getAttr(attrs[i]).getName();
    if (i < attrs.getSize() - 1)
      std::cout << ", ";
  }
  std::cout << ":" << std::endl;

  for (map<std::string, Vector<unsigned int> >::const_iterator it = m_map.begin(); it != m_map.end(); ++it)
  {
    key = it->first;
    groupVals = it->second;
    std::cout << "  Value: " << key << "\tOccurrences: " << groupVals.getSize() << " ";

    //TODO: Remove later
    std::cout << "Rows: ";
    for (unsigned int i = 0; i < groupVals.getSize(); i++)
      cout << groupVals[i] << " ";
    std::cout << std::endl;
  }

}

