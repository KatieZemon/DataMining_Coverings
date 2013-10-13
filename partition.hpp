//**************************************************************************
//  Name:        Katie Isbell and Camaro Walker
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

bool Partition::operator<= (const Partition &p1) const
{
  std::string key1, key;
  Vector<unsigned int> groupVals1, groupVals;
  bool subset = true;
  map<std::string, Vector<unsigned int> > map1;
  map1 = p1.getMap();

  for (map<std::string, Vector<unsigned int> >::const_iterator it1 = m_map.begin(); it1 != m_map.end() && subset == true; ++it1)
  {
    subset = false;
    key1 = it1->first;
    groupVals1 = it1->second;

    // Iterate through each group in P
    for (map<std::string, Vector<unsigned int> >::const_iterator it = map1.begin(); it != map1.end(); ++it)
    {
      key = it->first;
      groupVals = it->second;

      std::string pattern;

      // Is the selected group in P1 a subset of a group in P?
      if (isSubset(groupVals1, groupVals))
      {
        subset = true;
        it == map1.end();
      }
    }
  }
  return subset;
}

