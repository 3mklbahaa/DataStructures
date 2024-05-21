#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool find_pair_with_sum(int A[], int size_A, int x, int *first, int *second) {
    int hash_table[1000] = {0}; // Assuming values are in range 0-999

    for (int i = 0; i < size_A; i++) {
        int complement = x - A[i];
        if (complement >= 0 && hash_table[complement]) {
            *first = A[i];
            *second = complement;
            return true;
        }
        hash_table[A[i]] = 1;
    }
    return false;
}

int main() {
    int A[] = {1, 4, 45, 6, 10, 8};
    int size_A = sizeof(A) / sizeof(A[0]);
    int x = 16;
    int first, second;

    if (find_pair_with_sum(A, size_A, x, &first, &second)) {
        printf("Pair found: (%d, %d)\n", first, second);
    } else {
        printf("No pair found with sum %d\n", x);
    }

    return 0;
}
