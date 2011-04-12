#include <iostream>
namespace mano {
#include "mano.cc"
}

using namespace std;

class Mano {
    public:
        int test() { return mano::test(); }
};

int main (int argc, char** argv) {
    Mano m;
    cout << m.test() << endl;
    return 0;
}


