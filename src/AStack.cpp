/** @file AStack.cpp
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
#include <iostream>
#include <sstream>
#include <string>
#include "AStack.hpp"
#include "StackException.hpp"
using namespace std;


/** grow stack
 * Private member method that will increase the memory allocation if
 * the stack is currently at capacity.  To do this, we double the
 * current allocation, copy all of the values from the original block
 * of memory to the new block of memory, then delete the old block
 * that is no longer needed.  This method is called by methods that
 * need to grow the stack, to ensure we have enough allocated capacity
 * to accommodate the growth.
 */
template <class T>
void AStack<T>::growStackIfNeeded()
{
  // if size is still less than what we have allocated, we still have room
  // to grow at least one or more items in sizes
  if (this->size < allocationSize)
  {
    return;
  }

  // otherwise size is equal to our allocation, double the size of our allocation
  // to accommodate future growth, or make size 10 initially by default if
  // an empty stack is being grown
  if (allocationSize == 0)
  {
    allocationSize = INITIAL_ALLOCATION_SIZE;
  }
  else
  {
    allocationSize = 2 * allocationSize;
  }

  // dynamically allocate a new block of values of the new size
  T* newValues = new T[allocationSize];

  // copy the values from the original memory to this new block of memory
  for (int index = 0; index < this->size; index++)
  {
    newValues[index] = values[index];
  }

  // we don't need the old block of memory anymore, be good managers of
  // memory and return it to the heap
  delete[] values;

  // now make sure we are using the new block of memory going forward for this
  // stack
  values = newValues;
}


/** default constructor
 * Construct an empty stack.  The empty stack will have no allocated memory
 * nor any values.
 */
template <class T>
AStack<T>::AStack()
{
  // Empty stack has no values nor any allocated memory
  // associated with it
  this->size = 0;
  this->allocationSize = 0;
  values = nullptr;
}


/** standard constructor
 * Construct a stack of  values from a (statically) defined and
 * provided array of values.  We simply allocate a block of memory
 * dynamically large enough to hold the values, then copy the values
 * from the input parameter into our own private array of values.
 *
 * @param size The size of the input values were are given as well as the
 *   size of the new stack we are to construct.
 * @param values The (static) array of values to use to construct
 *   this Stack values with.
 */
template <class T>
AStack<T>::AStack(int size, T values[])
{
  // dynamically allocate a block of memory on the heap large enough to copy
  // the given input values into
  this->size = size;
  this->allocationSize = size;
  this->values = new T[allocationSize];

  // copy the values from the input paramter into our new shiny block of memory
  // we interpret the input array index 0 to be top of stack, so values[0]
  // needs to be in last index and values[size-1] needs to be at index 0
  int stackIndex;
  for (int index = 0; index < size; index++)
  {
    stackIndex = this->size - 1 - index;
    this->values[stackIndex] = values[index];
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
 * @param stack The other Stack we are to make a copy of in this
 *   constructor.
 */
template <class T>
AStack<T>::AStack(const AStack<T>& stack)
{
  // copy the size of the existing stack and allocate memory to hold
  // values we will copy
  this->size = stack.getSize();
  allocationSize = 2 * this->size;
  values = new T[allocationSize];

  // copy the values from the input Stack into this stack
  int stackIndex;
  for (int index = 0; index < this->size; index++)
  {
    // relies on overloaded index operator[] for Stack types
    // need to flip the index in our values array, stack[0] should end
    // up in position size-1 in our values array
    stackIndex = this->size - 1 - index;
    values[stackIndex] = stack[index];
  }
}


/** destructor
 * Destructor for the Stack class.  A concrete Stack implementation must
 * provide a clear() method to clear all items and safely deallocate any
 * memory that the concrete instance is using.  Invoke the clear
 * of the concrete subclass to perform the destruction.
 */
template <class T>
AStack<T>::~AStack()
{
  // call clear to do actual work to deallocate any allocation
  // before we destruct
  this->clear();
}


/** allocation size accessor
 * Accessor method to get the current amount of memory allocated
 * by and being managed by this stack.
 *
 * @returns int Returns the current allocation size of the
 *   Stack of values.
 */
template <class T>
int AStack<T>::getAllocationSize() const
{
  return allocationSize;
}


/** access top of stack
 * Accessor method to get a copy of the item currently
 * at the top of this stack.
 *
 * @returns T Returns a copy of the top item of the
 *   stack.
 *
 * @throws StackEmptyException If an attempt is made to
 *   access top item of an empty stack, this exception
 *   is generated and thrown instead.
 */
template <class T>
T AStack<T>::top() const
{
  // make sure stack is not empty before we try and access
  // the top item
  if (this->isEmpty())
  {
    ostringstream out;
    out << "Error: <Astack>::top() attempt to get item"
        << " from empty stack, size:  " << this->size;

    throw StackEmptyException(out.str());
  }

  // otherwise safe to return the top item
  return values[this->size - 1];
}


/** Stack to string
 * Accessor method to construct and return a string representation
 * of the current values and status of this Stack instance.
 *
 * @returns string Returns the string constructed with the information
 *   about this Stack.
 */
template <class T>
string AStack<T>::str() const
{
  ostringstream out;

  // stream stack information into the output stream
  out << "<stack> size: " << this->size
      << " top:[ ";

  // stream the current values of the stack to the output stream
  // we keep top of stack at end, but we define output to have
  // top first, so iterate in reverse
  for (int index = this->size - 1; index >= 0; index--)
  {
    out << values[index];

    // separate the values of the stack, last one does not need , separator
    if (index == 0)
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
bool AStack<T>::operator==(const Stack<T>& rhs) const
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
  // need to flip index of the values array, the index
  // size - 1 is the top of stack
  int stackIndex;
  for (int index = 0; index < this->size; index++)
  {
    stackIndex = this->size - 1 - index;
    if (values[stackIndex] != rhs[index])
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
 * internal array of integers.  This allows code to, for the
 * most part, treated an instance of our Stack as if it were
 * an array, though we also provide bounds checking to ensure
 * no illegal access beyond the stack bounds is attempted.
 *
 * @param index The index of the value it is desired to access from
 *   this Stack.  Index 0 should indicate top of stack, and
 *   index size - 1 is bottom item of stack.
 *
 * @returns int& Returns a reference to the requested Stack item at
 *   the requested index.
 *
 * @throws StackMemoryBoundsException if a request for an index beyond
 *   the end of the array (or less than 0) is made.
 */
template <class T>
T& AStack<T>::operator[](int index) const
{
  // first check that the requsted index is legally
  // within the bounds of the current size of our stack
  if ( (index < 0) or (index >= this->size)  )
  {
    ostringstream out;
    out << "Error: <AStack::operator[]> illegal bounds access, stack size: " << this->size
        << " tried to access index address: " << index;

    throw StackMemoryBoundsException(out.str());
  }

  // otherwise it is safe to return the reference to this value
  // in order for stack to be compatible with other stack implementations,
  // we need to interpret index 0 as top of stack, which is actually
  // at the end of our array.  So we make a calculation to reverse
  // the actual location we access
  int stackIndex = this->size - 1 - index;
  return values[stackIndex];
}


/** clear out stack
 * Clear or empty out the stack.  Return the stack back
 * to an empty stack.
 *
 * @param rhs The other stack on the right hand side of the
 *   boolean comparison that we are comparing this Stack to.
 *
 * @returns bool true if the stacks are equal, false if the are not.
 */
template <class T>
void AStack<T>::clear()
{
  // if values is not null, it points to a dynamic block of memory, so
  // delete that block.
  if (values != nullptr)
  {
    delete[] values;
    values = nullptr;
  }

  // make sure size and allocation are both reading as 0 now
  this->size = 0;
  allocationSize = 0;
}


/** push value on top of stack
 * Push the indicated value to the top of this Stack
 * of values.  This method will grow the stack allocation if
 * needed to accomodate appending the new value.
 *
 * @param value The value to push on the top of the current stack.
 */
template <class T>
void AStack<T>::push(const T& value)
{
  // first check and grow the memory allocation if needed
  growStackIfNeeded();

  // stack allocation is guaranteed to have some room now, so
  // simply append the value to the end of the current values
  values[this->size] = value;
  this->size++;
}


/** pop stack top
 * Pop the item from the top of the stack.  This is a
 * trivial O(1) operation for an array based implementation.
 */
template <class T>
void AStack<T>::pop()
{
  // make sure stack is not empty before we try and access
  // the top item
  if (this->isEmpty())
  {
    ostringstream out;
    out << "Error: <AStack>::pop() attempt to pop top item"
        << " from empty stack, size:  " << this->size;

    throw StackEmptyException(out.str());
  }

  // removing top item of an array means simply reducing size by 1
  this->size -= 1;
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
template class AStack<int>;
template class AStack<string>;
template class AStack<char>;