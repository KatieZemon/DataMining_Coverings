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


/*
  unsigned int i = 0;

  while (getline(in,line))
  {
    iss << line;

    for (unsigned int j = 0; j < numCols; j++)
    {
      getline(iss, a[i][j], ',');
    }
    iss.clear();
    i++;
  }
  return in;
  */



/*
 // Operator + for Matrix + Matrix
 template <class T>
 Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs) const
 {
 Matrix<T> result(*this);// Copy the lhs Matrix into a new Matrix named result
 return result += rhs;
 }

 // Operator += for Matrix += Matrix
 template <class T>
 Matrix<T>& Matrix<T>::operator+=(const Matrix<T> &rhs)
 {
 // Check that both matrices are the same size
 if(m_numRows != rhs.m_numRows || m_numCols != rhs.m_numCols)
 {
 throw SizeMismatchError();
 }

 // Add the two Matrices
 for (int i = 0; i < m_numRows; i++)
 {
 // Add the Vectors in the i'th row
 elm[i] += rhs.elm[i];
 }
 return *this;
 }

 // Operator - for Matrix - Matrix
 template <class T>
 Matrix<T> Matrix<T>::operator-(const Matrix<T> &rhs) const
 {
 Matrix<T> result(*this); // Copy lhs into a new Matrix named result
 return result -= rhs;
 }

 // Operator -= for Matrix -= Matrix
 template <class T>
 Matrix<T>& Matrix<T>::operator-=(const Matrix<T> &rhs)
 {
 // Check that both matrices are the same size
 if(m_numRows != rhs.m_numRows || m_numCols != rhs.m_numCols)
 {
 throw SizeMismatchError();
 }

 // Subtract the two Matrices
 for (int i = 0; i < m_numRows; i++)
 {
 elm[i] -= rhs.elm[i];
 }
 return *this;
 }

 // Operator == for Matrix == Matrix
 template <class T>
 bool Matrix<T>::operator==(const Matrix<T> &rhs) const
 {
 // Check whether the Matrices have the same number of rows and cols
 if (m_numRows != rhs.m_numRows || m_numCols != rhs.m_numCols)
 {
 return false;
 }

 // Else, Compare Vectors within each Matrix
 for (unsigned int i = 0; i < rhs.m_numRows; i++)
 {
 // If a difference is found, return false.
 if (elm[i] != rhs.elm[i])
 return false;
 }
 return true;
 }

 // Operator != for Matrix != Matrix
 template <class T>
 bool Matrix<T>::operator !=(const Matrix<T> &rhs) const
 {
 return !(*this == rhs);
 }

 // Operator * for Matrix * scalar
 template <class T>
 Matrix<T> Matrix<T>::operator* (const T scalar) const
 {
 Matrix<T> result(*this); // copy lhs Matrix into a new Matrix named result
 return result *= scalar;
 }

 // Operator *= for Matrix *= scalar
 template <class T>
 Matrix<T> Matrix<T>::operator*= (const T scalar)
 {
 // Multiply the scalar by each array in the Matrix
 for (unsigned int i = 0; i < m_numRows; i++)
 {
 elm[i] *= scalar;
 }
 return *this;
 }

 // Operator * for scalar * Matrix
 template<typename T2>
 Matrix<T2> operator*(const T2 scalar, const Matrix<T2> &m)
 {
 return m * scalar;
 }

 // Operator* for Matrix * Matrix
 template <class T>
 Matrix<T> Matrix<T>::operator* (const Matrix<T> &rhs) const
 {
 Matrix<T> result(*this);
 return result *= rhs;
 }

 // Operator *= for Matrix * Matrix
 template <class T>
 Matrix<T> Matrix<T>::operator*= (const Matrix<T> &rhs)
 {
 // Check that the number of columns of lhs equals the number
 // of rows of rhs
 if (m_numCols != rhs.m_numRows)
 {
 throw SizeMismatchError();
 }
 // Create a new matrix to store the product
 Matrix<T> product(m_numRows,rhs.m_numCols);

 // Multiply the two matrices
 for (unsigned int i = 0; i < rhs.m_numCols; i++)
 {
 for (unsigned int j = 0; j < m_numRows; j++)
 {
 for (unsigned int k = 0; k < m_numCols; k++)
 product.elm[j][i] += elm[j][k] * rhs.elm[k][i];
 }
 }

 return product;
 }

 // Operator* for Matrix * Vector
 template <class T>
 Vector<T> Matrix<T>::operator* (const Vector<T> &vect) const
 {
 // Check that the number of cols in the matrix equals the size of vect
 if(m_numCols != vect.getSize() )
 {
 throw SizeMismatchError();
 }

 // Create a new vector to store the result with all elements initialized to zero
 Vector<T> result(vect.getSize());

 // Multiply the Matrix and Vector
 for (unsigned int i = 0; i < m_numRows; i++)
 {
 for (unsigned int j = 0; j < m_numCols; j++)
 {
 result[i] += elm[i][j] * vect[j];
 }
 }
 return result;
 }

 // Operator* for Vector * Matrix
 template<typename T2>
 Vector<T2> operator* (const Vector<T2> &vect, const Matrix<T2> &matrix)
 {
 unsigned int numRows = matrix.getNumRows();
 unsigned int numCols = matrix.getNumCols();
 unsigned int vectSize = vect.getSize();

 // Check that the size of the vector equals the number of rows in the matrix
 if(vectSize != numRows )
 {
 throw SizeMismatchError();
 }

 // Create a new vector to store the result with all elements initialized to zero
 Vector<T2> result(vectSize);
 
 // Multiply the Vector by the Matrix
 for (unsigned int i = 0; i < numCols; i++)
 {
 for (unsigned int j = 0; j < numRows; j++)
 {
 result[i] += matrix[j][i] * vect[j];
 }
 }
 return result;
 }

 // Operator / for Matrix / scalar
 template <class T>
 Matrix<T> Matrix<T>::operator/(const T scalar) const
 {
 Matrix<T> result(*this);  // The resulting Matrix to be returned
 return result /= scalar;
 }

 // Operator /=
 template <class T>
 Matrix<T> Matrix<T>::operator/= (const T scalar)
 {
 if (scalar == 0)
 {
 throw DivisionByZeroError();
 }
 // Divide the each element in the Matrix by the scalar
 for (unsigned int i = 0; i < m_numRows; i++)
 {
 for (unsigned int j = 0; j < m_numCols; j++)
 {
 elm[i][j] /= scalar;
 }
 }
 return *this;
 }

 // Operator - for negation
 template <class T>
 Matrix<T> Matrix<T>::operator-() const
 {
 Matrix<T> result(*this);
 for (unsigned int i = 0; i < m_numRows; i++)
 {
 for(unsigned int j = 0; j < m_numCols; j++)
 {
 if (elm[i][j] != 0)         // For displaying 0 instead of -0
 result.elm[i][j] *= -1;
 }
 }
 return result;
 }
 */
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

template<class T>
bool Matrix<T>::isDiagonallyDominant () const
{
  int size = m_numRows;
  int elmValue;

  // Check that the matrix is a square matrix
  if (m_numRows != m_numCols)
  {
    throw SizeMismatchError();
  }

  // Check that the matrix has at least 1 element
  if (size == 0)
  {
    throw SizeMismatchError();
  }

  // Determine if the matrix m is diagonally dominant
  for (unsigned int i = 0; i < size; i++)
  {
    elmValue = std::abs(m_elm[i][i]);

    // Check that abs(elm[i][i]) is greater than the sum of the
    // absolute values of the elements in the same row
    for (unsigned int j = 0; j < size; j++)
    {
      if (i != j)
        elmValue -= std::abs(m_elm[i][j]);
      if (elmValue < 0)
        return false;
    }
  }
  return true;
}

