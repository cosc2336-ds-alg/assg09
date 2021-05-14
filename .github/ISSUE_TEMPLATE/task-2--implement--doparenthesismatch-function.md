---
name: 'Task 2: Implement `doParenthesisMatch()` Function'
about: Task 2 for Students
title: 'Task 2: Implement `doParenthesisMatch()` Function'
labels: enhancement
assignees: ''

---

**Description**

Implement the `doParenthesisMatch()` regular C/C++ function in the `stack-functions.[hpp|cpp]` files.  This function takes a `string` parameter as input and it returns a `bool` boolean result.  The purpose of this function is to determine if a given input string of open `(` and close `)` parenthesis are matching or not.

**Suggested Solution**

The algorithm to check for matching parenthesis using a stack is
fairly simple.  A pseudo-code description might be
   
```
for each charcter c in expression
do
    if c is an open paren '('
        push it on stack

    if c is a close paren ')':
    then
        if stack is empty
            answer is false, because we can't match the current ')'

        else
            pop stack, because we just matched an open '(' with a close ')'
    endif
done
```

Your function will be given a C++ string class as input.  It is
relatively simple to parse each character of a C++ string.  Here is an
example for loop to do this:
   
``` c++
s = "(())";
for (size_t index = 0; index < s.length(); index++)
{
    char c = s[index];

    // handle char c of the string expression s here
}
```


**Additional Requirements**

- You must use one of our `Stack` concrete implementations in your function.  It doesn't matter if
  if is a `LStack` or a `AStack`, mix them up in this assignment.

