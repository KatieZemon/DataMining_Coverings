//****************************************************************************
//  Name:        Camero Walker and Katie Isbell
//  File:        instance.hpp
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     Create an attribute class to hold one instance
//****************************************************************************
#include <iostream>
#include <fstream>
#include <cmath>
#include "vector.h"
#include "matrix.h"

int main()
{
  // Declare Variables
  Matrix<int> data_instances; // stores all instances
  unsigned int size; // number of rows and columns of our matrix
  std::string fileName;

  // Greeting
  std::cout << "This program will return all coverings for a given database " <<
  std::endl << std::endl;

  // Get the file name
  std::cout << "What is the name of the read file?" << std::endl;
  std::cin >> fileName;
  std::cout << std::endl;

  // Initialize the Matrix using the input file
  std::ifstream file;
  file.open(fileName.c_str());
  file >> size;
	
  // Store values for the first matrix
  data_instances.setSize(size, size);
  file >> data_instances;
  file.close();

  // Print the values
  std::cout << "Our data values are as follows: " << std::endl;
  std::cout << data_instances << std::endl;
	
	
	return 0;
}

