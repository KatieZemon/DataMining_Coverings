// *************************************************************************
//  Name:        Katie Isbell
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

    
  protected:
    unsigned int m_numRows; // The number of rows in the matrix
    unsigned int m_numCols; // The number of columns in the matrix
    Vector<Vector<T> > m_elm; // Using Vectors so we can change the size of our numRows and numCols

};

#include "matrix.hpp"
#endif
