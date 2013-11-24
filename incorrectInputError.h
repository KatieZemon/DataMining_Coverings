//**************************************************************************
//  Name:        Katie Isbell
//  File:        incorrectInputError.h
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     Handle exception for when the user incorrectly inputs
//               requested values into the program
//**************************************************************************

#ifndef INCORRECT_INPUT
#define INCORRECT_INPUT

// *********************************************************************
// @class IncorrectInputError
// @brief A class that handles all errors due to incorrect input
// *********************************************************************
class IncorrectInputError
{
  public:

    // *********************************************************************
    // @fn IncorrectInputError
    // @brief An exception thrown when trying the user incorrectly input
    //        values due to inputting the wrong values or inputting the values
    //        in the expected format
    // @pre The user input the wrong values for the program
    // @post None
    // *********************************************************************
    IncorrectInputError();

    // *********************************************************************
    // @fn IncorrectInputError
    // @brief An exception thrown when trying the user incorrectly input
    //        values due to inputting the wrong values or inputting the values
    //        in the expected format
    // @pre The user input the wrong values for the program
    // @post None
    // @param message - A special message to be displayed to help the user
    //                  know what he/she did wrong
    // *********************************************************************
    IncorrectInputError (std::string message)
    {
      std::cout << message << std::endl;
    }

};
#endif
