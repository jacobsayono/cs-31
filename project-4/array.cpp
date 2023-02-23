#include <iostream>
#include <cassert>
using namespace std;

int locateMaximum(const string array[], int n);
bool hasNoDuplicates(const string array[], int n);
int countXPairs(const string array[], int n, int x);
int findSecondToLastOccurrence(const string array[], int n, string target);
int countPunctuation(const string array[], int n);
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
    
    string codeboard[7] = {"AA", "BB", "BB", "BB", "cc", "dd", "ee"};
    string numbers[7] = {"5", "1", "5", "2", "10", "11", "15"};
    
    // locateMaximum()
    assert(locateMaximum(folks, 8) == 4);
    assert(locateMaximum(folks_last_index, 8) == 7);
    assert(locateMaximum(folks, 0) == -1);

    assert(locateMaximum(codeboard, 6) == 5);
    // assert(locateMaximum(codeboard, 5) == 4);  // 5
    // cout << locateMaximum(codeboard, 5) << endl;
    assert(locateMaximum(codeboard, 7) == 6);

    // hasNoDuplicates()
    assert(hasNoDuplicates(people, 5) == true);
    assert(hasNoDuplicates(people, 0) == true);
    assert(hasNoDuplicates(folks, 8) == false);

    assert(hasNoDuplicates(codeboard, 2) == true);

    // countXPairs()
    string example[5] = {"1", "10", "5", "4", "0"};
    string better_example[6] = {"8", "-1", "3", "4", "5", "2"};
    assert(countXPairs(example, 5, 5) == 2);
    assert(countXPairs(better_example, 6, 7) == 3);
    assert(countXPairs(example, 5, 10) == 1);
    assert(countXPairs(example, -10, -10) == -1);

    // findSecondToLastOccurence()
    string data[5] = {"mama", "mama", "12,", "sansa", "mama"};
    assert(findSecondToLastOccurrence(data, 5, "mama") == 1);
    assert(findSecondToLastOccurrence(data, 5, "howard") == -1);
    assert(findSecondToLastOccurrence(data, 0, "mama") == -1);

    // countPunctuation()
    string sample[4] = {"4.4.3.3", "+44", "-33.098", "33.098a"};
    assert(countPunctuation(sample, 4) == 6);
    assert(countPunctuation(sample, -14) == -1);

    // flipAround()
    string more_people[5] = {"howard", "pixie", "barak", "joe", "donald"};
    string reverse_people[5] = {"donald", "joe", "barak", "pixie", "howard"};
    flipAround(more_people, 5);
    for (int i = 0; i < 5; i++) {
        assert(more_people[i] == reverse_people[i]);
    }
    assert(flipAround(more_people, 5) == 2);

    string numbers1[7] = {"5", "1", "5", "2", "10", "11", "15"};
    string reverse_numbers[7] = {"5", "1", "5", "2", "10", "11", "15"};
    assert(flipAround(numbers1, 6) == 3);

    // moveToEnd()
    string cool_people[5] = {"howard", "pixie", "barak", "joe", "donald"};
    string cool_people_moved[5] = {"howard", "barak", "joe", "donald", "pixie"};
    moveToEnd(cool_people, 5, 1);
    for (int i = 0; i < 5; i++) {
        assert(cool_people[i] == cool_people_moved[i]);
    }
    assert(moveToEnd(cool_people, 5, 1) == 1);
}

// return the index of the largest item found in the array or -1 if n <= 0.
int locateMaximum(const string array[], int n) {
    int retvalue;
    if (n <= 0) {
        retvalue = -1;
    }
    else {
        // // iterate through every index to check the string in current index is greater than the string in next index
        // for (int i = 0; i < n - 1; i++) {  // iterate n - 1 times (n = 8 -> 0 to 6 -> 7 times)
        //     if (array[i] > array[i + 1]) {
        //         retvalue = i;
        //     }
        // }
        // // check last index since the above does not actually check the very last index (i.e., index = n - 1)
        // if (array[n - 1] > array[retvalue]) {
        //     retvalue = n - 1;
        // }
        string max = array[0];  // set first element as the maximum
        // iterate through every index to check if the string in current index is greater than the current max value
        for (int i = 0; i < n; i++) {
            if (array[i] > max) {  // if the element in this current index is greater
                retvalue = i;  // then we know the index to return is this one
                max = array[i];  // update the max value to this new value for next iteration check
            }
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
            for (int j = i + 1; j < n; j++) {  // j = 0;
                // if (i == j) {  // skip iteration j if comparing the same index (to prevent testing equality for the string in the same index)
                //     j++;
                // }
                if (array[i] == array[j]) {  // check for identical elements
                    retvalue = false;
                }
            }
        }
    }
    return retvalue;
}

// return the number of times that two different elements in the array sum up to the parameter value x
int countXPairs(const string array[], int n, int x) {
    if (n <= 0) {
        return -1;
    }
    else {
        int retvalue = 0;
        int int_array[n];  // initialize a new array to contain integer numbers (that were initially written in string format)
        for (int i = 0; i < n; i++) {
            int_array[i] = stoi(array[i]);  // using std::io() function from project prompt
        }
        // iterate such that i,j:      0,1; 0,2; 0;3; 0;4     1,2; 1,3; 1,4;      2,3; 2,4;      3;4
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (int_array[i] + int_array[j] == x) {
                    retvalue++;
                }
            }
        }
        return retvalue;
    }
}

// return the second largest index that holds the target value in the array or return -1 if it is not found at all or return -1 if n <= 0
int findSecondToLastOccurrence(const string array[], int n, string target) {
    int retvalue;
    if (n <= 0) {
        retvalue = -1;
    }
    else {
        int c = 0;  // check if target is in the array
        for (int i = 0; i < n - 1; i++) {
            if (array[i] == target) {
                c++;
            }
        }
        if (c == 0) {
            retvalue = -1;
        }
        else {
            int store_index;
            for (int i = n - 1; i >= 0; i--) {  // iterate backwards, being careful with indices
                if (array[i] == target) {
                    store_index = i;
                    break;  // once we find the first occurence, break out of loop to create a new counter
                }
            }
            store_index--;  // go to next index after first occurence (or last, since we flipped)
            for (int i = store_index; i >= 0; i--) {  // iterate in the same direction
                if (array[i] == target) {
                    retvalue = i;
                    break;  // once we find the second occurence, break out of loop so we don't accidently overwrite the index number if the target occurs again
                }
            }
        }
    }
    return retvalue;
}

// return the total number of punctuation values found in all the array elements of the passed array argument, return -1 if n <= 0
int countPunctuation(const string array[], int n) {
    int retvalue = 0;
    if (n <= 0) {
        retvalue = -1;
    }
    else {
        for (int i = 0; i < n; i++) {
            string s = array[i];  // pull out each string element in the array
            for (int j = 0; j < s.size(); j++) {
                char c = s.at(j);  // pull out each char element in the string
                switch (c) {  // test for these symbols
                    case '.':
                    case ',':
                    case '!':
                    case ';':
                    case '\'':
                    case '-':
                    case '/':
                    case ':':
                    case '?':
                    case '"':
                        retvalue++;  // count +1 if there is one
                        break;
                }
            }
        }
    }
    return retvalue;
}

// flip (reverse) items found in the array and return the number of flips it perfomed
int flipAround(string array[], int n) {
    string stored[n];  // store original array
    for (int i = 0; i < n; i++) {
        stored[i] = array[i];
    }

    for (int left = 0; left < n / 2; left++) {  // left half
        array[left] = stored[n - 1 - left];
    }
    for (int right = n - 1; right > n / 2 - 1; right--) {  // right half
        array[right] = stored[n - 1 - right];
    }

    return n / 2;  // number of flips is always size of array divided by 2
}

// eliminate the item at position pos by copying all elements after it one place to the left
// put the item that was eliminated into the last position of the array
int moveToEnd(string array[], int n, int pos) {
    if (n <= 0 || pos >= n || pos < 0) {  // only 2 conditions that will not work, 3rd condition for codeboard segmentation fault
        return -1;
    }
    else {
        string stored = array[pos];  // store the eliminated item
        for (int i = pos + 1; i < n; i++) {  // move all elements (starting from the right of pos) to the left by 1
            array[i - 1] = array [i];
        }
        array[n - 1] = stored;  // now put back the stored element to the last index
        return pos;  // always return position of moved element if passed the 2 conditions above
    }
}