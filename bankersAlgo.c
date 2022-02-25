#include <stdio.h>
main()
{
    int p, r, instances, i = 0, j = 0, k = 0, count1 = 0, count2 = 0;
    printf("\nEnter no of processes:  ");
    scanf("%d", &p);
    printf("\nEnter no of Resources:  ");
    scanf("%d", &r);

    int available[r], allocated[p][r], max[p][r], need[p][r];
    int completed[p];

    for (int i = 0; i < p; i++)
        completed[i] = 0; // Setting flag for the uncompleted processes flag=0 i.e not completed!

    printf("\nEnter no of Available Resources: ");
    for (int i = 0; i < r; i++)
    {
        printf(" R[%d] : ", i);
        scanf("%d", &instances);
        available[i] = instances;
    }
    printf("\nEnter Maximum (MAX TABLE ) Resources for a each Process: ");
    for (i = 0; i < p; i++)
    {
        printf(" P[%d] : ", i);
        for (j = 0; j < r; j++)
        {
            scanf("%d", &instances);
            max[i][j] = instances;
        }
    }

    printf("\nEnter no. of Instances ALREADY ALLOCATED Resources for a each Process: ");
    for (i = 0; i < p; i++)
    {
        printf(" P[%d] : ", i);
        for (j = 0; j < r; j++)
        {
            scanf("%d", &instances);
            allocated[i][j] = instances;
            need[i][j] = max[i][j] - allocated[i][j]; // Calculating the ""NEED""of EACH PROCESS
        }
    }
    printf("Possible Sequence is: ");
    while (count1 != p) // use count1 to track processes compltn! INTIALLY count1=0
    {
        count2 = count1; // count2 intially 0

        for (i = 0; i < p; i++)
        {
            for (j = 0; j < r; j++)
            {
                if (need[i][j] <= available[j])
                {
                    k++; // flag for resource allocation
                }
            }
            if (k == r && completed[i] == 0) // k==r means above if condn satisfied all times && this process not yet completed
            {
                printf(" P[%d] -> ", i); // adds the process to the list
                completed[i] = 1;        // flags it as completed
                for (j = 0; j < r; j++)
                {
                    available[j] = available[j] + allocated[i][j]; // adds to available resources
                }
                count1++; // hence count1 increases by 1
            }
            k = 0; // reset k to ZERO for next process checking
        }

        if (count1 == count2) // INtially if count1 didnt increase i.e no reource found then goes to DEADLOCK
        {
            printf("... and then DEADLOCK occurs");
            break;
        }
        // while loop repeats till we map all processes to a resource so (count1!=p)

        // next assign count2 =count1 at beginning soat the end-->check whether we found a reosurce if YES then count1++ so (count1==count2) => doesnt SATISFY & NO DEADLOCK!
        // and in last if loop(count1==count2) gets satisfied --> denoting that DEADLOCK has occured.
    }
    printf("\n\n");
}