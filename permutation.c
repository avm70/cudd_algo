#include <stdio.h>
#include <stdlib.h>


int less(int value_0, int value_1) {
    return value_0 < value_1;
}

void swap(int * arr, int index_0, int index_1) {
    int item = arr[index_0];
    arr[index_0] = arr[index_1];
    arr[index_1] = item;
}


int nextPermutation(int * arr, int count) {
    int i = count;
    int j = 0;
    do {
        if( i < 2 )
            return 0;
        --i;
    } while(!(less(arr[i - 1], arr[i])));
    for(j = count; j > i && !(less(arr[i - 1],arr[--j])););
    swap(arr, i - 1, j);
    for(j = count; i < --j; i++)
        swap(arr, i++, j);
    return 1;
}


int main() {
    int n = 4;
    int * permutation = (int*)malloc(n  * sizeof(int));
    for(int i = 1; i <= n; i++) {
        permutation[i - 1] = i;
    }
    do {
        for(int i = 0; i < n; i++) {
        printf("%d ", permutation[i]);
        }
        printf("\n");
    } while(nextPermutation(permutation, n));
    return 0;
}