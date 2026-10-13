\# Family Tree in C



\## Project Overview



This project implements a three-generation family tree using the C programming language.



The program collects the names and ages of seven family members, establishes relationships using pointers, displays the family tree, and frees dynamically allocated memory before terminating.



\## Features



\* Stores each family member in a `Person` structure.

\* Collects names and ages through interactive console input.

\* Uses pointers to represent relationships between family members.

\* Displays parents and grandparents by traversing pointers.

\* Uses `malloc()` for dynamic memory allocation.

\* Uses `free()` to release allocated memory.



\## Data Structure



Each `Person` structure contains:



\* `name`: Stores the person's name.

\* `age`: Stores the person's age.

\* `father`: Points to the person's father.

\* `mother`: Points to the person's mother.



Each family member is represented by a single `Person` structure. Relationships reference existing structures through pointers rather than duplicating family members' data.



\## Family Members



1\. Paternal Grandfather

2\. Paternal Grandmother

3\. Maternal Grandfather

4\. Maternal Grandmother

5\. Father

6\. Mother

7\. Yourself



\## Compilation



Compile the program using GCC:



```bash

gcc -Wall -Wextra -std=c11 family\_tree.c -o family\_tree

```



\## Execution



On Linux:



```bash

./family\_tree

```



On Windows PowerShell:



```powershell

.\\family\_tree.exe

```



\## Sample Output



The program displays the user's details, both parents, and all four grandparents by traversing the family tree's pointers.



!\[Family Tree Program Output](family\_tree\_output.png)



\## Memory Management



The program dynamically allocates memory for each family member using `malloc()`.



The `free\_family\_tree()` function releases the allocated memory for all seven family members before the program terminates.



\## Author



Ajeet Mahto



