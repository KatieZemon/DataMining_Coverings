//**************************************************************************
//  Name:        Camaro Walker and Katie Isbell
//  File:        database.h
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     Create a class for a database
//**************************************************************************
#include "matrix.h"
#ifndef DATABASE_H
#define DATABASE_H

//**************************************************************************
// @class Database
// @brief Functions used for creating a Database for storing our data
//**************************************************************************
template <class T>
class Database : public virtual Matrix<T>
{
  public:
    //**********************************************************************
    // @fn     Database
    // @brief  Default Constructor
    // @pre    None
    // @post   The number of rows and number of columns are initialized to
    //         zero
    //**********************************************************************
    Database() {};

    //**********************************************************************
    // @fn     Database
    // @brief  Constructor which initializes the number of rows and cols
    // @pre    None
    // @post   The number of rows and columns in the database have been set
    //         and all of the coefficient values are initialized to zero
    //**********************************************************************
     Database(const unsigned int numRows, const unsigned int numCols);

    //**********************************************************************
    // @fn     Database
    // @brief  Copy Constructor
    // @pre    None
    // @post   The new Database is an exact copy of the original Database. It
    //         has the same size and coefficients as the original Database.
    //**********************************************************************
    Database(const Database<T> &v);

    //**********************************************************************
    // @fn     ~Database
    // @brief  Destructor that clears the Database
    // @pre    None
    // @post   The size of the Database is set to zero and the data has been
    //         cleared
    //**********************************************************************
    ~Database();
    
    //**********************************************************************
    // @fn     operator =
    // @brief  Assigns one Database to another Database
    // @pre    None
    // @post   The resulting Database on the lhs will be a copy of the Database
    //         on the rhs
    //**********************************************************************
    Database<T>& operator= (const Database<T> &rhs);
    
    //**********************************************************************
    // @fn     operator >>
    // @brief  Extraction operator used for initializing Database contents
    // @pre    Type T should support operator >>
    // @post   
    //**********************************************************************
   // template <typename T2>
    //friend std::istream& operator>>(std::istream &in, Database<T2> &a);
    
    //**********************************************************************
    // @fn     clear
    // @brief  Used to clear a Database of type T
    // @pre    None
    // @post   The Matrix is cleared and attribute arrays are emptied
    //**********************************************************************
    void clear();
    
    //**********************************************************************
    // @fn     setSize
    // @brief  Used to set the number of database instances and database
    //         attributes (rows and columns)
    // @pre    None
    // @post   The Database is cleared and attribute arrays are emptied. Each
    //         time the database is resized, we will have to reinitialize all
    //         of our data instances and attribute values.
    //**********************************************************************
    void setSize(const unsigned int numRows, const unsigned int numCols);
    
    //**********************************************************************
    // @fn     setAttributeName
    // @brief  Used to set the a name for our attribute (column).
    // @pre    None
    // @post   The attribute name at column index "colIndex" is set to the
    //         string value "name"
    //**********************************************************************
    void setAttributeName(unsigned int colIndex, std::string name);
    
    //**********************************************************************
    // @fn     getNumAttributes
    // @brief  Used to get the number of attributes (or columns) in our
    //         database
    // @pre    None
    // @post   The number of columns in our matrix is returned
    //**********************************************************************
    int getNumAttributes() const { return Matrix<T>::getNumCols(); }
    
    //**********************************************************************
    // @fn     getNumInstances()
    // @brief  Used to get the number of instances (or rows) in the database
    // @pre    None
    // @post   The number of rows in our matrix is returned
    //**********************************************************************
    int getNumInstances() const { return Matrix<T>::getNumRows(); }

    //**********************************************************************
    // @fn     setAttribute_type
    // @brief  Used to set the a type of our attribute (numerical or nominal)
    // @pre    None
    // @post   The attribute type has been set
    //**********************************************************************
   // setAttribute_type(unsigned int colIndex, char type);
     
    //**********************************************************************
    // @fn     setAttribute_possibleValues
    // @brief  Used to set the possible values of our attribute
    // @pre    None
    // @post   The attribute at column index "colIndex" is set to the array
    //         of strings
    //**********************************************************************
  //  setAttribute_possibleValues(unsigned int colIndex, std::string values*);
    
    //**********************************************************************
    // @fn     getAttributeName
    // @brief  Used to get the a name for our attribute (column).
    // @pre    None
    // @post   Returns the name of our attribute at the specified index
    //**********************************************************************
    std::string getAttributeName(unsigned int colIndex) const;
    //char getAttribute_type(int colIndex) const;
    
   
  protected:
    std::string *m_col_name; // List of Attribute names
   // char *m_col_type; // List of Attribute Types (numerical or nominal)
   // std::string *m_col_possible_values; // The possible values for an attribute(col)
    
      
    

};

#include "database.hpp"
#endif
