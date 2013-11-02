//**************************************************************************
//  Name:        Katie Isbell
//  File:        vector.h
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     Create a class for a specialized column Vector representing
//               an Attribute of our data.
// *************************************************************************
#ifndef VECTOR_H
#define VECTOR_H

#include "divisionByZeroError.h"
#include "subscriptRangeError.h"
#include "sizeMismatchError.h"

// *************************************************************************
// @class Vector
// @brief Functions used for creating a Vector
// *************************************************************************
template <class T> 
class Vector
{
  public:
    // *********************************************************************
    // @fn     Vector
    // @brief  Default Constructor
    // @pre    None
    // @post   The size of the Vector is initialized to zero
    // *********************************************************************
    Vector();

    // *********************************************************************
    // @fn     Vector
    // @brief  Constructor that sets a specified size of the Vector and sets
    //         all coefficient values to zero
    // @pre    None
    // @post   m_size is set to numCoefficients and all elements in m_data
    //         are set to zero.
    // *********************************************************************
    Vector(const unsigned int numCoefficients);

    // *********************************************************************
    // @fn     Vector
    // @brief  Copy Constructor: Vector coefficient values are copied from
    //         the original Vector to the new Vector.
    // @pre    None
    // @post   The new Vector is an exact copy of the original Vector. It
    //         has the same size and data values as the original Vector.
    // *********************************************************************
    Vector(const Vector<T> &v);
    
    // *********************************************************************
    // @fn     ~Vector
    // @brief  Destructor that clears the Vector
    // @pre    None
    // @post   The size of the Vector is set to zero and the data has been
    //         cleared
    // *********************************************************************
    ~Vector();

    // *********************************************************************
    // @fn     operator =
    // @brief  Assigns one vector to another vector
    // @pre    None
    // @post   The resulting Vector on the lhs will be a copy of the Vector
    //         on the rhs
    // *********************************************************************
    Vector<T>& operator= (const Vector<T> &rhs);

    // *********************************************************************
    // @fn     operator []
    // @brief  Sets the value in the Vector at the specified index
    // @pre    None
    // @post   Sets the value at index i
    // *********************************************************************
    T& operator[] (const unsigned int i);
    
    // *********************************************************************
    // @fn     operator []
    // @brief  Gets the value in the Vector at the specified index
    // @pre    The parameter must be greater than or equal to 0 and less
    //         than m_size.
    // @post   Gets the value at index i
    // *********************************************************************
    const T& operator[] (const unsigned int i) const;
    
    // *********************************************************************
    // @fn     operator <<
    // @brief  Insertion operator used for printing
    // @pre    Type T should support <<
    // @post   returns an ostream that can be used for printing the Vector
    //         coefficients to the screen
    // *********************************************************************
    template <typename T2>
    friend std::ostream& operator<< (std::ostream &os, const Vector<T2> &v);
    
    // *********************************************************************
    // @fn     operator >>
    // @brief  Extraction operator used for initializing Vector coefficients
    // @pre    Type T should support >>
    // @post   Returns an istream used to set the values of the Vector
    //         coefficients
    // *********************************************************************
    template <typename T2>
    friend std::istream& operator>> (std::istream &is, const Vector<T2> &v);
    
    // *************************************************************************
    // @fn     operator +
    // @brief  Adds two Vectors
    // @pre    The two Vectors must have the same size and type, T. Type T
    //         must have operator +=
    // @post   Returns the sum of the two Vectors. The resulting Vector
    //         will have elements of type T, the same arithmetic type of the
    //         coefficients of the original Vectors.
    // *************************************************************************
    Vector<T> operator+(const Vector<T> &rhs) const;

    // *********************************************************************
    // @fn     operator +=
    // @brief  Performs v1 += v2, where v1 and v2 are two Vectors.
    // @pre    The two Vectors v1 and v2 must have the same number of
    //         elements and they must be of the same type T. Type T must
    //         support operator +=
    // @post   Vector v1 is set to v1 + v2. The resulting type is type T,
    //         the arithmetic type of both v1 and v2. The number of
    //         coefficients in v1 will not change.
    // *********************************************************************
    Vector<T>& operator+=(const Vector<T> &rhs);

    // *************************************************************************
    // @fn     Operator - for subtraction
    // @brief  Subtracts two Vectors
    // @pre    The two Vectors have the same size and type, T. Type T must have
    //         operator -=.
    // @post   Returns a Vector representing the difference between the lhs
    //         Vector and the Rhs Vector
    // *************************************************************************
    Vector<T> operator-(const Vector<T> &rhs) const;
    
    // *********************************************************************
    // @fn     operator -=
    // @brief  Performs v1 -= v2, where v1 and v2 are Vectors
    // @pre    v1 must have the same number of elements as v2. Type T must
    //         have operator -=
    // @post   v1 is set to v1 - v2
    // *********************************************************************
    Vector<T>& operator-=(const Vector<T> &rhs);

    // *********************************************************************
    // @fn     operator ==
    // @brief  Performs v1 == v2, where v1 and v2 are Vectors
    // @pre    v1 must have the same number of elements as v2. Type T must
    //         support operator !=
    // @post   Returns true if the Vectors are equal, else it returns false
    // *********************************************************************
    bool operator== (const Vector<T> &rhs) const;

    // *************************************************************************
    // @fn     Operator !=
    // @brief  Performs v1 != v2 where v1 and v2 are Vectors
    // @pre    The two Vectors have the same size and type, T. Type T must have
    //         operator !=
    // @post   Returns true if the Vectors are not equal, else it returns false
    // *************************************************************************
    bool operator!= (const Vector<T> &rhs) const;

    // *********************************************************************
    // @fn     operator *
    // @brief  Multiplies a Vector and scalar: vect * scalar
    // @pre    The coefficients in the Vector and scalar are both type T, an
    //         arithmetic type. T must support operator *=
    // @post   This returns the product of the Vector and scalar. The
    //         coefficients of the resulting Vector will have type T, the
    //         same arithmetic type of the coefficients from the original
    //         Vector.
    // *********************************************************************
    Vector<T> operator* (const T scalar) const;
    
    // *********************************************************************
    // @fn     operator *=
    // @brief  Used for Vector *= scalar
    // @pre    The coefficients in the Vector and scalar are both type T, an
    //         arithmetic type. T must have operator *=
    // @post   This returns the product of the Vector and scalar. The
    //         coefficients of the resulting Vector will have type T, the
    //         same arithmetic type of the coefficients from the original
    //         Vector.
    // *********************************************************************
    Vector<T> operator*= (const T scalar);

    // *********************************************************************
    // @fn     operator *
    // @brief  Multiplies a scalar and Vector: scalar * vect
    // @pre    T2 must have operator *=
    // @post   The resulting Vector will be equal to the original Vector
    //         multiplied by the scalar. The resulting Vector will have
    //         the same type as the passed-in Vector
    // *********************************************************************
    template<typename T1, typename T2>
    friend Vector<T1> operator* (const T2 scalar, const Vector<T1> &v);
    
    // *********************************************************************
    // @fn     operator *
    // @brief  Produces the dot product of two Vectors
    // @pre    Both Vectors must be of the same type, T, where T should be
    //         an arithmetic type. Type T should support operator += and 
    //         operator *
    //         The two Vectors must have the same size
    // @post   Returns the dot product of the two Vectors. The result
    //         will have type T, the resulting arithmetic type.
    // *********************************************************************
    T operator*(const Vector<T> &v) const;
    
    // *********************************************************************
    // @fn     operator /
    // @brief  Divides a Vector by a scalar: vect / scalar
    // @pre    Type T should support operator /=
    // @post   This returns the quotient of the Vector and scalar
    //         (Vector/scalar). The coefficients of the resulting Vector will
    //         have type T, the same arithmetic type of the coefficients from
    //         the original Vector.
    // *********************************************************************
    Vector<T> operator/(const T scalar) const;
    
    // *********************************************************************
    // @fn     operator /=
    // @brief  Computes Vector /= scalar
    // @pre    Type T should support operator /=
    // @post   The values of the coefficients in the original passed-in 
    //         Vector are each divided by the scalar. These coefficients will
    //         result in having type T, the same arithmetic type of the
    //         coefficients from the original Vector.
    // *********************************************************************
    Vector<T> operator/=(const T scalar);
    
    // *********************************************************************
    // @fn     operator ~
    // @brief  Computes the magnitude of the Vector
    // @pre    Type T should support operator += and operator *         
    // @post   The magnitude of the Vector is returned. It will be type
    //         returned is type T, the same arithmetic type of the Vector
    //         coefficients.
    // *********************************************************************
    T operator~() const;

    // *********************************************************************
    // @fn     operator -
    // @brief  Negates a Vector
    // @pre    T must support operator *=
    // @post   Returns a Vector whose coefficients are of type T and 
    //         coefficient values are the negated values of the Vector that
    //         was passed into the function.
    // *********************************************************************
    Vector<T> operator-() const;
    
    // *********************************************************************
    // @fn push_back
    // @brief Adds data of type generic to the end of the vector
    // @pre The vector size must be less than max_size-1
    // @post Data has been added to the end of the vector and
    //       size is increased by one
    // @param generic The variable that will be put on to the
    //        end of the vector
    // *********************************************************************
    void push_back (const T);

    // *********************************************************************
    // @fn pop_back
    // @brief Decreases the vector's size
    // @pre The vector's size is greater than zero
    // @post The size of the vector is decreased by one
    // *********************************************************************
    void pop_back ();

    // *********************************************************************
    // @fn     clear
    // @brief  Used to clear a Vector of type T
    // @pre    None
    // @post   The size of the Vector is set to zero and the elements
    //         of m_data[] are cleared
    // *********************************************************************
    void clear();

    // *********************************************************************
    // @fn     mag
    // @brief  Used to find the magnitude, or length of the Vector
    // @pre    Type T should have operator += and operator *
    // @post   The length of the Vector is returned. The length is type T,
    //         the same type of the Vector's coefficients
    // *********************************************************************
    T mag () const;
    
    // *********************************************************************
    // @fn     proj
    // @brief  Used to find the projection of Vector u onto Vector v. This
    //         can be used by calling projection(u,v).
    // @pre    Both vectors have the same number of coefficients and
    //         are of the same type T. Type T should support *= and /=
    // @post   A Vector of type T is returned and represents the projection
    //         of Vector u onto Vector v. Type T is the same arithmetic type
    //         of the Vector coefficients.
    //         If the Vectors are not the same size then a SizeMismatchError
    //         will be thrown
    // *********************************************************************
    Vector<T> proj(const Vector<T> &u, const Vector<T> &v) const;
    
    // *********************************************************************
    // @fn     getSize
    // @brief  Returns the size of the Vector
    // @pre    None
    // @post   The size of the Vector has been returned
    // *********************************************************************
    unsigned int getSize() const { return m_size; }
    
    // *********************************************************************
    // @fn     setSize
    // @brief  Sets the size of the Vector
    // @pre    None
    // @post   The Vector is set to the specified size and all values
    //         are initialized to zero
    // *********************************************************************
    void setSize(const unsigned int numCoefficients);

    ///////////////////////////////////////////////////////////////////////
    /// @fn max_size
    /// @brief Returns the maximum amount of items the vector can hold
    /// @pre  The value of m_max_size is greater than m_size
    /// @post It returns m_max_size, which is the maximum value
    ///       for the size of m_size
    ///////////////////////////////////////////////////////////////////////
    unsigned int getMaxSize () const;

    // *********************************************************************
    // @fn     isSubset
    // @brief  We determine whether the vector is a subset of Vector v2. It
    //         is if our lhs vector contains values that are in our rhs vector,
    //         v2.
    // @pre    We assume that there are no repeating values in v1.
    // @post   Returns true if the vector is a subset of another vector, v2.
    // *********************************************************************
    bool isSubset (const Vector<T>& v2);

    // *********************************************************************
    // @fn     isEmpty
    // @brief  Returns whether or not the vector is empty
    // @pre    None
    // @post   Returns false only if the size of the vector is zero
    // *********************************************************************
    bool isEmpty();

  protected:
    // Holds the coefficients within the vector. This is dynamically allocated
    // so that we can set the size at runtime.
    T *m_data;
    
    // The number of coefficients in the vector
    unsigned int m_size;

    // The maximum number of coefficients the vector can hold
    unsigned int m_max_size;

};

#include "vector.hpp"
#endif
