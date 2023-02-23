// Stack
// 0               int i = 0;
// Heap
// OS Reserved


// RAM Memory
// a location in memory
// will have a hexadecimal value

// number ---> base 10
// 0 1 2 3 4 5 6 7 8 9

// hexadecimal ---> base 16
// 0 1 2 3 4 5 6 7 8 9 A B C D E F (0 to 15 -> 16 numbers)

// 123 = 123 in decimal
// 1 * 10^2 + 2 * 10^1 + 3 * 10^0

// 0x123
// 1 * 16^2 + 2 * 16^1 + 3 * 16^0



// see the hex value of that variable

// * is pointer (when initializing)
// * is dereferencer  (when calling)
// & is address

// int i = 12;
// int* ptr_i = &i;

//                  i
// ptr_i --------> |12|  "referent"

// i = 13;
//                  i
// ptr_i --------> |13|

// *ptr_i  // walk the arrow, get at the box. "dereference"

#include <iostream>
using namespace std;

int main() {
    int* ptr;
    int i = 12;
    int j = 7;

    cout << ptr << endl;  // 0, but when ptr "learns" to reference to an object, prints out address of ptr
    
    cout << endl;
    
    cout << i << endl;
    cout << &i << endl;  // reference address A
    cout << j << endl;
    cout << &j << endl;  // reference address B

    cout << endl;

    ptr = &i;  // change ptr address to A
    cout << *ptr << endl;  // value at address A
    cout << ptr << endl;

    cout << endl;

    ptr = &j;  // change ptr address to B
    cout << *ptr << endl;  // value at address B
    cout << ptr << endl;

    int& ref = j;  // references require an initializer
    cout << ref << endl;  // value at address B 
    cout << &ref << endl;  // reference address B

    int bla = j;
    cout << bla << endl;
    cout << &bla << endl;

    cout << endl;

    cout << (ref == bla) << endl;  // true
    cout << (&ref != &bla) << endl;  // false
}

// pointer variables can switch to whichever address it wants
// reference variables are set in stone to the address

// 0x5642f1bf5120       ptr

// 12                   i
// 0x7fff2e62ef3c       &i
// 7                    j
// 0x7fff2e62ef40       &j

// 12                   *ptr
// 0x7fff2e62ef3c       ptr

// 7                    *ptr
// 0x7fff2e62ef40       ptr
// 7                    ref
// 0x7fff2e62ef40       &ref
// 7                    bla
// 0x7fff2e62ef44       &bla

// 1                    ref == bla
// 0                    &ref != &bla