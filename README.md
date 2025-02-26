# Push_swap - 42 Amman

## Author
- **Hamza Almuhisen** - [@hamzah1432](https://github.com/hamzah1432)
- 42 Amman Student

## Overview
`push_swap` is a sorting algorithm project at 42 Amman where the goal is to sort a stack of integers using the smallest number of operations. It involves two stacks (`a` and `b`) and a limited set of commands to manipulate them.

---

## Objectives
- Write a sorting program in C.
- Optimize for minimal operations.
- Understand algorithmic complexity and efficiency.

---

## Features
- **Two Stacks:** Operate on `a` and `b`.
- **Commands:**
  - **Swap:** `sa`, `sb`, `ss`
  - **Push:** `pa`, `pb`
  - **Rotate:** `ra`, `rb`, `rr`
  - **Reverse Rotate:** `rra`, `rrb`, `rrr`
- **Sorting Goal:** Sort integers in ascending order in stack `a`.

---

## Input Requirements
- **Valid Input:**
  - Integer numbers only
  - No duplicates allowed
  - Numbers must be within INT_MIN (-2147483648) to INT_MAX (2147483647)
  - Numbers can be provided as a string with spaces
  
- **Examples of valid input:**
  ```
  ./push_swap 1 2 3 4 5
  ./push_swap -123 45 67 -89
  ```

- **Invalid inputs (will display "Error"):**
  - Non-numeric values
  - Duplicates
  - Numbers outside integer range
  - Empty input

---

## Requirements
- **Language:** C
- **Standards:** Adherence to the Norm.
- **Memory Management:** No memory leaks or segmentation faults.
- **Makefile:** Targets include `all`, `clean`, `fclean`, and `re`.

---

## 42 School Project
This project is part of the 42 School curriculum, specifically developed and tested at 42 Amman. It follows the school's coding standards and requirements.
