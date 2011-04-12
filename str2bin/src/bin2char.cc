#include <iostream>
#include <sstream>
#include <bitset>
#include <limits>

using namespace std;
int main ( int argc, char* argv[]) {
    const int word=8;
    const unsigned int wordmask = (1<<word) -1;
    string a;
    ostringstream bs, bss;
    int count=0;
    while ( cin >> a ) {
        for ( int i=0; i < a.length(); i++ ) {
            if ( a[i]=='0' || a[i]=='1' ) {
                bs << a[i];
                bss << a[i];
                ++count;
                if ( count == word ) {
                    cout << (char) ( std::bitset<word>(bss.str()).to_ulong() & wordmask );
                    bss.flush(); bss.str(""); bss.clear();
                    count=0;
                }
            }
        }
    }
    cout << endl;
    return 0;
}
