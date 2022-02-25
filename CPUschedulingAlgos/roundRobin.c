#include <stdio.h>
// NOTES: This works only when all processes have ARRIVAL time=0;
void main()
{
    int n, i, q, x = 0, count = 0, temp;
    int bt[10], temp_bt[10], tat[10], wt[10];
    float twt = 0, ttat = 0;
    printf("***** RR (ROUND ROBIN) SCHEDULING ******\n");
    printf("\nEnter the number of processes : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the burst time of process %d : ", i);
        scanf("%d", &bt[i]);
        temp_bt[i] = bt[i]; // using a temporary burst-time array in ROUND-ROBIN
    }

    printf("\nEnter the time quantum : ");
    scanf("%d", &q);

    while (1) // ROund-RObin so continous till n==count;
    {
        for (i = 0; i < n; i++)
        {
            temp = q; // temp has Quanta value

            // case-1
            if (temp_bt[i] == 0) // if BT is already =0 <happens eventually as we iterate>
            {
                count++;  // when this happens then increase count to let know the no. of processes done and helps in exiting the while(1)
                continue; // continue- will skip upcoming code and goes directly into next iteration
            }

            // case-2
            if (temp_bt[i] > q)
                temp_bt[i] = temp_bt[i] - q;
            else if (temp_bt[i] >= 0) // case-3 <if q=2 but temp_bt is 1 then we follow this>
            {
                temp = temp_bt[i]; // then assign that to temp <helps in updating the CT or TAT else it might take default Quanta value <--IMPT!  >
                temp_bt[i] = 0;    // make it ZERO
            }
            x = x + temp; // update temp value to x here x-> tracks the CT/TAT of the processes;
            tat[i] = x;   // keeps updating to the latest value of TAT of that process
        }

        if (n == count) // when this happens it means all processes compltd so END the loop
            break;
    }

    for (i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i]; // Calc WT
        twt = twt + wt[i];      // Calc TWT
        ttat = ttat + tat[i];   // Calc TTAT
    }

    // Diplaying all the Results:

    printf("\nProcess\t|Burst Time\t|Wait Time\t|Turn-Around Time");
    for (i = 0; i < n; i++)
    {
        printf("\n%d\t|%d\t\t|%d\t\t|%d", i, bt[i], wt[i], tat[i]);
    }
    printf("\n\nTotal waiting time is %f", twt);
    printf("\nAverage waiting time is %f", twt / n);
    printf("\n\nTotal turn around time is %f", ttat);
    printf("\nAverage turn around time is %f\n\n", ttat / n);
}