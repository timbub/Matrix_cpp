## Matrix 

### Project tree

```text
matrix
├── CMakeLists.txt
├── main.cpp
├── Matrix.hpp
├── BufMatrix.hpp
├── tests
|   ├── run_tests.sh
|   ├── input
|   |  ├── test_1.in
|   |  ├── test_2.in
|   |  ├── ...
|   ├── output
|   |  ├── test_1.out
|   |  ├── test_2.out
|   |  ├── ...
└── 
```
### About project
This project implements a program that calculates the determinant of a matrix using Gaussian elimination.

### Run
#### Clone repository
```
git clone ...
cd Matrix_cpp
```
#### Build
```
cmake -DCMAKE_BUILD_TYPE=Release -S . -B build
cmake --build build
```
#### Run
```
cd build
./matrix
```
