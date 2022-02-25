#include <stdio.h>
int i, j, nof, nor, flag = 0, ref[20], frm[20], pf = 0, victim = -1;
int count = 0, tq[20]; // count is used to give

// tq[] stores the count value for each frame elemnt so that we could decide the oldest one and swap it out!
// tq[] stores the count and newer elemnts have higher count value and older ones have lower count value
// this helps us find the older ones i.e older than tq[0]!

int find(); // used to find the index of the victim-frame

int main()
{
    printf("***** LRU (Least recently used) Page replacement algorithm ******\n");
    printf("\n Enter no.of Frames in memory : ");
    scanf("%d", &nof);
    printf("\nEnter no.of pages required to load : ");
    scanf("%d", &nor);

    printf("\nEnter page numbers required to load in sequence : ");
    for (i = 0; i < nor; i++)
        scanf("%d", &ref[i]);

    for (i = 0; i < nof; i++)
    {
        frm[i] = -1; // make all frame defualt -1 -> empty
        tq[i] = 0;   // intially keep 0 as count for all frame-values
    }

    for (i = 0; i < nor; i++)
    {
        count++;  // for every page incrmnt the count
        flag = 0; // used for PAGEfault FLAG
        printf("\n\t Reference pn%d->\t", ref[i]);

        for (j = 0; j < nof; j++)
        {
            if (frm[j] == ref[i]) // pageHIT condition
            {
                flag = 1;      // when HIT then flag=1
                tq[j] = count; // assign count to tq[j] on HIT!
                printf("already present in memory");
                break;
            }
        }
        if (flag == 0)
        {
            pf++;          // count the PageFAULTS
            if (pf <= nof) // means stack has empty positions < happens--->intially till stack has empty positions avail. >
                victim = (victim + 1) % nof;
            else
                victim = find(); // if no empty slot then find the Least Recently USED elemnt!

            tq[victim] = count;   // add latest count value to where victim is repl. by new value
            frm[victim] = ref[i]; // update the respected index pos i.e victim with the page values i.e ref[i]

            for (j = 0; j < nof; j++)
                printf("%4d", frm[j]); // print out the values in page
        }
    }

    printf("\n\n No.of page faults : %d \n\n", pf);
}

int find() // function to find the index of the elemnt viz LRU
{
    int i, index = 0, temp = tq[0]; // index =0 if no condn satisfies swap out the  0th index-value
                                    // assume temp as tq[0] means that intially it is to be swapped but if there is an older elemnt then swap that out
    for (i = 1; i < nof; i++)
    {
        if (temp > tq[i]) // older elemnts have lower/less value compared to tq[o] if satisify then make that elemnt's index as victim!
        {
            temp = tq[i];
            index = i;
        }
    }
    return index;
}