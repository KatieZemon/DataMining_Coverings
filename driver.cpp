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
vector<int> setDecisionAttributes(Database<string>& db);
map<std::string, vector<int> > computePartition(Database<std::string>& db, vector<int> a);
bool isSubset(const std::vector<int>& a, const std::vector<int>& b);

int main()
{
  Database<std::string> db;
  std::string fileName;

  // Greeting
  std::cout << "This program will return all coverings for a given database " << std::endl << std::endl;

  // Get the file name
  // std::cout << "What is the name of the read file?" << std::endl;
  // std::cin >> fileName;
  // std::cout << std::endl;*/
  fileName = "table3_10_fg.arff";

  // Initialize our database
  db.initDatabase(fileName);

  // Set our decision attributes
  vector<int> decisionAttributes = setDecisionAttributes(db);
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
 // map<std::string, vector<int> > p;
//  p = computePartition(db, decisionAttributes);

  vector<int> n;
  n.push_back(1);

  // Compute the partition of our nonDecision attributes
 // map<std::string, vector<int> > p1;
//  p1 = computePartition(db, n);


  Partition p3(db, decisionAttributes);
  Partition p4(db,n);
  cout << p3 << endl;
  cout << p4;
  cout << endl << endl;

  p3.print();
  cout << endl;
  p4.print();


  cout << "P4 <= P3? " << (p4 <= p3) << endl;

/*
  // Is P1 <= P???
  bool subset = true;
  for (map<std::string, vector<int> >::const_iterator it1 = p1.begin(); it1 != p1.end() && subset == true; ++it1)
  {
    subset = false;
    key1 = it1->first;
    groupVals1 = it1->second;

    // Iterate through each group in P
    for (map<std::string, vector<int> >::const_iterator it = p.begin(); it != p.end(); ++it)
    {
      key = it->first;
      groupVals = it->second;

      std::string pattern;

      // Is the selected group in P1 a subset of a group in P?
      if ( isSubset(groupVals1, groupVals) )
      {
        subset = true;
        it == p.end();
      }
    }
  }*/

 // std::cout << "Subset? " << subset<< std::endl;

  return 0;
}
/*
// Is vector b a subset of vector a
bool isSubset(const std::vector<int>& a, const std::vector<int>& b)
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
}*/

// setDecisionAttributes
vector<int> setDecisionAttributes(Database<string> &db)
{
  string input;
  unsigned int singleVal;
  vector<int> decisionAttrs; // selected decision attributes

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

  //db.setDecisionAttrs(decisionAttrs);

  return decisionAttrs;
}


// Computes the partition for our attributes
// @param a - the column numbers of our attributes
map<std::string, vector<int> > computePartition(Database<string> &db, vector<int> a)
{
  map<std::string, vector<int> > p;

  // Push elements onto the map
  std::string key;
  for(unsigned int i = 0; i < db.getNumRows(); i++)
  {
    key = "";
    for (unsigned int j = 0; j < a.size(); j++)
    {
      key += db[i][ a[j] ]; // Cols
      if (j+1 < a.size() ) { key += ", "; }
    }
    p[key].push_back(i);
  }
  return p;
}

















