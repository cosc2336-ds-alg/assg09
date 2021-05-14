---
name: 'Task 4: Implement `insertItemOnSortedStack()` Template Function'
about: Task 4 for Students
title: 'Task 4: Implement `insertItemOnSortedStack()` Template Function'
labels: enhancement
assignees: ''

---

**Description**

The fourth task is to implement `insertItemOnSortedStack()` function.  This function will ultimately take an item of some type `T` as input, though initially before you turn the function into a template function, you can first get it working for concrete `int` types.  A second parameter, a `Stack<T>&`, a reference to a stack of some type `T` is also given.  This parameter must be a reference parameter.  You can initially use a `Stack<int>&` a reference to a stack of integers and then templatize the function once you get that working.

This function expects the stack to be sorted before it is called.  This function will insert the item it is given onto the stack in the correct position to keep the stack sorted.


**Suggested Solution**

The pseudo-code to accomplish this insertion is as follow:

   
```
given and inputStack
and you create a temporaryStack for this algorithm

while top of inputStack > item we want to insert
do
    pop topItem from inputStack
    push topItem onto the temporaryStack
done

at this point, items on inputStack are <= to the item we want to insert
so push item onto inputStack

now put items back from temporaryStack to original inputStack
while temporaryStack is not empty
do
    pop topItem from temporaryStack
    push topItem onto the inputStack
done
```

**Additional Requirements**

- You must ultimately make this function a template function, that will accept a
  item of any type `T` and a `Stack<T>&` to insert the item onto in the correct place.
- You will need an internal temporary stack that is different from the one passed in as a parameter.  Again you need to use one of our `Stack` functions from this assignment.


