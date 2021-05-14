/** @file Stack.hpp
 * @brief Abstract base class definition of Stack abstract data type.
 *   This header defines the abstraction/interface for concrete
 *   Stack implementations.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Stacks
 * @date   June 1, 2021
 *
 * Defination of Stack abstraction.  Concrete implementations of
 * this Stack interface must inherit from this abstract base class
 * and implement all defined virtual functions.
 */
#ifndef _STACK_HPP_
#define _STACK_HPP_
#include <iostream>
using namespace std;


/** @class Stack
 * @brief The Stack data type abstraction
 *
 * The defined ADT interface for a Stack data type.  This abstraction
 * provides the ability to perform the most common tasks we want to
 * perform with stacks, such as push and pop the top item on the
 * stack and retrieve the top value of the stack.
 */
template <class T>
class Stack
{
protected:
  /// @brief the current size of the stack of values, this is
  ///   protected so derived classes can access it
  int size;

public:
  // accessor and information methods
  int getSize() const;
  bool isEmpty() const;
  virtual T top() const = 0;
  virtual string str() const = 0;
  virtual bool operator==(const Stack<T>& rhs) const = 0;
  virtual T& operator[](int index) const = 0;

  // adding, accessing and removing values from the stack
  virtual void clear() = 0;
  //virtual void push(const T& newItem) = 0;
  //virtual void pop() = 0;

  // friend functions and friend operators
  template <typename U>
  friend ostream& operator<<(ostream& out, const Stack<U>& rhs);
};

#endif // _STACK_HPP_