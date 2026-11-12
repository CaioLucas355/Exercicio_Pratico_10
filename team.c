#include "team.h"
#include <stdlib.h>
#include <string.h>

// TODO: defina aqui os campos de "struct team"
struct team {
    int id;
    char *name;
    int wins;
    int draws;
    int losses;
    int goals_scored;
    int goals_conceded;
};

Team *team_create(int id, const char *name) {
    Team * time = malloc(sizeof(Team));

    if (time == NULL) {
        return NULL;
    }

    time->id = id;
    time->name = malloc(strlen(name) + 1);// aloco um vetor do tamanho do nome dotime mais 1 espaço para o \0
    
    if (time->name == NULL) {
        return NULL;
    }

    strcpy(time->name,name);

    time->wins = 0;
    time->draws = 0;
    time->losses = 0;
    time->goals_scored = 0;
    time->goals_conceded = 0;
    return time;
}

int team_id(Team *t) {
    if (t == NULL) {
        return -1;
    }
    return t->id;
}

const char *team_name(Team *t) {
    if (t == NULL) {
        return NULL;
    }
    return t->name;
}

int team_wins(Team *t) {
    if (t == NULL) {
        return -1;
    }
    return t->wins;
}

int team_draws(Team *t) {
    if (t == NULL) {
        return -1;
    }
    return t->draws;
}

int team_losses(Team *t) {
    if (t == NULL) {
        return -1;
    }
    return t->losses;
}

int team_goals_scored(Team *t) {
    if (t == NULL) {
        return -1;
    }
    return t->goals_scored;
}

int team_goals_conceded(Team *t) {
    if (t == NULL) {
        return -1;
    }
    return t->goals_conceded;
}

void team_free(Team *t) {
    if (t == NULL) {
        return;
    }
    free(t->name);
    free(t);
    
}