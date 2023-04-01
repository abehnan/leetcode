## How to Build

Open a terminal and navigate to the `cpp` directory.

```bash
mkdir build
cd build
cmake .. && cmake --build .
```

#### Disclaimer on C++ Memory Management

Leetcode's tests often expect raw pointers to objects allocated on the heap when dealing with their internal implementation of linked lists.

That said, when using C++11 or newer, the use of smart pointers such as `std::unique_ptr` and `std::shared_ptr` should be
preferred to the `new`/`delete` operators in order to avoid memory leaks.
