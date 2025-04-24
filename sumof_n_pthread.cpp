#include <iostream>
#include <pthread.h>
using namespace std;

int* arr;
int size;

// Function to compute the sum
int computeSum() {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

void* threadFunction(void* arg) {
    int result = computeSum();
    cout << "Sum of given numbers: " << result << endl;
    return NULL;
}

int main() {
    cout << "Enter number of elements: ";
    cin >> size;

    arr = new int[size];
    cout << "Enter the elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    pthread_t thread;
    pthread_create(&thread, NULL, threadFunction, NULL);
    pthread_join(thread, NULL);

    delete[] arr;
    return 0;
}
