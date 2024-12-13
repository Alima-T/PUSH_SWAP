# PUSH_SWAP

## Introduction

**PUSH_SWAP** is a 42 project that focuses on creating an optimized algorithm to sort a stack of integers using a minimal number of operations. The task is performed with the help of two stacks and a predefined set of operations.

## Algorithm

This implementation is based on Turk Algorithm, adapted to work efficiently.

---

## Features

- Two stacks (`A` and `B`) for sorting.
- Custom operations:
  - `sa`, `sb`, `ss`: Swap the top two elements.
  - `pa`, `pb`: Push the top element between stacks.
  - `ra`, `rb`, `rr`: Rotate stack (shift up).
  - `rra`, `rrb`, `rrr`: Reverse rotate stack (shift down).
- Optimized sorting for small to large datasets.

---

## Instructions

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/Alima-T/PUSH_SWAP.git
   cd push_swap
   ```
2. Compile the program:
   ```bash
   make
   ```

### Usage

Run the program with a list of integers to sort:
```bash
./push_swap [integers]
```
Example:
```bash
./push_swap 3 2 5 1 4
```
---

## Gretitude

My gretitudes to [roma-sh](https://github.com/roma-sh) for the valuable and useful exchange of experience.
