#include <iostream>
#include <string>
#include <sstream>

using namespace std;
int main ( int argc, char* argv[] ) {
    string input;
    cin >> input;
    int sz;
    for ( sz=1; sz*sz <= input.length(); sz++ );
    sz--;
    cout << sz << endl;
    if ( ! sz ) return 1;
    string * r = new string[ sz ];
    
    std::string::iterator i=input.begin();
    for ( int c=1 ; i != input.end(); i++,c++ ) {
        char x=(char) *i;
        int f = 'A' + ((x+13-'A'+26)%26);
        r[c%sz] += (char)f;
    }
    for ( int c=1; c<sz;c++) { cout << r[c]; }
    cout << r[0];
    cout << endl;
    return 0;
}
