//**************************************************************************
//  Name:        Camaro Walker and Katie Isbell
//  File:        database.h
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     Create a class for a database
// *************************************************************************
#include "matrix.h"
#include "attribute.h"
#include <string>
#include <fstream>

#ifndef DATABASE_H
#define DATABASE_H

// *************************************************************************
// @class Database
// @brief Functions used for creating a Database for storing our data
// *************************************************************************
template <class T>
class Database : public virtual Matrix<T>
{
  public:
    // *********************************************************************
    // @fn     Database
    // @brief  Default Constructor
    // @pre    None
    // @post   The number of rows and number of columns are initialized to
    //         zero
    // *********************************************************************
    Database() {}

    // *********************************************************************
    // @fn     Database
    // @brief  Constructor which initializes the number of rows and cols
    // @pre    None
    // @post   The number of rows and columns in the database have been set
    //         and all of the coefficient values are initialized to zero
    // *********************************************************************
    Database(const unsigned int numRows, const unsigned int numCols);

    // *********************************************************************
    // @fn     Database
    // @brief  Copy Constructor
    // @pre    None
    // @post   The new Database is an exact copy of the original Database. It
    //         has the same size and coefficients as the original Database.
    // *********************************************************************
    Database(const Database<T> &v);

    // *********************************************************************
    // @fn     ~Database
    // @brief  Destructor that clears the Database
    // @pre    None
    // @post   The size of the Database is set to zero and the data has been
    //         cleared
    // *********************************************************************
    ~Database();
    
    // *********************************************************************
    // @fn     operator =
    // @brief  Assigns one Database to another Database
    // @pre    None
    // @post   The resulting Database on the lhs will be a copy of the Database
    //         on the rhs
    // *********************************************************************
    Database<T>& operator= (const Database<T> &rhs);
    
    // *********************************************************************
    // @fn     initDatabase
    // @brief  Initialize a database from file input
    // @pre    The file should be in arff file format
    // @post   The database rows, cols, and attribute properties are al
    //         initialized
    // *********************************************************************
    void initDatabase(const std::string filename);


    // *********************************************************************
    // @fn     clear
    // @brief  Used to clear a Database of type T
    // @pre    None
    // @post   The Matrix is cleared and attribute arrays are emptied
    // *********************************************************************
    void clear();
    
    // *********************************************************************
    // @fn     setSize
    // @brief  Used to set the number of database instances and database
    //         attributes (rows and columns)
    // @pre    None
    // @post   The Database is cleared and attribute arrays are emptied. Each
    //         time the database is resized, we will have to reinitialize all
    //         of our data instances and attribute values.
    // *********************************************************************
    void setSize(const unsigned int numRows, const unsigned int numCols);
    
    // *********************************************************************
    // @fn     setAttributeName
    // @brief  Used to set the a name for our attribute (column).
    // @pre    None
    // @post   The attribute name at column index "colIndex" is set to the
    //         string value "name"
    // *********************************************************************
    void setAttributeName(unsigned int colIndex, std::string name);
    
    // *********************************************************************
    // @fn     getNumAttributes
    // @brief  Used to get the number of attributes (or columns) in our
    //         database
    // @pre    None
    // @post   The number of columns in our matrix is returned
    // *********************************************************************
    unsigned int getNumAttributes() const { return Matrix<T>::getNumCols(); }
    
    // *********************************************************************
    // @fn     getNumInstances()
    // @brief  Used to get the number of instances (or rows) in the database
    // @pre    None
    // @post   The number of rows in our matrix is returned
    // *********************************************************************
    unsigned int getNumInstances() const { return Matrix<T>::getNumRows(); }

    // *********************************************************************
    // @fn     getAttribute
    // @brief  Used to get an attribute
    // @pre    None
    // @post   Returns an attribute
    // *********************************************************************
    Attribute& getAttr(unsigned int index);

    // *********************************************************************
    // @fn     addAttribute
    // @brief  Adds a new attribute to our list of attributes
    // @pre    None
    // @post   The new attribute is added
    // *********************************************************************
    void addAttribute(const Attribute a){ m_attributes.push_back(a); }

    // *********************************************************************
    // @fn     addAttribute
    // @brief  Adds a new attribute to the database
    // @pre    None
    // @post   The new attribute is added
    // *********************************************************************
    void addAttribute();

    // *********************************************************************
    // @fn     setDecisionAttrs
    // @brief  Receive a list of decision attributes and set these attributes
    //         as being decision attributes
    // @pre    None
    // @post   m_typeIsDecision is set for each of our decision attributes
    // *********************************************************************
    void setDecisionAttrs(Vector<unsigned int> decisionAttrs);

    // *********************************************************************
    // @fn     getDecisionAttrs
    // @brief  Return a list of the decision attributes
    // @pre    None
    // @post   returns the indices of all of the decision attributes
    // *********************************************************************
    Vector<unsigned int> getDecisionAttrs();

    // *********************************************************************
    // @fn     getNonDecisionAttrs
    // @brief  Return a list of the non-decision attributes
    // @pre    None
    // @post   returns the indices of all of the non-decision attributes
    // *********************************************************************
    Vector<unsigned int> getNonDecisionAttrs();

    std::basic_istream<char>& getline2(std::basic_istream<char>&, std::string&);


  protected:
    Vector<Attribute> m_attributes;
};

#include "database.hpp"
#endif
