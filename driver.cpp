//****************************************************************************
//  Name:        Katie Isbell
//  File:        driver.cpp
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     The purpose of this assignment is to produce association
//               rules for a given Dataset using the RICO algorithm
//****************************************************************************
#include <iostream>
#include <sstream>
#include <map>
#include "vector.h"
#include "matrix.h"
#include "dataset.h"
#include "attribute.h"
#include "rico.h"
#include "partition.h"
#include "incorrectInputError.h"

//**********************************************************************
// @fn     setDecisionAttributes
// @brief  Prints a menu of attributes within the dataset and prompts
//         the user to input the decision attributes. If input has been
//         given correctly, it flags the user-selected attributes as
//         decision attributes.
// @param  db - The Dataset which we use to find the minimal coverings
// @pre    We assume our Dataset has been initialized and that we have
//         a variety of possible choices for our decision attribute.
// @post   If input was correctly given, one or more attributes in our
//         Dataset are now flagged as being decision attributes.
//         Else an error will be printed to the screen telling the user
//         that he/she did not pick valid values to represent the
//         decision attributes
//**********************************************************************
void setDecisionAttributes (Dataset<string>& db);


//**********************************************************************
// @fn     printDecisionAttributes
// @brief  Prints the names of the decision attributes that were selected
// @param  db - The Dataset which we use to find the minimal coverings
// @pre    We assume the decision attributes for our dataset have been
//         set
// @post   The names of the decision attributes are printed to the screen
//**********************************************************************
void printDecisionAttributes (Dataset<string>& db);

//**********************************************************************
// @fn     main
// @brief  Main driver function for creating our Dataset and calling
//         the RICO algorithm
//**********************************************************************
int main ()
{
  Dataset<std::string> db; // Our Dataset
  std::string fileName; // The name of our read file
  RICO ruleOfInduction; // RICO algorithm

  // Greeting
  std::cout << "This program will return the minimum coverings for a given Dataset." << std::endl << std::endl;

  // Get the file name
  std::cout << "What is the name of the read file?" << std::endl;
  fileName = "datasets/contactLenses.arff"; // getline(cin, fileName);

  // Initialize Dataset values from the read file
  db.initDataset(fileName);

  // Display the menu and set the decision attributes based on user input
  setDecisionAttributes(db);

  // Print the decision attributes that were selected
  printDecisionAttributes(db);

  // Compute Rule of Induction to get the minimal Coverings
  ruleOfInduction(db);

}


void setDecisionAttributes (Dataset<string> &db)
{
  string input;
  unsigned int int_inputVal; // input value given by the user
  string string_inputVal;   // input value given by the user
  int numItemsInput = 0; // Total number of items input by the user
  int numIntegersInput = 0; // The total number of items input by the user that are integers
  Vector<unsigned int> decisionAttrs; // selected decision attributes

  // Print our menu
  cout << endl << "The attributes for this dataset are as follows: " << endl;
  for (unsigned int i = 0; i < db.getNumAttributes(); i++)
  {
    cout << i + 1 << ". " << db.getAttr(i).getName() << endl;
  }
  cout << endl;

  // Prompt the user to input a list of numbers
  cout << "Specify your decision attributes from the list above. " << endl;
  cout << "Enter a list of numbers separated by spaces." << endl;
  getline(cin, input);


  std::istringstream iss(input); // stringstream we use to iterate across all values input by the user
  std::istringstream iss2(input); // stringstream we use to iterate across only integer values input by the user

  // Count the number of total items input by the user
  while (iss2 >> string_inputVal)
  {
    numItemsInput++;
  }

  while (iss >> int_inputVal)
  {
    // Throw an error if the number input by the user is out of bounds
    if (int_inputVal < 1 || int_inputVal > db.getNumAttributes())
    {
      throw IncorrectInputError("Error! You did not input valid options for your decision attributes.");
    }
    decisionAttrs.push_back(int_inputVal - 1);

    numIntegersInput++;
  }

  // Throw an error if there were no decision attributes set (ie no integers were input) or
  // if the number of integers input is not equal to the number of items input (implying the user also input some extra characters)
  if (decisionAttrs.getSize() == 0 || numIntegersInput != numItemsInput)
  {
    throw IncorrectInputError("Error! You did not input valid options for your decision attributes.");
  }

  // Set our decision attributes
  db.setDecisionAttrs(decisionAttrs);
}


void printDecisionAttributes (Dataset<string> &db)
{
  // initialize our vector to hold our decision attributes
  Vector<unsigned int> attrs = db.getDecisionAttrs();

  // Print the names of the decision attributes
  cout << "\nThe selected decision attributes are: ";
  for (unsigned int i = 0; i < attrs.getSize(); i++)
  {
    cout << db.getAttr(attrs[i]).getName() << " ";
  }
  cout << endl << endl;

}

