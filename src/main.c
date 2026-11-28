#include <stdlib.h>
#include <stdio.h>

void vider_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { 
    }
}


int main(){
  int choix = 0;
    printf("************* Projet Crash-tech *************\n");
        printf("veuillez choisir le mode\n");
        printf("1. Year_Data\n");
        printf("2. Age_Data\n");
        printf("3. Crash_Data\n");
    do {
        printf("Choix (1, 2 ou 3) : ");
        if (scanf("%d", &choix) != 1) {
            printf("Saisie invalide, entrez un chiffre.\n");
            vider_buffer();
            choix = 0;
        } else {
            vider_buffer();
            if (choix < 1 || choix > 3) {
                printf("Choix invalide, veuillez saisir 1, 2 ou 3.\n");
            }
        }
    } while (choix < 1 || choix > 3);
     if (choix == 1) {
        printf("Nom du fichier de donnees (.csv) : ");
        if (scanf("%255s", fichier) != 1) {
            printf("Erreur : nom de fichier non lu.\n");
            return 1;
        }
        vider_buffer();
        init_tab(&tab);
        if (lire_fichier_year(fichier, &tab) != 0) {
            return 1;
        }
        lancer_menu_year(&tab);
    } else {
        printf("Ce mode n'est pas encore disponible.\n");
    }
    return 0;
}
        
