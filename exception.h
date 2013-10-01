//////////////////////////////////////////////////////////////////////
/// @file exception.h
/// @author Katie Isbell
/// @brief Define the exception class
//////////////////////////////////////////////////////////////////////

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
using std::string;

enum Error_Type { CONTAINER_FULL, CONTAINER_EMPTY, OUT_OF_BOUNDS };

//////////////////////////////////////////////////////////////////////////
/// @class Exception
/// @brief A class that handles all errors
//////////////////////////////////////////////////////////////////////////
class Exception
{
  public:
    ///////////////////////////////////////////////////////////////////////
    /// @fn Exception
    /// @brief Sets error code and error message
    /// @pre None
    /// @post The size of the array is decreased by one
    /// @param Error_Type An enumerator that holds 3 possible options-
    ///                   CONTAINER_FULL, CONTAINER_EMPTY, and
    ///                   OUT_OF_BOUNDS
    /// @param string The error message
    ///////////////////////////////////////////////////////////////////////
    Exception (Error_Type, string);

    ///////////////////////////////////////////////////////////////////////
    /// @fn error_code
    /// @brief Handles the error code
    /// @pre An error code has been initialized
    /// @post Returns the error code
    ///////////////////////////////////////////////////////////////////////
    Error_Type error_code ();

    ///////////////////////////////////////////////////////////////////////
    /// @fn error_message
    /// @brief Returns an error message
    /// @pre There exists an error message
    /// @post An error message has been returned
    ///////////////////////////////////////////////////////////////////////
    string error_message ();

  private:
    // One of the three error types declared in enumb Error_Type
    Error_Type m_error_code;

    // The message displayed when there is an error
    string m_error_message;
};

#include "exception.hpp"
#endif
