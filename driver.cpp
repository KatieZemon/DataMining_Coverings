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
#include "vector.h"
#include "matrix.h"
#include "database.h"
using namespace std;

int main()
{
  // Declare Variables
  Database<string> db1; // stores all of our data
  unsigned int numRows = 0, numCols = 0; // number of instances and attributes
  std::string fileName;
  string word;
  string word2;

  // Greeting
  std::cout << "This program will return all coverings for a given database " <<
  std::endl << std::endl;

  // Get the file name
  // std::cout << "What is the name of the read file?" << std::endl;
  // std::cin >> fileName;
  // std::cout << std::endl;
  fileName = "table3_10_fg.arff";
  
 
  // Open the file
  std::ifstream file;
  file.open(fileName.c_str());
  
  // get numRows and numCols from the file
  getline(file, word); // @relation table3_10_fg
  
  while (word != "@data")
  {
    getline(file, word);
    numCols++;
  }

  while (!file.eof())
  {
    getline(file, word);
    numRows++;
  }
  file.close();
  
  // Set the size of our database
  db1.setSize(9,6);
  
   // Open the file
  file.open(fileName.c_str());
  // Read in data from input file
  getline(file, word); // @relation table3_10_fg
   
  for (int i = 0; i < db1.getNumCols(); i++)
  {
    file >> word; // @attribute
    
    file >> word; // Attribute Name
    db1.setAttributeName(i,word); 
    
    file >> word; // Attribute Values
  } 

  file >> word; // @data
  
  // Initialize data values
  file >> db1;
  file.close();
  

  // Print the values
  for (int i = 0; i < db1.getNumCols(); i++)
  {
    cout << "Attribute " << i << " name: " << db1.getAttributeName(i) << endl;
  }
  cout << endl;
    
  std::cout << "Our data values are as follows: " << std::endl;
  std::cout << db1;
  
  cout << "Number of instances: " << db1.getNumInstances() << endl;
  cout << "Number of attributes: " << db1.getNumAttributes() << endl;
  cout << "The name of attribute 3: " << db1.getAttributeName(3) << endl;
  cout << "Row 4 data: " << db1[4] << endl;
  cout << "Row 4 column 1 data: " << db1[4][1] << endl;

  return 0;
}
