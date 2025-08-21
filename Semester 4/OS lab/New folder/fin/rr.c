#include <stdio.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 2 // Adjust time quantum as needed

struct Process {
    int pid; // Process ID
    int arrival_time; // Arrival Time
    int burst_time; // Burst Time
    int remaining_time; // Remaining Burst Time
    int waiting_time; // Waiting Time
    int turnaround_time; // Turnaround Time
};

void roundRobin(struct Process processes[], int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int time = 0;

    // Copy burst time to remaining time
    for (int i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
    }

    // Keep track of completion status of processes
    int completed[MAX_PROCESSES] = {0};

    // Perform Round Robin scheduling
    while (1) {
        int all_processes_completed = 1;

        // Traverse all processes
        for (int i = 0; i < n; i++) {
            if (!completed[i]) {
                all_processes_completed = 0;

                // Execute the process for time quantum or remaining time, whichever is smaller
                int execute_time = (processes[i].remaining_time < TIME_QUANTUM) ? processes[i].remaining_time : TIME_QUANTUM;
                processes[i].remaining_time -= execute_time;
                time += execute_time;

                // Update waiting and turnaround time
                processes[i].waiting_time += (time - processes[i].arrival_time - processes[i].burst_time);
                processes[i].turnaround_time = (time - processes[i].arrival_time);

                // Mark process as completed if its remaining time becomes 0
                if (processes[i].remaining_time <= 0) {
                    completed[i] = 1;
                }
            }
        }

        // If all processes are completed, break from the loop
        if (all_processes_completed)
            break;
    }

    // Calculate total waiting and turnaround time
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    // Display process details
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    // Display average waiting time and average turnaround time
    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[MAX_PROCESSES];

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
    }

    // Perform Round Robin scheduling
    roundRobin(processes, n);

    return 0;
}
