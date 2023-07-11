void np_sjf()
{
    displayInput();
    printf("\n");

    // ascending order acc to arrival time
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

    //burst compared with arrival 
    for (i = 1; i < 5; i++)
    {
        int min = i;
        for (int j = i + 1; j < 5; j++)
        {

            if (a[j] < bt[0])
            {
                min = j;
            }
        }

        swap(&p[i], &p[min]);
        swap(&a[i], &a[min]);
        swap(&bt[i], &bt[min]);
    }

    for (i = 1; i < 5; i++)
    {
        int min = i;
        for (int j = i + 1; j < 5; j++)
        {

            if (bt[j] < bt[min])
            {
                min = j;
            }
        }

        swap(&p[i], &p[min]);
        swap(&a[i], &a[min]);
        swap(&bt[i], &bt[min]);
    }

    printf("\n--------------SJF(non-preemptive)-----------\n\n");
    displayOutput();
}