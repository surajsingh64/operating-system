#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int process[n], burst[n], waiting[n], turnaround[n];

    // Input burst times
    for (int i = 0; i < n; i++) {
        cout << "Enter burst time for Process " << i + 1 << ": ";
        cin >> burst[i];
        process[i] = i + 1;
    }

    // Sort processes by burst time (SJF logic)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (burst[j] < burst[i]) {
                swap(burst[i], burst[j]);
                swap(process[i], process[j]);
            }
        }
    }

    // Calculate waiting time
    waiting[0] = 0;
    for (int i = 1; i < n; i++) {
        waiting[i] = waiting[i - 1] + burst[i - 1];
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
    }

    // Display results
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    float totalWaiting = 0, totalTurnaround = 0;

    for (int i = 0; i < n; i++) {
        cout << "P" << process[i] << "\t" << burst[i] << "\t\t"
             << waiting[i] << "\t\t" << turnaround[i] << endl;
        totalWaiting += waiting[i];
        totalTurnaround += turnaround[i];
    }

    cout << "\nAverage Waiting Time: " << totalWaiting / n << endl;
    cout << "Average Turnaround Time: " << totalTurnaround / n << endl;

    return 0;
}

