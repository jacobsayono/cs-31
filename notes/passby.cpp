#include <iostream>
using namespace std;

void passByVal(int val);
void passByRef(int& ref);
void passByPtr(int* ptr);
void passByPtrRef(int* &ptrRef);

int main() {
    int x = 5;
    cout << "x before: " << x << endl;
    cout << endl;

    passByVal(x);
    cout << "x after: " << x << endl;
    cout << endl;

    passByRef(x);
    cout << "x after: " << x << endl;
    cout << endl;



    x = 5;
    cout << "x: " << x << endl;

    int* ptr_x = &x;
    cout << "*ptr_x: " << *ptr_x << endl;

    passByPtr(ptr_x);
    cout << "x after: " << x << endl;
    cout << "*ptr_x after: " << *ptr_x << endl;
    return 0;
}

void passByVal(int val) {
    val = 10;
    cout << "passByVal: " << val << endl;
}

void passByRef(int& ref) {
    ref = 20;
    cout << "passByRef: " << ref << endl;
}

void passByPtr(int* ptr) {
    *ptr = 30;
    // ptr = nullptr;
    cout << "passByPtr: " << *ptr << endl;
}