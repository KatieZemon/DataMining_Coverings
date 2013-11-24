//**************************************************************************
//  Name:        Katie Isbell
//  File:        fileNotExistError.h
//  Assignment:  Semester Project Programming Option
//  Due Date:    12/6/2013
//  Course:      CS301
//  Purpose:     Handle exception for when a file does not exist
//**************************************************************************

#ifndef FILE_NOT_EXIST
#define FILE_NOT_EXIST

// *********************************************************************
// @class FileNotExistError
// @brief A class that handles all errors
// *********************************************************************
class FileNotExistError
{
  public:

    // *********************************************************************
    // @fn FileNotExistError
    // @brief An exception thrown when trying to open a file that could not
    //        be found
    // @pre The user input the wrong filename
    // @post None
    // @param fileName The name of the file that could not be found
    // *********************************************************************
    FileNotExistError ();

    // *********************************************************************
    // @fn    FileNotExistError
    // @brief An exception that prints out the name of the file that could
    //        not be opened
    // @pre   The user input the wrong filename
    // @post  The name of the file that could not be opened is printed
    // @param fileName The name of the file that could not be found
    // *********************************************************************
    FileNotExistError (std::string fileName)
    {
      std::cout << "Error: The file " << fileName << " does not exist at the "
          "specified file path!" << std::endl;
    }

};
#endif
