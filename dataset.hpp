//**************************************************************************
//  Name:        Katie Isbell
//  File:        Dataset.hpp
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     Define operators and functions for the Dataset class
//**************************************************************************

// Constructor
template<class T>
Dataset<T>::Dataset (const unsigned int numRows, const unsigned int numCols)
{
  Matrix<T>::Matrix(numRows, numCols);
}

// Copy Constructor
template<class T>
Dataset<T>::Dataset (const Dataset<T> &m)
{
  //Derived* rhs_d = dynamic_cast<Derived*>(&rhs);
  *this = m;
}

// Operator = for Assignment
template<class T>
Dataset<T>& Dataset<T>::operator= (const Dataset<T> &rhs)
{
  this->clear();
  Matrix<T>::m_numRows = rhs.m_numRows;
  Matrix<T>::m_numCols = rhs.m_numCols;
  Matrix<T>::m_elm = rhs.m_elm; //new Vector<T> [Matrix<T>::m_numRows];

  for (unsigned int i = 0; i < rhs.m_numRows; ++i)
  {
    Matrix<T>::m_elm[i] = rhs.m_elm[i];
  }

  return *this;
}

// Destructor
template<class T>
Dataset<T>::~Dataset ()
{
  this->clear();
}

// Initialize Dataset values using the read file
template<class T>
void Dataset<T>::initDataset (const std::string fileName)
{
  std::string word;
  unsigned int numAttributes = 0, numInstances = 0; // number of attributes and instances in our Dataset
  Vector<std::string> listRows; // store each row in a Vector
  std::stringstream iss;

  // Open the file
  std::ifstream file;
  file.open(fileName.c_str());

  // If the file does not exist, then throw an error
  if (!file)
  {
    throw FileNotExistError(fileName);
  }

  // Read until we come across the word "@attribute" in our file
  do
  {
    file >> word;
  } while (word != "@attribute");

  // Store our attributes. Stop when we come across the word "@data" in our file
  for (unsigned int i = 0; word != "@data"; i++)
  {
    // Increment the total number of attributes we have in our dataset
    this->addAttribute();

    // Read and store the Attribute name
    file >> word;
    this->getAttr(i).setName(word); // set the name of this attribute

    // Get attribute possible values (a list of values)
    getline2(file,word);

    // Set the possible values for our attribute.
    this->getAttr(i).setPossibleVals( formatString(word) ); // Skip end-of-line comments

    // Read until we come across a new attribute. This will skip commented lines
    do
    {
      file >> word;
    } while(word != "@attribute" && word != "@data");
    numAttributes++;
  }
  getline2(file, word);

  // Everything after @data
  // Store our dataset values
  while (getline2(file, word))
  {
    if (word[0] != '%' && word.length() != 0) // Skip over commented lines or blank lines
    {
      listRows.push_back( formatString(word) ); // skip end of line comments
    }

  }
  numInstances = listRows.getSize();

  // Set the size of our matrix
  this->setSize(numInstances, numAttributes); // number of rows and cols in our Dataset "matrix" of data

  // Initialize matrix values
  for (unsigned int i = 0; i < listRows.getSize(); i++)
  {
    iss << listRows[i];
    for (unsigned int j = 0; j < numAttributes; j++)
    {
      getline(iss, (*this)[i][j], ',');
    }
    iss.clear();
  }

  file.close();
}

template<class T>
std::basic_istream<char>& Dataset<T>::getline2 (std::basic_istream<char>& c, std::string& s)
{

  getline(c, s);

  // Remove '\r' if we are using windows line delimiters
  if ('\r' == s[s.size() - 1])
  {
    s.erase(s.size() - 1);
  }

  return c;
}

// Format a string by removing any whitespace characters and text following % for comments
template<class T>
std::string Dataset<T>::formatString(std::string input)
{
  std::string solution;
  bool repeat = true;
  for (unsigned int i = 0; i < input.length() && repeat; i++)
  {
    if (input[i] != ' ')
    {
      if (input[i] == '%')
      {
        repeat = false;
      }
      else
        solution += input[i];
    }
  }
  return solution;
}

// Clear a Dataset
template<class T>
void Dataset<T>::clear ()
{
  if (0 != Matrix<T>::m_numRows)
  {
    Matrix<T>::clear();
  }
  m_attributes.clear();
}

// Set Size (and clear)
template<class T>
void Dataset<T>::setSize (const unsigned int numRows, const unsigned int numCols)
{
  Matrix<T>::setSize(numRows, numCols);
}

// Get Attribute
template<class T>
Attribute& Dataset<T>::getAttr (unsigned int i)
{
  return m_attributes[i];
}

template<class T>
void Dataset<T>::addAttribute ()
{
  Attribute a;
  addAttribute(a);
}

template<class T>
void Dataset<T>::setDecisionAttrs (Vector<unsigned int> decisionAttrs)
{
  for (unsigned int i = 0; i < decisionAttrs.getSize(); i++)
  {
    m_attributes[decisionAttrs[i]].setDecision(true);
  }
}

template<class T>
Vector<unsigned int> Dataset<T>::getDecisionAttrs ()
{
  Vector<unsigned int> decisionAttrs;

  for (unsigned int i = 0; i < m_attributes.getSize(); i++)
  {
    if (m_attributes[i].isDecision())
    {
      decisionAttrs.push_back(i);
    }
  }
  return decisionAttrs;
}

template<class T>
Vector<unsigned int> Dataset<T>::getNonDecisionAttrs ()
{
  Vector<unsigned int> nonDecisionAttrs;

  for (unsigned int i = 0; i < m_attributes.getSize(); i++)
  {
    if (!m_attributes[i].isDecision())
    {
      nonDecisionAttrs.push_back(i);
    }
  }
  return nonDecisionAttrs;
}

