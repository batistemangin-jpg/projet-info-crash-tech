#include <stdio.h>
#include "year_data.h"

int annee_idx(int annee) {
    if (annee < ANNEE_DEBUT || annee > ANNEE_FIN) {
        return -1;
    }
    return annee - ANNEE_DEBUT;
}

void init_tab(TabAnnees *tab) {
    int i;

    if (tab == NULL) {
        return;
    }

    for (i = 0; i < NB_ANNEES; i++) {
        tab->annees[i].accidents = 0;
        tab->annees[i].morts = 0;
        tab->annees[i].blesses_graves = 0;
        tab->annees[i].blesses_legers = 0;
        tab->annees[i].indemnes = 0;
        tab->annees[i].dernier_id = 0;
        tab->annees[i].a_un_accident = 0;
    }
}

void ajout_ligne(TabAnnees *tab, DonneeLigne *donnee) {
    int indice;
    StatsAnnee *stats;

    if (tab == NULL || donnee == NULL) {
        return;
    }

    indice = annee_idx(donnee->annee);
    if (indice < 0) {
        return;
    }

    stats = &tab->annees[indice];

    if (!stats->a_un_accident || donnee->id_collision != stats->dernier_id) {
        stats->accidents++;
        stats->dernier_id = donnee->id_collision;
        stats->a_un_accident = 1;
    }

    if (donnee->gravite == 2) {
        stats->morts++;
    } else if (donnee->gravite == 3) {
        stats->blesses_graves++;
    } else if (donnee->gravite == 4) {
        stats->blesses_legers++;
    } else if (donnee->gravite == 1) {
        stats->indemnes++;
    }
}
