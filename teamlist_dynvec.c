#include "teamlist.h"
#include <stdlib.h>

// Implementação do TAD TeamList com VETOR DINÂMICO.

struct teamlist {
    int n;
    int n_max;
    Team **times;
};

TeamList *tl_create(void) {
    TeamList *tl = (TeamList *) malloc(sizeof(TeamList));
    if (tl == NULL) {
        return NULL;
    }
    tl->n = 0;
    tl->n_max = 3; // Pode começar com um valor pequeno, ex: 3 ou 10
    tl->times = (Team **) malloc(tl->n_max * sizeof(Team *));
    if (tl->times == NULL) {
        free(tl);
        return NULL;
    }
    return tl;
}

void tl_append(TeamList *tl, Team *t) {
    if (tl == NULL) return;

    // Correção 1: usar tl_size(tl) ou comparar tl->n diretamente com tl->n_max
    if (tl->n >= tl->n_max) {
        tl->n_max *= 2;
        Team **aux = (Team **) realloc(tl->times, tl->n_max * sizeof(Team *));
        if (aux == NULL) {
            return; // Falha de alocação
        }
        // Correção 2: atualizar o ponteiro do vetor com o endereço retornado pelo realloc
        tl->times = aux;
    }
    tl->times[tl->n++] = t;
}

int tl_size(TeamList *tl) {
    if (tl == NULL) {
        return 0; // O ideal é retornar 0 se a lista for nula
    }
    return tl->n;
}

Team *tl_get(TeamList *tl, int i) {
    if (tl == NULL || i < 0 || i >= tl->n) {
        return NULL;
    }
    return tl->times[i];
}

void tl_free(TeamList *tl) {
    if (tl == NULL) {
        return;
    }
    for (int i = 0; i < tl->n; i++) {
        team_free(tl->times[i]);
    }
    free(tl->times);
    free(tl);
}