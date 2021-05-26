/** @file AStack.hpp
 * @brief Concrete array based implementation of Stack ADT.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Stacks
 * @date   June 1, 2021
 *
 * Implement the Stack abstraction using a fixed sized array.  This
 * array based implementation will dynamically allocate a new block of
 * memory once the current allocation becomes full.  The new block is
 * double in size of the old.  Thus push at the end of the stack
 * can be O(1) in most cases, but will take O(n) copies as well as a
 * memory allocation if it needs to grow.
 */
#ifndef _ASTACK_HPP_
#define _ASTACK_HPP_
#include "Stack.hpp"
#include <string>
using namespace std;

/** @class AStack
 * @brief The AStack concrete array based implemention of the
 *   Stack interface.
 *
 * Concrete implementation of Stack abstraction using an array based
 * implementation.
 */
template<class T>
class AStack : public Stack<T>
{
public:
  // constructors and destructors
  AStack();                            // default constructor
  AStack(int size, T values[]);        // array based constructor
  AStack(const AStack<T>& otherStack); // copy constructor
  ~AStack();                           // destructor

  // accessors and information methods
  int getAllocationSize() const;
  T top() const;
  string str() const;
  bool operator==(const Stack<T>& rhs) const;
  T& operator[](int index) const;

  // adding, accessing and removing values from the stack
  void clear();
  void push(const T& newItem);
  void pop();

private:
  /// @brief private constant, initial allocation size for empty stacks
  ///   to grow to
  const int INITIAL_ALLOCATION_SIZE = 10;

  /// @brief the current amount of allocated memory being
  ///   managed by/for this stack of values
  int allocationSize;

  /// @brief For the array based implementation, the values is a fixed
  ///   array of type T values.  The values contained in the stack
  ///   will be manged from the array, and a new array allocated and
  ///   values copied if we fill up the current allocation.
  T* values;

  // private member methods for managing the Stack internally
  void growStackIfNeeded();
};

#endif // define _ASTACK_HPP_
