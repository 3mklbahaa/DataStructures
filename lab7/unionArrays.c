#include <stdio.h>
#include <stdlib.h>

int* union_arrays(int T1[], int size_T1, int T2[], int size_T2, int *size_union) {
    int hash_table[1000] = {0}; // Assuming values are in range 0-999
    int* union_array = (int*)malloc((size_T1 + size_T2) * sizeof(int));
    int index = 0;

    for (int i = 0; i < size_T1; i++) {
        if (!hash_table[T1[i]]) {
            union_array[index++] = T1[i];
            hash_table[T1[i]] = 1;
        }
    }

    for (int i = 0; i < size_T2; i++) {
        if (!hash_table[T2[i]]) {
            union_array[index++] = T2[i];
            hash_table[T2[i]] = 1;
        }
    }

    *size_union = index;
    return union_array;
}

int main() {
    int T1[] = {1, 2, 3};
    int T2[] = {3, 4, 5};
    int size_T1 = sizeof(T1) / sizeof(T1[0]);
    int size_T2 = sizeof(T2) / sizeof(T2[0]);
    int size_union;

    int* union_array = union_arrays(T1, size_T1, T2, size_T2, &size_union);

    printf("Union array: ");
    for (int i = 0; i < size_union; i++) {
        printf("%d ", union_array[i]);
    }
    printf("\n");

    free(union_array);
    return 0;
}
