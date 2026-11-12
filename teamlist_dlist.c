#include "teamlist.h"
#include <stdlib.h>

// Implementação do TAD TeamList com LISTA DUPLAMENTE ENCADEADA.

// TODO: defina aqui a struct do nó (um Team* e os ponteiros next e prev)
// e os campos de "struct teamlist" (primeiro nó, último nó e quantidade)
typedef struct node{
    Team* t;
    ListNode * next;
    ListNode * prev;

}ListNode;


struct teamlist {
    int qnt;
    ListNode * first;
    ListNode * last;
    
};

TeamList *tl_create(void) {
    TeamList * tl = (TeamList *)malloc(sizeof(TeamList));
    tl->qnt = 0;
    tl->first = NULL;
    tl->last = NULL;
}

void tl_append(TeamList *tl, Team *t) {
    ListNode *time = (ListNode*)malloc(sizeof(ListNode));
    time->t = t;
    time->next = NULL;
    time->prev =  tl->last;
    tl->last = time;
    tl->qnt++;
}

int tl_size(TeamList *tl) {
    if (tl == NULL) {
        return -1;
    }
    return tl->qnt;
}

Team *tl_get(TeamList *tl, int i) {
    
    int cont = 1;
    ListNode *p = tl->first;
    while((p!=NULL) && cont<i){
       p = p->next;
       cont++;
    }    
    
    return p;
}

void tl_free(TeamList *tl) {
    ListNode *p = tl->first;
    ListNode *h;
    while (p!=NULL)
    {
        h = p->next;
        free(p);
        p = h;
    }
    free(tl);
}
