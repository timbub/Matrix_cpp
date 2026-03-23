## Matrix Project

### About project
This project has two main parts: the **Matrix** class and the **MatrixChain** class

#### 1. Matrix Class
This class is for basic matrix math. It can:
*   **Calculate the determinant**: Find the determinant of a square matrix.
*   **Multiply matrices**: Multiply two matrices using an optimized method.
*   **Basic operations**: Easy access to rows and columns.

#### 2. MatrixChain Class
This class is for working with many matrices at once. It helps you:
*   **Find the best order**: It calculates the fastest way to multiply a long chain of matrices.
*   **Show the sequence**: It tells you exactly which matrices to multiply first (the optimal sequence).

### How to Run

#### Clone repository
```bash
git clone ...
cd Matrix_cpp
```

#### Build
```bash
cmake -DCMAKE_BUILD_TYPE=Release -S . -B build
cmake --build build
```

#### Run
#### 1. Matrix Determinant
To calculate the determinant, provide the size of the square matrix and its elements.
```bash
./build/determinate/det
```
**Input:**
```text
3
1 2 3
0 1 4
5 6 0
```
**Output:**
```text
1.00
```
#### 2. Matrix Chain Multiplication
To find the optimal multiplication order, provide the number of dimension values and the dimensions themselves.
```bash
./build/chain/chain
```
**Input:**
```text
5
30 35 15 5 10
```
**Output:**
```text
1 0 2
```
