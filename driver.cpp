//****************************************************************************
//  Name:        Katie Isbell and Camaro Walker
//  File:        driver.cpp
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     The purpose of this assignment is to produce association
//               rules for a given database using the rule of induction for
//               coverings
//****************************************************************************
#include <iostream>
#include <sstream>
#include <map>
#include "vector.h"
#include "matrix.h"
#include "database.h"
#include "attribute.h"
#include "rico.h"
#include "partition.h"

// Function prototypes
void setDecisionAttributes (Database<string>& db);


int main ()
{
  Database<std::string> db;
  std::string fileName;
  RICO ruleOfInduction;

  // Greeting
  std::cout << "This program will return the minimum coverings for a given database " << std::endl << std::endl;

  // Get the file name
  // std::cout << "What is the name of the read file?" << std::endl;
  // std::cin >> fileName;
  // std::cout << std::endl;*/
  fileName = "weatherData.arff";

  // Read from file and initialize our database values
  db.initDatabase(fileName);

  // Display the menu and set the decision attributes based on user input
  setDecisionAttributes(db);

  // Compute Rule of Induction to get the minimal Coverings
  ruleOfInduction(db);


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

