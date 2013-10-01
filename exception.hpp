//////////////////////////////////////////////////////////////////////
/// @file exception.hpp
/// @author Katie Isbell, Section B
/// @brief Construct the exception class and handle functions
//////////////////////////////////////////////////////////////////////

#include "exception.h"

Exception::Exception (Error_Type _error_code, string _error_message)
{
  // Set up our error information
  m_error_code = _error_code;
  m_error_message = _error_message;
}

Error_Type Exception::error_code ()
{
  return m_error_code;
}

string Exception::error_message ()
{
  return m_error_message;
}
