/** @file LStack.cpp
 * @brief Concrete link stacked based implementation of Stack ADT.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Stacks
 * @date   June 1, 2021
 *
 * Implement the Stack abstraction using a linked stack of dynamically
 * allocated node items.  The linked stack based implementation
 * creates new nodes dynamically when items are pushed onto the
 * stack, and deletes these nodes when the value is popped back off.
 * The Node structure defined in the Node.hpp header file is used
 * by this stack and is private to this stack member functions.
 * We use the top (front) of the linked stack to push items onto
 * and pop off of the stack since both operations are naturally
 * constant time O(1) to implement with a linked stack.
 */
#include <iostream>
#include <sstream>
#include <string>
#include "LStack.hpp"
#include "StackException.hpp"
using namespace std;


/** default constructor
 * Construct an empty stack.  The empty stack will have no allocated memory
 * nor any values.
 */
template <class T>
LStack<T>::LStack()
{
  // Empty stack has size 0 and top is null
  this->size = 0;
  topNode = nullptr;
}


/** standard constructor
 * Construct a stack of values from a (statically) defined and
 * provided array of values.  We need to dynamically construct
 * a node for each value in the array and create a linked stack of these
 * nodes.
 *
 * @param size The size of the input values we are given as well as the
 *   size of the new stack we are to construct.
 * @param values The (static) array of values to use to construct
 *   this new Stack of values with.
 */
template <class T>
LStack<T>::LStack(int size, T values[])
{
  // Make sure stack is empty before copying values from array.
  // Empty stack has size 0 and top is null
  this->size = 0;
  topNode = nullptr;

  // iterate through the array reusing member functions to
  // simply insert new values one-by-one on the back.  Value
  // at index 0 of the passed in array should be on top, so
  // iterate backwards through the values to push them on stack
  // in correct order
  for (int index = size - 1; index >= 0; index--)
  {
    //push(values[index]);
  }
}


/** copy constructor
 * Provide a copy constructor for the Stack class.  A copy constructor
 * will be invoked whenver you assign one instance of a Stack to another.
 * For example
 *   Stack newStack = existingStack;
 * Where of course existingStack was a previously created Stack.  This copy
 * constructor, as the name suggests, should make a copy of the values from
 * the given input stack into a new Stack instance.
 *
 * @param stack The other Stack type we are to make a copy of in this
 *   constructor.
 */
template <class T>
LStack<T>::LStack(const LStack<T>& stack)
{
  // Make sure stack is empty before copying values from other stack.
  // Empty stack has size 0 and top is null
  this->size = 0;
  topNode = nullptr;

  // if the other stack is not empty, then we need to iterate through
  // its values and insert them into the back of this stack
  // need to iterate backwards through other stack to push them in
  // correct order onto this stack.
  for (int index = stack.getSize() - 1; index >= 0; index--)
  {
    //push(stack[index]);
  }
}


/** destructor
 * Destructor for the Stack class.  A concrete Stack implementation must
 * provide a clear() method to clear all items and safely deallocate any
 * memory that the concrete instance is using.  Invoke the clear
 * of the concrete subclass to perform the destruction.
 */
template <class T>
LStack<T>::~LStack()
{
  // call clear to do actual work to deallocate any allocation
  // before we destruct
  clear();
}


/** access top of stack
 * Accessor method to get a copy of the item currently
 * at the top of this stack..
 *
 * @returns T Returns a copy of the top item of the
 *   stack..
 *
 * @throws StackEmptyException If an attempt is made to
 *   access top item of an empty list, this exception
 *   is generated and thrown instead.
 */
template <class T>
T LStack<T>::top() const
{
  // make sure stack is not empty before we try and access
  // the top item
  if (this->isEmpty())
  {
    ostringstream out;
    out << "Error: <LStack>::top() attempt to get item"
        << " from empty stack, size:  " << this->size;

    throw StackEmptyException(out.str());
  }

  // otherwise safe to return the top item
  return topNode->value;
}


/** Stack to string
 * Accessor method to construct and return a string representation
 * of the current values and status of this Stack instance.
 *
 * @returns string Returns the string constructed with the information
 *   about this Stack.
 */
template <class T>
string LStack<T>::str() const
{
  ostringstream out;

  // stream stack information into the output stream
  out << "<stack> size: " << this->size
      << " top:[ ";

  // stream the current values of the stack to the output stream
  Node<T>* current = topNode;
  while (current != nullptr)
  {
    // put value out to the stream
    out << current->value;

    // advance to the next value
    current = current->next;

    // separate for next value, or just space if no more values
    if (current == nullptr)
    {
      out << " ";
    }
    else
    {
      out << ", ";
    }
  }

  out << "]:bottom";

  // convert the string stream into a concrete string to return
  return out.str();
}


/** boolean equals operator
 * Check if this Stack is equal to the right hand side (rhs)
 * stack.  The stacks are equal if their sizes are equal, and if
 * all elements in both stacks are equal.
 *
 * @param rhs The other stack on the right hand side of the
 *   boolean comparison that we are comparing this Stack to.
 *
 * @returns bool true if the stacks are equal, false if the are not.
 */
template <class T>
bool LStack<T>::operator==(const Stack<T>& rhs) const
{
  // first the stacks have to be of the same size, or else they
  // cannot be equal
  if (this->size != rhs.getSize())
  {
    return false;
  }

  // otherwise, stacks are equal if all elements are equal.
  // compare each element, and if we find a pair that is not
  // equal then the answer is false
  for (int index = 0; index < this->size; index++)
  {
    if (this->operator[](index) != rhs[index])
    {
      return false;
    }
  }

  // if we get to this point, all values were the same in both
  // stacks, so the answer is true, the stacks are equal
  return true;
}


/** indexing operator
 * Provide a way to index individual values in our private
 * linked stack of values.  This allows code to, for the
 * most part, treated an instance of our Stack as if it were
 * an array, though we also provide bounds checking to ensure
 * no illegal access beyond the stack bounds is attempted.
 *
 * @param index The index of the value it is desired to access from
 *   this Stack.
 *
 * @returns int& Returns a reference to the requested Stack item at
 *   the requested index.
 *
 * @throws StackMemoryBoundsException if a request for an index beyond
 *   the end of the array (or less than 0) is made.
 */
template <class T>
T& LStack<T>::operator[](int index) const
{
  // first check that the requsted index is legally
  // within the bounds of the current size of our stack
  if ( (index < 0) or (index >= this->size)  )
  {
    ostringstream out;
    out << "Error: <LStack::operator[]> illegal bounds access, stack size: " << this->size
        << " tried to access index address: " << index;

    throw StackMemoryBoundsException(out.str());
  }

  // otherwise it is safe to return the reference to the value, but
  // we have to do some work to find it first
  Node<T>* current = topNode;
  for (int currentIdx = 0; currentIdx < index; currentIdx++)
  {
    // advance to next node until we reach the index'th node of
    // this stack
    current = current->next;
  }

  // return the reference to the value in the index'th node of the
  // stack
  return current->value;
}


/** clear out stack
 * Clear or empty out the stack.  Return the stack back
 * to an empty stack.
 */
template <class T>
void LStack<T>::clear()
{
  // if the stack is not empty, we need to deallocate and return the nodes
  // back to the heap
  if (not this->isEmpty())
  {
    Node<T>* current = topNode;

    // iterate through the nodes of the stack to delete them
    while (current != nullptr)
    {
      // remember this node to delete while advancing
      // to next node for next iteration
      Node<T>* nodeToDelete = current;
      current = current->next;

      // now safe to free up the memory of this node
      delete nodeToDelete;
    }
  }

  // make sure size is now 0 and top is null again
  this->size = 0;
  topNode = nullptr;
}


/**
 * @brief Cause specific instance compilations
 *
 * This is a bit of a kludge, but we can use normal make dependencies
 * and separate compilation by declaring template class Stack<needed_type>
 * here of any types we are going to be instantianting with the
 * template.
 *
 * https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
 * https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl
 */
template class LStack<int>;
template class LStack<string>;
template class LStack<char>;