# leetcode

This project is where I store solution of some Leetcode problems I've worked on.

#### Disclaimer on C++ Memory Management

Leetcode's tests often expect raw pointers to objects allocated on the heap.

That said, in a real world scenario, the use of smart pointers such as `std::unique_ptr` and `std::shared_ptr` should be
preferred to the `new`/`delete` operators in order to avoid memory leaks.
