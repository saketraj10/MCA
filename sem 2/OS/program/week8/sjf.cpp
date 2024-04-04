#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int processId[n], arrivalTime[n], burstTime[n], remainingTime[n], finishTime[n], waitingTime[n], turnaroundTime[n];
    float avgWaitingTime, avgTurnaroundTime;
    int currentTime = 0, completed = 0;

    cout << "Enter the process id, arrival time, and burst time: " << endl;
    for(int i = 0; i < n; i++) {
        cout << "Process id: ";
        cin >> processId[i];
        cout << "Arrival time: ";
        cin >> arrivalTime[i];
        cout << "Burst time: ";
        cin >> burstTime[i];
        remainingTime[i] = burstTime[i];
    }

    cout << "Process ID\tTurnaround Time\tWaiting Time" << endl;

    while(completed != n) {
        int smallest = -1;
        for(int i = 0; i < n; i++) {
            if(arrivalTime[i] <= currentTime && remainingTime[i] > 0) {
                if(smallest == -1 || remainingTime[i] < remainingTime[smallest]) {
                    smallest = i;
                }
            }
        }

        if(smallest == -1) {
            currentTime++;
            continue;
        }

        remainingTime[smallest]--;
        if(remainingTime[smallest] == 0) {
            completed++;
            finishTime[smallest] = currentTime + 1;
            waitingTime[smallest] = finishTime[smallest] - arrivalTime[smallest] - burstTime[smallest];
            turnaroundTime[smallest] = finishTime[smallest] - arrivalTime[smallest];
            cout << processId[smallest] << "\t\t" << turnaroundTime[smallest] << "\t\t\t" << waitingTime[smallest] << endl;
        }
        currentTime++;
    }

    float totalWaitingTime = 0, totalTurnaroundTime = 0;
    for(int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    avgWaitingTime = totalWaitingTime / n;
    avgTurnaroundTime = totalTurnaroundTime / n;

    cout << "Average Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;

    return 0;
}