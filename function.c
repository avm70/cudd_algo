#include <stdio.h>
#include <stdlib.h>
#include "cudd.h"
#include "cuddInt.h"

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

void print_dd(DdManager *mng, DdNode * dd, int n, int pr) {
    printf("DdManager nodes: %ld\n", Cudd_ReadNodeCount(mng));
    printf("DdManager vars: %d\n", Cudd_ReadSize(mng));
    printf("DdManager reoderding: %d\n", Cudd_ReadReorderings(mng));
    printf("DdManager memory: %ld\n", Cudd_ReadMemoryInUse(mng));
    Cudd_PrintDebug(mng, dd, n, pr);
}

void write_dd(DdManager *mng, DdNode *dd, char *filename) {
    FILE *outputfile;
    outputfile = fopen(filename, "w");
    DdNode **ddnodearray = (DdNode**)malloc(sizeof(DdNode*));
    ddnodearray[0] = dd;
    Cudd_DumpDot(mng, 1, ddnodearray, NULL, NULL, outputfile);
    free(ddnodearray);
    fclose(outputfile);
}

void insert_dummy_pass_transistor(DdManager *mng, DdNode *dd) {

}


int main() {
    char filename[30];
    DdManager *mng;
    mng = Cudd_Init(0, 0, CUDD_UNIQUE_SLOTS, CUDD_CACHE_SLOTS, 0);
    DdNode *bdd, *var, *tmp_neg, *tmp;
    bdd = Cudd_ReadOne(mng);
    Cudd_Ref(bdd);
    DdNode* nodes[4];
    for(int i = 0; i < 4; i++) {
        nodes[i] = Cudd_bddIthVar(mng, i);
        tmp_neg = Cudd_Not(nodes[i]);
        tmp = Cudd_bddAnd(mng, tmp_neg, bdd);
        Cudd_Ref(tmp);
        Cudd_RecursiveDeref(mng, bdd);
        bdd = tmp;
    }
    int NodeCnt = Cudd_ReadNodeCount(mng);
    int tmp_nodecnt = 0;
    int n = 4;
    int * permutation = (int*)malloc(n  * sizeof(int));
    for(int i = 1; i <= n; i++) {
        permutation[i - 1] = i;
    }
    do {
        Cudd_ShuffleHeap(mng, permutation);
        tmp_nodecnt = Cudd_ReadNodeCount(mng);
        if( NodeCnt > tmp_nodecnt ) {
            NodeCnt = tmp_nodecnt;
            bdd = Cudd_ReadOne(mng);
        }
    } while(nextPermutation(permutation, n));
    tmp = bdd;
    Cudd_PrintDebug(mng, bdd, 2, 4);
    //Cudd_PrintInfo(mng,)
    printf("TEST\n");
    printf("index %u\n", tmp->index);
    if( tmp->next == NULL ) {
        printf("next null \n");
    }
    tmp = tmp->next;
    printf("index %u\n", tmp->index);


    
    //bdd = Cudd_BddToAdd(mng, bdd);
    //print_dd(mng, bdd, 2, 4);
    //sprintf(filename, "./graph1.dot");
    //write_dd(mng, bdd, filename);
    Cudd_Quit(mng);
    return 0;
}