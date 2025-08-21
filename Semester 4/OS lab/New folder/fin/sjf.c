#include <iostream>
#include <algorithm>

using namespace std;

struct Process {
    int pid; // Process ID
    int arrival_time; // Arrival Time
    int burst_time; // Burst Time
    int waiting_time; // Waiting Time
    int turnaround_time; // Turnaround Time
};

bool compareArrivalTime(const Process& p1, const Process& p2) {
    return p1.arrival_time < p2.arrival_time;
}

void sjf(Process* processes, int n) {
    sort(processes, processes + n, compareArrivalTime);

    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int current_time = 0;

    for (int i = 0; i < n; i++) {
        // Process will arrive after current time
        if (processes[i].arrival_time > current_time) {
            current_time = processes[i].arrival_time;
        }

        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;

        current_time += processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    cout << "Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].pid << "\t\t" << processes[i].arrival_time << "\t\t" << processes[i].burst_time << "\t\t"
             << processes[i].waiting_time << "\t\t" << processes[i].turnaround_time << endl;
    }

    cout << "\nAverage Waiting Time: " << (float)total_waiting_time / n << endl;
    cout << "Average Turnaround Time: " << (float)total_turnaround_time / n << endl;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process* processes = new Process[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival Time and Burst Time for Process " << i + 1 << ": ";
        cin >> processes[i].arrival_time >> processes[i].burst_time;
        processes[i].pid = i + 1;
    }

    sjf(processes, n);

    delete[] processes;

    return 0;
}

