#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate

using namespace std;

// Function to detect deadlock
void detect(vector<int> &process, vector<vector<int>> &allocation, vector<vector<int>> &request, vector<int> &work) {
    int n = process.size();
    vector<bool> finish(n, false);

    // Check for processes that have no allocation
    for (int i = 0; i < n; ++i) {
        if (allocation[i] == vector<int>{0, 0, 0}) {
            finish[i] = true;
        }
    }

    // Iterate through processes
    for (int i = 0; i < n; ++i) {
        if (!finish[i] && request[i] <= work) {
            // Update available resources
            for (int j = 0; j < 3; ++j) {
                work[j] += allocation[i][j];
            }
            finish[i] = true;
        }
    }

    // Output results
    cout << "Finish array: [";
    for (int i = 0; i < n; ++i) {
        cout << (finish[i] ? "True" : "False") << " ";
    }
    cout << "]" << endl;

    bool deadlock = true;
    for (int i = 0; i < n; ++i) {
        if (!finish[i]) {
            cout << "Deadlock occurs for the process " << i << endl;
            deadlock = false;
        }
    }
    if (deadlock) {
        cout << "No Deadlock!" << endl;
    }
}

int main() {
    vector<int> process = {0, 1, 2, 3, 4};
    vector<vector<int>> allocation = {{0, 1, 0}, {2, 0, 0}, {3, 0, 3}, {2, 1, 1}, {0, 0, 2}};
    vector<vector<int>> request = {{0, 0, 0}, {2, 0, 2}, {0, 0, 0}, {1, 0, 0}, {0, 0, 2}};
    vector<int> available = {0, 0, 0};

    detect(process, allocation, request, available);

    return 0;
}
