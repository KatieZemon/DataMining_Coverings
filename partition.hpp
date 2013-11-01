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
Partition::Partition (const Database<std::string>& db, const Vector<unsigned int>& a)
{
  m_attrs = a;
  std::string key;
  for(unsigned int i = 0; i < db.getNumRows(); i++)
  {
    key = "";
    for (unsigned int j = 0; j < a.getSize(); j++)
    {
      key += db[i][ a[j] ]; // Cols
      if (j+1 < a.getSize() )
      { key += ", ";}
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




