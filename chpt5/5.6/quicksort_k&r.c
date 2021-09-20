// quicksort

void qsort(int *a, int left, int right)
{
    int i, last;
    
    if (left >= right) // do nothing if fewer than two elements.
        return; 
    swap(&(a[left]), &(a[(left+right)/2])); // Move partition element
    last = left;
    for (i = left+1; i <= right; i++) // Partition
        if (a[i] < a[left])
            swap(&(a[++last]), &(a[i]));
    swap(&(a[left]), &(a[last]));
    qsort(a, left, last-1);
    qsort(a, last+1, right);
}