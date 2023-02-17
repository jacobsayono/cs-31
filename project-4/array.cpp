#include <iostream>
#include <cassert>
using namespace std;

int locateMaximum(const string array[], int n);
bool hasNoDuplicates(const string array[], int n);
int countXPairs(const string array[], int n, int x);
int findSecondToLastOccurence(const string array[], int n, string target);
int flipAround(string array[], int n);
int moveToEnd(string array[], int n, int pos);

int main() {
    // string a[5] = {"A", "AA", "0", "a", "ab"};
    // int value;
    // value = locateMaximum(a, 5);  // 4 (index)
    // value = locateMaximum(a, -456456);  // empty array
    // value = locateMaximum(a, 456456);  // bad DRIVER to blame
    // value = locateMaximum(a, 3);  // size less than the actual array size, output = 1

    // string b[15];
    // value = locateMaximum(b, 5);  // bad DRIVER to blame

    string people[5] = {"howard", "pixie", "barak", "joe", "donald"};
    string folks[8] = {"samwell", "jon", "margaery", "daenerys", "tyrion", "jon", "llewmas", "noj"};
    string folks_last_index[8] = {"samwell", "jon", "margaery", "daenerys", "tyrion", "jon", "llewmas", "zzzzzzzz"};
    
    // locateMaximum()
    assert(locateMaximum(folks, 8) == 4);
    assert(locateMaximum(folks_last_index, 8) == 7);
    assert(locateMaximum(folks, 0) == -1);

    // hasNoDuplicates()
    assert(hasNoDuplicates(people, 5) == true);
    assert(hasNoDuplicates(people, 0) == true);
    assert(hasNoDuplicates(folks, 8) == false);

    string example[5] = {"1", "10", "5", "4", "0"};
    assert(countXPairs(example, 5, 5) == 2);
    assert(countXPairs(example, -10, -10) == -1);
}

// return the index of the largest item found in the array or -1 if n <= 0.
int locateMaximum(const string array[], int n) {
    int retvalue;
    if (n <= 0) {
        retvalue = -1;
    }
    else {
        // iterate through every index to check the string in current index is greater than the string in next index
        for (int i = 0; i < n - 1; i++) {  // iterate n - 1 times (n = 8 -> 0 to 6 -> 7 times)
            if (array[i] > array[i + 1]) {
                retvalue = i;
            }
        }
        // check last index since the above does not actually check the very last index (i.e., index = n - 1)
        if (array[n - 1] > array[retvalue]) {
            retvalue = n - 1;
        }
    }
    return retvalue;
}

// return true if there is no value that is repeatedly found in the array, false otherwise, or false if n < 0
bool hasNoDuplicates(const string array [], int n) {
    bool retvalue = true;
    if (n < 0) {
        retvalue = false;
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {  // skip iteration j if comparing the same index (to prevent testing equality for the string in the same index)
                    break;
                }
                if (array[i] == array[j]) {
                    retvalue = false;
                }
            }
        }
    }
    return retvalue;
}

// return the number of times that two different elements in the array sum up to the parameter value x
int countXPairs(const string array[], int n, int x) {
    int retvalue = 0;
    if (n <= 0) {
        retvalue = -1;
    }
    else {
        int int_array[n];  // initialize a new array to contain integer numbers (that were initially written in string format)
        int sum_array[(n - 1) * (n - 1)];  // initialize a new array to contain sums of pairs, which would be the size (n - 1)^2. n - 1 because we do not count number summing itself
        for (int i = 0; i < n; i++) {
            int_array[i] = stoi(array[i]);  // using std::io() function from project prompt
            for (int j = 0; i < n; i++) {
                if (i == j) {
                    break;
                }
                sum_array[i] = int_array[i] + int_array[j];
                if (sum_array[i] == x) {
                    retvalue++;
                }
            }
        }
    }
    return retvalue;
}

int findSecondToLastOccurence(const string array[], int n, string target) {
    return 0;
}

int flipAround(string array[], int n) {
    return 0;
}

int moveToEnd(string array[], int n, int pos) {
    return 0;
}