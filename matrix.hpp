//**************************************************************************
//  Name:        Katie Isbell
//  File:        matrix.hpp
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     Define operators and functions for the Matrix class
//**************************************************************************

// Constructor to initialize Matrix
template<class T>
Matrix<T>::Matrix (const unsigned int numRows, const unsigned int numCols)
{
  // It is possible to have a 0x0 matrix. You cannot, however, have a 0xn or nx0
  // matrix
  if ((numRows == 0 && numCols != 0) || (numRows != 0 && numCols == 0))
  {
    throw SizeMismatchError();
  }

  m_numRows = numRows;
  m_numCols = numCols;

  m_elm = new Vector<Vector<T> >;

  for (unsigned int i = 0; i < numCols; i++)
  {
    m_elm[i].setSize(numCols); // We know the number of instances before hand
  }

}

// Copy Constructor
template<class T>
Matrix<T>::Matrix (const Matrix<T> &m)
{
  *this = m;
}

// Destructor
template<class T>
Matrix<T>::~Matrix ()
{
  this->clear();
}

// Operator = for Assignment
template<class T>
Matrix<T>& Matrix<T>::operator= (const Matrix<T> &rhs)
{
  this->clear();
  m_numRows = rhs.m_numRows;
  m_numCols = rhs.m_numCols;
  m_elm = rhs.m_elm;

  return *this;
}

// Operator[] for getting a row in the Matrix A
template<class T>
const Vector<T>& Matrix<T>::operator[] (const unsigned int rowIndex) const
{
  if (rowIndex >= m_numRows)
  {
    // Out of bounds. Throw an exception
    throw SubscriptRangeError(rowIndex);
  }
  return m_elm[rowIndex];
}

// Operator[] for setting a row in the Matrix A
template<class T>
Vector<T>& Matrix<T>::operator[] (const unsigned int rowIndex)
{
  if (rowIndex >= m_numRows)
  {
    // Out of bounds. Throw an exception
    throw SubscriptRangeError(rowIndex);
  }
  return m_elm[rowIndex];
}

// Operator << for printing the Matrix values
template<typename T>
std::ostream& operator<< (std::ostream &os, const Matrix<T> &m)
{
  for (unsigned int i = 0; i < m.m_numRows; i++)
  {
    for(unsigned int j = 0; j < m.m_numCols; j++)
    {
      os << m.m_elm[i][j] << " ";
    }
    os << "\n";
  }
  return os;
}

// Operator >> for inserting values into the Matrix
template<typename T2>
std::istream& operator>> (std::istream &in, Matrix<T2> &a)
{
  unsigned int numRows = a.getNumRows();
  unsigned int numCols = a.getNumCols();
  std::string line;
  std::stringstream iss;

  // Initialize the Matrix elements
  for (unsigned int i = 0; i < numRows; ++i)
  {
    // Get the entire row
    getline(in,line);
    iss << line;
    for (unsigned int j = 0; j < numCols; j++)
    {
      getline(iss, a[i][j], ',');
    }
    iss.clear();
  }
  return in;
}


// Clear a Matrix
template<class T>
void Matrix<T>::clear ()
{
  // Delete contents of m_data as long as it contains elements
  if (0 != m_numRows)
  {
    m_elm.clear();
    m_numRows = 0;
    m_numCols = 0;
  }
}

template<class T>
void Matrix<T>::setSize (const unsigned int numRows, const unsigned int numCols)
{
  m_numRows = numRows;
  m_numCols = numCols;

  m_elm.setSize(numRows);
  for (unsigned int i = 0; i < numRows; i++)
  {
    m_elm[i].setSize(numCols);
  }

}


