#include <iostream>
#include <cstdlib>  // for system()

using namespace std;

int main() {
    cout << "----------- System Kernel -----------" << endl;
    system("uname -r");

    cout << "\n----------- Kernel Build Info -----------" << endl;
    system("cat /proc/version");

    cout << "\n----------- CPU Information -----------" << endl;
    system("lscpu | head -8");

    return 0;
}
