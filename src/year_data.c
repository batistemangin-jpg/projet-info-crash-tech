#include <stdio.h>
#include "year_data.h"

static void vider_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void lancer_menu_year(const YearData tab_annees[]) {
    int choix = -1;
    int annee;
    YearStats stats;

    if (tab_annees == NULL) {
        printf("Erreur : tableau non initialise.\n");
        return;
    }

    do {
        printf("\n=== MENU YEAR_DATA ===\n");
        printf("1. Consulter une annee (2005 - 2024)\n");
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
            printf("Annee (2005 - 2024) : ");
            if (scanf("%d", &annee) != 1) {
                printf("Saisie invalide.\n");
                vider_buffer();
                continue;
            }
            vider_buffer();

            if (annee < ANNEE_MIN || annee > ANNEE_MAX) {
                printf("Annee hors limites (%d - %d).\n", ANNEE_MIN, ANNEE_MAX);
                continue;
            }

            stats = calculer_stats_annee(tab_annees, annee);
            printf("\n--- Resultats %d ---\n", annee);
            printf("Accidents       : %d\n", stats.nb_accidents);
            printf("Indemnes        : %d\n", stats.indemnes);
            printf("Tues            : %d\n", stats.tues);
            printf("Blesses graves  : %d\n", stats.blesses_graves);
            printf("Blesses legers  : %d\n", stats.blesses_legers);
        } else if (choix == 2) {
            /* A completer pour le bonus meilleure/pire annee */
            printf("Option bonus non encore implementee.\n");
        } else if (choix != 0) {
            printf("Choix invalide.\n");
        }
    } while (choix != 0);
}
