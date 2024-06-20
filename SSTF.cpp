#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

int process[50];
int head = 0;
int noOfProcess = 0;
int totalDistance = 0;
int completed = 0;
bool iscompleted[50];

int getProcess() {
    int min = INT_MAX;
    int id = -1;
    for (int i = 0; i < noOfProcess; i++) {
        if (!iscompleted[i]) {
            if (abs(head - process[i]) < min) {
                min = abs(head - process[i]);
                id = i;
            }
        }
    }
    return id;
}

void SSTF_Algo() {
    int id = -1;
    while (completed != noOfProcess) {
        id = getProcess();

        totalDistance += abs(head - process[id]);
        head = process[id];
        iscompleted[id] = true;
        completed++;
    }
}

void input() {
    cout << "Enter no. of Processes: ";
    cin >> noOfProcess;

    cout << "Enter Processes: ";
    for (int i = 0; i < noOfProcess; i++) {
        cin >> process[i];
    }

    cout << "Enter Head Position: ";
    cin >> head;

    for (int i = 0; i < noOfProcess; i++) {
        iscompleted[i] = false;
    }
}

void output() {
    cout << "\nTotal Distance covered: " << totalDistance << endl;
}

int main() {
    input();
    SSTF_Algo();
    output();
    return 0;
}

