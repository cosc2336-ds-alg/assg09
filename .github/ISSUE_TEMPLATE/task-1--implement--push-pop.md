---
name: 'Task 1: Implement `push()` and `pop()` `LStack` Member Functions'
about: Task 1 for Students
title: 'Task 1: Implement `push()` and `pop()` `LStack` Member Functions'
labels: enhancement, good first issue
assignees: ''

---

**Description**

Implement the missing `push()` and `pop()` member methods of the `LStack` class.  This class is a concrete linked list implementation of the `Stack` API.  For performance reasons, we need to push and pop values to the front of the link list of nodes being maintained by this class for the stack.

**Suggested Solution**

For `push()` do the following:

1. Create a new `Node` dynamically.
   - Initialize the nodes value to the value given to the `push()` function.
   - Initialize the `next` pointer to be `nullptr` for now.
2. Test if the stack is empty using the `isEmpty()` member method.
   - If the stack is empty, this new node becomes the only node in the
     stack, so point `topNode` to the node you just created.
   - If the stack is not empty, then point the new node to the
     current `topNode` of the stack, and repoint `topNode` to be
	 this new node that you are pushing.
3. Don't forget to update the `size` of the stack, which has grown
   by 1 now.


For 'pop()' do the following:

1. You should check if the stack is empty first, and if it is throw
   an exception of type `StackEmptyException` to indicate an illegal
   attempt to pop from an empty stack.
2. Otherwise, make a temporary pointer and point it to the current
   `topNode`
3. Move the `topNode` to point to the next node in the list.
4. Delete the old top node that is pointed to by your temporary
   pointer since it is no longer needed and we need to return its
   memory back to the heap.
5. Don't forget to update the `size` of the stack, which has now been
   reduced by 1.


**Additional Requirements**

- You should make it a habit to always reuse code instead of repeating code.  Here you need to test if the stack is empty or not.  Reuse the `isEmpty()` function instead of testing size or the status of `front` and `back` pointers.  This makes your intention clearer (`isEmpty()` is generally more readable).  And it means if we want to change how we test if the list is empty or not, we can do it in one function if all parts of the class use this function when checking if the list is empty or not. 
- Make sure that you uncomment the calls to `push()` in the `LStack` constructors so that they are reusing your function and properly constructing lists now.
- You are required to `throw` the correct exception if an attempt is made to pop a value from an empty stack.
