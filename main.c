#include <stdio.h>
#include <stdlib.h>
#include <cudd.h>

int factorial(int n) {
    if( n == 0 || n == 1 ) {
        return 1;
    } else {
        return n * factorial( n - 1 );
    }
}

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
    int n = 6;
    DdNode* nodes[n];
    for(int i = 0; i < n; i++) {
        nodes[i] = NULL;
    }
    DdManager* manager = Cudd_Init(n, 0, CUDD_UNIQUE_SLOTS, CUDD_CACHE_SLOTS, 0);
    if( manager == NULL ) {
        printf("Error when initializing CUDD.\n");
        return 1;
    }
    for( int i = 1; i <= n; i++) {
        nodes[i - 1] = Cudd_bddIthVar(manager, i);
    }
    int NodeCnt = Cudd_ReadNodeCount(manager);
    int tmp = 0;
    DdNode * output = NULL;
    int * permutation = (int*)malloc(n  * sizeof(int));
    for(int i = 1; i <= n; i++) {
        permutation[i - 1] = i;
    }
    do {
        Cudd_ShuffleHeap(manager, permutation);
        tmp = Cudd_ReadNodeCount(manager);
        if( NodeCnt > tmp ) {
            NodeCnt = tmp;
        }
    } while(nextPermutation(permutation, n));
    printf("%d\n", tmp);
    printf("Test passed.\n");
    return 0;
}