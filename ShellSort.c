    /* C implementation ShellSort */
    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    /* function to sort array using shellSort */
    void shellSort(int A[], int n)
    {
        int gap,i;
        // Start with a larger gap, then reduce the gap to 1
        // we take gap sequence in order of |N/2|, |N/4|, |N/8|...1
        for (gap = n/2; gap > 0; gap /= 2)
        {
            // we performe gapped insertion sort for this gap size.
            // The first gap elements a[0..gap-1] are already in gapped order
            // keep adding one more element until the entire array is gap sorted
            for (i = gap; i < n; i += 1) { 
          // store a[i] in temp and make a hole at position i 
          int temp = A[i]; 
          // shift earlier gap-sorted elements up until the correct 
          // location for a[i] is found 
          int j; 
          for (j = i; j >= gap && A[j - gap] > temp; j -= gap)
                    A[j] = A[j - gap];
                //  put temp (the original a[i]) in its correct location
                A[j] = temp;
            }
        }
    }
    /*  function to print an array */
    void print_array(int A[], int size)
    {
        int i;
        for (i=0; i < size; i++)
            printf("%d ", A[i]);
        printf("
    ");
    }
    int main()
    {
        int A[] = {61,109,149,111,34,2,24,119,122,125,27,145};
        int n = sizeof(A)/sizeof(A[0]);
        printf("Unsorted array: ");
        print_array(A, n);
        printf("
    ");
        //Call shell sort function
        shellSort(A, n);
        printf("Sorted array: ");
        print_array(A, n);
        return 0;
    }