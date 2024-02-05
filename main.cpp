#include "main.h"
#include <cassert>
#include <iostream>
int main()
{
    // an instance of my CirkelBuffer with int and size of 4
    CirkelBuffer<int, 6> buffer;

    // write elements to buffer
    buffer.Write(10);
    buffer.Write(20);
    buffer.Write(30);
    buffer.Write(40);

    // print present elements
    std::cout << "buffer 1:  " << buffer << std::endl;

    // Starting size check after writing 4 elements
    assert(4 == buffer.Size());

    // Read 10, size becomes 3
    assert(10 == buffer.Read());
    assert(3 == buffer.Size());

    // Read 20, size becomes 2
    assert(20 == buffer.Read());
    assert(2 == buffer.Size());
    std::cout << "buffer 2:  " << buffer << std::endl;

    // Write 50, size becomes 3
    buffer.Write(50);
    assert(3 == buffer.Size());
  std::cout << "buffer 3:  " << buffer << std::endl;
    // Read 30, size becomes 2
    assert(30 == buffer.Read());
    assert(2 == buffer.Size());

    // Read 40, size becomes 1
    assert(40 == buffer.Read());
    assert(1 == buffer.Size());

    // Updated assert to match the right size
    assert(50 == buffer.Read());
    assert(0 == buffer.Size());

    // Print the present state of the buffer
    std::cout << "buffer last:  " << buffer << std::endl;

    return 0;
}
