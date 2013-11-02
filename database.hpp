//**************************************************************************
//  Name:        Katie Isbell and Camaro Walker
//  File:        Database.hpp
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     Define operators and functions for the Database class
//**************************************************************************

// Constructor
template<class T>
Database<T>::Database (const unsigned int numRows, const unsigned int numCols)
{
  Matrix<T>::Matrix(numRows, numCols);
}

// Copy Constructor
template<class T>
Database<T>::Database (const Database<T> &m)
{
  //Derived* rhs_d = dynamic_cast<Derived*>(&rhs);
  *this = m;
}

// Operator = for Assignment
template<class T>
Database<T>& Database<T>::operator= (const Database<T> &rhs)
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
Database<T>::~Database ()
{
  this->clear();
}

// Initialize database values using the read file
template<class T>
void Database<T>::initDatabase (const std::string fileName)
{
  std::string word;
  unsigned int numCols = 0, numRows = 0; // number of attributes and instances
  Vector<std::string> listRows; // store each row in a Vector
  std::stringstream iss;

  // Open the file
  std::ifstream file;
  file.open(fileName.c_str());

  if (!(file.is_open()))
    //throw Exception(SMELLY_POOP, "Eeewww!! It smells bad!"); // TODO: UH OH!!! That's not good

  // Read until we come across the word "@attribute" in our file
  do
  {
    file >> word;
  } while (word != "@attribute");

  // Store our attribute data
  for (unsigned int i = 0; word != "@data"; i++)
  {
    this->addAttribute(); // Add a new attribute
    numRows++;

    file >> word;
    this->getAttr(i).setName(word); // Set the attribute name

    file >> word;
    this->getAttr(i).setPossibleVals(word); // Set the attribute possible values

    file >> word; // Ignore the word "@attribute"
    numCols++;
  }
  getline(file, word);

  // Push database rows onto a vector
  while (getline(file, word))
  {
    listRows.push_back(word);
  }
  numRows = listRows.getSize();

  // Set the size of our matrix
  this->setSize(numRows, numCols);

  // Initialize matrix values
  for (unsigned int i = 0; i < listRows.getSize(); i++)
  {
    iss << listRows[i];
    for (unsigned int j = 0; j < numCols; j++)
    {
      getline(iss, (*this)[i][j], ',');
    }
    iss.clear();
  }

  file.close();
}

// Clear a Database
template<class T>
void Database<T>::clear ()
{
  if (0 != Matrix<T>::m_numRows)
  {
    Matrix<T>::clear();
  }
  m_attributes.clear();
}

// Set Size (and clear)
template<class T>
void Database<T>::setSize (const unsigned int numRows, const unsigned int numCols)
{
  Matrix<T>::setSize(numRows, numCols);
}

// Get Attribute
template<class T>
Attribute& Database<T>::getAttr (unsigned int i)
{
  return m_attributes[i];
}

template<class T>
void Database<T>::addAttribute ()
{
  Attribute a;
  addAttribute(a);
}

template<class T>
void Database<T>::setDecisionAttrs (Vector<unsigned int> decisionAttrs)
{
  for (unsigned int i = 0; i < decisionAttrs.getSize(); i++)
  {
    m_attributes[ decisionAttrs[i] ].setDecision(true);
  }
}

template<class T>
Vector<unsigned int> Database<T>::getDecisionAttrs()
{
  Vector<unsigned int> decisionAttrs;

  for (unsigned int i = 0; i < m_attributes.getSize(); i++)
  {
    if ( m_attributes[i].isDecision() )
    {
      decisionAttrs.push_back(i);
    }
  }
  return decisionAttrs;
}

template<class T>
Vector<unsigned int> Database<T>::getNonDecisionAttrs()
{
  Vector<unsigned int> nonDecisionAttrs;

  for (unsigned int i = 0; i < m_attributes.getSize(); i++)
  {
    if ( !m_attributes[i].isDecision() )
    {
      nonDecisionAttrs.push_back(i);
    }
  }
  return nonDecisionAttrs;
}





