//**************************************************************************
//  Name:        Katie Isbell
//  File:        attribute.hpp
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     Define operators and functions for the mathematical
//               Vector class
//**************************************************************************

// Default Constructor
Attribute::Attribute ()
{
  m_name = "Untitled";
  m_valuesAreNumeric = false;
  m_typeIsDecision = false;
}

// Copy Constructor
Attribute::Attribute (const Attribute &a)
{
  *this = a;
}

// Default Constructor
Attribute::~Attribute ()
{
  m_possibleVals.clear();
}

// Operator = for Assignment
Attribute& Attribute::operator= (const Attribute &rhs)
{
  m_name = rhs.m_name;
  m_possibleVals = rhs.m_possibleVals;
  m_valuesAreNumeric = rhs.m_valuesAreNumeric;
  m_typeIsDecision = rhs.m_typeIsDecision;

  return *this;
}


// Operator ==
bool Attribute::operator== (const Attribute &rhs) const
{
  // If the two Vectors have different sizes, return false
  if ( (m_name == rhs.m_name) && ( m_valuesAreNumeric == rhs.m_valuesAreNumeric )
      && ( m_typeIsDecision == rhs.m_typeIsDecision )  && (m_possibleVals == rhs.m_possibleVals) )
    return true;

  return false;
}

// Operator !=
bool Attribute::operator != (const Attribute &rhs) const
{
  return !(*this == rhs);
}

// getPossibleVals
std::string Attribute::getPossibleVals() const
{
  return m_possibleVals;
}

// setName
void Attribute::setName(const std::string name)
{
  m_name = name;
}

// setPossibleVals with String input
void Attribute::setPossibleVals(const string possibleVals)
{
  if (possibleVals == "numeric")
    setNumeric(true);
  m_possibleVals = possibleVals;
}
/*
// setPossibleVals with vector input
void Attribute::setPossibleVals(const Vector<string> possibleVals)
{str
  m_possibleVals = possibleVals;
}*/

// setDecision
void Attribute::setDecision(const bool isDecision)
{
  if (isDecision)
    m_typeIsDecision = true;
  else
    m_typeIsDecision = false;
}

// setNumeric
void Attribute::setNumeric(const bool isNumeric)
{
  if (isNumeric)
    m_valuesAreNumeric = true;
  else
    m_valuesAreNumeric = false;
}




















