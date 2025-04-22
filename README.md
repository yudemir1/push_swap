# Push_swap - Algorithmic Stack Sorting (42 Project) 🔄🔢

This project is a challenging algorithmic exercise from the 42 school curriculum. The core task is to sort a list of unique integers using only **two stacks** (`'a'` and `'b'`) and a restricted set of **11 operations**. The primary objective is not just to sort the numbers, but to do so using the **minimum possible number of operations** to pass rigorous benchmark tests.

---

## 🎯 Problem

Given a list of integers, initially all in stack `'a'` (stack `'b'` is empty), output a sequence of stack operations (`sa`, `pb`, `ra`, `rrr`, etc.) that results in stack `'a'` being sorted in ascending order.

---

## ⚙️ Constraints & Challenges

*   Only the **11 specified operations** are allowed.
*   The solution must be optimized for **minimal operation count**. Different sorting strategies and optimizations are required for varying list sizes to meet benchmark requirements (e.g., sorting 500 numbers efficiently).
*   Strict error handling for invalid input.
*   No global variables.
*   Memory leak-free.

---

## 🛠️ Implemented Operations

*   `sa` (swap a)
*   `sb` (swap b)
*   `ss` (sa and sb)
*   `pa` (push a)
*   `pb` (push b)
*   `ra` (rotate a)
*   `rb` (rotate b)
*   `rr` (ra and rb)
*   `rra` (reverse rotate a)
*   `rrb` (reverse rotate b)
*   `rrr` (rra and rrb)

---

## ✨ Bonus Features

*   `[ ]` **The Checker Program:** Implementation of a separate executable (`checker`) that validates the output of `push_swap`. It reads the initial stack configuration and the sequence of operations from standard input, executes them, and reports `"OK"` if the stack is sorted and `'b'` is empty, or `"KO"` otherwise. *(Mark `[x]` if implemented)*

---

## 🧠 Sorting Strategy

My approach combines methods based on the input size:

### Handling the Simple Cases (N=2, N=3)

*   **For exactly two numbers (`sort_two`):** It's trivial: I just check if they're out of order and use `sa` if needed. One move, maximum.
*   **For exactly three numbers (`sort_three`):** There are only 3! = 6 possible arrangements. I figured out the shortest sequence of moves (`sa`, `ra`, `rra`) for each specific permutation based on their final sorted `index` values. This guarantees the optimal sort for three elements.

### The Main Strategy (N > 3)

*   **Initial Partition:** I start by pushing all but the last three elements from stack `'a'` to stack `'b'` using `pb`. This leaves a small, manageable base case (3 or sometimes 2 elements) in stack `'a'`.
*   **Sort the Base:** I then sort the remaining 2 or 3 elements in stack `'a'` using my optimized `sort_two` or `sort_three` functions. Now, stack `'a'` holds a small, sorted foundation.
*   **Cost-Optimized Insertion:** This is the core loop (`while (*b)`). My strategy here is to intelligently move elements back from `'b'` to `'a'`, inserting them into their correct sorted position relative to what's already in `'a'`. To do this efficiently:
    *   I calculate the `target_pos` in `'a'` for *each* element currently in `'b'`. This is where that `'b'` element *should* eventually sit in the sorted `'a'` stack.
    *   I calculate the rotation `cost` (`cost_a`, `cost_b`) needed to bring both the `'b'` element and its `'a'` target position to the top of their respective stacks using the fewest `r*` or `rr*` moves.
    *   I find the `cheapest` element in `'b'` – the one whose combined `cost_a` + `cost_b` (absolute values) is the lowest. This is a **greedy approach**, aiming to make the most efficient move at each step.
    *   I execute the necessary rotations (`rotate_both`, `rotate_a`, `rotate_b`) and then push the `cheapest` element from `'b'` to `'a'` (`pa`).
*   **Final Alignment:** Once stack `'b'` is empty, all elements are in `'a'` in the correct *relative* order. However, the smallest element (index 0) might not be at the top. So, I use `rotate_top` to perform the final `ra` or `rra` operations needed to bring the absolute smallest element to the very top of stack `'a'`.

---

## 🚀 Build & Usage

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/yudemir1/push_swap.git
    cd push_swap
    ```

2.  **Compile:**
    ```bash
    make
    ```

3.  **Run `push_swap` with arguments:**
    *(Examples show strong parsing capability)*
    ```bash
    ./push_swap 2 1 3 6 5 8
    # or
    ./push_swap "2 1 3 6 5 8"
    # or
    ./push_swap 2 "1 3 6" 5 8
    ```

4.  **Example using the `checker` (if compiled via `make bonus`):**
    ```bash
    ./push_swap 2 1 3 6 5 8 | ./checker 2 1 3 6 5 8
    ```
    *Expected output: `OK` (if the output of `push_swap` is correct and sorts the list)*

5.  **Example with error handling:**
    ```bash
    ./push_swap 1 two 3
    ```
    *Expected output: `Error`*

---
