#include <stdio.h>
int i, j, nof, nor, flag = 0, ref[20], frm[20], pf = 0, victim = -1;
int recent[20], lrucal[20], count = 0, tq[20];
int find();
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
        frm[i] = -1;
        tq[i] = 0;
    }
    for (i = 0; i < nor; i++)
    {
        count++;
        flag = 0;
        printf("\n\t Reference pn%d->\t", ref[i]);
        for (j = 0; j < nof; j++)
        {
            if (frm[j] == ref[i])
            {
                flag = 1;
                tq[j] = count;
                printf("already present in memory");
                break;
            }
        }
        if (flag == 0)
        {
            pf++;
            if (pf <= nof)
                victim = (victim + 1) % nof;
            else
                victim = find();
            tq[victim] = count;
            frm[victim] = ref[i];
            for (j = 0; j < nof; j++)
                printf("%4d", frm[j]);
        }
    }
    printf("\n\n No.of page faults : %d \n\n", pf);
}
int find()
{
    int i, index = 0, temp = tq[0];
    for (i = 1; i < nof; i++)
    {
        if (temp > tq[i])
        {
            temp = tq[i];
            index = i;
        }
    }
    return index;
}