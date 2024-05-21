#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool are_all_values_included(int T1[], int size_T1, int T2[], int size_T2) {
    int hash_table[1000] = {0}; // Assuming values are in range 0-999

    for (int i = 0; i < size_T2; i++) {
        hash_table[T2[i]] = 1;
    }

    for (int i = 0; i < size_T1; i++) {
        if (!hash_table[T1[i]]) {
            return false;
        }
    }
    return true;
}

int main() {
    int T1[] = {1, 2, 3};
    int T2[] = {4, 2, 3, 1};
    int size_T1 = sizeof(T1) / sizeof(T1[0]);
    int size_T2 = sizeof(T2) / sizeof(T2[0]);

    if (are_all_values_included(T1, size_T1, T2, size_T2)) {
        printf("All values in T1 are included in T2\n");
    } else {
        printf("Not all values in T1 are included in T2\n");
    }

    return 0;
}
