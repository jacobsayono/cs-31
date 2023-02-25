#include <iostream>
using namespace std;

int main() {
    int a = 100, b = 30;
    cout << a + b << endl;

    int* ptr = &a;
    cout << *ptr + b << endl;

    *ptr = 10;
    cout << *ptr + b << endl;

    ptr = &b;
    *ptr = -12;
    cout << *ptr + 2 * b << endl;

    int c = a + *ptr;
    cout << c << endl;

    b = -5;
    cout << a + b << endl;

    int arr[5] = {4, 5, 10, 11, -1};
    ptr = arr + 1;
    cout << *arr + *ptr << endl;

    int cs;
    int& pic = cs;
    ptr = &pic;
    pic = 31;
    cs++;
    cout << *ptr << endl;

    int track[] = {10, 20, 30, 40};
    int* p;
    p = track;
    track[1] += 30;
    cout << *p << " ";
    *p -= 10;
    p++;
    cout << *p << " ";
    p += 2;
    cout << *p << " ";
    cout << track[0] << endl;

    int num[5];
    int* pt;
    pt = num;       *pt = 100;
    pt++;           *pt = 90;
    pt = &num[2];   *pt = 80;
    pt = num + 3;   *pt = 70;
    pt = num;      *(pt + 4) = 60;
    for (int i = 0; i < 5; i++) {
        cout << num[i] << " ";
    }
    cout << endl;

    return 0;
}