#include <iostream>
#include <string>
#include <sstream>

using namespace std;
int main ( int argc, char* argv[] ) {
    string input;
    cin >> input;
    
    for ( std::string::iterator i=input.begin(); i != input.end(); i++ ) {
        char x=(char) *i;
        if ( (x-'a') >= 0 ) x-='a'-'A';
        int f = 'A' + ((x+13-'A'+26)%26);
        cout << (char) f;
    }
    cout << endl;
    return 0;
}
