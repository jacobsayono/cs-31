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

// check validity of amount
bool valid_amount(int int_amount);

// check the option in a segment (right side of ':')
string option(string segment);

// check validity of option
bool valid_option(string option);

// returns true if parameter is a well-formed order string
bool isValidOrderString(string orders);

// returns segment cost for all the order
double segment_cost(string segment);

// returns total cost for the whole order. invalid order string returns -1.00
double cost(string orders);

// count number of combo orders. int whichCombo must be 1, 2, 3. return -1 if anything else.
int howManyCombos(string orders, int whichCombo);

// count number of shake orders. string whichShake must be "Chocolate", "Vanilla", "Strawberry". return -1 if anything else
int howManyShakes(string orders, string whichShake);


int main() {
    size_t index;
    size_t segment_index;

    // number_of_underscores()
    string s = "1:1_20:2_3:3";
    assert(number_of_underscores(s) == 2);

    // save_segments()
    index = 4;
    assert(save_segment(s, index) == "20:2");

    // segment()
    assert(segment(s, 1, index) == "1:1");
    assert(segment(s, 2, index) == "20:2");
    assert(segment(s, 3, index) == "3:3");
    assert(segment(s, 5, index) == "");
    assert(segment(s, 50, index) == "invalid segment number");

    string massive = "1:1_2:2_3:3_1:C_1:S_1:V_2:V_3:V_12:S";  // 9 segments
    assert(segment(massive, 9, index) == "12:S");
    assert(segment(massive, 10, index) == "");
    assert(segment(massive, 0, index) == "invalid segment number");

    // valid_segment()
    string has_colon = "2:3";
    string no_colon = "2-3";
    string empty = "";
    assert(valid_segment(has_colon) == true);
    assert(valid_segment(no_colon) == false);
    assert(valid_segment(empty) == true);

    // amount()
    assert(amount("20:3") == "20");

    // int_amount()
    assert(int_amount("20") == 20);
    assert(int_amount("0") == -1);
    assert(int_amount("5") == 5);
    assert(int_amount("111") == -1);
    assert(int_amount("99") == 99);

    // valid_amount()
    int correct_amount_2_digits = 32;
    int correct_amount = 4;
    int zero_amount = 0;
    int too_large_amount = 50;
    assert(valid_amount(correct_amount_2_digits) == true);
    assert(valid_amount(correct_amount) == true);
    assert(valid_amount(zero_amount) == false);
    assert(valid_amount(too_large_amount) == false);
    assert(valid_amount(-1) == false);

    // option()
    string segment4 = "123:5";
    assert(option(segment4) == "5");
    string correct_option = "20:S";
    string wrong_option_multiple_char = "20:9S32";
    string wrong_option = "20:9";
    assert(option(correct_option) == "S");
    assert(option(wrong_option_multiple_char) == "9S32");
    assert(option(wrong_option) == "9");

    // valid_option()
    string C = "C";
    string c = "c";
    string one = "1";
    string four = "4";
    string haha = "9S32";
    string B = "B";
    assert(valid_option(C) == true);
    assert(valid_option(c) == false);
    assert(valid_option(one) == true);
    assert(valid_option(four) == false);
    assert(valid_option(haha) == false);
    assert(valid_option(B) == false);

    // isValidOrderString()
    assert(isValidOrderString("1:1_1:2_1:3_1:C_1:S_1:V") == true);
    assert(isValidOrderString("10:1") == true);
    assert(isValidOrderString("1:1_5:1_4:1") == true);
    assert(isValidOrderString("4:1") == true);
    assert(isValidOrderString("2:1_2:1") == true);
    assert(isValidOrderString("2:2_2:1") == true);
    assert(isValidOrderString("2:1_1:C") == true);

    assert(isValidOrderString("xyz") == false);
    assert(isValidOrderString("1:c") == false);
    assert(isValidOrderString("1:1 zzz") == false);
    assert(isValidOrderString("100:1") == false);
    assert(isValidOrderString("10:1_20:1_30:2") == false);
    assert(isValidOrderString("40:1_10:2_1:3") == false);
    assert(isValidOrderString("40:C_10:V_1:S") == false);
    assert(isValidOrderString("40:1_10:2") == false);
    assert(isValidOrderString("40:C_10:V") == false);
    assert(isValidOrderString("40 : C") == false);
    assert(isValidOrderString("4:5") == false);
    assert(isValidOrderString("+4:1") == false);
    assert(isValidOrderString("1:1_2:2_0:3") == false);
    assert(isValidOrderString("1:1_-12:2") == false);
    assert(isValidOrderString("500:1_500:2") == false);
    assert(isValidOrderString("40:1_10:1_1:1") == false);
    assert(isValidOrderString("40:1_10:2_1:3") == false);
    assert(isValidOrderString("1:1_2") == false);

    // segment_cost()
    assert(segment_cost("4:1") == 37.80);
    assert(segment_cost("xyz") == -1);

    // cost()
    assert(cost("4:1") == 37.80);
    assert(cost("2:1_2:1") == 37.80);
    assert(cost("2:2_2:1") == 34.80);
    assert(cost("xyz") == -1);

    // howManyCombos()
    assert(howManyCombos("2:1_2:1", 1) == 4);
    assert(howManyCombos("3:1_2:2_1:3", 1) == 3);
    assert(howManyCombos("3:1_2:2_1:3", 2) == 2);
    assert(howManyCombos("3:1_2:2_1:3", 3) == 1);


}

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
    index = 0;  // this line is only used for individual asserts

    // create an array storing all the string segments. if there is no more segments after a segment, those segments will be stored as "".
    string stored_segment[49];  // max possible number of segments in a valid string order is 49 elements
    for (int j = 0; j < 49; j++) {
        stored_segment[j] = save_segment(orders, index);
        index++;
    }

    // return the specific segment given the segment number n
    if (n >= 1 && n <= 49) {
        return stored_segment[n - 1];
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
    if (segment == "") {  // allow empty segment, but later in isValidStringOrder(), DO NOT allow empty string
        return_value = true;
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
// this function also checks for valid "amount" in the string order
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
    if (int_amount >= 1 && int_amount <= 49) {  // the requirement is that a single item amount must be between 1 and 49
        return true;
    }
    else {
        return false;  // this includes all the -1 values that was returned by int_amount
    }
}

// create a function that checks the option in the segment (right side of ':')
string option(string segment) {
    string option = "";
    int i = 0;
    for (; i < segment.size(); i++) {
        if (segment.at(i) == ':') {  // find the ':'
            break;
        }
    }
    i++;  // add index by 1 so that we start looking at the element AFTER the ':'
    for (; i < segment.size(); i++) {
        option += segment.at(i);  // record everything to the right of the ':'
    }
    return option;
}

// create a function to check validity of the option
bool valid_option(string option) {
    if (option.size() != 1) {  // option must be 1 digit (string of size 1, i.e., a char)
        return false;
    }
    else {  // now that we know the option is 1 char...
        char kind = option.at(0);
        if (kind == '1' || kind == '2' || kind == '3' || kind == 'C' || kind == 'S' || kind == 'V') {  // that 1 digit char must be either of these 6 chars
            return true;
        }
        else {
            return false;
        }
    }
}

// project requirement
bool isValidOrderString(string orders) {
    size_t index = 0;  // index of the string "orders"
    int segment_number = 1;  // keep count of the segment number
    bool return_value = true;

    string each_segment;
    string each_amount;
    int each_int_amount;  // amount int
    string each_option;  // option char (string of size 1)

    // initialize the sum at 0
    int sum_amount = 0;

    for (segment_number; segment_number <= 49; segment_number++) {  // iterate through all the segments
        each_segment = segment(orders, segment_number, index);  // construct each segment
        if (each_segment == "") {  // ignore all the other empty strings "" in the array (which means the last filled array is the last segment)
            break;
        }
        if (valid_segment(each_segment) != true) {  // check segment validity
            return_value = false;
        }

        for (int i = 0; i < each_segment.size(); i++) {  // iterate through a single segment
            each_amount = amount(each_segment);  // consturct each amount (string)
            each_int_amount = int_amount(each_amount);  // construch each amount (int)  
            if (valid_amount(each_int_amount) != true) {  // check amount validity
                return_value = false;
            }
            else {
                sum_amount += each_int_amount;  // add up all the amount values
            }
            if (sum_amount >= 50) {  // check that the sum of all amount is less than 50 items
                return_value = false;
            }

            each_option = option(each_segment);  // construct each option
            if (valid_option(each_option) != true) {  // check option validity
                return_value = false;
            }
        }
    }

    if (orders == "") {  // check for empty orders, which overwrites the permission for empty segments
        return_value = false;
    }

    return return_value;
}

// create a function to find the cost of each segment
double segment_cost(string segment) {
    if (valid_segment(segment) != true) {  // check segment validity first
        return -1.00;
    }

    string each_amount;
    int each_int_amount;  // focus on this
    string each_option;  // focus on this

    double option_cost;
    double segment_cost = 0;

    for (int k = 0; k < segment.size(); k++) {
        each_amount = amount(segment);
        each_int_amount = int_amount(each_amount);
        each_option = option(segment);
        // determine the cost of each option (1, 2, 3, C, S, V)
        if (each_option == "1") {
            option_cost = 9.45;
        }
        if (each_option == "2") {
            option_cost = 7.95;
        }
        if (each_option == "3") {
            option_cost = 7.55;
        }
        if (each_option == "C" || each_option == "S" || each_option == "V") {
            option_cost = 2.85;
        }
        segment_cost = each_int_amount * option_cost;  // sum the total cost of each segment altogether
    }
    return segment_cost;
}

// project requirement
double cost(string orders) {
    if (isValidOrderString(orders) != true) {  // check string orders validity first
        return -1.00;
    }
    // construct amount and option, similar to isValidOrderString() function
    int segment_number = 1;
    size_t index = 0;
    string each_segment;
    double total_cost = 0;

    for (segment_number; segment_number <= 49; segment_number++) {  // iterate through possible 49 segments
        each_segment = segment(orders, segment_number, index);  // construct segments
        total_cost += segment_cost(each_segment);  // sum up cost of all the segment costs
    }
    return total_cost;
}

// project requirement
int howManyCombos(string orders, int whichCombo) {
    if (isValidOrderString(orders) != true) {
        return -1;
    }

    // construct amount and option, similar to isValidOrderString() function
    int segment_number = 1;
    size_t index = 0;
    string each_segment;

    string each_amount;
    int each_int_amount;
    string each_option;
    int item;

    int count = 0;

    // construct segments
    for (segment_number; segment_number <= 49; segment_number++) {  // iterate through possible 49 segments
        each_segment = segment(orders, segment_number, index);  // construct segments
        if (each_segment == "") {  // ignore all the other empty strings "" in the array (this means the last filled array is the last segment)
            break;
        }
        for (int i = 0; i < each_segment.size(); i++) {
            each_amount = amount(each_segment);
            each_int_amount = int_amount(each_amount);  // convert amount string to int

            each_option = option(each_segment);
            item = each_option.at(0) - '0';  // convert option string to int
        }
        if (item == whichCombo) {  // if whichCombo matches the item in the segment
            count += each_int_amount;  // sum up all the amount of that item
        }
    }
    return count;
}

// project requirement
int howManyShakes(string orders, string whichShake) {
    return 0;
}