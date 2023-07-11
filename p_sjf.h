void p_sjf()
{
    displayInput();
    float avg_wt, avg_tat, total = 0, obt[5];

    for (int i = 0; i < 5; i++)
    {
        obt[i] = bt[i];
    }

    int currentTime = 0;
    int completed = 0;
    int sjIndex;

    while (completed != 5)
    {
        sjIndex = -1;
        int shortestJob = 9999;

        // Find the process with the shortest remaining burst time among the arrived processes
        for (i = 0; i < 5; i++)
        {
            if (a[i] <= currentTime && obt[i] > 0 && bt[i] < shortestJob)
            {
                sjIndex = i;
                shortestJob = bt[i];
            }
        }

        // No process found, increment current time
        if (sjIndex == -1)
        {
            currentTime++;
        }
        else
        {
            obt[sjIndex]--;

            // Process is completed
            if (obt[sjIndex] == 0)
            {
                completed++;
                tat[sjIndex] = currentTime + 1 - a[sjIndex];
                wt[sjIndex] = tat[sjIndex] - bt[sjIndex];
                total += wt[sjIndex];
            }

            currentTime++;
        }
    }

    avg_wt = (float)total / 5;
    total = 0;

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < 5; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, a[i], bt[i], wt[i], tat[i]);
        total += tat[i];
    }

    avg_tat = (float)total / 5;

    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
}
