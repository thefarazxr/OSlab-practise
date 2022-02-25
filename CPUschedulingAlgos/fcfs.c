#include <stdio.h>
void getdata();
void comptime();
void wait();
void turnaround();
void display();

int i, n, at[10], bt[10], ct[10], wt[10], tat[10];
float ttat = 0, twt = 0;
// In prev Clg given approach if at[0]!=0 we get wrong output so I implemented Completion Time method

void main()
{
    printf("\n***********FCFS CPU Scheduling ALGO*********************\n");
    printf("\n***********NOTE: Keep AT<Arrival Time in Ascending Order>*********************\n");
    getdata();
    comptime();
    turnaround();
    wait();
    // turnaround();
    display();
}

void getdata()
{
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d Process -- AT  --- BT : \t", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }
}
void comptime()
{
    ct[0] = at[0] + bt[0]; // Initally after some arrival time then the P1 starts and completes after bt[0]
    for (int i = 1; i < n; i++)
    {
        ct[i] = ct[i - 1] + bt[i]; // other all porcesse start at compltn of their prev process and run for some-time(bt[i])
    }
}
void wait()
{
    int s = 0;
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = tat[i] - bt[i]; // Formula we know!
        // s = s + bt[i - 1];       Prev Approach
        // wt[i] = s - at[i];       prev approach
        twt += wt[i];
    }
}

void turnaround()
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i]; // Formula we know
        // tat[i] = wt[i] + bt[i];
        ttat += tat[i];
    }
}

void display()
{
    printf("\nPROCESS\t |ARRIVAL TIME\t|BURST TIME\t|COMPLTION TIME\t|WAIT TIME\t|TURN AROUNDTIME\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t|%d\t\t|%d\t\t|%d\t\t|%d\t\t|%d\n", i + 1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }
    printf("\nTotal Waiting time (TWT) = %f", twt);
    printf("\nAverage Waiting time (AWT) = %f", twt / n);
    printf("\n\nTotal Turn Around Time(TAT) = %f", ttat);
    printf("\nAverage Turn Around Time Avg.(TAT) = %f \n\n", ttat / n);
}
