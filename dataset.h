//**************************************************************************
//  Name:        Katie Isbell
//  File:        Dataset.h
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     Create a class for a Dataset
// *************************************************************************
#include "matrix.h"
#include "attribute.h"
#include "fileNotExistError.h"
#include <string>
#include <fstream>

#ifndef Dataset_H
#define Dataset_H

// *************************************************************************
// @class Dataset
// @brief Functions used for creating a Dataset for storing our data
// *************************************************************************
template <class T>
class Dataset : public virtual Matrix<T>
{
  public:
    // *********************************************************************
    // @fn     Dataset
    // @brief  Default Constructor
    // @pre    None
    // @post   The number of rows and number of columns are initialized to
    //         zero
    // *********************************************************************
    Dataset() {}

    // *********************************************************************
    // @fn     Dataset
    // @brief  Constructor which initializes the number of rows and cols
    // @pre    None
    // @post   The number of rows and columns in the Dataset have been set
    //         and all of the coefficient values are initialized to zero
    // *********************************************************************
    Dataset(const unsigned int numRows, const unsigned int numCols);

    // *********************************************************************
    // @fn     Dataset
    // @brief  Copy Constructor
    // @pre    None
    // @post   The new Dataset is an exact copy of the original Dataset. It
    //         has the same size and coefficients as the original Dataset.
    // *********************************************************************
    Dataset(const Dataset<T> &v);

    // *********************************************************************
    // @fn     ~Dataset
    // @brief  Destructor that clears the Dataset
    // @pre    None
    // @post   The size of the Dataset is set to zero and the data has been
    //         cleared
    // *********************************************************************
    ~Dataset();
    
    // *********************************************************************
    // @fn     operator =
    // @brief  Assigns one Dataset to another Dataset
    // @pre    None
    // @post   The resulting Dataset on the lhs will be a copy of the Dataset
    //         on the rhs
    // *********************************************************************
    Dataset<T>& operator= (const Dataset<T> &rhs);
    
    // *********************************************************************
    // @fn     initDataset
    // @brief  Initialize a Dataset from file input
    // @pre    The file should be in arff file format
    // @post   The Dataset rows, cols, and attribute properties are al
    //         initialized
    // *********************************************************************
    void initDataset(const std::string filename);


    // *********************************************************************
    // @fn     clear
    // @brief  Used to clear a Dataset of type T
    // @pre    None
    // @post   The Matrix is cleared and attribute arrays are emptied
    // *********************************************************************
    void clear();
    
    // *********************************************************************
    // @fn     setSize
    // @brief  Used to set the number of Dataset instances and Dataset
    //         attributes (rows and columns)
    // @pre    None
    // @post   The Dataset is cleared and attribute arrays are emptied. Each
    //         time the Dataset is resized, we will have to reinitialize all
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
    //         Dataset
    // @pre    None
    // @post   The number of columns in our matrix is returned
    // *********************************************************************
    unsigned int getNumAttributes() const { return Matrix<T>::getNumCols(); }
    
    // *********************************************************************
    // @fn     getNumInstances()
    // @brief  Used to get the number of instances (or rows) in the Dataset
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
    // @brief  Adds a new attribute to the Dataset
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

    // *********************************************************************
    // @fn     getline2
    // @brief  A modified version of the standard getline function that
    //         accounts for the \r delimiter for windows files
    // @pre    None
    // @post   returns the same result as getline with files using only the
    //         newline as with files using both newline and carriage return
    // *********************************************************************
    std::basic_istream<char>& getline2(std::basic_istream<char>&, std::string&);

    std::string formatString(const std::string input);



  protected:
    Vector<Attribute> m_attributes;
};

#include "dataset.hpp"
#endif
