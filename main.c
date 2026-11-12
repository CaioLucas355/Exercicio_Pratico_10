#include "team.h"
#include "teamlist.h"
#include <stdio.h>
#include <stdlib.h>

// Este arquivo não pode depender da implementação escolhida em config.mk:
// use apenas as funções de team.h e teamlist.h.

int main(void) {
    TeamList *tl = tl_create();

    FILE *f = fopen("teams.csv","rt");
    if(f == NULL){
        return 1;
    }
    int id;
    char name[50];
    while(fscanf(f, "%d,%49[^\n]", &id, name)== 2){
        Team *t = team_create(id,name);
        tl_append(tl, t);
        
    }
    fclose(f);
    printf("ID  Time            V   E   D   GM  GS  S   PG\n");
    for(int i = 0; i < tl_size(tl); i++){
        Team * t = tl_get(tl,i);
        int goals_sald = team_goals_scored(t) - team_goals_conceded(t);
        int points = 3 * team_wins(t) + team_draws(t);
        printf("%-3d %-15s", team_id(t), team_name(t));

        printf(" %-3d %-3d %-3d %-3d %-3d %-3d %-3d\n",
               team_wins(t), team_draws(t), team_losses(t),
               team_goals_scored(t), team_goals_conceded(t),
               goals_sald, points);
    }

    
    // TODO: imprima a tabela de classificação (ID, Time, V, E, D, GM, GS, S,
    // PG) na ordem em que os times foram lidos, usando tl_size e tl_get

    tl_free(tl);
    return 0;
}
