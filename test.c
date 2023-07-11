#include <stdio.h>
#include "swap.h"
void main()
{
    int p[] = {1, 2, 3, 4, 5};
    int a[] = {5, 0, 0, 1, 2};
    int bt[] = {11, 4, 14, 9, 21};
    int tat[5], wt[5], ct[5];
    int pri[] = {1, 2, 3, 4, 5};
    int i;

    int obt[5];
    for (int i = 0; i < 5; i++)
    {
        obt[i] = bt[i];
    }

    for (i = 0; i < 4; i++)
    {
        int min = i;
        for (int j = i + 1; j < 5; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }

        swap(&p[i], &p[min]);
        swap(&a[i], &a[min]);
        swap(&bt[i], &bt[min]);
        swap(&pri[i], &pri[min]);
    }

    int currentTime = 0;
    int completed = 0;
    int hpIndex;

    while (completed != 5)
    {
        hpIndex = -1;
        int hp = 9999;

        for (i = 0; i < 5; i++)
        {
            if (a[i] <= currentTime && bt[i] > 0 && pri[i] < hp)
            {
                hpIndex = i;
                hp = pri[i];
            }
        }

        if (hpIndex == -1)
            currentTime++;

        else
        {
            bt[hpIndex]--;

            if (bt[hpIndex] == 0)
            {
                completed++;
                tat[hpIndex] = currentTime + 1 - a[hpIndex];
                printf("%d", currentTime);
            }
        }
    }
}
