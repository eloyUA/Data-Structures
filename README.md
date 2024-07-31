# Data-Structures
In this repository, there are data structures such as static stack, dynamic stack, static queue, dynamic queue...

## Table of Contents
1. [General information](#general-information)
2. [Installation](#installation)

### General information
An data structure, is an implementation of all the functions to store data in different forms.
For example, in this repository, we have a stack (dynamic and static), a queue (dynamic and static),
a linked list (obviously dynamic) and a dictionary.

### Installation
First, we need to know that all data structures in this repository are modules. Therefore, we need another C file to execute them.
So, if we want to compile this file 'main.c' and use the dynamic stack module:

```
git clone https://github.com/eloyUA/Data-Structures
cd Data-Structures/dynamicStack
gcc -c dynamicStack.c
gcc [path of the main.c] dynamicStack.o -o nameProgram
```
