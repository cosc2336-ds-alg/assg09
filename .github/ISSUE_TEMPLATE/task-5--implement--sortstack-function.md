---
name: 'Task 5: Implement `sortStack()` Template Function'
about: Task 4 for Students
title: 'Task 5: Implement `sortStack()` Template Function'
labels: enhancement
assignees: ''

---

**Description**

The fifth task is to implement the `sortStack()` template function. This function is a `void` function, nothing explicit is returned.  It takes a `Stack<int>&` reference to a stack of integers as its only parameter.  Again you will later templatize this function to work on a `Stack<T>&` of any type.  Also again it is important that this parameter be passed in by refernce, because the stack is sorted by this function, and if the parameter is not passed in by reference, the sorting will not be seen by the caller on return.

The function, as the name implies, will take an unsorted stack, and
will sort them in the same order we used previously, e.g.  in
ascending order with the smallest item at the bottom of the stack, and
the largest at the top. 

**Suggested Solution**

The pseudo-code to accomplish this using a recursive algorithm is as
follows:
   
```
given inputStack as an input parameter

# the base case
if inputStack is empty, do nothing (return)

# the general case
take top item from inputStack and save it in a local variable

call sortStack(inputStack) recursively on this now smaller stack

# on return, the stack should be sorted, so
insertItemOnSortedStack(my item I popped, inputStack)
```


**Additional Requirements**

- You are required to write a recursive implementation for the `sortStack()` function.




