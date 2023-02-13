#include <iostream>
#include <cassert>
#include <string>
using namespace std;

// 1:C_17:2_3:3_4:V

// substr(start index, length)
// s.substr(3, 2) -> "_1"

// determine number of segments in the string
int number_of_underscores(string orders);

// save a segment in the string
string save_segment(string orders, size_t &index);

// pull out segment n in the string
string segment(string orders, int n, size_t &index);

// check validity of segment
bool valid_segment(string segment);

// check the amount in a segment (left side of ':')
string amount(string segment);

// convert amount char to amount int
int int_amount(string amount);

// check validity of amount;
bool valid_amount(int int_amount);

// check the option in a segment (right side of ':')
string option(string segment);




// returns true if parameter is a well-formed order string
bool isValidOrderString(string orders);

// returns total cost for all the order. invalid order string returns -1.00
double cost(string orders);

// count number of combo orders. int whichCombo must be 1, 2, 3. return -1 if anything else.
int howManyCombos(string orders, int whichCombo);

// count number of shake orders. string whichShake must be "Chocolate", "Vanilla", "Strawberry". return -1 if anything else
int howManyShakes(string orders, string whichShake);


int main() {
    size_t index;
    size_t segment_index;

    string s = "1:1_20:2_3:3";
    assert(number_of_underscores(s) == 2);

    index = 4;
    assert(save_segment(s, index) == "20:2");

    assert(segment(s, 1, index) == "1:1");
    assert(segment(s, 2, index) == "20:2");
    assert(segment(s, 3, index) == "3:3");

    string one = segment(s, 1, index);
    string two = segment(s, 2, index);
    string three = segment(s, 3, index);
    cout << one << " " << two << " " << three << endl;

    string nope = "F:2";
    // assert(isValidSegment(one) == true);
    // assert(isValidSegment(nope) == false);

}

// bool isValidOrderString(string orders) {
//     for (int i = 0; i < orders.size(); i++) {
//         if ((orders.at(i) < '0' || orders.at(i) > '9') && orders.at(i) != 'C' && orders.at(i) != 'V' && orders.at(i) != 'S') {
//             return false;            
//         }
//     }
// }








// create a function to find how many options were ordered (to determine number of segments)
int number_of_underscores(string orders) {
    int sum_underscores = 0;  // 1 underscore ---> 2 options (segments) were ordered on the menu, etc.
    for (int i = 0; i < orders.size(); i++) {
        if (orders.at(i) == '_') {
            sum_underscores++;
        }
    }
    return sum_underscores;
}

// create a function to save a specific segment from a given string
string save_segment(string orders, size_t &index) {
    string segment = "";
    for (; index < orders.size(); index++) {  // iterate over entire string
        if (orders.at(index) == '_') {
            break;
        }
        segment += orders.at(index);
    }
    return segment;
}

// create a function that can output a segment when given a string and a segment number
string segment(string orders, int n, size_t &index) {
    // call function to determine the number of underscores we will be working on (which tells us how many segments in the string)
    int sum_underscores = number_of_underscores(orders);
    index = 0;

    // there can only be a maximum of 6 segments for a valid order string
    string segment1 = "", segment2 = "", segment3 = "", segment4 = "", segment5 = "", segment6 = "";

    // create an array storing all the string segments. if there is no more segments after a segment, those segments will be stored as "".
    string stored_segment[6];
    for (int j = 0; j < 6; j++) {
        // string stored_segment[] = {segment1, segment2, segment3, segment4, segment5, segment6};
        stored_segment[j] = save_segment(orders, index);
        index++;
    }

    // return the specific segment given the segment number n
    if (n >= 1 && n <= 6) {
        return stored_segment[n-1];
    }
    else {
        return "invalid segment number";
    }
}

// create a function that checks validity of a segment
bool valid_segment(string segment) {
    bool return_value = false;
    for (int i = 0; i < segment.size(); i++) {
        if (segment.at(i) == ':') {  // there has to be at least one ':' in the segment
            return_value = true;
        }
    }
    return return_value;
}

// create a function that checks the amount in the segment (left side of ':')
string amount(string segment) {
    string amount = "";
    for (int segment_index = 0; segment_index < segment.size(); segment_index++) {
        if (segment.at(segment_index) == ':') {
            break;
        }
        amount += segment.at(segment_index);
    }
    return amount;
}

// create a function to convert string to int
int int_amount(string amount) {
    if (amount.size() == 1) {
        if (amount.at(0) >= '1' && amount.at(0) <= '9') {  // if the amount is 0, the order is not valid
            return amount.at(0) - '0';
        }
        else {
            return -1;
        }
    }
    else if (amount.size() == 2) {
        int tens, ones;
        if (amount.at(0) >= '1' && amount.at(0) <= '9') {  // tens place can only be a number between 1 and 5
            tens = amount.at(0) - '0';
        }
        else {
            return -1;
        }
        if (amount.at((1) >= '0') && amount.at(1) <= '9') {  // for 2 digit numbers, the ones place can be from 0 to 9
            ones = amount.at(1) - '0';
        }
        else {
            return -1;
        }
        return tens * 10 + ones;  // this should give us an integer from 1 to 99
    }
    else {
        return -1;
    }
}

// create a function to check validity of the amount
bool valid_amount(int int_amount) {
    if (int_amount >= 0 && int_amount <= 50) {  // the requirement is that a single item amount must be between 1 and 49
        return true;
    }
    else {
        return false;  // this includes all the -1 values that was returned by int_amount
    }
}

// create a function that checks the option in the segment (right side of ':')
string option(string segment) {
    string option = "";
    for (int i = 0; i < segment.size(); i++) {
        if (segment.at(i) == ':') {
            option += segment.at(i);
        }
    }
    return option;
}

// create a function to check validity of the option
bool valid_option(string option) {
    if (option.size() != 1) {
        return false;
    }
    else {
        char kind = option.at(0);
        if (kind == '1' || kind == '2' || kind == '3' || kind == 'C' || kind == 'S' || kind == 'V') {
            return true;
        }
        else {
            return false;
        }
    }
}