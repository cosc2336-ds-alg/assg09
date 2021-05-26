/** @file stack-functions.cpp
 * @brief Stack function declarations for assignment
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Stacks
 * @date   June 1, 2021
 *
 * @description Assignment Stacks: applications of stacks.  Use the
 *   given Stack ADT to implement a set of functions/algorithms.  This
 *   implementation file is for the functions you are to write for
 *   this assignment.  You should modify this file by adding
 *   implementations of the 4 functions you are to write.  You need to
 *   use the Stack ADT given to you, and included for you, for the
 *   Stack instances for your functions.  It is incorrect to include
 *   STL stacks or other containers here to use for this assignment.
 */
#include "AStack.hpp"
#include "LStack.hpp"
#include "Stack.hpp" // only use the Stack ADT given, do not use STL stacks

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
// uncomment the following when working on task 4 to implement the insertItemOnSortedStack() template function
// template void insertItemOnSortedStack<int>(int item, Stack<int>& sortedStack);
// template void insertItemOnSortedStack<string>(string item, Stack<string>& sortedStack);

// uncomment the following when working on task 5 to implement the sortStack() template function
// template void sortStack<int>(Stack<int>& aStack);
// template void sortStack<string>(Stack<string>& aStack);