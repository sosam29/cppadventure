#include "intarray.h"
#include <iostream>
#include <cassert>

int main()
{
    using std::cout;

    std::cout << "Creating an empty Array\n";
    IntArray a{};
    std::cout << "Size of a is " << a.Size() <<"\n";
    assert(a.IsEmpty());

    std::cout << "Creating 10 element Array\n";
    IntArray b{10};
    std::cout << "size of b is  " << b.Size() << "\n";
    assert(! b.IsEmpty());    

    return 0;

}