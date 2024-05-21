#include <stdio.h>
#include <stdlib.h>

void count_occurrences(int T1[], int size_T1) {
    int hash_table[1000] = {0}; // Assuming values are in range 0-999

    for (int i = 0; i < size_T1; i++) {
        hash_table[T1[i]]++;
    }

    for (int i = 0; i < size_T1; i++) {
        if (hash_table[T1[i]] > 0) {
            printf("%d: %d times\n", T1[i], hash_table[T1[i]]);
            hash_table[T1[i]] = 0; // Set to 0 to avoid duplicate printing
        }
    }
}

int main() {
    int T1[] = {1, 2, 3, 1, 2, 1};
    int size_T1 = sizeof(T1) / sizeof(T1[0]);

    count_occurrences(T1, size_T1);

    return 0;
}
