/** @file LStack.hpp
 * @brief Concrete link listed based implementation of Stack ADT.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Stacks
 * @date   June 1, 2021
 *
 * Implement the Stack abstraction using a linked list of dynamically
 * allocated node items.  The linked list based implementation
 * creates new nodes dynamically when items are pushed onto the
 * stack, and deletes these nodes when the value is popped back off.
 * The Node structure defined in the Node.hpp header file is used
 * by this stack and is private to this stack member functions.
 * We use the top (front) of the linked list to push items onto
 * and pop off of the stack since both operations are naturally
 * constant time O(1) to implement with a linked list.
 */
#ifndef _LSTACK_HPP_
#define _LSTACK_HPP_
#include "Node.hpp"
#include "Stack.hpp"
#include <string>
using namespace std;

/** @class LStack
 * @brief The LStack concrete linked list implemention of the
 *   Stack interface.
 *
 * Concrete implementation of Stack abstraction using a dynamic
 * link listed of nodes.
 */
template<class T>
class LStack : public Stack<T>
{
public:
  // constructors and destructors
  LStack();                            // default constructor
  LStack(int size, T values[]);        // array based constructor
  LStack(const LStack<T>& otherStack); // copy constructor
  ~LStack();                           // destructor

  // accessors and information methods
  T top() const;
  string str() const;
  bool operator==(const Stack<T>& rhs) const;
  T& operator[](int index) const;

  // adding, accessing and removing values from the stack
  void clear();

private:
  /// @brief pointer to the top (or front) of the linked list of
  ///   nodes that we manage for the stack.
  Node<T>* topNode;
};

#endif // define _LSTACK_HPP_
