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

int main() {
    DdManager *mng;
    int n = 4;
    int table[1 << 4];
    table[0] = 1;
    table[1] = 1;
    table[2] = 0;
    table[3] = 1;
    table[4] = 0;
    table[5] = 1;
    table[6] = 1;
    table[7] = 0;
    table[8] = 0;
    table[9] = 0;
    table[10] = 0;
    table[11] = 0;
    table[12] = 0;
    table[13] = 1;
    table[14] = 1;
    table[15] = 0;
    DdNode* nodes[n];
    mng = Cudd_Init(0, 0, CUDD_UNIQUE_SLOTS, CUDD_CACHE_SLOTS, 0);
    DdNode *bdd, *var, *tmp_neg, *tmp, *complete;
    //bdd = Cudd_ReadOne(mng);
    //complete = Cudd_ReadOne(mng);
    //Cudd_Ref(bdd);
    for(int i = 0; i < n; i++) {
        nodes[i] = Cudd_bddIthVar(mng, i);
    }
    tmp = Cudd_bddAnd(mng, Cudd_Not(nodes[0]), Cudd_Not(nodes[1]));
    Cudd_Ref(tmp);
    tmp = Cudd_bddAnd(mng, tmp, Cudd_Not(nodes[2]));
    Cudd_Ref(tmp);
    tmp = Cudd_bddAnd(mng, tmp, Cudd_Not(nodes[3]));
    Cudd_Ref(tmp);
    bdd = Cudd_bddAnd(mng, Cudd_Not(nodes[0]), Cudd_Not(nodes[1]));
    Cudd_Ref(bdd);
    bdd = Cudd_bddAnd(mng, bdd, Cudd_Not(nodes[2]));
    Cudd_Ref(bdd);
    bdd = Cudd_bddAnd(mng, bdd, nodes[3]);
    Cudd_Ref(bdd);
    complete = Cudd_bddOr(mng, tmp, bdd);
    Cudd_Ref(complete);

    /*for(int i = 0; i < (1 << n); i++) {
        if(table[i]) {
            for(int j = 0; j < n; j++) {
                if((i & ( 1 << (n - j - 1))) == 0) {
                    tmp_neg = Cudd_Not(nodes[j]);        
                } else {
                    tmp_neg = nodes[j];
                }
                tmp = Cudd_bddAnd(mng, tmp_neg, bdd);
                Cudd_Ref(tmp);
                Cudd_RecursiveDeref(mng, bdd);
                bdd = tmp;
            }
            complete = Cudd_bddOr(mng, bdd, complete);
            Cudd_Ref(complete);
            Cudd_RecursiveDeref(mng, complete);
        }
    }*/
    complete = Cudd_BddToAdd(mng, complete);
    print_dd(mng, complete, 4, 4);
    Cudd_Quit(mng);
    return 0;
}