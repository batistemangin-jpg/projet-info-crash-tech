#ifndef YEAR_DATA_H
#define YEAR_DATA_H

#define ANNEE_DEBUT 2005
#define ANNEE_FIN 2024
#define NB_ANNEES 20

typedef struct DonneeLigne{
    int annee;
    unsigned int id_collision;
    int gravite;
} DonneeLigne;

typedef struct StatsAnnee{
    unsigned int accidents;
    unsigned int morts;
    unsigned int blesses_graves;
    unsigned int blesses_legers;
    unsigned int indemnes;
    unsigned int dernier_id;
    unsigned char a_un_accident;
} StatsAnnee;


typedef struct TabAnnees{
    StatsAnnee annees[NB_ANNEES];
} TabAnnees;

int annee_idx(int annee);
void init_tab(TabAnnees *tab);
void ajout_ligne(TabAnnees *tab, DonneeLigne *donnee);

StatsAnnee calculer_stats_annee(TabAnnees *tab, int annee);
unsigned int total_victimes(StatsAnnee *st);
int pire_annee(TabAnnees *tab, int critere);
int meilleure_annee(TabAnnees *tab, int critere);

void afficher_stats_annee(int annee, StatsAnnee *st);
void afficher_extremes(TabAnnees *tab);
void lancer_menu_year(TabAnnees *tab);

#endif
