#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> // for std::numeric_limits

using namespace std;

// Function to calculate waiting time for each process
void waitingTime(vector<vector<int>> &process, vector<int> &wt) {
    int n = process.size();
    vector<int> rt(n); // Remaining time for each process

    for (int i = 0; i < n; ++i) {
        rt[i] = process[i][2]; // Burst time initially
    }

    int complete = 0;
    int current_t = 0;
    int min_t = numeric_limits<int>::max(); // Initialize min_t to maximum integer value
    int short_idx = 0;
    bool flag = false;

    while (complete != n) {
        flag = false;
        for (int i = 0; i < n; ++i) {
            if (process[i][1] <= current_t && rt[i] < min_t && rt[i] > 0) {
                min_t = rt[i];
                short_idx = i;
                flag = true;
            }
        }

        if (!flag) {
            current_t++;
            continue;
        }

        rt[short_idx]--;
        min_t = rt[short_idx];

        if (min_t == 0) {
            min_t = numeric_limits<int>::max();
        }

        if (rt[short_idx] == 0) {
            complete++;
            flag = false;
            int final_t = current_t + 1;
            wt[short_idx] = final_t - process[short_idx][1] - process[short_idx][2];

            if (wt[short_idx] < 0) {
                wt[short_idx] = 0;
            }
        }

        current_t++;
    }
}

// Function to calculate turnaround time for each process
void turnAroundTime(vector<vector<int>> &process, vector<int> &wt, vector<int> &tat) {
    for (int i = 0; i < process.size(); ++i) {
        tat[i] = process[i][2] + wt[i];
    }
}

// Function to calculate average waiting time and turnaround time
void avgTime(vector<vector<int>> &process) {
    int n = process.size();
    vector<int> wt(n, 0);
    vector<int> tat(n, 0);
    int total_wt = 0, total_tat = 0;

    waitingTime(process, wt);
    turnAroundTime(process, wt, tat);

    for (int i = 0; i < n; ++i) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;

    // Display results
    cout << "Process\t Arrival Time\t Burst Time\t Waiting Time\t Turn Around Time\n";
    for (int i = 0; i < n; ++i) {
        cout << process[i][0] << "\t\t" << process[i][1] << "\t\t" << process[i][2] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << avg_wt << endl;
    cout << "Average Turn Around Time: " << avg_tat << endl;
}

int main() {
    // Define processes
    vector<vector<int>> process = {{1, 0, 3}, {2, 1, 4}, {3, 2, 5}, {4, 3, 1}, {5, 4, 2}};

    // Call function to calculate average waiting time and turnaround time
    avgTime(process);

    return 0;
}
