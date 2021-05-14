/** @file StackException.cpp
 * @brief Implement Exceptions that can be thrown by Stack instances.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Linked Stacks
 * @date   June 1, 2021
 *
 * Implementall exception methods that can be generated and thrown by Stack
 * instances.
 */
#include <string>
#include "StackException.hpp"
using namespace std;


/**
 * @brief StackEmptyException constructor
 *
 * Constructor for exceptions used for our
 * Stack  class.
 *
 * @param message The exception message thrown when an error occurs.
 */
StackEmptyException::StackEmptyException(const string& message)
{
  this->message = message;
}


/**
 * @brief StackEmptyException destructor
 *
 * Destructor for exceptions used for our StackEmptyException
 * class.
 */
StackEmptyException::~StackEmptyException()
{
}


/**
 * @brief StackEmptyException message
 *
 * Accessor method to access/return message given when an exception occurs.
 *
 * @returns char* Returns a const old style c character array message for
 *   display/use by the process that catches this exception.
 */
const char* StackEmptyException::what() const throw()
{
  // what expects old style array of characters, so convert to that
  return message.c_str();
}


/**
 * @brief StackMemoryBoundsException constructor
 *
 * Constructor for exceptions used for our
 * Stack  class.
 *
 * @param message The exception message thrown when an error occurs.
 */
StackMemoryBoundsException::StackMemoryBoundsException(const string& message)
{
  this->message = message;
}


/**
 * @brief StackMemoryBoundsException destructor
 *
 * Destructor for exceptions used for our StackMemoryBoundsException
 * class.
 */
StackMemoryBoundsException::~StackMemoryBoundsException()
{
}


/**
 * @brief StackMemoryBoundsException message
 *
 * Accessor method to access/return message given when an exception occurs.
 *
 * @returns char* Returns a const old style c character array message for
 *   display/use by the process that catches this exception.
 */
const char* StackMemoryBoundsException::what() const throw()
{
  // what expects old style array of characters, so convert to that
  return message.c_str();
}