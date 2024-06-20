#include <iostream>
#include <vector>

using namespace std;

void waitingTime(vector<vector<int>>& process, vector<int>& wt, int quantum) {
    int n = process.size();
    vector<int> rt(n);

    for (int i = 0; i < n; ++i) {
        rt[i] = process[i][2];
    }

    int current_t = 0;

    while (true) {
        bool flag = true;

        for (int i = 0; i < n; ++i) {
            if (rt[i] > 0) {
                flag = false;

                if (rt[i] > quantum) {
                    current_t += quantum;
                    rt[i] -= quantum;
                } else {
                    current_t += rt[i];
                    wt[i] = current_t - process[i][2];
                    rt[i] = 0;
                }
            }
        }

        if (flag)
            break;
    }
}

void turnAroundTime(vector<vector<int>>& process, vector<int>& wt, vector<int>& tat) {
    int n = process.size();

    for (int i = 0; i < n; ++i) {
        tat[i] = process[i][2] + wt[i];
    }
}

void avgTime(vector<vector<int>>& process, int quantum) {
    int n = process.size();
    vector<int> wt(n, 0), tat(n, 0);
    int total_wt = 0, total_tat = 0;

    waitingTime(process, wt, quantum);
    turnAroundTime(process, wt, tat);

    for (int i = 0; i < n; ++i) {
        total_wt += wt[i];
    }

    for (int i = 0; i < n; ++i) {
        total_tat += tat[i];
    }

    double avg_wt = (double)total_wt / n;
    double avg_tat = (double)total_tat / n;

    // Displaying the results
    cout << "Process\t Arrival Time\t Burst Time\t Waiting Time\t Turn Around Time" << endl;
    for (int i = 0; i < n; ++i) {
        cout << process[i][0] << "\t\t" << process[i][1] << "\t\t" << process[i][2] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }
    cout << "\nAverage Waiting Time: " << avg_wt << endl;
    cout << "Average Turn Around Time: " << avg_tat << endl;
}

int main() {
    vector<vector<int>> process = {{1, 0, 3}, {2, 1, 4}, {3, 2, 5}, {4, 3, 1}, {5, 4, 2}};
    int quantum = 2;

    avgTime(process, quantum);

    return 0;
}
