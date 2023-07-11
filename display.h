int p[] = {1, 2, 3, 4, 5};
int a[] = {5, 0, 0, 1, 2};
int bt[] = {11, 4, 14, 9, 21};
int pri[] = {1, 2, 3, 4, 5};
int tat[5], wt[5], ct[5];
int tq = 5;
int i, j;

void displayInput()
{
    printf("\nProcess\t\tArrival\t\tBurst\t\tPriority\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i], a[i], bt[i], pri[i]);
    }
}

void displayOutput()
{
    printf("Process\t\tArrival\t\tBurst\t\tPriority\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i], a[i], bt[i], pri[i]);
    }
    printf("\n");

    // CT i.e completion time calc
    printf("\nGantt Chart:");
    printf("\t------------------------------------\n");
    printf("\t\t|");
    ct[-1] = 0;
    for (i = 0; i < 5; i++)
    {
        ct[i] = ct[i - 1] + bt[i];
        printf("  P%d  |", p[i]);
    }
    printf("\n");
    printf("\t\t------------------------------------\n");
    printf("\nProcess\t  TAT\tWT\n");
    for (i = 0; i < 5; i++)
    {
        tat[i] = ct[i] - a[i];
        wt[i] = tat[i] - bt[i];
        printf("P%d\t  %d\t%d\n", p[i], tat[i], wt[i]);
    }
    printf("\n");

    float sum = 0, sum_wt = 0;
    float tat_avg = 0, wt_avg = 0;
    for (i = 0; i < 5; i++)
    {
        sum += tat[i];
        tat_avg = sum / 5;
        sum_wt += wt[i];
        wt_avg = sum_wt / 5;
    }

    printf("TAT avg = %.2f\n", tat_avg);
    printf("WT avg  = %.2f\n\n", wt_avg);
}
