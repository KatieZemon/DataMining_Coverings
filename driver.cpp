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
  std::string repeatProgram = "y";

  // Greeting
  std::cout << "This program will return the minimum coverings for a given database." << std::endl << std::endl;
//  do
 // {
    // Get the file name
    std::cout << "What is the name of the read file?" << std::endl;
    getline(cin, fileName);
    //TODO WITH CIN

    // Read from file and initialize our database values
    db.initDatabase(fileName);

    // Display the menu and set the decision attributes based on user input
    setDecisionAttributes(db);

    // Compute Rule of Induction to get the minimal Coverings
    ruleOfInduction(db);

   // std::cout << "Again? (y/n)" << std::endl;
   // getline(cin, repeatProgram);

//  } while (repeatProgram == "y" || repeatProgram == "yes");

}

// setDecisionAttributes
void setDecisionAttributes (Database<string> &db)
{
  string input;
  unsigned int singleVal;
  Vector<unsigned int> decisionAttrs; // selected decision attributes

  // Print our menu
  cout << endl << "The attributes for this dataset are as follows: " << endl;
  for (unsigned int i = 0; i < db.getNumAttributes(); i++)
  {
    cout << i + 1 << ". " << db.getAttr(i).getName() << endl;
  }
  cout << endl;

  // Select the decision attributes
  cout << "Specify your decision attributes from the list above. " << endl;
  cout << "Enter a list of numbers separated by spaces." << endl;

  getline(cin, input);
  std::istringstream iss(input);

  while (iss >> singleVal)
    decisionAttrs.push_back(singleVal - 1);

  db.setDecisionAttrs(decisionAttrs);
}

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
