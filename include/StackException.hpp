/** @file StackException.hpp
 * @brief Declare Exceptions that can be thrown by Stack instances.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Stacks
 * @date   June 1, 2021
 *
 * Declare all exceptions that can be generated and thrown by Stack
 * instances.
 */
#ifndef _STACK_EXCEPTION_HPP_
#define _STACK_EXCEPTION_HPP_
#include <string>
using namespace std;

/** @class StackEmptyException
 * @brief Stack Empty Exception for the Stack class.
 *
 * Exception to be thrown by our Stack class if attempt to access item
 * from top of an empty stack is attempted.
 *
 */
class StackEmptyException : public exception
{
public:
  explicit StackEmptyException(const string& message);
  ~StackEmptyException();
  virtual const char* what() const throw();

private:
  /// Stores the particular message describing what caused the exception.
  string message;
};

/** @class StackMemoryBoundsException
 * @brief Memory Bounds Exception for the Stack class.
 *
 * Exception to be thrown by our Stack class if an illegal memory
 * bounds access is attempted.  Not a normal exception, but for this
 * assignment we provide an indexing operator mostly for debugging
 * purposes of the stack
 *
 */
class StackMemoryBoundsException : public exception
{
public:
  explicit StackMemoryBoundsException(const string& message);
  ~StackMemoryBoundsException();
  virtual const char* what() const throw();

private:
  /// Stores the particular message describing what caused the exception.
  string message;
};

#endif // _STACK_EXCEPTION_HPP_