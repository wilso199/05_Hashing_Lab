05_Hashing_Lab
==============

Implement a hash table in C++

Requirements
------------

1. `keyExists`, `find`, `remove`, and `size` should all be O(1)
2. `add` should be reasonably fast. Use linear probing to find an open slot in the hash table. This will be O(1), on average, except when `grow` is called.
3. `grow` should be O(n)
4. Do not leak memory


Reading
=======
"Open Data Structures," Chapter 5, except for 5.2.3. http://opendatastructures.org/ods-cpp/5_Hash_Tables.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. works and all are completed in O(1) time. Size returns a variable and find, remove, and keyExists all rely on linear probing which should always be around constant time.
2. works. Add should always be around O(1) time unless grow is called, then it will be O(n).
3. works. Correctly assigns keys to locations in the new array and runs at O(n) time. 
4. There should not be any memory leaks as everything is destructed properly in the grow() method and the destructor. 

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

I think the best way to design the functionality is to have both of these functions available. First, it allows the user to only check if the keyExists if for some reason they would want to do that. Also by having find() call keyExists it will give the programer an error message if it doesn’t exist which is a much more helpful message than just receiving NULL. By having an error message it allows programmers to more easily understand what is going on in the code and is much easier to catch when implementing a hash table then catching NULL would be.  

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Advice: Try to make sure you fully understand the concept behind the hash table data structure before you jump in to the code. If you just jump in to the code, things get confusing very fast. 