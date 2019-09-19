void QuickSort_Stampa(unsigned long A[], unsigned long l) //Θ(n log n) → Θ(n²)
{
    unsigned long i;
    for (i = 1; i <= l; i++)
    {
        if (A[i - 1] < 10)
            printf("%lu", 0);

        printf("%lu", A[i - 1]);
        printf("|");
    }

    printf("\n");
}

void QuickSort_Scambia(unsigned long A[], unsigned long indice_partenza, unsigned long indice_destinazione)
{
    unsigned long temp = A[indice_partenza - 1];
    A[indice_partenza - 1] = A[indice_destinazione - 1];
    A[indice_destinazione - 1] = temp;
}

unsigned long QuickSort_Partition(unsigned long A[], unsigned long p, unsigned long r) //Θ(n²)
{
    unsigned long j;
    unsigned long x = A[r - 1];
    unsigned long i = p - 1;

    for (j = p; j <= r - 1; j++)
        if (A[j - 1] <= x)
        {
            i++;
            QuickSort_Scambia(A, i, j);
        }

    QuickSort_Scambia(A, i + 1, r);

    return (i + 1);
}

void QuickSort_QuickSort_Da_A(unsigned long A[], unsigned long p, unsigned long r) //Θ(n log n) → Θ(n²)
{
    if (p < r)
    {
        unsigned long q = QuickSort_Partition(A, p, r);

        QuickSort_QuickSort_Da_A(A, p, q - 1);
        QuickSort_QuickSort_Da_A(A, q + 1, r);
    }
}

void QuickSort_QuickSort(unsigned long A[], unsigned long l) //Θ(n log n) → Θ(n²)
{
    QuickSort_QuickSort_Da_A(A, 1, l);
}