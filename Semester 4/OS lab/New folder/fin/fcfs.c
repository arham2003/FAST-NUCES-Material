#include <iostream>

using namespace std;

struct Process {
    int pid; // Process ID
    int arrival_time; // Arrival Time
    int burst_time; // Burst Time
    int waiting_time; // Waiting Time
    int turnaround_time; // Turnaround Time
};

void fcfs(Process* processes, int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    // Waiting time for the first process is 0
    processes[0].waiting_time = 0;

    // Calculating waiting time for each process
    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }

    // Calculating turnaround time for each process and total waiting and turnaround time
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    // Displaying process details
    cout << "Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].pid << "\t\t" << processes[i].arrival_time << "\t\t" << processes[i].burst_time << "\t\t"
             << processes[i].waiting_time << "\t\t" << processes[i].turnaround_time << endl;
    }

    // Displaying average waiting time and average turnaround time
    cout << "\nAverage Waiting Time: " << (float)total_waiting_time / n << endl;
    cout << "Average Turnaround Time: " << (float)total_turnaround_time / n << endl;
}

int main() {
    // Number of processes
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process* processes = new Process[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival Time and Burst Time for Process " << i + 1 << ": ";
        cin >> processes[i].arrival_time >> processes[i].burst_time;
        processes[i].pid = i + 1;
    }

    // Perform FCFS scheduling
    fcfs(processes, n);

    delete[] processes; // Freeing dynamically allocated memory

    return 0;
}
