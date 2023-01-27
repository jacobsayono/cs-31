#include <iostream>
using namespace std;

int main() {
    int len;

    cout << "Enter a number: ";
    cin >> len;

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {  // for loop version
            cout << " ";
        }
        cout << "#" << endl;
    }

    for (int i = 0; i < len; i++) {
        int j = i + 1;
        while (j < len) {  // while loop version
            cout << " ";
            j++;
        }
        cout << "#" << endl;
    }

    int i = 0;
    do { // do-while loop version
        if (len < 0) {
            return 0;
        }
        else {
            int j = i + 1;
            while (j < len) {
                cout << " ";
                j++;
            }
            cout << "#" << endl;
            i++;
        }
    } while (i < len);

    return 0;
}

/*
input:
5

output:
    #
   #
  #
 #
#
*/