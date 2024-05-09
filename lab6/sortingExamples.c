#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generate_random_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = random_int(1, 100000);
    }
}

void bubble_sort(int A[], int n) {
    int pass, i, temp, swapped = 1;
    for (pass = n - 1; pass >= 0 && swapped; pass--) {
        swapped = 0;
        for (i = 0; i < pass; i++) {
            if (A[i] > A[i + 1]) {
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                swapped = 1;
            }
        }
    }
}

int linear_search(int array[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (array[i] == key) {
            printf("Element found at position %d\n", i);
            return 1;
        }
    }
    return 0;
}

int binary_search(int array[], int size, int key){
    int l = 0, r = size -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (array[m] == key)
            return m;
        if (array[m] < key)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int binary_searchV2(int array[], int l, int r, int key) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (array[m] == key)
            return m;
        if (array[m] < key)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

// Function to search in sorted array
int ternary_search(int array[], int size, int key) {
    int mid1 = 1 + (size-1)/3, mid2 = size - (size-1)/3;
    if(array[mid1]<key && array[mid2]>key){
        int l = mid1, r = mid2;
        while(l<r){
            int m = l + (r-l) / 2;
            if(array[m] == key){
                return m;
            }
            if(array[m] < key){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
    }
    else if(array[mid1] > key){
        int l = 0, r = mid1;
        while(l<r){
            int m = l + (r-l) / 2;
            if(array[m] == key){
                return m;
            }
            if(array[m] < key){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
    }
    else if(array[mid2] < key){
        int l = mid2, r = size;
        while(l<r){
            int m = l + (r-l) / 2;
            if(array[m] == key){
                return m;
            }
            if(array[m] < key){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
    }
}
// Function to search in sorted array
int exponential_search(int array[], int size, int key) {
    if (array[0] == key)
        return 0;

    // Find range for binary search by repeated doubling
    int i = 1;
    while (i < size && array[i] <= key)
        i = i * 2;

    return binary_searchV2(array, i / 2, (i < size) ? i : size - 1, key);
}
// Function to search in sorted array
int findFibonacci(int n) {
    if (n <= 1)
        return n;
    int a = 0, b = 1, c = 1;
    while (c < n) {
        a = b;
        b = c;
        c = a + b;
    }
    return c;
}


int fibonacci_search(int array[], int size, int key) {
    int fibM2 = 0;
    int fibM1 = 1;
    int fibM = fibM1 + fibM2;

    while (fibM < size) {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM = fibM1 + fibM2;
    }

    int offset = -1;

    while (fibM > 1) {
        // Find the index of the element to be compared
        int i = (offset + fibM2) < (size - 1) ? (offset + fibM2) : (size - 1);

        if (array[i] == key)
            return i;
        else if (array[i] > key) {
            fibM = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fibM - fibM1;
        }
        else {
            fibM = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM1;
            offset = i;
        }
    }

    if (fibM1 == 1 && array[offset + 1] == key)
        return offset + 1;

    return -1;
}

int main() {
    srand(time(NULL));
    clock_t start_time, end_time;
    int unsorted_array[ARRAY_SIZE];
    int sorted_array[ARRAY_SIZE];
    int search_key = random_int(1, 100000); // Random search key within array range

    generate_random_array(unsorted_array, ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        sorted_array[i] = unsorted_array[i];
    }

    start_time = clock();
    bubble_sort(sorted_array, ARRAY_SIZE);
    end_time = clock();
    double sort_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken to sort array with bubble sort is %lf seconds\n", sort_time);

    start_time = clock();
    int found = linear_search(unsorted_array, ARRAY_SIZE, search_key);
    end_time = clock();
    double search_time_unsorted = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken to search in unsorted array is %lf seconds\n", search_time_unsorted);

    if (found) {
        start_time = clock();
        int found_sorted = linear_search(sorted_array, ARRAY_SIZE, search_key);
        end_time = clock();
        double search_time_sorted = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Time taken to search in sorted array is %lf seconds\n", search_time_sorted);
    } else {
        printf("Search key not found in unsorted array, skipping search in sorted array.\n");
    }

    return 0;
}
