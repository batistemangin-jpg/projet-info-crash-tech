#include <stdio.h>
#include "age_data.h"
#include "utils.h"

#define MAX_AGE_STEP 120

static const char *filter_user_name(int f)
{
    return (f == 0) ? "tous" : (f == 1) ? "conducteurs" : (f == 2) ? "passagers" : "pietons";
}

static const char *filter_gender_name(int f)
{
    return (f == 0) ? "tous" : (f == 1) ? "hommes" : "femmes";
}

void run_age_data(const char *path)
{
    long choice = 0;
    long value;
    int filter_user = 0;
    int filter_gender = 0;
    int step = 1;

    (void)path; /* pas encore utilise : le fichier sera lu plus tard */
    do {
        printf("\n===== MODE AGE_DATA =====\n");
        printf("Filtres : type = %s | genre = %s | pas d'age = %d an(s)\n",
               filter_user_name(filter_user), filter_gender_name(filter_gender), step);
        printf("1. Pyramide des ages par genre\n");
        printf("2. Repartition par type de personne\n");
        printf("3. Filtre type (0 tous, 1 conducteur, 2 passager, 3 pieton)\n");
        printf("4. Filtre genre (0 tous, 1 hommes, 2 femmes)\n");
        printf("5. Pas d'age (1 = chaque age, 10 = tranches de 10 ans...)\n");
        printf("0. Quitter ce mode\n");
        if (!read_long_in_range("Votre choix : ", 0, 5, &choice)) {
            break;
        }
        if (choice == 1) {
            printf("[A venir] pyramide des ages par genre.\n");
        } else if (choice == 2) {
            printf("[A venir] repartition par type de personne.\n");
        } else if (choice == 3) {
            if (!read_long_in_range("Filtre type (0-3) : ", 0, 3, &value)) {
                break;
            }
            filter_user = (int)value;
        } else if (choice == 4) {
            if (!read_long_in_range("Filtre genre (0-2) : ", 0, 2, &value)) {
                break;
            }
            filter_gender = (int)value;
        } else if (choice == 5) {
            if (!read_long_in_range("Pas d'age (1-120) : ", 1, MAX_AGE_STEP, &value)) {
                break;
            }
            step = (int)value;
        }
    } while (choice != 0);
}
