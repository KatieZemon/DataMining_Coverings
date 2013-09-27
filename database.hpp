//**************************************************************************
//  Name:        Camaro Walker and Katie Isbell
//  File:        Database.hpp
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     Define operators and functions for the Database class
//**************************************************************************



// Constructor
template <class T>
Database<T>::Database(const unsigned int numRows, const unsigned int numCols)
{
  Matrix<T>::Matrix(numRows, numCols);
  
  // Set each column name to be "Untitled" by default
  m_col_name = new std::string[numCols];
  for (unsigned int i = 0; i < numCols; i++)
  {
    m_col_name[i] = "Untitled";
  }
}

// Copy Constructor
template <class T>
Database<T>::Database(const Database<T> &m)
{
  *this = m;
}


// Operator = for Assignment
template <class T>
Database<T>& Database<T>::operator=(const Database<T> &rhs)
{
  this->clear();
  Matrix<T>::m_numRows = rhs.m_numRows;
  Matrix<T>::m_numCols = rhs.m_numCols;
  Matrix<T>::elm = new Vector<T>[Matrix<T>::m_numRows];

  for (unsigned int i = 0; i < rhs.m_numRows; ++i)
  {
    Matrix<T>::elm[i] = rhs.elm[i];
  }

  m_col_name = new std::string[Matrix<T>::m_numCols];
  
  for (unsigned int i = 0; i < Matrix<T>::m_numCols; ++i)
  {
    m_col_name[i] = rhs.m_col_name[i];
  }

  return *this;
}


// Destructor
template <class T>
Database<T>::~Database()
{
  this->clear();
}

/* Operator >> for inserting values into the Database
template <typename T2>
std::istream& operator>>(std::istream &in, Database<T2> &a)
{ 
 // in >> (Matrix<T2>)a;
}*/

// Clear a Database
template <class T>
void Database<T>::clear()
{
  if (0 != Matrix<T>::m_numRows)
  {
    Matrix<T>::clear();
    delete[] m_col_name;
  }
}


// Clear and set size
template<class T>
void Database<T>::setSize(const unsigned int numRows, const unsigned int numCols)
{ 
  Matrix<T>::setSize(numRows, numCols);
  
  // Set each column name to be "Untitled" by default
  m_col_name = new std::string[numCols];
  for (unsigned int i = 0; i < numCols; i++)
  {
    m_col_name[i] = "Untitled";
  }
}


// Set the name of a column
template <class T>
void Database<T>:: setAttributeName(unsigned int i, std::string name)
{
  if (i >= Matrix<T>::m_numCols || Matrix<T>::m_numCols == 0)
  {
    throw SubscriptRangeError(i);
  }
  m_col_name[i] = name;
}

// Get the name of the column
template <class T>
std::string Database<T>:: getAttributeName(unsigned int i) const
{
  if (i >= Matrix<T>::m_numCols || Matrix<T>::m_numCols == 0)
  {
    throw SubscriptRangeError(i);
  }
  return m_col_name[i];
}





