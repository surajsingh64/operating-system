#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of processes: ";
    cin >> n;

    int processes[n], burst_time[n], waiting_time[n], turnaround_time[n];
    float total_waiting_time = 0, total_turnaround_time = 0;

    // Input burst times
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        cout << "Enter burst time for Process " << processes[i] << ": ";
        cin >> burst_time[i];
    }

    // Calculate waiting time
    waiting_time[0] = 0;
    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
        total_waiting_time += waiting_time[i];
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    // Output results
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << processes[i] << "\t"
             << burst_time[i] << "\t\t"
             << waiting_time[i] << "\t\t"
             << turnaround_time[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << total_waiting_time / n;
    cout << "\nAverage Turnaround Time: " << total_turnaround_time / n << "\n";

    return 0;
}
