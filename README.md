*This project has been created as part of the 42 curriculum by <wkrati>.*

# Push_Swap
---

## Description
The **push_swap** project is an algorithmic challenge whose objective is to sort a stack of integers in ascending order using a restricted set of operations.

The program takes a list of integers as command-line arguments, stores them in stack **A**, and outputs a sequence of instructions that sorts the stack while minimizing the number of operations, in accordance with the project rules.

## Instructions

### Compilation
```bash
make
```

### Execution
```bash
./push_swap 4 67 3 87 23
```

Example with randomly generated values:
```bash
ARG=$(shuf -i -1000:1000 -n 100 | tr '\n' ' ')
./push_swap $ARG
```

### Cleaning
```bash
make fclean
```

## Resources
- 42 official **push_swap** subject
- Unix manual pages:
  - `man write`
  - `man malloc`
  - `man free`
- Stack data structures and linked lists
- Sorting algorithms and optimization strategies

## AI Usage
AI tools were used as a learning assistant to:
- Clarify algorithmic concepts and constraints
- Assist in reasoning about edge cases and debugging
- Support understanding of optimization strategies

All code was written, tested, and validated manually by the student, in compliance with the 42 curriculum rules.

