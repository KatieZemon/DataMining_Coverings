//****************************************************************************
//  Name:        Camaro Walker and Katie Isbell
//  File:        driver.cpp
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     The purpose of this assignment is to produce association
//               rules for a given database using the rule of induction for
//               coverings
//****************************************************************************
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>
#include "vector.h"
#include "matrix.h"
#include "database.h"
#include "attribute.h"
#include <map>
#include <set>
#include <vector>
#include "partition.h"
using namespace std;

// Function prototypes
void setDecisionAttributes (Database<string>& db);
bool isSubset (const Vector<Vector<unsigned int> >& v1,const Vector<unsigned int>& v2);

int main ()
{
  Database<std::string> db;
  std::string fileName;

  // Greeting
  std::cout << "This program will return all coverings for a given database " << std::endl << std::endl;

  // Get the file name
  // std::cout << "What is the name of the read file?" << std::endl;
  // std::cin >> fileName;
  // std::cout << std::endl;*/
  fileName = "weatherData.arff";

  // Initialize our database with values from our file input
  db.initDatabase(fileName);

  // Set the decision attributes
  setDecisionAttributes(db);
  /*
   // Print Database values
   cout << "Our data values are as follows: " << std::endl;
   cout << db;
   cout << "Number of instances: " << db.getNumInstances() << endl;
   cout << "Number of attributes: " << db.getNumAttributes() << endl;
   cout << "Row 4 data: " << db[4] << endl;
   cout << "Row 4 column 1 data: " << db[4][1] << endl << endl;


   // Print Attribute properties
   cout << "Attribute Properties: " << endl;
   for (unsigned int i = 0; i < db.getNumAttributes(); i++)
   {
   cout << db.getAttr(i).getName() << " "
   << db.getAttr(i).getPossibleVals() << " ";

   if (db.getAttr(i).isNumeric())
   cout << "numeric ";
   else
   cout << "nominal ";
   vector<int>
   if (db.getAttr(i).isDecision())
   cout << "decision ";
   else
   cout << "nondecision";
   cout << endl;
   }*/

  // *** Rule of Induction Algorithm ***
  // Compute the partition of our decision attributes
  Vector<unsigned int> nonDecisionAttrs = db.getNonDecisionAttrs();
  Partition p3(db, db.getDecisionAttrs());

  // Print Results
  p3.printDistribution(db);
  cout << endl;
//  p4.printDistribution(db);

  // cout << "P4 <= P3? " << (p4 <= p3) << endl;

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

// Is a vector within v1 a subset of v2
// Assumes no repeating elements in either v1 or v2
bool isSubset (const Vector<Vector<unsigned int> >& v1,const Vector<unsigned int>& v2)
{
  for (unsigned int i = 0; i < v1.getSize(); i++)
  {
    if (isSubset(v1[i],v2))
      return true;
  }
  return false;
}


// setDecisionAttributes
void setDecisionAttributes(Database<string> &db)
{
  string input;
  unsigned int singleVal;
  Vector<unsigned int> decisionAttrs; // selected decision attributes

  // Print our menu
  cout << "~~Menu~~ " << endl;
  for (unsigned int i = 0; i < db.getNumAttributes(); i++)
  {
    cout << i+1 << ". " << db.getAttr(i).getName() << endl;
  }
  cout << endl;

  // Select the decision attributes
  cout << "Select your decision attributes." << endl;
  cout << "Enter numbers from the menu above separated by spaces" << endl;

  getline(cin,input);
  std::istringstream iss(input);

  while(iss >> singleVal)
  decisionAttrs.push_back( singleVal - 1 );

  db.setDecisionAttrs(decisionAttrs);
}

