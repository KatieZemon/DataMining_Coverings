// //**************************************************************************
//  Name:        Katie Isbell
//  File:        thomas.hpp
//  Assignment:  Assignment 6
//  Date:        4/22/2013
//  Course:      CS328
//  Purpose:     This file computes the solution to Ax=b using Thomas'
//               algorithm
//**************************************************************************

// Operator ()
void RICO::operator()(Database<std::string> &db)
{
  Vector<unsigned int> nonDecisionAttrs = db.getNonDecisionAttrs();
  Partition p3(db, db.getDecisionAttrs());

  p3.printDistribution(db);
  std::cout << std::endl;

  Vector<unsigned int> v, right;
  Vector<Vector<unsigned int> > left, newLeft, coverings;
  unsigned int nextLoc, x;
  for (unsigned int i = 0; i < nonDecisionAttrs.getSize(); i++)
  {
    v.push_back(nonDecisionAttrs[i]);
    Partition p(db,v);

    if (p <= p3) // Covering
    {
      coverings.push_back(v);
      p.print(db);
    }
    else
    {
      left.push_back(v);
      right.push_back(nonDecisionAttrs[i]);
    }
    v.clear();
  }

  for (unsigned int m = 0; m < nonDecisionAttrs.getSize(); m++) // Combinations of m letters
  {
    for (unsigned int i = 0; i < left.getSize(); i++) // Left half
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

        // Check if one of the previously declared coverings is a subset of v
        if (isSubset(coverings,v))
        {
        }

        else
        {
          Partition p(db,v);
          if (p <= p3)
          {
            coverings.push_back(v);
            p.print(db);
            cout << endl;

          }
          else
          {
            newLeft.push_back(v);
          }
        }

        v.clear();
      }
    }
    left = newLeft;
    newLeft.clear();
  }


}

// Is one of the vectors inside of v1 a subset of v2
// Assumes no repeating elements in either v1 or v2
bool isSubset (Vector<Vector<unsigned int> > v1,Vector<unsigned int> v2)
{
  for (unsigned int i = 0; i < v1.getSize(); i++)
  {
    if (v1[i].isSubset(v2))
      return true;
  }
  return false;
}

