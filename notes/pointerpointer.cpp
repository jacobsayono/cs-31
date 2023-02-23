#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int box = 5;
    int* ptr = &box;
    int** dPtr = &ptr;

    cout << "box holds: " << box << endl;
    cout << "box lives at: " << &box << endl;
    cout << "ptr points to address: " << ptr << endl;
    cout << "the thing that ptr points to has the value: " << *ptr << endl;  // dereference
    cout << "ptr lives at: " << &ptr << endl;
    cout << "dPtr points to: " << dPtr << endl;
    cout << "the thing that dPtr points to has the value: " << *dPtr << endl;
    cout << "the ptr that dPtr points to, points to an int with value: " << **dPtr << endl;
    cout << "dPtr lives at: " << &dPtr << endl;

    cout << endl << endl << "thing:         dPtr                    ptr                     box" << endl;
    cout << "address:       [" << &dPtr << "]        [" << &ptr << "]        [" << &box << "]" << endl;
    cout << "values:        [" << dPtr << "]   ->   [" << ptr << "]   ->   [" << box << "]" << endl;

    return 0;
}