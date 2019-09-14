#include <iostream>
#include <string>
using namespace std;

int main() {
    #ifdef NOSKIP
    cin >> noskipws;
    #endif
    for (;;) {
        char c;
        cin >> c;
        if ( cin.eof() ) break;
        cout << c;
    } // for
    cout << endl;
}
