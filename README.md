# HPX Parallel Matrix Multiplication

This project demonstrates a simple parallel matrix multiplication using the HPX runtime system in C++.

## Build Instructions

### Prerequisites

- CMake ≥ 3.16
- HPX library (installed and configured)
- A C++17 compatible compiler

### Steps

```bash
git clone https://github.com/your-username/hpx-matrix-multiplication.git
cd hpx-matrix-multiplication
mkdir build && cd build
cmake ..
make
./matrix_multiply
