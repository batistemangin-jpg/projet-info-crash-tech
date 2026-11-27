#include <stdio.h>
#include "year_data.h"

StatsAnnee calculer_stats_annee(TabAnnees *tab, int annee) {
    StatsAnnee stats_vide;
    int indice;
    stats_vide.accidents = 0;
    stats_vide.morts = 0;
    stats_vide.blesses_graves = 0;
    stats_vide.blesses_legers = 0;
    stats_vide.indemnes = 0;
    stats_vide.dernier_id = 0;
    stats_vide.a_un_accident = 0;
    if (tab == NULL) {
        return stats_vide;
    }
    indice = annee_idx(annee);
    if (indice < 0) {
        return stats_vide;
    }
    return tab->annees[indice];
}

unsigned int total_victimes(StatsAnnee *st) {
    if (st == NULL) {
        return 0;
    }
    return st->morts + st->blesses_graves + st->blesses_legers + st->indemnes;
}

unsigned int valeur_critere(StatsAnnee *st, int critere) {
    if (st == NULL) {
        return 0;
    }
    if (critere == 2) {
        return st->accidents;
    } else if (critere == 3) {
        return total_victimes(st);
    }
    return st->morts;
}

int pire_annee(TabAnnees *tab, int critere) {
    int i;
    int annee_max;
    unsigned int val_max;
    unsigned int val_courante;
    int a_des_donnees;
    if (tab == NULL) {
        return -1;
    }
    annee_max = -1;
    val_max = 0;
    a_des_donnees = 0;
    for (i = 0; i < NB_ANNEES; i++) {
        if (tab->annees[i].accidents > 0 || total_victimes(&tab->annees[i]) > 0) {
            val_courante = valeur_critere(&tab->annees[i], critere);
            if (!a_des_donnees || val_courante > val_max) {
                val_max = val_courante;
                annee_max = ANNEE_DEBUT + i;
                a_des_donnees = 1;
            }
        }
    }
    return annee_max;
}

int meilleure_annee(TabAnnees *tab, int critere) {
    int i;
    int annee_min;
    unsigned int val_min;
    unsigned int val_courante;
    int a_des_donnees;
    if (tab == NULL) {
        return -1;
    }
    annee_min = -1;
    val_min = 0;
    a_des_donnees = 0;
    for (i = 0; i < NB_ANNEES; i++) {
        if (tab->annees[i].accidents > 0 || total_victimes(&tab->annees[i]) > 0) {
            val_courante = valeur_critere(&tab->annees[i], critere);
            if (!a_des_donnees || val_courante < val_min) {
                val_min = val_courante;
                annee_min = ANNEE_DEBUT + i;
                a_des_donnees = 1;
            }
        }
    }
    return annee_min;
}
