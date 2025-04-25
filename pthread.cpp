#include <iostream>
#include <pthread.h>
using namespace std;

int arr[] = {1, 2, 3, 4, 5};
int n = 5;
int sum = 0;

// Thread function
void* calculateSum(void* arg) {
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t tid;

    // Create thread
    pthread_create(&tid, NULL, calculateSum, NULL);

    // Wait for thread to finish
    pthread_join(tid, NULL);

    cout << "Sum of array elements = " << sum << endl;

    return 0;
}
