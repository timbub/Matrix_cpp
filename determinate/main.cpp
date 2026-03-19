#include "Matrix.hpp"
#include <iostream>

int main() {
    try {
        size_t size = 0;
        if (!(std::cin >> size)) {
            if (std::cin.eof()) throw std::runtime_error("Unexpected end of input\n");
            throw std::invalid_argument("Size must be integer\n");
        }

        if (size == 0) throw std::out_of_range("Size must be > 0\n");

        using ElemT = double;
        matrix::Matrix<ElemT> matrix{size, size};
        ElemT elem = 0;

        for (size_t row = 0; row < size; row++)
        {
            for (size_t col = 0; col < size; col++) {
                if(!(std::cin >> elem)) {
                    if (std::cin.eof())  throw std::runtime_error("Not enough elements for matrix\n");
                    throw std::invalid_argument("Invalid elements type\n");

                }
                matrix[row][col] = elem;
            }
        }
        std::cout << matrix.determinate() << "\n";

    }
    catch(const std::runtime_error& e) {
        std::cout << "Runtime error: " << e.what() << "\n";
    }
    catch(const std::bad_alloc& e) {
        std::cerr << "Not enough memory/n";
    }
    catch(const std::invalid_argument& e) {
        std::cerr << "Input error: " << e.what() << "\n";
    }  //catch: bad alloc, not square matrix
    catch(const std::out_of_range& e) {
        std::cerr << "Input logic error: " << e.what() << "\n";
    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    catch(...) {
        std::cerr << "Unknown error/n";
    }
    return 0;
}
