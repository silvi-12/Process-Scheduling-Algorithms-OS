void p_priority()
{
    displayInput();
    float wt_avg, tat_avg, total = 0, remainingTime[5];

    for (int i = 0; i < 5; i++)
    {
        remainingTime[i] = bt[i];
    }

    // Sort the processes based on arrival time
    for (i = 0; i < 4; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pri[i];
                pri[i] = pri[j];
                pri[j] = temp;

                temp = remainingTime[i];
                remainingTime[i] = remainingTime[j];
                remainingTime[j] = temp;
            }
        }
    }

    int currentTime = 0;
    int completed = 0;
    int hpIndex;

    while (completed != 5)
    {
        hpIndex = -1;
        int hp = 9999;

        // Find the process with highest pri among the arrived processes
        for (i = 0; i < 5; i++)
        {
            if (a[i] <= currentTime && remainingTime[i] > 0 && pri[i] < hp)
            {
                hpIndex = i;
                hp = pri[i];
            }
        }

        // No process found, increment current time
        if (hpIndex == -1)
        {
            currentTime++;
        }
        else
        {
            remainingTime[hpIndex]--;

            // Process is completed
            if (remainingTime[hpIndex] == 0)
            {
                completed++;
                tat[hpIndex] = currentTime + 1 - a[hpIndex];
                wt[hpIndex] = tat[hpIndex] - bt[hpIndex];
                total += wt[hpIndex];
            }

            currentTime++;
        }
    }

    wt_avg = (float)total / 5;
    total = 0;

    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < 5; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, a[i], bt[i], pri[i], wt[i], tat[i]);
        total += tat[i];
    }

    tat_avg = (float)total / 5;

    printf("\nAverage Waiting Time: %.2f\n", wt_avg);
    printf("Average Turnaround Time: %.2f\n", tat_avg);
}
