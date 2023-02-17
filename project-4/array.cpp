#include <iostream>
using namespace std;

int locateMaximum(const string array[], int n);
bool hasNoDuplicates(const string array [], int n);
int countXPairs(const string array[], int n, int x);
int findSecondToLastOccurence(const string array[], int n, string target);
int flipAround(string array[], int n);
int moveToEnd(string array[], int n, int pos);

int main() {
    string a[5] = {"A", "AA", "0", "a", "ab"};
    int value;
    value = locateMaximum(a, 5);  // 4 (index)
    value = locateMaximum(a, -456456);  // empty array
    value = locateMaximum(a, 456456);  // bad DRIVER to blame
    value = locateMaximum(a, 3);  // size less than the actual array size, output = 1

    string b[15];
    value = locateMaximum(b, 5);  // bad DRIVER to blame
}

int locateMaximum(const string array[], int n) {
    return 0;
}

bool hasNoDuplicates(const string array [], int n) {

}

int countXPairs(const string array[], int n, int x) {

}

int findSecondToLastOccurence(const string array[], int n, string target) {

}

int flipAround(string array[], int n) {

}

int moveToEnd(string array[], int n, int pos) {
    
}