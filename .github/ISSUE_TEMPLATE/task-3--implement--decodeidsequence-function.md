---
name: 'Task 3: Implement `decodeIDSequence()` Function'
about: Task 3 for Students
title: 'Task 3: Implement `decodeIDSequence()` Function'
labels: enhancement
assignees: ''

---

**Description**

Implement the `decodeIDSequence()` function as described.  This function is a bit of a puzzle/game.  Given a seuqnce of `I` characters for increase and `D` characters for decrease, you need to return a string of digits that meets the criteria of the ID sequence.

This function takes a `string` as the input sequence, so you will need to iterate over it character by character again.  And it returns a new `string`, the constructed sequence of digits, that you should return as a result from this function.

**Suggested Solution**

Here is the pseudo-code for an algorithm using a stack that will correctly decode
an ID sequence into the correct sequence of digits.

```
for each index, character c in input sequence
do
    push character index+1 onto stack (given 0 based index in C)

    if we have processed all characters or c == 'I' (an increase)
    then
        pop each index from stack and append it to the end of result
    endif
done
```

**Additional Requirements**

- You are required to use one of our class `Stack` items for the stack needed by this algorithm.

