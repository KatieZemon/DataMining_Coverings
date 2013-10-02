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
using namespace std;

// Function prototypes
Vector<string> setDecisionAttributes(Database<string>& db);

int main()
{
  Database<std::string> db; // Our Database
  std::string fileName;
  Vector<string> v; // selected decision attributes

  // Greeting
  std::cout << "This program will return all coverings for a given database " << std::endl << std::endl;

  // Get the file name
  // std::cout << "What is the name of the read file?" << std::endl;
  // std::cin >> fileName;
  // std::cout << std::endl;*/
  fileName = "table3_10_fg.arff";
  
  // Initialize our database
  db.initDatabase(fileName); // Initialize database values using file

  // Set the decision attributes
  v = setDecisionAttributes(db); // Display menu and select decision attributes




/*
  // Print Database values
  cout << "Our data values are as follows: " << std::endl;
  cout << db;

  cout << "Number of instances: " << db.getNumInstances() << endl;
  cout << "Number of attributes: " << db.getNumAttributes() << endl;
  cout << "Row 4 data: " << db[4] << endl;
  cout << "Row 4 column 1 data: " << db[4][1] << endl << endl;


  // Print Attribute properties
  for (unsigned int i = 0; i < db.getNumAttributes(); i++)
  {
    cout << db.getAttr(i).getName() << " "
         << db.getAttr(i).getPossibleVals() << " ";

    if (db.getAttr(i).isNumeric())
      cout << "numeric ";
    else
      cout << "nominal ";

    if (db.getAttr(i).isDecision())
      cout << "decision ";
    else
      cout << "nondecision";
    cout << endl;
  }
*/
  return 0;
}

// setDecisionAttributes
Vector<string> setDecisionAttributes(Database<string> &db)
{
  string input, singleVal;
  Vector<string> v; // selected decision attributes
  bool validInput = true;

  // Print our menu
  cout << "~~Menu~~ " << endl;
  for (unsigned int i = 0; i < db.getNumAttributes(); i++)
  {
    cout << i+1 << ". " << db.getAttr(i).getName() << endl;
  }
  cout << endl;

  // Select the decision attributes
  cout << "Select your decision attributes." << endl;
  cout<< "Enter numbers from the menu above separated by spaces" << endl;

  getline(cin,input);
  std::istringstream iss(input);

  while(iss >> singleVal)
      v.push_back( singleVal );

  return v;
}


