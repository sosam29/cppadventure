#include "intarray.h"
#include <iostream>
#include <cassert>
#include <ostream>

std::ostream& operator<<(std::ostream& os, const IntArray& arr)
{
    os << "[";
    for (int i = 0; i < arr.Size(); i++)
    {
        os<< arr[i] <<' ';
    }
    os << "]";
    return os;
}
int main()
{
    using std::cout;

    // std::cout << "Creating an empty Array\n";
    // IntArray a{};
    // std::cout << "Size of a is " << a.Size() <<"\n";
    // assert(a.IsEmpty());

    // std::cout << "Creating 10 element Array\n";
    // IntArray b{10};
    // std::cout << "size of b is  " << b.Size() << "\n";
    // assert(! b.IsEmpty());    
    IntArray a3{10};
    a3[4]=10;

    for (int i = 0; i < a3.Size(); i++)
    {
        a3[i]=10*(i+1);
    }
    IntArray a4= a3;
    cout << "a3" << a4 <<"\n";
    cout << "a4" << a3 <<"\n";
        
    // cout << "Element at position 5 is " << a3[4]<<"\n";
    // try
    // {
    //     cout << "breaking the code \n";
    //     cout << "Element at not valid location " << a3[10];
    // }
    // catch(const IndexOutOfBoundException& e)
    // {
    //     // std::cerr << e.what() << '\n';
    //     cout << "Invalid index" ;
    // }
    return 0;

}