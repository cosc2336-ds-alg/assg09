/** @file assg-tests-stack-functions.cpp
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
 *   file has catch2 unit tests you need to test and implement the
 *   functions for your assignment.
 */
#include "catch.hpp"
#include "Stack.hpp"
#include "AStack.hpp"
#include "LStack.hpp"
#include "stack-functions.hpp"
using namespace std;


/** Task 2: test doParenthesisMatch() functions.  This is the first function
 * you are to implement for this assignment.
 */
/*
   TEST_CASE("<doParenthesisMatch()> test doParenthesismatch function",
          "[task2]")
   {
   // by definition an empty expression should be considered as balanced.
   // Does your function handle an empty expression correctly?
   CHECK(doParenthesisMatch("") );

   // test balanced expressions, from simple cases to more complex ones.
   // All of these match so the function should return true for all of them
   CHECK(doParenthesisMatch("()") );
   CHECK(doParenthesisMatch("()()") );
   CHECK(doParenthesisMatch("(())") );
   CHECK(doParenthesisMatch("(())((()))") );
   CHECK(doParenthesisMatch("(()((())))") );
   CHECK(doParenthesisMatch("((((()))(()((()))))()(()))") );

   // now test detects unbalanced expressions
   CHECK_FALSE(doParenthesisMatch("(") );
   CHECK_FALSE(doParenthesisMatch(")") );
   CHECK_FALSE(doParenthesisMatch("()(") );
   CHECK_FALSE(doParenthesisMatch("(()))") );
   CHECK_FALSE(doParenthesisMatch("((()(())())") );
   CHECK_FALSE(doParenthesisMatch("((((()))(()((())))()(()))") );
   }
 */


/** Task 3: test decodeIDSequence() functions.
 */
/*
   TEST_CASE("<decodeIDSequence()> test decodeIDSequence function",
          "[task3]")
   {
   // the empty squence should return simply 1 as the sequence
   CHECK(decodeIDSequence("") == "1");

   // simple cases of only I increase
   CHECK(decodeIDSequence("I") == "12");
   CHECK(decodeIDSequence("II") == "123");
   CHECK(decodeIDSequence("III") == "1234");
   CHECK(decodeIDSequence("IIIIII") == "1234567");

   // simple cases of only D decrease
   CHECK(decodeIDSequence("D") == "21");
   CHECK(decodeIDSequence("DD") == "321");
   CHECK(decodeIDSequence("DDDD") == "54321");
   CHECK(decodeIDSequence("DDDDDDD") == "87654321");

   // general case with mixed I and D increases and decreases
   CHECK(decodeIDSequence("ID") == "132");
   CHECK(decodeIDSequence("DI") == "213");
   CHECK(decodeIDSequence("IDIDII") == "1325467");
   CHECK(decodeIDSequence("IIDDIDID") == "125437698");
   CHECK(decodeIDSequence("IDIDDIDIIIIDDDDIDDIII") == "13265487910111615141312191817202122");
   }
 */


/** Task 4: test insertItemOnSortedStack() functions.
 */
/*
   TEST_CASE("<insertItemOnSortedStack()> test insertItemOnSorted function",
          "[task4]")
   {
   // only uncomment this first section first for task 4.  Once you have
   // your function sorking for a Stack<int>, then templatize it and
   // uncomment the second section to test on a Stack<string>
   SECTION("test insert item on a stack of integers")
   {
    // stacks should be sorted in descending order, highest value on top of stack
    LStack<int> stack;

    // test on an empty stack
    insertItemOnSortedStack(4, stack);
    CHECK( stack.getSize() == 1 );
    CHECK_FALSE( stack.isEmpty() );
    CHECK( stack.top() == 4 );
    CHECK( stack.str() == "<stack> size: 1 top:[ 4 ]:bottom" );

    // test insert on top of stack
    insertItemOnSortedStack(7, stack);
    CHECK( stack.getSize() == 2 );
    CHECK_FALSE( stack.isEmpty() );
    CHECK( stack.top() == 7 );
    CHECK( stack.str() == "<stack> size: 2 top:[ 7, 4 ]:bottom" );

    // test insert on bottom of stack
    insertItemOnSortedStack(2, stack);
    CHECK( stack.getSize() == 3 );
    CHECK_FALSE( stack.isEmpty() );
    CHECK( stack.top() == 7 );
    CHECK( stack.str() == "<stack> size: 3 top:[ 7, 4, 2 ]:bottom" );

    // test insert somewhere on stack
    insertItemOnSortedStack(6, stack);
    CHECK( stack.getSize() == 4 );
    CHECK_FALSE( stack.isEmpty() );
    CHECK( stack.top() == 7 );
    CHECK( stack.str() == "<stack> size: 4 top:[ 7, 6, 4, 2 ]:bottom" );

    // test insert somewhere on stack
    insertItemOnSortedStack(3, stack);
    CHECK( stack.getSize() == 5 );
    CHECK_FALSE( stack.isEmpty() );
    CHECK( stack.top() == 7 );
    CHECK( stack.str() == "<stack> size: 5 top:[ 7, 6, 4, 3, 2 ]:bottom" );

    // test insert on top and bottom one more time
    insertItemOnSortedStack(8, stack);
    insertItemOnSortedStack(1, stack);
    CHECK( stack.getSize() == 7 );
    CHECK_FALSE( stack.isEmpty() );
    CHECK( stack.top() == 8 );
    CHECK( stack.str() == "<stack> size: 7 top:[ 8, 7, 6, 4, 3, 2, 1 ]:bottom" );
   }

   // leave this commented out initially, and uncomment when ready to templatize
   // your insertItemOnSortedStack() and test it with Stack<string> types.
   SECTION("test insert item on a stack of strings")
   {
    // repeat but use a stack of strings.
    // also we'll use an AStack for the test stack, and LStack for expected
    AStack<string> stack;

    // test on an emtpy stack
    string item = "foxtrot";
    insertItemOnSortedStack(item, stack);
    CHECK( stack.getSize() == 1 );
    CHECK_FALSE( stack.isEmpty() );
    CHECK( stack.top() == "foxtrot" );
    CHECK( stack.str() == "<stack> size: 1 top:[ foxtrot ]:bottom" );

    // test insert on top of stack
    item = "whisky";
    insertItemOnSortedStack(item, stack);
    CHECK( stack.getSize() == 2 );
    CHECK_FALSE( stack.isEmpty() );
    CHECK( stack.top() == "whisky" );
    CHECK( stack.str() == "<stack> size: 2 top:[ whisky, foxtrot ]:bottom" );

    // test insert on bottom of stack
    item = "alpha";
    insertItemOnSortedStack(item, stack);
    CHECK( stack.getSize() == 3 );
    CHECK_FALSE( stack.isEmpty() );
    CHECK( stack.top() == "whisky" );
    CHECK( stack.str() == "<stack> size: 3 top:[ whisky, foxtrot, alpha ]:bottom" );

    // test insert somewhere on stack
    item = "charlie";
    insertItemOnSortedStack(item, stack);
    CHECK( stack.getSize() == 4 );
    CHECK_FALSE( stack.isEmpty() );
    CHECK( stack.top() == "whisky" );
    CHECK( stack.str() == "<stack> size: 4 top:[ whisky, foxtrot, charlie, alpha ]:bottom" );

    // test insert somewhere on stack
    item = "romeo";
    insertItemOnSortedStack(item, stack);
    CHECK( stack.getSize() == 5 );
    CHECK_FALSE( stack.isEmpty() );
    CHECK( stack.top() == "whisky" );
    CHECK( stack.str() == "<stack> size: 5 top:[ whisky, romeo, foxtrot, charlie, alpha ]:bottom" );
    // test insert on top and bottom one more time
    item = "zulu";
    insertItemOnSortedStack(item, stack);
    item = "alpga";
    insertItemOnSortedStack(item, stack);
    CHECK( stack.getSize() == 7 );
    CHECK_FALSE( stack.isEmpty() );
    CHECK( stack.top() == "zulu" );
    CHECK( stack.str() == "<stack> size: 7 top:[ zulu, whisky, romeo, foxtrot, charlie, alpha, alpga ]:bottom" );
   }
   }
 */


/** Task 5: test sortStack() functions.
 */
/*
   TEST_CASE("<sortStack()> test sortStack function",
          "[task5]")
   {
   // again it is suggested to first get your sortStack()
   // function to work with a Stack<int>.  So keep the
   // second section commented out initially
   SECTION("test sort function on an stack of integers")
   {
    LStack<int> stack;

    // sort an empty stack
    sortStack(stack);
    CHECK( stack.getSize() == 0 );
    CHECK( stack.isEmpty() );
    CHECK( stack.str() == "<stack> size: 0 top:[ ]:bottom" );

    // sort stack with single item
    stack.push(5);
    sortStack(stack);
    CHECK( stack.getSize() == 1 );
    CHECK_FALSE( stack.isEmpty() );
    CHECK( stack.top() == 5 );
    CHECK( stack.str() == "<stack> size: 1 top:[ 5 ]:bottom" );

    // sort already sorted stacks
    stack.push(7);
    stack.push(9);
    stack.push(11);
    sortStack(stack);
    CHECK( stack.getSize() == 4 );
    CHECK_FALSE( stack.isEmpty() );
    CHECK( stack.top() == 11 );
    CHECK( stack.str() == "<stack> size: 4 top:[ 11, 9, 7, 5 ]:bottom" );

    // add items out of order and sort
    stack.push(1);
    stack.push(15);
    stack.push(6);
    stack.push(8);
    stack.push(11);
    sortStack(stack);
    CHECK( stack.getSize() == 9 );
    CHECK_FALSE( stack.isEmpty() );
    CHECK( stack.top() == 15 );
    CHECK( stack.str() == "<stack> size: 9 top:[ 15, 11, 11, 9, 8, 7, 6, 5, 1 ]:bottom" );

    // sort a stack that is in reverse order
    stack.clear();
    stack.push(15);
    stack.push(11);
    stack.push(9);
    stack.push(7);
    stack.push(6);
    stack.push(4);
    stack.push(3);
    stack.push(1);
    sortStack(stack);
    CHECK( stack.getSize() == 8 );
    CHECK_FALSE( stack.isEmpty() );
    CHECK( stack.top() == 15 );
    CHECK( stack.str() == "<stack> size: 8 top:[ 15, 11, 9, 7, 6, 4, 3, 1 ]:bottom" );
   }


   // and when you are ready to templatize sortStack(), then uncomment the
   // next test section
   SECTION("test sort function on an stack of strings")
   {
    // perform same tests but with a stack of strings
    AStack<string> stack;

    // sort an empty stack
    sortStack(stack);
    CHECK( stack.getSize() == 0 );
    CHECK( stack.isEmpty() );
    CHECK( stack.str() == "<stack> size: 0 top:[ ]:bottom" );

    // sort stack with single item
    stack.push("mike");
    sortStack(stack);
    CHECK( stack.getSize() == 1 );
    CHECK_FALSE( stack.isEmpty() );
    CHECK( stack.top() == "mike" );
    CHECK( stack.str() == "<stack> size: 1 top:[ mike ]:bottom" );

    // sort already sorted stacks
    stack.push("papa");
    stack.push("sierra");
    stack.push("victor");
    sortStack(stack);
    CHECK( stack.getSize() == 4 );
    CHECK_FALSE( stack.isEmpty() );
    CHECK( stack.top() == "victor" );
    CHECK( stack.str() == "<stack> size: 4 top:[ victor, sierra, papa, mike ]:bottom" );

    // add items out of order and sort
    stack.push("alpha");
    stack.push("x-ray");
    stack.push("tango");
    stack.push("oscar");
    stack.push("mike");
    sortStack(stack);
    CHECK( stack.getSize() == 9 );
    CHECK_FALSE( stack.isEmpty() );
    CHECK( stack.top() == "x-ray" );
    CHECK( stack.str() == "<stack> size: 9 top:[ x-ray, victor, tango, sierra, papa, oscar, mike, mike, alpha ]:bottom" );

    // sort a stack that is in reverse order
    stack.clear();
    stack.push("yankee");
    stack.push("quebec");
    stack.push("november");
    stack.push("november");
    stack.push("lima");
    stack.push("hotel");
    stack.push("echo");
    stack.push("bravo");
    sortStack(stack);
    CHECK( stack.getSize() == 8 );
    CHECK_FALSE( stack.isEmpty() );
    CHECK( stack.top() == "yankee" );
    CHECK( stack.str() == "<stack> size: 8 top:[ yankee, quebec, november, november, lima, hotel, echo, bravo ]:bottom" );
   }
   }
 */