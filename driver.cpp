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
using namespace std;

// Function prototypes
vector<int> setDecisionAttributes(Database<string>& db);
map<std::string, vector<int> > computePartition(Database<std::string>& db, vector<int> a);

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


  // *** Rule of Induction Alcorithm ***

  // Compute the partition of our decision attributes
  map<std::string, vector<int> > p;
  p = computePartition(db, decisionAttributes);

  vector<int> n;
  n.push_back(1);

  // Compute the partition of our nonDecision attributes
  map<std::string, vector<int> > p1;
  p1 = computePartition(db, n);


  std::string key;
  vector<int> groupVals;

  // Print out our elements
  for (map<std::string, vector<int> >::const_iterator it = p.begin(); it != p.end(); ++it) {
     key = it->first;
     groupVals = it->second;

     cout << "{";
     for (unsigned int i = 0; i < groupVals.size(); i++)
       std::cout << " " << groupVals[i] << ",";
     cout<< " (" << key << ") }" << endl;
  }

  // Print out our elements
  for (map<std::string, vector<int> >::const_iterator it = p1.begin(); it != p1.end(); ++it) {
     key = it->first;
     groupVals = it->second;

     cout << "{";
     for (unsigned int i = 0; i < groupVals.size(); i++)
       std::cout << " " << groupVals[i] << ",";
     cout<< " (" << key << ") }" << endl;
  }

  // Is P1 a covering of P

  return 0;
}

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
/*
 * // Computes the partition for our attributes
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
 *
 */





 // cout << m[key] << endl;
  /*
  Vector<int> attributeList;
  attributeList.push_back(0);
  attributeList.push_back(2);

  Vector<Vector<int> > v;

  string pattern;
  for (unsigned int i = 0; i < db.getNumRows(); i++)
  {
    pattern = "";
    // Store our pattern
    for(unsigned int j = 0; j < attributeList.getSize(); j++)
    {
      pattern += db[i][ attributeList[j] ];
    }

    bool inserted = false;

    // Check whether an instance with this pattern already exists within our partition
    for (unsigned int j = 0; j < v.getSize(); j++)
    {
      // If it does, add the instance to this group
      if (v[j].getPattern() == pattern)
      {
        v[k].push_back(i);
        inserted = true;
      }
    }

    // If it does not, add a new subgroup
    if (!inserted)
    {
      v.addGroup(pattern);
      v[v.getSize()].push_back(i);
    }

    std::cout<< pattern << endl;
  }*/


















