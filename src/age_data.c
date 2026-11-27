#include <stdio.h>
#include "age_data.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MaillonAge {        //structure representant l'age le type de la personne impliqué et le genre 
    int age;
    int stats[4][4]; // [type_usager] 1 = conducteur 2 =passager 3=pieton 0 = pas reconnu||     [genre] 1= masculin 2=feminin   0 = pas reconnu 
    struct MaillonAge *suivant;
} MaillonAge, *pListeAge;




pListeAge Init(int age){    // initialisation du maillon //
pListeAge nouveau = malloc(sizeof(MaillonAge));
if(nouveau==NULL){
fprintf(stderr, "Erreur d'allocation memoire\n");
exit(1);
}
nouveau->age=age;
nouveau->suivant= NULL;
for (int i =0; i<3;i++){
for (int j =0; j<2;j++){
nouveau->stats[i][j]=0;
}
}
return nouveau;
}



int indice_type_usager(int type_user) {
    if (type >= 1 ype <= 3) {
        return user_type; // 1,2 ou 3 sinon pas reconnu
    }
    return 0; // le reste n'est pas reconnu 
}


int indice_genre_usager(int genre_user) {
    if (type == 1 || type == 2) {
        return user_type; // 1 ou  2 restent directement sur le bon indice
    }
    return 0; // le reste n'est pas reconnu 
}


























