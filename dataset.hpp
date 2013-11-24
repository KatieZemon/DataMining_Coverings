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

  // Store our attributes
  for (unsigned int i = 0; word != "@data"; i++) // Read until we come across the word "@data"
  {
    // Increment the total number of attributes we have in our dataset
    this->addAttribute();

    // Get attribute name
    file >> word;
    this->getAttr(i).setName(word);

    file >> word;
    std::cout << word << std::endl;
    //this->getAttr(i).setPossibleVals(word); // Set the attribute possible values

    file >> word; // Ignore the word "@attribute"
    numAttributes++;
  }
  getline2(file, word);

  // Push Dataset rows onto a vector
  while (getline2(file, word))
  {
    listRows.push_back(word);
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

