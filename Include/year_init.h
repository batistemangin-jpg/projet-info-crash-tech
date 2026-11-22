#ifndef YEAR_INIT_H
#define YEAR_INIT_H

/* Plage d'etude : 20 annees de 2005 a 2024 inclus */
#define ANNEE_DEBUT 2005
#define ANNEE_FIN 2024
#define NB_ANNEES 20

/* Donnees utiles extraites d'une ligne du CSV pour YEAR_DATA */
typedef struct {
    int annee;
    unsigned int id_collision;
    int gravite;
} DonneeLigne;

/* Compteurs statistiques cumules pour une annee */
typedef struct {
    unsigned int accidents;
    unsigned int morts;
    unsigned int blesses_graves;
    unsigned int blesses_legers;
    unsigned int indemnes;
    unsigned int dernier_id;
    unsigned char a_un_accident; /* 0 tant qu'aucun accident n'a ete lu pour cette annee */
} StatsAnnee;

/* Tableau statique de 20 cases (0 = 2005, 19 = 2024) */
typedef struct {
    StatsAnnee annees[NB_ANNEES];
} TabAnnees;

/* Convertit une annee (2005..2024) en indice (0..19), ou -1 si hors plage */
int annee_idx(int annee);

/* Initialise toutes les cases du tableau a 0 */
void init_tab(TabAnnees *tab);

/* Met a jour les compteurs de l'annee correspondant a la ligne */
void ajout_ligne(TabAnnees *tab, const DonneeLigne *donnee);

#endif
