//**************************************************************************
//  Name:        Camaro Walker and Katie Isbell
//  File:        Database.hpp
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     Define operators and functions for the Database class
//**************************************************************************




// Constructor
template<class T>
Database<T>::Database (const unsigned int numRows, const unsigned int numCols)
{
  Matrix<T>::Matrix(numRows, numCols);
}

// Copy Constructor
template<class T>
Database<T>::Database (const Database<T> &m)
{
  //Derived* rhs_d = dynamic_cast<Derived*>(&rhs);
  *this = m;
}

// Operator = for Assignment
template<class T>
Database<T>& Database<T>::operator= (const Database<T> &rhs)
{
  this->clear();
  Matrix<T>::m_numRows = rhs.m_numRows;
  Matrix<T>::m_numCols = rhs.m_numCols;
  Matrix<T>::elm = new Vector<T> [Matrix<T>::m_numRows];

  for (unsigned int i = 0; i < rhs.m_numRows; ++i)
  {
    Matrix<T>::elm[i] = rhs.elm[i];
  }

  return *this;
}

// Destructor
template<class T>
Database<T>::~Database ()
{
  this->clear();
}

// Initialize database values using read file
template<class T>
void Database<T>::initDatabase (const std::string fileName)
{
  std::string word;

  // Open the file
  std::ifstream file;
  /*
  unsigned int numRows = 0, numCols = 0; // number of instances and attributes

  file.open(fileName.c_str());

  ///////// get numRows and numCols from the file ///////////////
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
*/

  // Set the size of our database
  this->setSize(9, 6);


  file.open(fileName.c_str());

  // Read in data from input file
  do
  {
    file >> word;
  } while (word != "@attribute");

  // Store our Attributes
  for (unsigned int i = 0; word != "@data"; i++)
  {
    this->addAttribute();

    // Set the attribute name
    file >> word;
    this->getAttr(i).setName(word);

    // Set the attribute possible values
    file >> word;
    this->getAttr(i).setPossibleVals(word);

    file >> word; // @attribute
  }

  // Initialize data values
  file >> *this;
  file.close();
}

// Clear a Database
template<class T>
void Database<T>::clear ()
{
  if (0 != Matrix<T>::m_numRows)
  {
    Matrix<T>::clear();
  }
  m_attributes.clear();
}

// Set Size (and clear)
template<class T>
void Database<T>::setSize (const unsigned int numRows, const unsigned int numCols)
{
  Matrix<T>::setSize(numRows, numCols);
}


// Get Attribute
template<class T>
Attribute& Database<T>::getAttr (unsigned int i)
{
  return m_attributes[i];
}

template<class T>
void Database<T>::addAttribute()
{
  Attribute a;
  addAttribute(a);
}

template<class T>
void Database<T>::setDecisionAttrs(Vector<unsigned int> decisionAttrs)
{
  for (unsigned int i = 0; i < decisionAttrs.getSize(); i++)
  {
    m_attributes[i].setDecision(true);
  }
}




