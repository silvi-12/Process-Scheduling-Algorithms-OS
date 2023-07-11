#include "queue.h"

void roundRobin()
{
    int p[] = {1, 2, 3, 4, 5};
    int a[] = {5, 0, 0, 1, 2};
    int bt[] = {11, 4, 14, 9, 21};
    int pri[] = {1, 2, 3, 4, 5};
    int tat[5], wt[5], ct[5];
    int tq = 5;
    int i;
    displayInput();

    Queue *bqueue = createQueue(); // burst time queue
    Queue *queue = createQueue();  // queue
    Queue *tqueue = createQueue(); // time queue for noting the time at context switches
    Queue *cqueue = createQueue(); // completion time
    Queue *pqueue = createQueue(); // process queue
    Queue *aqueue = createQueue(); // arrival queue

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

    int rem[5];
    int time = 0;
    int completed = 0;

    while (completed < 5)
    {
        for (i = 0; i < 5; i++)
        {
            if (bt[i] > 0)
            {
                enqueue(bqueue, bt[i]);

                if (bt[i] > tq)
                {
                    bt[i] -= tq;
                    time += tq;
                    enqueue(tqueue, time);
                }
                else
                {
                    time += bt[i];

                    enqueue(tqueue, time);
                    enqueue(pqueue, p[i]);
                    enqueue(aqueue, a[i]);
                    rem[i] = time - a[i] - bt[i];
                    completed++;
                    enqueue(cqueue, time);
                    bt[i] = 0;
                }

                enqueue(queue, p[i]);
            }
        }
    }

    printf("\n------------------------- Round Robin --------------------------\n\n");

    displayQueue(queue);
    tdisplayTime(tqueue);

    printf("\n\nProcess     : ");
    displayTime(pqueue);
    printf("\nArrival     : ");
    displayTime(aqueue);
    printf("\nCompletion  : ");
    displayTime(cqueue);

    printf("\nProcess\t  TAT\tWT\n");
    for (i = 0; i < 5; i++)
    {
        tat[i] = cqueue->data[i] - aqueue->data[i];
        wt[i] = tat[i] - bqueue->data[i];
        printf("P%d\t  %d\t%d\n", pqueue->data[i], tat[i], wt[i]);
    }
    printf("\n");

    // calc of tat and wt avg
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
