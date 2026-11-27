#ifndef YEAR_INIT_H
#define YEAR_INIT_H

#define ANNEE_DEBUT 2005
#define ANNEE_FIN 2024
#define NB_ANNEES 20

typedef struct {
    int annee;
    unsigned int id_collision;
    int gravite;
} DonneeLigne;

typedef struct {
    unsigned int accidents;
    unsigned int morts;
    unsigned int blesses_graves;
    unsigned int blesses_legers;
    unsigned int indemnes;
    unsigned int dernier_id;
    unsigned char a_un_accident;
} StatsAnnee;

typedef struct {
    StatsAnnee annees[NB_ANNEES];
} TabAnnees;

int annee_idx(int annee);

void init_tab(TabAnnees *tab);

void ajout_ligne(TabAnnees *tab, const DonneeLigne *donnee);

#endif
