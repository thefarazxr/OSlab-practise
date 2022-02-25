#include <stdio.h>
main()
{
    int i, j, nof, nop, flag = 0, ref[10], frm[10], pf = 0, victim = -1;
    // ref[10]-> stores page numbers values
    // frm[10]-> stores final values that we show in output
    // pf->no of pageFaults
    // victim->used to find the frame_position of the the victim page (intialized with -1) so as ot range from [0...(nof-1)]
    printf("***** FIFO (First in first out) Page replacement algorithm ******\n");

    printf("\n Enter no.of frames in memory : ");
    scanf("%d", &nof);

    printf("Enter number of pages required to process : ");
    scanf("%d", &nop);

    printf("Enter the pages numbers to load in sequence : ");
    for (i = 0; i < nop; i++)
        scanf("%d", &ref[i]);

    for (i = 0; i < nof; i++)
        frm[i] = -1; //-1 denotes empty element
    printf("\n");

    for (i = 0; i < nop; i++)
    {
        flag = 0; // used to flag when HIT happens!
        printf("\n\t Reference pn %d->\t", ref[i]);
        for (j = 0; j < nof; j++)
        {
            if (frm[j] == ref[i])
            {
                flag = 1;
                printf("HIT=>already present in memory");
                break;
            }
        }
        if (flag == 0) // if HIT doesnt Happen
        {
            pf++;                  // PageFault COUNT
            victim++;              // used to find the frame_position of the the victim page
            victim = victim % nof; // modulo to keep index in limits of the frame_size
            frm[victim] = ref[i];
            for (j = 0; j < nof; j++)
                printf("%4d", frm[j]); // use %4d to give gap/space between each numbr!
        }
    }
    printf("\n\n No.of pages faults : %d \n\n", pf);
}