#include <iostream>
#include <cstdlib>
using namespace std;

int box1 = 1;
int box2 = 2;
int* gptr;

void passByPtr(int* ptr);
void passByPtrRef(int* &ptrRef);

int main(int argc, char* argv[]) {
    int* p = &box1;
    gptr = &box2;

    // passByPtr(p);
    passByPtrRef(p);

    if (p == &box1)
        cout << "p is pointing to box1" << endl;
    else if (p == &box2)
        cout << "p is pointing to box2" << endl;
    else
        cout << "p is pointing to another box" << endl;
    
    if (gptr == &box1)
        cout << "gptr is pointing to box1" << endl;
    else if (gptr == &box2)
        cout << "gptr is pointing to box2" << endl;
    else
        cout << "gptr is pointing to another box" << endl;

    cout << "box1 contains the value: " << box1 << endl;
    cout << "box2 contains the value: " << box2 << endl;

    return 0;
}

void passByPtr(int* ptr) {
    *ptr = 3;
    ptr = gptr;
    *ptr = 4;
    cout << "passByPtr() called" << endl;
}

void passByPtrRef(int* &ptrRef) {
    *ptrRef = 5;
    ptrRef = gptr;
    *ptrRef = 6;
    cout << "passByPtrRef() called" << endl;
}