#include <stdio.h>
#include <stdlib.h>
#include <cudd.h>

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

int main() {
    char filename[30];
    DdManager *mng;
    mng = Cudd_Init(0, 0, CUDD_UNIQUE_SLOTS, CUDD_CACHE_SLOTS, 0);
    DdNode *bdd, *var, *tmp_neg, *tmp;
    bdd = Cudd_ReadOne(mng);
    Cudd_Ref(bdd);
    for(int i = 0; i < 4; i++) {
        printf("1\n");
        var = Cudd_addIthVar(mng, i);
        printf("2\n");
        tmp_neg = Cudd_Not(var);
        printf("3\n");
        tmp = Cudd_bddAnd(mng, tmp_neg, bdd);
        printf("4\n");
        Cudd_Ref(tmp);
        printf("5\n");
        Cudd_RecursiveDeref(mng, bdd);
        printf("6\n");
        bdd = tmp;
    }
    bdd = Cudd_BddToAdd(mng, bdd);
    sprintf(filename, "./graph.dot");
    //write_dd(mng, bdd, filename);
    Cudd_Quit(mng);
    return 0;
}