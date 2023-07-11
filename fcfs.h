#include "display.h"
#include "swap.h"
void fcfs()
{
    // int op[5], oa[5], ob[5], opri[5];

    displayInput();

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
    }

    printf("\n------------------------- FCFS --------------------------\n\n");
    displayOutput();
}
