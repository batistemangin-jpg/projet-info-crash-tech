#include <stdio.h>
#include "age_data.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MaillonAge {
    int age;
    int stats[3][2]; // [type_usager] 0 = conducteur 1 =passager 2=pieton l'autre [genre] 0= masculin 1=feminin //
    struct MaillonAge *suivant;
} MaillonAge, *pListeAge;

pListeAge Init(int age){
plisteAge nouveau = malloc(sizeof(MaillonAge));
if(nouveau==NULL){
fprintf(stderr, "Erreur d'allocation memoire\n");
exit(1);
}

nouveau->age=age;
nouveau->suivant= NULL;

for (int i =0; i<3;i++){
for (int j =0; j<2;j++){
nouveau->stat[i][j]=0;
}
}
return nouveau;
}
