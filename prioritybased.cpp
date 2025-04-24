#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int id;            // Process ID
    int burstTime;     // Burst time (CPU time required)
    int priority;      // Priority of the process
    int waitingTime;   // Waiting time for the process
    int turnAroundTime; // Turnaround time for the process
};

// Comparator function to sort the processes by priority
bool compare(Process a, Process b) {
    return a.priority < b.priority;
}

// Function to calculate waiting time and turnaround time
void calculateTimes(vector<Process>& processes) {
    int n = processes.size();
    processes[0].waitingTime = 0; // First process has no waiting time
    
    // Calculate waiting time for each process
    for (int i = 1; i < n; ++i) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
    }

    // Calculate turnaround time for each process
    for (int i = 0; i < n; ++i) {
        processes[i].turnAroundTime = processes[i].burstTime + processes[i].waitingTime;
    }
}

// Function to print the details of the processes
void printProcessDetails(const vector<Process>& processes) {
    cout << "Process ID | Burst Time | Priority | Waiting Time | Turnaround Time" << endl;
    for (const auto& p : processes) {
        cout << p.id << "          | " << p.burstTime << "        | " << p.priority 
             << "        | " << p.waitingTime << "            | " << p.turnAroundTime << endl;
    }
}

// Function to implement the Non-Preemptive Priority Scheduling
void priorityScheduling(vector<Process>& processes) {
    // Sort processes by priority (lowest priority number first)
    sort(processes.begin(), processes.end(), compare);

    // Calculate waiting time and turnaround time for each process
    calculateTimes(processes);
    
    // Print the process details
    printProcessDetails(processes);

    // Calculate average waiting time and turnaround time
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    int n = processes.size();
    for (const auto& p : processes) {
        totalWaitingTime += p.waitingTime;
        totalTurnaroundTime += p.turnAroundTime;
    }

    cout << "\nAverage Waiting Time: " << (float)totalWaitingTime / n << endl;
    cout << "Average Turnaround Time: " << (float)totalTurnaroundTime / n << endl;
}

int main() {
    int n;

    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    // Input the details of each process
    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1; // Assigning Process ID
        cout << "Enter burst time for Process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
        cout << "Enter priority for Process " << i + 1 << ": ";
        cin >> processes[i].priority;
    }

    // Call the function to implement the scheduling
    priorityScheduling(processes);

    return 0;
}
