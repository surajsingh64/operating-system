#include <iostream>
using namespace std;

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    fill_n(allocation, n, -1);  // Initialize all allocations to -1 (unallocated)

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    cout << "\nFirst Fit Allocation:\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << "\n";
    }
}

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    fill_n(allocation, n, -1);

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    cout << "\nBest Fit Allocation:\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << "\n";
    }
}

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    fill_n(allocation, n, -1);

    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }

        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    cout << "\nWorst Fit Allocation:\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << "\n";
    }
}

int main() {
    int m, n;
    cout << "Enter number of memory blocks: ";
    cin >> m;
    int blockSize[m], originalBlocks[m];

    cout << "Enter sizes of memory blocks:\n";
    for (int i = 0; i < m; i++) {
        cin >> blockSize[i];
        originalBlocks[i] = blockSize[i];  // Save original for reuse
    }

    cout << "Enter number of processes: ";
    cin >> n;
    int processSize[n];

    cout << "Enter sizes of processes:\n";
    for (int i = 0; i < n; i++) {
        cin >> processSize[i];
    }

    // First Fit
    firstFit(blockSize, m, processSize, n);

    // Restore original blocks for next strategy
    copy(originalBlocks, originalBlocks + m, blockSize);
    bestFit(blockSize, m, processSize, n);

    copy(originalBlocks, originalBlocks + m, blockSize);
    worstFit(blockSize, m, processSize, n);

    return 0;
}
