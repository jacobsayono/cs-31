#include <iostream>
using namespace std;

int countSpacesInFirstSentence(string s);

int main() {
    cout << countSpacesInFirstSentence("call me ishmael.") << endl;
    cout << countSpacesInFirstSentence("i am sam. sam am i.") << endl;
    cout << countSpacesInFirstSentence("where now? who now? when now?") << endl;
}

// control reaches end of non-void function
int countSpacesInFirstSentence(string s) {
    int nSpaces = 0;
    for (int k = 0; k != s.size(); k++) {
        if (s[k] == ' ') {
            nSpaces++;
        }
        else if (s[k] == '.') {
            return nSpaces;
        }
    }
}