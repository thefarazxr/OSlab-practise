#include <stdio.h>
main()
{
    int time, bt[10], at[10], sum_bt = 0, small, n, i;
    int sum_turnaround = 0, sum_wait = 0;
    printf("***** SJF ( SHORTEST JOB FIRST ) NON-PRE-EMPTIVE SCHEDULING ******\n\n");
    printf("Enter no of processes : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter arrival time & burst time for process %d : ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        sum_bt += bt[i]; // Calc sum of all burstTimes to know when to end!
    }
    bt[9] = 9999; // assume it as Highest BT -- helps in finding MIN. BT
    printf("\n\nProcess\t|Arrival Time\t|Burst Time\t|Waiting Time\t|Turn Around Time\n");
    // here we print Processes and their detailed table based on the Order(AT & BT)

    for (time = 0; time < sum_bt;) // time- time consumed/passed
    {
        small = 9; // small- used to denote an index intially denoted bt[small] which helps in finding bt[i] with least BT

        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && bt[i] > 0 && bt[i] < bt[small]) // 1.Check if process ARRIVED 2. bt[i]>0 to VALIDATE+ discard already considerd processes 3. TO find Min BT
                small = i;                                       // if found then update the index using "small"
        }
        if (small == 9) // this happens only when AT>time i.e process not yet loaded
        {
            time++;   // then we increase time by 1 and use "continue" to go at start of loop for next iteration
            continue; // continue- will skip upcoming code and goes directly into next iteration
        }
        printf("%d\t|%d\t\t|%d\t\t|%d\t\t|%d\t\n", small + 1, at[small], bt[small], time - at[small], time + bt[small] - at[small]); // time+bt[small] is Comp Time
        sum_turnaround += time + bt[small] - at[small];
        sum_wait += time - at[small];

        time += bt[small]; // increament time as process executes
        bt[small] = 0;     // used to make that process's BT to 0 as it is executed once and prevents from Executing again! Use in line25 Condition : bt[i]>0
    }
    printf("\nTotal Waiting Time (TWT) = %f", sum_wait * 1.0); // converts to Float value vlaue;
    printf("\nAverage Waiting Time (AWT) = %f", sum_wait * 1.0 / n);
    printf("\n\nTotal Turn Around Time(TAT) = %f", sum_turnaround * 1.0);
    printf("\nAverage Turnaround Time (ATAT) = %f \n\n\n", sum_turnaround * 1.0 / n);
}