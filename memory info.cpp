#include <iostream>
#include <cstdlib>  // for system()

using namespace std;

int main() {
    cout << "----------- Memory Information -----------" << endl;
    system("free -h");
    return 0;
}
