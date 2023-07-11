#include <stdio.h>
#include "fcfs.h"
#include "np_sjf.h"
#include "np_priority.h"
#include "RR.h"
#include "p_priority.h"
#include "p_sjf.h"

int main()
{
    int choice;
    printf("-----Process Scheduling Algorithms-----\n");
    printf("1 - FCFS\n2 - SJF(non-preemptive)\n3 - SJF(preemptive)\n4 - Priority(non-preemptive)\n5 - Priority(preemptive)\n6 - Round Robin\n7 - Exit");
    printf("\nEnter choice number for PSA : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        fcfs();
        break;

    case 2:
        np_sjf();
        break;

    case 3:
        p_sjf();
        break;

    case 4:
        np_priority();
        break;

    case 5:
        p_priority();
        break;

    case 6:
        roundRobin();
        break;

    case 7:
        exit(0);
    }

    return 0;
}