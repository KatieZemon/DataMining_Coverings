//**************************************************************************
//  Name:        Camaro Walker and Katie Isbell
//  File:        vector.hpp
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     Define operators and functions for the mathematical
//               Vector class
//**************************************************************************

// Default Constructor
template <class T>
Vector<T>::Vector()
{
  m_size = 0;
  m_data = NULL;
}

// Constructor to initialize Vectors
template <class T>
Vector<T>::Vector(const unsigned int numCoefficients)
{
  m_size = numCoefficients;
  m_data = new T[m_size];
}

// Copy Constructor
template <class T>
Vector<T>::Vector(const Vector<T> &v)
{
  m_size = 0;
  *this = v;
}

// Destructor
template <class T>
Vector<T>::~Vector ()
{
  this->clear();
}


// Operator = for Assignment
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T> &rhs)
{
  this->clear();
  m_size = rhs.m_size;
  m_data = new T[m_size];

  for (unsigned short i = 0; i < rhs.m_size; ++i)
  {
    m_data[i] = rhs.m_data[i];
  }

  return *this;
}

// Operator[] for setting the value of an element in m_data
template <class T>
T& Vector<T>::operator[](const unsigned int i)
{
  // Throw an exception if we are out of bounds
  if (i >= m_size)
  {
    throw SubscriptRangeError(i);
  } 
  return m_data[i];
}

// Operator[] for getting the value of an element in m_data
template <class T>
const T& Vector<T>::operator[](const unsigned int i) const
{
  // Throw an exception if we are out of bounds
  if (i >= m_size)
  {
    throw SubscriptRangeError(i);
  }
  return m_data[i];
}

// Operator <<
template <typename T2>
std::ostream& operator<<(std::ostream &os, const Vector<T2> &v)
{
  os << "<";
  for (unsigned int i = 0; i < v.m_size; i++)
  {
    os << v.m_data[i];
    if (i < v.m_size - 1)
    {
      os << ", ";
    }
  }
  os << ">";
  return os;
}

// Operator >>
template <typename T2>
std::istream& operator>>(std::istream &in, Vector<T2> &v)
{
  unsigned int size = v.getSize();
  
  // Initialize elements in the Vector
  for (unsigned int i = 0; i < size; ++i)
  {
    in >> v[i];
  }
  return in;
}


// Operator + for Vector + Vector
template <class T>
Vector<T> Vector<T>::operator+(const Vector<T> &rhs) const
{
  Vector<T> result(*this); // Copy the lhs Vector into a new Vector named result
  return result += rhs;    // result = lhs + rhs, saves code space
}

// Operator += for Vector += Vector
template <class T>
Vector<T>& Vector<T>::operator+=(const Vector<T> &rhs)
{
  // Throw sizeMismatch exception if the Vectors are not the same size
  if (m_size != rhs.m_size)
  {
    throw SizeMismatchError();
  }
  
  for (int i = 0; i < rhs.m_size; i++)
  {
    m_data[i] += rhs.m_data[i];
  }
  return *this;
}

// Operator - for Vector - Vector
template <class T>
Vector<T> Vector<T>::operator-(const Vector<T> &rhs) const
{
  Vector<T> result(*this); // Copy lhs into a new Vector named result
  return result -= rhs;    // result = lhs - rhs
}

// Operator -= for Vector -= Vector
template <class T>
Vector<T>& Vector<T>::operator-=(const Vector<T> &rhs)
{
  // Throw sizeMismatch exception if the Vectors are not the same size
  if (m_size != rhs.m_size)
  {
    throw SizeMismatchError();
  }
  
  for (unsigned short i = 0; i < rhs.m_size; i++)
  {
    m_data[i] -= rhs.m_data[i]; // lhs -= rhs
  }
  return *this;
}

// Operator == for Vector == Vector
template <class T>
bool Vector<T>::operator==(const Vector<T> &rhs) const
{
  // If the two Vectors have different sizes, return false
  if (m_size != rhs.m_size)
  {
    return false;
  }
  
  // Else compare values of each element in both Vectors
  for (unsigned int i = 0; i < rhs.m_size; i++)
  {
    // If a difference is found, return false.
    if (m_data[i] != rhs.m_data[i])
    {
      return false;
    }
  }
  return true;
}

// Operator != for Vector != Vector
template <class T>
bool Vector<T>::operator !=(const Vector<T> &rhs) const
{
  return !(*this == rhs);
}

// Operator * for Vector * scalar
template <class T>
Vector<T> Vector<T>::operator* (const T scalar) const
{
  Vector<T> result(*this); // copy lhs Vector into a new Vector named result
  return result *= scalar;
}

// Operator *= for Vector *= scalar
template <class T>
Vector<T> Vector<T>::operator*= (const T scalar)
{
  // Multiply the scalar by each element in the Vector
  for (unsigned int i = 0; i < m_size; i++)
  {
    m_data[i] *= scalar;
  }
  return *this;
}

// Operator * for scalar * Vector
template<typename T1, typename T2>
Vector<T1> operator*(const T2 scalar, const Vector<T1> &v)
{
  return v * scalar;
}

// Operator* for Vector * Vector (Dot Product)
template <class T>
T Vector<T>::operator*(const Vector<T> &rhs) const
{
  // Throw sizeMismatch exception if the Vectors are not the same size
  if (m_size != rhs.m_size)
  {
    throw SizeMismatchError();
  }
  
  T result = 0;
  
  // Calculate the dot product
  for (unsigned int i = 0; i < m_size; i++)
  {
    result += m_data[i] * rhs.m_data[i];
  }
  return result; 
}



// Operator/ for Vector / scalar
template <class T>
Vector<T> Vector<T>::operator/(const T scalar) const
{
  Vector<T> result(*this);  // The resulting Vector to be returned
  return result /= scalar;
}

// Operator/= for Vector /= scalar
template <class T>
Vector<T> Vector<T>::operator/= (const T scalar)
{
  if (scalar == 0)
  {
    throw DivisionByZeroError();
  }
  // Divide the each element in the Vector by the scalar
  for (unsigned int i = 0; i < m_size; i++)
  {
    m_data[i] /= scalar;
  }
  return *this;
}

// Operator ~ for magnitude
template <class T>
T Vector<T>::operator~() const
{
  return (*this).mag();
}

// Operator - for negation
template <class T>
Vector<T> Vector<T>::operator-() const
{
  Vector<T> result(*this);
  for (unsigned short i = 0; i < m_size; i++)
  {
    if (m_data[i] != 0)         // For displaying 0 instead of -0
      result.m_data[i] *= -1;
  }
  return result;
}

// Clear a Vector
template <class T>
void Vector<T>::clear()
{
  // Delete contents of m_data as long as it contains elements
  if (0 != m_size)
  {
    delete[] m_data;
    m_size = 0;
  }
}

// Magnitude = square root of the sum of squares of each coefficient in the Vector
template <class T>
T Vector<T>::mag() const
{
  T magnitude = 0;
  for (unsigned int i = 0; i < m_size; i++)
  {
    magnitude += m_data[i] * m_data[i];
  }

  magnitude = sqrt(magnitude);
  return magnitude;
}

// Find the projection of Vector u onto Vector v
template <typename T>
Vector<T> Vector<T>::proj(const Vector<T> &u, const Vector<T> &v) const
{
  // Equation for finding the projection of u onto v
  Vector<T> result = ((u * v) / (u * u) ) * u;
  return result;
}

template <typename T>
void Vector<T>::setSize(int numCoefficients)
{
  m_size = numCoefficients;
  m_data = new T[m_size];
}

