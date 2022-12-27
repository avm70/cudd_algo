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
    DdManager *gbm; /* Global BDD manager. */
    gbm = Cudd_Init(0,0,CUDD_UNIQUE_SLOTS,CUDD_CACHE_SLOTS,0); /* Initialize a new BDD manager. */
    DdNode *bdd, *x1, *x2;
    x1 = Cudd_bddNewVar(gbm); /*Create a new BDD variable x1*/
    x2 = Cudd_bddNewVar(gbm); /*Create a new BDD variable x2*/
    bdd = Cudd_bddAnd(gbm, x1, x2); /*Perform AND Boolean operation*/
    Cudd_Ref(bdd);          /*Update the reference count for the node just created.*/
    bdd = Cudd_BddToAdd(gbm, bdd); /*Convert BDD to ADD for display purpose*/
    DdNode *test = Cudd_addNewVarAtLevel(gbm, 1);
    if( test != NULL ) {
        printf("add new var\n");
    }
    DdNode *T = Cudd_T(test);
    T = Cudd_ReadOne(gbm);
    DdNode *E = Cudd_E(test);
    E = Cudd_ReadZero(gbm);
    print_dd (gbm, bdd, 2,4);   /*Print the dd to standard output*/
    sprintf(filename, "./graph2.dot"); /*Write .dot filename to a string*/
    write_dd(gbm, bdd, filename);  /*Write the resulting cascade dd to a file*/
    FILE *outputfile;
    outputfile = fopen("./info.txt", "w");
    Cudd_PrintInfo(gbm, outputfile);
    fclose(outputfile);
    Cudd_Quit(gbm);
    return 0;
}