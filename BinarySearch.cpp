int binarySearch(int A[], int low, int high, int target) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] == target) return mid;
        if (A[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}
