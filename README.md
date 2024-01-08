# Push_swap Project

## Introduction

The Push_swap project challenges participants to implement an efficient sorting algorithm using two stacks and a limited set of instructions. The goal is to create a program, `push_swap`, that generates the smallest sequence of instructions to sort a given set of integers.

## Why it is Relevant

This project is relevant for various reasons:

- **Algorithmic Understanding:** Participants gain a deeper understanding of sorting algorithms, their complexities, and the importance of optimization.

- **Practical Application:** Sorting algorithms are fundamental in computing, making this project applicable in real-world scenarios.

- **Optimization Challenges:** Emphasizes the optimization of algorithms to produce the most efficient solution.

## Key Concepts

- **Stacks:** Two stacks, denoted as Stack A and Stack B, follow the Last In, First Out (LIFO) principle. They are used for managing integers during the sorting process.

- **Algorithmic Complexity:**
  - **Time Complexity:** Radix Sort provides linear time complexity, making it efficient for large datasets.
  - **Space Complexity:** The algorithm's space complexity is influenced by the number of digits in the largest number.

- **Radix Sort Algorithm:** The project specifies the use of Radix Sort, a non-comparative sorting algorithm with linear time complexity (O(NK)), where N is the number of elements, and K is the number of digits in the largest number.


## How to Run

### Prerequisites

- c compiler.

### Commands

1. **Compile the project:**

    ```bash
    make
    ```

2. **Run the `push_swap` program:**

    ```bash
    ./push_swap [list_of_integers]
    ```

3. **Example:**

    ```bash
    ./push_swap 2 1 3 6 5 8
    ```

## Running Additional Tests

Create and run additional tests to ensure the program's robustness, covering various scenarios and edge cases. Use the provided `checker` program to validate correctness.

## License

This project under MIT LICENSE.
