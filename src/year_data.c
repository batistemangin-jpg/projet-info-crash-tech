#include <stdio.h>
#include "year_data.h"

void lancer_menu_year(const YearData tab_annees[]) {
    int choix = -1;
    int annee = 0;
    int c = 0;
    YearStats stats;

    if (tab_year == NULL) {
        printf("Erreur : le tableau des annees n'est pas initialise.\n");
        return;
    }

    do {
        printf("\n=== MENU YEAR_DATA ===\n");
        printf("1. Consulter une annee (2005 - 2024)\n");
        printf("2. Afficher la meilleure et la pire annee (Bonus)\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");

        if (scanf("%d", &choix) != 1) {
            printf("Saisie invalide, entrez un chiffre.\n");
            while ((c = getchar()) != '\n' && c != EOF) {
            }
            choix = -1;
        } else {
            while ((c = getchar()) != '\n' && c != EOF) {
            }

            if (choix == 1) {
                printf("Entrez une annee (entre 2005 et 2024) : ");
                if (scanf("%d", &annee) != 1) {
                    printf("Saisie invalide, entrez une annee en chiffres.\n");
                    while ((c = getchar()) != '\n' && c != EOF) {
                    }
                } else {
                    while ((c = getchar()) != '\n' && c != EOF) {
                    }

                    if (annee < 2005 || annee > 2024) {
                        printf("Année non valide  (2005 - 2024).\n");
                    } else {
                        stats = calculer_stats_annee(tab_annees, annee);
                        printf("\n--- Resultats pour %d ---\n", annee);
                        printf("Accidents : %d\n", stats.nb_accidents);
                        printf("Indemnes  : %d\n", stats.indemnes);
                        printf("Tues      : %d\n", stats.tues);
                        printf("Blesses graves : %d\n", stats.blesses_graves);
                        printf("Blesses legers : %d\n", stats.blesses_legers);
                    }
                }
            } else if (choix == 2) {
                // 
            } else if (choix == 0) {
                printf("Retour au menu principal.\n");
            } else {
                printf("Choix invalide.\n");
            }
        }
    } while (choix != 0);
}
