inline void swap(int& a, int& b) {
    int t = a; a = b; b = t;
}

void quickSort(int A[], int low, int high) {
    if (low >= high) return; // base condition

    // divide process
    int i = low - 1, j = low;
    int& pivot = A[high];
    for (; j < high; ++j) {
        if (A[j] < pivot)
            swap(A[++i], A[j]);
    }
    swap(A[++i], pivot);

    // conquer process
    quickSort(A, low, i - 1);
    quickSort(A, i + 1, high);
}