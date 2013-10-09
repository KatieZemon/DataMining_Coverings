// *************************************************************************
//  Name:        Camaro Walker and Katie Isbell
//  File:        matrix.h
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     Create a class for a matrix
// *************************************************************************
#ifndef MATRIX_H
#define MATRIX_H

#include "divisionByZeroError.h"
#include "subscriptRangeError.h"
#include "sizeMismatchError.h"
#include "vector.h"
#include <cmath>

// *************************************************************************
// @class Matrix
// @brief Functions used for creating a Matrix
// *************************************************************************
template <class T> 
class Matrix
{
  public:
    // *********************************************************************
    // @fn     Matrix
    // @brief  Default Constructor
    // @pre    None
    // @post   The number of rows and columns are initialized to zero
    // *********************************************************************
    Matrix(): m_numRows(0), m_numCols(0) {}

    // *********************************************************************
    // @fn     Matrix
    // @brief  Constructor to initialize numRows and numCols
    // @pre    None
    // @post   The number of rows and columns in the matrix have been set
    //         and all of the coefficient values are initialized to zero
    // *********************************************************************
    Matrix(const unsigned int numRows, const unsigned int numCols);

    // *********************************************************************
    // @fn     Matrix
    // @brief  Copy Constructor
    // @pre    None
    // @post   The new Matrix is an exact copy of the original Matrix. It
    //         has the same size and coefficients as the original Matrix.
    // *********************************************************************
    Matrix(const Matrix<T> &v);
    
    // *********************************************************************
    // @fn     ~Matrix
    // @brief  Destructor that clears the Matrix
    // @pre    None
    // @post   The size of the Matrix is set to zero and the data has been
    //         cleared
    // *********************************************************************
    ~Matrix();

    // *********************************************************************
    // @fn     operator =
    // @brief  Assigns one Matrix to another Matrix
    // @pre    None
    // @post   The resulting Matrix on the lhs will be a copy of the Matrix
    //         on the rhs
    // *********************************************************************
    Matrix<T>& operator= (const Matrix<T> &rhs);

    // *********************************************************************
    // @fn     operator []
    // @brief  Gets the specified row in the Matrix. Each row is a Vector
    //         holding the Matrix elements.
    // @pre    None
    // @post   Returns the Vector at the specified row index
    // *********************************************************************
    const Vector<T>& operator[](const unsigned int rowIndex) const;
    
    // *********************************************************************
    // @fn     operator []
    // @brief  Used to set a specific row of the Matrix. Each row in the
    //         Matrix is a vector holding the elements
    // @pre    None
    // @post   Returns the Vector at the specified row index
    // *********************************************************************
    Vector<T>& operator[] (const unsigned int rowIndex);
     
    // *********************************************************************
    // @fn     operator <<
    // @brief  Insertion operator used for printing the values of the Matrix
    // @pre    Typt T should support operator <<
    // @post   returns an ostream that can be used for printing the Matrix
    //         coefficients to the screen
    // *********************************************************************
    template <typename T2>
    friend std::ostream& operator<< (std::ostream &os, const Matrix<T2> &m);
   
    // *********************************************************************
    // @fn     operator >>
    // @brief  Extraction operator used for initializing Matrix coefficients
    // @pre    Type T should support operator >>
    // @post   Returns an istream used to set the values of the Vector
    //         coefficients
    // *********************************************************************
    template <typename T2>
    friend std::istream& operator>>(std::istream &in, Matrix<T2> &a);

   
    /**********************************************************************
    // @fn     operator +
    // @brief  Adds two Matrices
    // @pre    The two Matrices must have the same size and type, T. Type T
    //         must have operator +=
    // @post   Returns the sum of the two Matrices. The resulting Matrix has
    //         elements of type T, which is the same arithmetic type of the
    //         coefficients of the original Vectors.
    // *************************************************************************
    Matrix<T> operator+(const Matrix<T> &rhs) const;

    // *********************************************************************
    // @fn     operator +=
    // @brief  Performs m1 += m2, where m1 and m2 are Matrices.
    // @pre    The two Matrices must have the same number of rows and columns
    //         and they must be of the same type T.
    // @post   Matrix m1 is set to m1 + m2. The resulting type is type T,
    //         the arithmetic type of both m1 and m2. The number of
    //         rows and columns in m1 will not change.
    // *********************************************************************
    Matrix<T>& operator+=(const Matrix<T> &rhs);
    
    // *************************************************************************
    // @fn     Operator - for subtraction
    // @brief  Subtracts two Matrices
    // @pre    The two Matrices have the same size and type, T. Type T must have
    //         operator -=.
    // @post   Returns a Matrix representing the difference between the lhs
    //         Matrix and the Rhs Matrix
    // *************************************************************************
    Matrix<T> operator-(const Matrix<T> &rhs) const;
    
    // *********************************************************************
    // @fn     operator -=
    // @brief  Performs m1 -= m2, where m1 and m2 are Matrices
    // @pre    m1 must have the same number of elements as m2. Type T must
    //         have operator -=
    // @post   m1 is set to m1 - m2
    // *********************************************************************
    Matrix<T>& operator-=(const Matrix<T> &rhs);

    // *********************************************************************
    // @fn     operator ==
    // @brief  Performs m1 == m2, where m1 and m2 are Matrices
    // @pre    m1 must have the same number of elements as m2. Type T must
    //         support operator !=
    // @post   Returns true if the Matrices are equal, else it returns false
    // *********************************************************************
    bool operator== (const Matrix<T> &rhs) const;

    // *************************************************************************
    // @fn     Operator !=
    // @brief  Performs m1 != m2 where m1 and m2 are Matrices
    // @pre    The two Matrices have the same size and type, T. Type T must have
    //         operator !=
    // @post   Returns true if the Matrices are not equal, else it returns false
    // *************************************************************************
    bool operator!= (const Matrix<T> &rhs) const;

    // *********************************************************************
    // @fn     operator *
    // @brief  Multiplies a Matrix and scalar: Matrix * scalar
    // @pre    The coefficients in the Matrix and scalar are both type T, an
    //         arithmetic type. T must support operator *=
    // @post   This returns the product of the Matrix and scalar. The
    //         coefficients of the resulting Matrix will have type T, the
    //         same arithmetic type of the coefficients from the original
    //         Matrix.
    // *********************************************************************
    Matrix<T> operator* (const T scalar) const;
    
    // *********************************************************************
    // @fn     operator *=
    // @brief  Used for Matrix *= scalar
    // @pre    The coefficients in the Matrix and scalar are both type T, an
    //         arithmetic type. T must have operator *=
    // @post   This returns the product of the Matrix and scalar. The
    //         coefficients of the resulting Vector will have type T, the
    //         same arithmetic type of the coefficients from the original
    //         Matrix.
    // *********************************************************************
    Matrix<T> operator*= (const T scalar);

    // *********************************************************************
    // @fn     operator *
    // @brief  Multiplies a scalar and Matrix: scalar * Matrix
    // @pre    T2 must have operator *=
    // @post   The resulting Matrix will be equal to the original Matrix
    //         multiplied by the scalar. The resulting Matrix will have
    //         the same type as the passed-in Matrix.
    // *********************************************************************
    template<typename T2>
    friend Matrix<T2> operator* (const T2 scalar, const Matrix<T2> &m);

    // *********************************************************************
    // @fn     operator *
    // @brief  Multiplies two Matrices
    // @pre    The number of rows in the lhs Matrix should be equal to the 
    //         number of columns in the rhs matrix.
    //         Both Matrices must be of the same type, T, where T should be
    //         an arithmetic type. 
    //         Type T should support operator += and operator *.
    // @post   Returns the product of the two Matrices.
    // *********************************************************************
    Matrix<T> operator*(const Matrix<T> &rhs) const;
    
    // *********************************************************************
    // @fn     operator *=
    // @brief  Multiplies two Matrices
    // @pre    The number of rows in the lhs Matrix should be equal to the 
    //         number of columns in the rhs matrix.
    //         Both Matrices must be of the same type
    //         Type T should support operator += and operator *.
    // @post   Returns the product of the two Matrices.
    // *********************************************************************
    Matrix<T> operator*=(const Matrix<T> &rhs);
   
    // *********************************************************************
    // @fn     operator *
    // @brief  Multiplies a Matrix and a Vector (Matrix * Vector)
    // @pre    The number of columns in the Matrix should equal the size
    //         of the Vector
    //         Type T should support += and * 
    //         The Matrix and Vector should have the same type
    // @post   Returns a Vector representing the product of the Matrix and
    //         Vector
    // *********************************************************************
    Vector<T> operator* (const Vector<T> &vect) const;

    // *********************************************************************
    // @fn     operator *
    // @brief  Multiplies a Vector and Matrix (Vector * Matrix)
    // @pre    The size of the Vector should equal the number of rows in
    //         the Matrix
    //         Type T should support += and * 
    //         The Matrix and Vector should have the same type
    // @post   Returns a Vector representing the product of the Matrix and
    //         Vector
    // *********************************************************************
    template<typename T2>
    friend Vector<T2> operator* (const Vector<T2> &vect, const Matrix<T2> &matrix);
    
    // *********************************************************************
    // @fn     operator /
    // @brief  Divides a Matrix by a scalar
    // @pre    Type T should support operator /=
    //         The value of the scalar cannot be equal to zero
    // @post   This returns the quotient of the Matrix and scalar
    //         The coefficients of the resulting Matrix will have type T, the
    //         the same arithmetic type of the coefficients from the original
    //         Matrix.
    // *********************************************************************
    Matrix<T> operator/(const T scalar) const;
    
    // *********************************************************************
    // @fn     operator /=
    // @brief  Computes Matrix /= scalar
    // @pre    Type T should support operator /=
    //         The value of the scalar cannot be equal to zero.
    // @post   The values of the coefficients in the original Matrix are 
    //         divided by the scalar. These coefficients in the resulting
    //         Matrix will have type T, the same arithmetic type of the
    //         coefficients from the original Matrix.
    // *********************************************************************
    Matrix<T> operator/=(const T scalar);

    // *********************************************************************
    // @fn     operator -
    // @brief  Negates a Matrix
    // @pre    T must support operator *=
    // @post   Returns a Matrix whose coefficients are of type T and 
    //         coefficient values are the negated values of the passed-in
    //          Matrix
    // *********************************************************************
    Matrix<T> operator-() const;
  */
    // *********************************************************************
    // @fn     clear
    // @brief  Used to clear a Matrix of type T
    // @pre    None
    // @post   numCols and numRows are set to zero and elm is deleted
    // *********************************************************************
    void clear();

    // *********************************************************************
    // @fn     getNumRows
    // @brief  Returns the number of rows in the matrix
    // @pre    None
    // @post   The number of rows in the matrix is returned
    // *********************************************************************
    unsigned int getNumRows() const { return m_numRows; }
    
    // *********************************************************************
    // @fn     getNumCols
    // @brief  Returns the number of columns in the matrix
    // @pre    None
    // @post   The number of columns in the matrix is returned
    // *********************************************************************
    unsigned int getNumCols() const { return m_numCols; }
    
    // *********************************************************************
    // @fn     setSize
    // @brief  Sets the number of rows and columns in the matrix
    // @pre    None
    // @post   The number of rows and columns have been set and all
    //         the coefficient values are reset to zero
    // *********************************************************************
    void setSize(const unsigned int numRows, const unsigned int numCols);
     
    // *********************************************************************
    // @fn     isDiagonallyDominant
    // @brief  Determines whether the matrix is diagonally dominant
    // @pre    The matrix must contain n number of rows and n number of cols,
    //         where n is an integer
    //         Type T must support -= and be used with std::abs
    // @post   Returns true if the matrix is diagonally dominant
    // *********************************************************************
    bool isDiagonallyDominant() const;
    
  protected:
    unsigned int m_numRows; // The number of rows in the matrix
    unsigned int m_numCols; // The number of columns in the matrix
    Vector<Vector<T> > m_elm; // Using Vectors so we can change the size of our numRows and numCols

};

#include "matrix.hpp"
#endif
