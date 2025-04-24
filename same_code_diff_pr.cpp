#include <iostream>
#include <unistd.h>      // for fork(), getpid()
#include <sys/types.h>   // for pid_t

using namespace std;

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        cerr << "Fork failed!" << endl;
        return 1;
    } 
    else if (pid == 0) {
        // Child-specific code
        cout << "Hello from Child! PID: " << getpid() << endl;
    } 
    else {
        // Parent-specific code
        cout << "Hello from Parent! PID: " << getpid() 
             << ", Child PID: " << pid << endl;
    }

    return 0;
}
