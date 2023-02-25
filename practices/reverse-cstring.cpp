#include <iostream>
// #include <cstring>
using namespace std;

void reverse(char* cstring);
void reverse_v2(char* cstring);

int main() {
    char s[] = "hello";
    cout << s << endl << endl;
    reverse(s);
    cout << s << endl << endl;

    char s_v2[] = "goodbye";
    cout << s_v2 << endl;
    reverse_v2(s_v2);
    cout << s_v2 << endl;
}

void reverse(char* cstring) {
    char* end = cstring;
    cout << *end << " " << end << endl;
    while (*end != '\0') {
        end++;
        cout << *end << " " << end << endl;
    }
    end--;
    while (cstring < end) {
        char temp = *cstring;
        *cstring = *end;
        cstring++;
        *end = temp;
        end--;
    }
}

void reverse_v2(char* cstring) {
    int i = 0;
    for (; *(cstring + i) != '\0'; i++);
    
    int len = i;
    i--;

    for (int j = 0; j < len / 2; j++) {
        char temp = *(cstring + j);
        *(cstring + j) = *(cstring + i);
        *(cstring + i) = temp;
        i--;
    }
}