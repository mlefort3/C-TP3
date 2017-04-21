//
//  ex2tp3.c
//  
//
//  Created by Maxence Lefort on 15/03/2017.
//
//
#include <stdlib.h>
#define taille 20

typedef struct Personne Personne;
struct Personne {
    char nom[32];
    char numero[16];
};

typedef struct carnet carnet;
struct carnet {
    int compteur;
    Personne tableau[taille];
};

Personne setPersonne(char nom[32], char numero[16]) {
    Personne perso;
    strcpy(perso.nom, nom);
    strcpy(perso.numero, numero);
    return perso;
}

Personne getPersonne(char nomCherche[], char numeroCherche[], carnet carn) {
    for (int i = 0;i<taille;i++) {
        if ((strcmp(nomCherche,carn.tableau[i].nom) == 0) & (strcmp(numeroCherche,carn.tableau[i].numero) == 0)) {
            return carn.tableau[i];
        }
    }
    printf("\nPas de personne trouvée.\n");
}

carnet addPersonne(carnet carn, Personne perso) {
    carn.tableau[carn.compteur] = perso;
    carn.compteur++;
    return carn;
}

void affichePersonne(Personne pA) {
    printf("\nLe nom de la personne est %s et son numéro est %s.\n",pA.nom,pA.numero);
}

void afficheCarnet(carnet carn) {
    printf("\nIl y a %d personnes dans le carnet. Les voici :\n",carn.compteur);
    for (int i=0;i<carn.compteur;i++) {
        printf("    - Personne %d : %s, %s\n",i+1,carn.tableau[i].nom,carn.tableau[i].numero);
    }
}

int afficheMenu() {
    printf("\n---------- MENU ----------\n");
    printf("\nVoici les différentes options :\n");
    printf("    1 - Ajouter une personne au carnet\n");
    printf("    2 - Afficher le carnet\n");
    printf("    3 - Quitter\n");
    printf("Rentrez votre choix ici ... ");
    int choix;
    scanf("%d",&choix);
    return choix;
}

int main() {
    //Personne pA = setPersonne("PJK","01");
    //Personne pB = setPersonne("Prard","02");
    //carnet carnet;
    //carnet = addPersonne(carnet,pA);
    //carnet = addPersonne(carnet,pB);
    //affichePersonne(carnet.tableau[0]);
    //affichePersonne(getPersonne("PJK","01",carnet));
    //afficheCarnet(carnet);
    carnet carnet;
    int choix = 0;
    while (choix!=3) {
        choix = afficheMenu();
        if (choix==1) {
            char nom[32];
            char numero[16];
            printf("\nRentrez le nom de la personne : \n");
            scanf("%s",&nom);
            printf("\nRentrez le numéro de la personne : \n");
            scanf("%s",&numero);
            Personne perso = setPersonne(nom,numero);
            carnet = addPersonne(carnet,perso);
        }
        if (choix==2) {
            afficheCarnet(carnet);
        }
    }
    exit(EXIT_SUCCESS);
}
