#include <stdio.h>
#include "year_data.h"

void vider_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void afficher_stats_annee(int annee, StatsAnnee *st) {
    if (st == NULL) {
        return;
    }

    printf("\n--- Resultats %d ---\n", annee);
    printf("Accidents       : %u\n", st->accidents);
    printf("Indemnes        : %u\n", st->indemnes);
    printf("Morts           : %u\n", st->morts);
    printf("Blesses graves  : %u\n", st->blesses_graves);
    printf("Blesses legers  : %u\n", st->blesses_legers);
}

void afficher_extremes(TabAnnees *tab) {
    int annee_pire;
    int annee_meilleure;
    StatsAnnee st_pire;
    StatsAnnee st_meilleure;

    if (tab == NULL) {
        printf("Erreur : tableau non initialise.\n");
        return;
    }

    /* Critere 1 : par exemple le nombre de morts (a adapter selon ce que James met dans pire_annee / meilleure_annee) */
    annee_pire = pire_annee(tab, 1);
    annee_meilleure = meilleure_annee(tab, 1);

    if (annee_pire < ANNEE_DEBUT || annee_pire > ANNEE_FIN ||
        annee_meilleure < ANNEE_DEBUT || annee_meilleure > ANNEE_FIN) {
        printf("\nImpossible de determiner la meilleure et la pire annee.\n");
        return;
    }

    st_pire = calculer_stats_annee(tab, annee_pire);
    st_meilleure = calculer_stats_annee(tab, annee_meilleure);

    printf("\n=== MEILLEURE ET PIRE ANNEE ===\n");
    printf("Pire annee      : %d (%u morts, %u accidents)\n",
           annee_pire, st_pire.morts, st_pire.accidents);
    printf("Meilleure annee : %d (%u morts, %u accidents)\n",
           annee_meilleure, st_meilleure.morts, st_meilleure.accidents);
}

void lancer_menu_year(TabAnnees *tab) {
    int choix = -1;
    int annee;
    StatsAnnee stats;

    if (tab == NULL) {
        printf("Erreur : tableau non initialise.\n");
        return;
    }

    do {
        printf("\n=== MENU YEAR_DATA ===\n");
        printf("1. Consulter une annee (%d - %d)\n", ANNEE_DEBUT, ANNEE_FIN);
        printf("2. Meilleure et pire annee (Bonus)\n");
        printf("0. Quitter\n");
        printf("Choix : ");

        if (scanf("%d", &choix) != 1) {
            printf("Saisie invalide.\n");
            vider_buffer();
            choix = -1;
            continue;
        }
        vider_buffer();

        if (choix == 1) {
            printf("Annee (%d - %d) : ", ANNEE_DEBUT, ANNEE_FIN);
            if (scanf("%d", &annee) != 1) {
                printf("Saisie invalide.\n");
                vider_buffer();
                continue;
            }
            vider_buffer();

            if (annee < ANNEE_DEBUT || annee > ANNEE_FIN) {
                printf("Annee hors limites (%d - %d).\n", ANNEE_DEBUT, ANNEE_FIN);
                continue;
            }

            stats = calculer_stats_annee(tab, annee);
            afficher_stats_annee(annee, &stats);
        } else if (choix == 2) {
            afficher_extremes(tab);
        } else if (choix != 0) {
            printf("Choix invalide.\n");
        }
    } while (choix != 0);
}
