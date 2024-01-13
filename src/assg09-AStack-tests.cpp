/** @file test-AStack.cpp
 * @brief Unit tests for Assignment Overloading and Templates
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Stacks
 * @date   June 1, 2021
 *
 * Tests of the array based implementation of the Stack API.
 */
#include "AStack.hpp"
#include "StackException.hpp"
#include "catch.hpp"
#include <cmath>
#include <iostream>
using namespace std;

/** Test AStack<int> concrete array implementation of stack of integers
 */
TEST_CASE("AStack<int> test integer stack concrete array implementation", "[task0]")
{
  SECTION("test empty stack is empty")
  {
    // empty stacks should be empty
    AStack<int> empty;
    CHECK(empty.getSize() == 0);
    CHECK(empty.getAllocationSize() == 0); // only for AStack
    CHECK(empty.isEmpty());
    CHECK(empty.str() == "<stack> size: 0 top:[ ]:bottom");

    // empty stacks should compare as being equal
    AStack<int> otherEmpty;
    CHECK(otherEmpty == empty);
    CHECK(empty == otherEmpty);

    // empty stacks should complain if asked to get a value from them
    CHECK_THROWS_AS(empty.top(), StackEmptyException);
    CHECK_THROWS_AS(empty[0], StackMemoryBoundsException);

    // empty stack can be cleared and is still empty
    empty.clear();
    CHECK(empty.getSize() == 0);
    CHECK(empty.getAllocationSize() == 0); // only for AStack<>
    CHECK(empty.isEmpty());
    CHECK(empty.str() == "<stack> size: 0 top:[ ]:bottom");
  }

  SECTION("test push, pop and top general functionality")
  {
    // start with emtpy stack
    AStack<int> stack;
    CHECK(stack.getSize() == 0);
    CHECK(stack.getAllocationSize() == 0); // only for AStack
    CHECK(stack.isEmpty());
    CHECK(stack.str() == "<stack> size: 0 top:[ ]:bottom");

    // push an item on empty stack
    stack.push(5);
    CHECK(stack.getSize() == 1);
    CHECK(stack.getAllocationSize() == 10); // only for AStack
    CHECK_FALSE(stack.isEmpty());
    CHECK(stack.top() == 5);
    CHECK(stack.str() == "<stack> size: 1 top:[ 5 ]:bottom");

    // push a second  item on stack
    stack.push(8);
    CHECK(stack.getSize() == 2);
    CHECK(stack.getAllocationSize() == 10); // only for AStack
    CHECK_FALSE(stack.isEmpty());
    CHECK(stack.top() == 8);
    CHECK(stack.str() == "<stack> size: 2 top:[ 8, 5 ]:bottom");

    // push a third item on stack
    stack.push(15);
    CHECK(stack.getSize() == 3);
    CHECK(stack.getAllocationSize() == 10); // only for AStack
    CHECK_FALSE(stack.isEmpty());
    CHECK(stack.top() == 15);
    CHECK(stack.str() == "<stack> size: 3 top:[ 15, 8, 5 ]:bottom");

    // test pop of stack with more than 1 item
    stack.pop();
    CHECK(stack.getSize() == 2);
    CHECK(stack.getAllocationSize() == 10); // only for AStack
    CHECK_FALSE(stack.isEmpty());
    CHECK(stack.top() == 8);
    CHECK(stack.str() == "<stack> size: 2 top:[ 8, 5 ]:bottom");

    // push 2 itmes on
    stack.push(1);
    CHECK(stack.top() == 1);
    stack.push(3);
    CHECK(stack.getSize() == 4);
    CHECK(stack.getAllocationSize() == 10); // only for AStack
    CHECK_FALSE(stack.isEmpty());
    CHECK(stack.top() == 3);
    CHECK(stack.str() == "<stack> size: 4 top:[ 3, 1, 8, 5 ]:bottom");

    // pop back to 1 item
    stack.pop();
    stack.pop();
    stack.pop();
    CHECK(stack.getSize() == 1);
    CHECK(stack.getAllocationSize() == 10); // only for AStack
    CHECK_FALSE(stack.isEmpty());
    CHECK(stack.top() == 5);
    CHECK(stack.str() == "<stack> size: 1 top:[ 5 ]:bottom");

    // make stack empty again
    stack.pop();
    CHECK(stack.getSize() == 0);
    CHECK(stack.getAllocationSize() == 10); // only for AStack
    CHECK(stack.isEmpty());
    CHECK(stack.str() == "<stack> size: 0 top:[ ]:bottom");

    // should complain if we try and pop an empty stack
    CHECK_THROWS_AS(stack.pop(), StackEmptyException);

    // push on 10 items
    for (int index = 1; index <= 10; index++)
    {
      stack.push(pow(index, 3));
    }
    CHECK(stack.getSize() == 10);
    CHECK(stack.getAllocationSize() == 10); // only for AStack
    CHECK_FALSE(stack.isEmpty());
    CHECK(stack.str() == "<stack> size: 10 top:[ 1000, 729, 512, 343, 216, 125, 64, 27, 8, 1 ]:bottom");

    // Array based stack should double in size, only for AStack tests
    stack.push(pow(11, 3));
    CHECK(stack.getSize() == 11);
    CHECK(stack.getAllocationSize() == 20); // only for AStack
    CHECK_FALSE(stack.isEmpty());
    CHECK(stack.str() == "<stack> size: 11 top:[ 1331, 1000, 729, 512, 343, 216, 125, 64, 27, 8, 1 ]:bottom");
  }

  SECTION("test clear of stack")
  {
    // create stack of 11 values
    AStack<int> stack;
    for (int index = 1; index <= 11; index++)
    {
      stack.push(pow(index, 3));
    }
    CHECK(stack.getSize() == 11);
    CHECK(stack.getAllocationSize() == 20); // only for AStack
    CHECK_FALSE(stack.isEmpty());
    CHECK(stack.str() == "<stack> size: 11 top:[ 1331, 1000, 729, 512, 343, 216, 125, 64, 27, 8, 1 ]:bottom");

    // clear the stack
    stack.clear();
    CHECK(stack.getSize() == 0);
    CHECK(stack.getAllocationSize() == 0); // only for AStack
    CHECK(stack.isEmpty());
    CHECK(stack.str() == "<stack> size: 0 top:[ ]:bottom");

    // should be equal to an empty stack
    AStack<int> empty;
    CHECK(empty == stack);
    CHECK(stack == empty);
  }

  SECTION("test array based constructor")
  {
    int values[] = {1, 3, -2, -4, 7};
    AStack<int> stack(5, values);

    // nonempty stack should not be empty
    CHECK(stack.getSize() == 5);
    CHECK(stack.getAllocationSize() == 5); // only for AStack<>
    CHECK_FALSE(stack.isEmpty());
    CHECK(stack.str() == "<stack> size: 5 top:[ 1, 3, -2, -4, 7 ]:bottom");

    // test access to front and back
    CHECK(stack.top() == 1);

    // test indexing access
    CHECK(stack[0] == 1);
    CHECK(stack[1] == 3);
    CHECK(stack[2] == -2);
    CHECK(stack[3] == -4);
    CHECK(stack[4] == 7);
    CHECK_THROWS_AS(stack[-1], StackMemoryBoundsException);
    CHECK_THROWS_AS(stack[5], StackMemoryBoundsException);
    stack[2] = 42;
    CHECK(stack[2] == 42);
    CHECK(stack.str() == "<stack> size: 5 top:[ 1, 3, 42, -4, 7 ]:bottom");

    // test inserting on stack, and that stack allocation grows as expected
    stack.push(22);
    CHECK(stack.getSize() == 6);
    CHECK(stack.getAllocationSize() == 10); // only for AStack<>
    CHECK(stack.top() == 22);
    CHECK(stack.str() == "<stack> size: 6 top:[ 22, 1, 3, 42, -4, 7 ]:bottom");

    stack.push(38);
    CHECK(stack.getSize() == 7);
    CHECK(stack.getAllocationSize() == 10); // only for AStack<>
    CHECK(stack.top() == 38);
    CHECK(stack.str() == "<stack> size: 7 top:[ 38, 22, 1, 3, 42, -4, 7 ]:bottom");
  }

  SECTION("test copy constructor")
  {
    int values[] = {3, 1, 4, 2};
    AStack<int> stack(4, values);
    AStack<int> copy = stack;

    // copy should be equal to the stack
    CHECK(copy == stack);
    CHECK(stack == copy);

    // copy is no longer equal
    stack.push(5);
    CHECK_FALSE(copy == stack);
    CHECK_FALSE(stack == copy);

    // now they are the same again
    copy.push(5);
    CHECK(copy == stack);
    CHECK(stack == copy);

    // now they are no longer equal, copy is 2 shorter
    copy.pop();
    copy.pop();
    CHECK_FALSE(copy == stack);
    CHECK_FALSE(stack == copy);
  }
}

/** Test AStack<string> concrete array implementation of stack of strings
 */
TEST_CASE("AStack<string> test string stack concrete array implementation", "[task0]")
{
  SECTION("test empty stack is empty")
  {
    // empty stacks should be empty
    AStack<string> empty;
    CHECK(empty.getSize() == 0);
    CHECK(empty.getAllocationSize() == 0); // only for AStack
    CHECK(empty.isEmpty());
    CHECK(empty.str() == "<stack> size: 0 top:[ ]:bottom");

    // empty stacks should compare as being equal
    AStack<string> otherEmpty;
    CHECK(otherEmpty == empty);
    CHECK(empty == otherEmpty);

    // empty stacks should complain if asked to get a value from them
    CHECK_THROWS_AS(empty.top(), StackEmptyException);
    CHECK_THROWS_AS(empty[0], StackMemoryBoundsException);

    // empty stack can be cleared and is still empty
    empty.clear();
    CHECK(empty.getSize() == 0);
    CHECK(empty.getAllocationSize() == 0); // only for AStack<>
    CHECK(empty.isEmpty());
    CHECK(empty.str() == "<stack> size: 0 top:[ ]:bottom");
  }

  SECTION("test push, pop and top general functionality")
  {
    // start with empty stack
    AStack<string> stack;
    CHECK(stack.getSize() == 0);
    CHECK(stack.getAllocationSize() == 0); // only for AStack
    CHECK(stack.isEmpty());
    CHECK(stack.str() == "<stack> size: 0 top:[ ]:bottom");

    // push an item on empty stack
    stack.push("echo");
    CHECK(stack.getSize() == 1);
    CHECK(stack.getAllocationSize() == 10); // only for AStack
    CHECK_FALSE(stack.isEmpty());
    CHECK(stack.top() == "echo");
    CHECK(stack.str() == "<stack> size: 1 top:[ echo ]:bottom");

    // push a second  item on stack
    stack.push("hotel");
    CHECK(stack.getSize() == 2);
    CHECK(stack.getAllocationSize() == 10); // only for AStack
    CHECK_FALSE(stack.isEmpty());
    CHECK(stack.top() == "hotel");
    CHECK(stack.str() == "<stack> size: 2 top:[ hotel, echo ]:bottom");

    // push a third item on stack
    stack.push("oscar");
    CHECK(stack.getSize() == 3);
    CHECK(stack.getAllocationSize() == 10); // only for AStack
    CHECK_FALSE(stack.isEmpty());
    CHECK(stack.top() == "oscar");
    CHECK(stack.str() == "<stack> size: 3 top:[ oscar, hotel, echo ]:bottom");

    // test pop of stack with more than 1 item
    stack.pop();
    CHECK(stack.getSize() == 2);
    CHECK(stack.getAllocationSize() == 10); // only for AStack
    CHECK_FALSE(stack.isEmpty());
    CHECK(stack.top() == "hotel");
    CHECK(stack.str() == "<stack> size: 2 top:[ hotel, echo ]:bottom");

    // push 2 itmes on
    stack.push("alpha");
    CHECK(stack.top() == "alpha");
    stack.push("charlie");
    CHECK(stack.getSize() == 4);
    CHECK(stack.getAllocationSize() == 10); // only for AStack
    CHECK_FALSE(stack.isEmpty());
    CHECK(stack.top() == "charlie");
    CHECK(stack.str() == "<stack> size: 4 top:[ charlie, alpha, hotel, echo ]:bottom");

    // pop back to 1 item
    stack.pop();
    stack.pop();
    stack.pop();
    CHECK(stack.getSize() == 1);
    CHECK(stack.getAllocationSize() == 10); // only for AStack
    CHECK_FALSE(stack.isEmpty());
    CHECK(stack.top() == "echo");
    CHECK(stack.str() == "<stack> size: 1 top:[ echo ]:bottom");

    // make stack empty again
    stack.pop();
    CHECK(stack.getSize() == 0);
    CHECK(stack.getAllocationSize() == 10); // only for AStack
    CHECK(stack.isEmpty());
    CHECK(stack.str() == "<stack> size: 0 top:[ ]:bottom");

    // should complain if we try and pop an empty stack
    CHECK_THROWS_AS(stack.pop(), StackEmptyException);

    // push on 10 items
    for (int index = 1; index <= 10; index++)
    {
      stack.push("string-" + to_string(int(pow(index, 3))));
    }
    CHECK(stack.getSize() == 10);
    CHECK(stack.getAllocationSize() == 10); // only for AStack
    CHECK_FALSE(stack.isEmpty());
    CHECK(stack.str() == "<stack> size: 10 top:[ string-1000, string-729, string-512, string-343, string-216, string-125, string-64, "
                         "string-27, string-8, string-1 ]:bottom");

    // Array based stack should double in size, only for AStack tests
    stack.push("string-" + to_string(int(pow(11, 3))));
    CHECK(stack.getSize() == 11);
    CHECK(stack.getAllocationSize() == 20); // only for AStack
    CHECK_FALSE(stack.isEmpty());
    CHECK(stack.str() == "<stack> size: 11 top:[ string-1331, string-1000, string-729, string-512, string-343, string-216, string-125, "
                         "string-64, string-27, string-8, string-1 ]:bottom");
  }

  SECTION("test clear of stack")
  {
    // create stack of 11 values
    AStack<string> stack;
    for (int index = 1; index <= 11; index++)
    {
      stack.push("string-" + to_string(int(pow(index, 3))));
    }
    CHECK(stack.getSize() == 11);
    CHECK(stack.getAllocationSize() == 20); // only for AStack
    CHECK_FALSE(stack.isEmpty());
    CHECK(stack.str() == "<stack> size: 11 top:[ string-1331, string-1000, string-729, string-512, string-343, string-216, string-125, "
                         "string-64, string-27, string-8, string-1 ]:bottom");

    // clear the stack
    stack.clear();
    CHECK(stack.getSize() == 0);
    CHECK(stack.getAllocationSize() == 0); // only for AStack
    CHECK(stack.isEmpty());
    CHECK(stack.str() == "<stack> size: 0 top:[ ]:bottom");

    // should be equal to an empty stack
    AStack<string> empty;
    CHECK(empty == stack);
    CHECK(stack == empty);
  }

  SECTION("test array based constructor")
  {
    string values[] = {"alpha", "charlie", "neg-bravo", "neg-delta", "golf"};
    AStack<string> stack(5, values);

    // nonempty stack should not be empty
    CHECK(stack.getSize() == 5);
    CHECK(stack.getAllocationSize() == 5); // only for AStack<>
    CHECK_FALSE(stack.isEmpty());
    CHECK(stack.str() == "<stack> size: 5 top:[ alpha, charlie, neg-bravo, neg-delta, golf ]:bottom");

    // test access to front and back
    CHECK(stack.top() == "alpha");

    // test indexing access
    CHECK(stack[0] == "alpha");
    CHECK(stack[1] == "charlie");
    CHECK(stack[2] == "neg-bravo");
    CHECK(stack[3] == "neg-delta");
    CHECK(stack[4] == "golf");
    CHECK_THROWS_AS(stack[-1], StackMemoryBoundsException);
    CHECK_THROWS_AS(stack[5], StackMemoryBoundsException);
    stack[2] = "life-universe-everything";
    CHECK(stack[2] == "life-universe-everything");
    CHECK(stack.str() == "<stack> size: 5 top:[ alpha, charlie, life-universe-everything, neg-delta, golf ]:bottom");

    // test inserting on stack, and that stack allocation grows as expected
    stack.push("victor");
    CHECK(stack.getSize() == 6);
    CHECK(stack.getAllocationSize() == 10); // only for AStack<>
    CHECK(stack.top() == "victor");
    CHECK(stack.str() == "<stack> size: 6 top:[ victor, alpha, charlie, life-universe-everything, neg-delta, golf ]:bottom");

    stack.push("zulu");
    CHECK(stack.getSize() == 7);
    CHECK(stack.getAllocationSize() == 10); // only for AStack<>
    CHECK(stack.top() == "zulu");
    CHECK(stack.str() == "<stack> size: 7 top:[ zulu, victor, alpha, charlie, life-universe-everything, neg-delta, golf ]:bottom");
  }

  SECTION("test copy constructor")
  {
    string values[] = {"charlie", "alpha", "delta", "bravo"};
    AStack<string> stack(4, values);
    AStack<string> copy = stack;

    // copy should be equal to the stack
    CHECK(copy == stack);
    CHECK(stack == copy);

    // copy is no longer equal
    stack.push("echo");
    CHECK_FALSE(copy == stack);
    CHECK_FALSE(stack == copy);

    // now they are the same again
    copy.push("echo");
    CHECK(copy == stack);
    CHECK(stack == copy);

    // now they are no longer equal, copy is 2 shorter
    copy.pop();
    copy.pop();
    CHECK_FALSE(copy == stack);
    CHECK_FALSE(stack == copy);
  }
}
