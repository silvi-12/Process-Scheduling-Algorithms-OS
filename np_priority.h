void np_priority()
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
        swap(&pri[i], &pri[min]);
    }

    for (i = 1; i < 5; i++)
    {
        int min = i;
        // int k = 0;
        for (int j = i + 1; j < 5; j++)
        {

            if (a[j] < bt[0])
            {
                min = j;
            }
            // k++;
        }
        swap(&p[i], &p[min]);
        swap(&a[i], &a[min]);
        swap(&bt[i], &bt[min]);
        swap(&pri[i], &pri[min]);
    }

    for (i = 1; i < 5; i++)
    {
        int min = i;
        for (int j = i + 1; j < 5; j++)
        {

            if (pri[j + 1] < pri[min])
            {
                if (a[j] < bt[0])
                {
                    min = j;
                }
                // min = j;
            }
            swap(&p[i], &p[min]);
            swap(&a[i], &a[min]);
            swap(&bt[i], &bt[min]);
            swap(&pri[i], &pri[min]);
        }
    }

    for (i = 2; i < 5; i++)
    {
        int min = i;
        // int k = 0;
        for (int j = i + 1; j < 5; j++)
        {

            if (a[j] < bt[1])
            {
                min = j;
            }
            // k++;
        }

        swap(&p[i], &p[min]);
        swap(&a[i], &a[min]);
        swap(&pri[i], &pri[min]);
        swap(&bt[i], &bt[min]);
    }

    for (i = 2; i < 5; i++)
    {
        int min = i;
        for (int j = i + 1; j < 5; j++)
        {

            if (pri[j] < pri[min])
            {
                min = j;
            }
        }

        swap(&p[i], &p[min]);
        swap(&a[i], &a[min]);
        swap(&bt[i], &bt[min]);
        swap(&pri[i], &pri[min]);
    }

    printf("\n--------------Priority(non-preemptive)-----------\n\n");
    displayOutput();
}