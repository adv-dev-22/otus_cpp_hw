#include  <iostream>
#include "vers_lib.h"

using std::cout;
using std::endl;

int main() {

    cout << "Hello, World!" << endl;
    cout << " Major version: " << version_major() << endl;
    cout << " Minor version: " << version_minor() << endl;
    cout << " Patch version: " << version_patch() << endl;

    return 0;
}




