#include <bits/stdc++.h>
using namespace std;
struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int starting_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};
int main()
{
    int n;
    float stat = 0.0, swt = 0.0, atat = 0.0, awt = 0.0;
    cout << setprecision(2) << fixed;
    cout << "Enter no. of processes : ";
    cin >> n;
    process p[n];
    cout << "\n";
    // int gaant[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time of process " << i + 1 << " : ";
        cin >> p[i].arrival_time;
        cout << "Enter burst time of process " << i + 1 << " : ";
        cin >> p[i].burst_time;
        cout << "\n";
        p[i].pid = i + 1;
    }
    int current_time = 0, j = 0;
    int completed = 0;
    vector<bool>done(n,false);

    while (completed != n)
    {
        cout<<current_time<<" ";
        int idx = -1;
        int min = 100000;
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival_time <= current_time && !done[i])
            {
                if (p[i].burst_time < min)
                {
                    min = p[i].burst_time;
                    idx = i;
                }
                if (p[i].burst_time == min)
                {
                    if (p[i].arrival_time < p[idx].arrival_time)
                    {
                        min = p[i].burst_time;
                        idx = i;
                    }
                }
            }
        }
        if (idx != 1)
        {
            p[idx].starting_time = current_time;
            p[idx].completion_time = p[idx].starting_time + p[idx].burst_time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;

            stat += p[idx].turnaround_time;
            swt += p[idx].waiting_time;
            current_time = p[idx].completion_time;
            completed++;
            done[idx] = 1;
            // gaant[j] = idx;
            // j++;
        }
        else
            current_time++;
    }
    atat = stat / n;
    awt = swt / n;
    cout << "PID\tAT\tBT\tST\tCT\tTAT\tWT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i].pid << "\t" << p[i].arrival_time << "\t" << p[i].burst_time << "\t" << p[i].starting_time << "\t" << p[i].completion_time << "\t" << p[i].turnaround_time << "\t" << p[i].waiting_time << endl;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "|\t" << gaant[i] << "\t" << p[i].completion_time;
    // }
    cout << "AVG. TURNAROUND TIME : " << atat << endl
         << "AVG. WAITING TIME : " << awt << endl;
}