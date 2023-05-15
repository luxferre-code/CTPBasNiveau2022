#include <stdio.h>
#include <stdlib.h>

// Définition des structures
//Exercice 2
typedef struct bouquet_t {
    int roses, tulipes, pivoines;
} bouquet_t;

// Définition des fonctions
// Exercice 1
void exemple_pointeur(void);
void exemple_tableau(char* tableau, int taille);
void caractere_suivant(char* pt_car);
int taille_chaine_de_caracteres(char* chaine);
void affiche_tableau(int* tableau, int taille);
// Exercice 2
bouquet_t* nouveau_bouquet(void);
void initialise_bouquet(bouquet_t* bouquet, int nb_roses, int nb_tulipes, int nb_pivoines);
void affiche_bouquet(bouquet_t* bouquet);
void libere_bouquet(bouquet_t* bouquet);
bouquet_t* combine_bouquets(bouquet_t* bouquet_1, bouquet_t* bouquet_2);

int main() {
    // Exercice 1
    exemple_pointeur();
    char tab[] = "abc";
    exemple_tableau(tab, 3);
    char car = 'a';
    caractere_suivant(&car);
    printf("Le caractère suivant est : %c\n", car);
    char chaine[] = "Bonjour";
    printf("La taille de la chaine de caractères est : %d\n", taille_chaine_de_caracteres(chaine));
    int tableau[] = {1, 2, 3, 4, 5};
    affiche_tableau(tableau, 5);

    // Exercice 2


    return 0;
}

// Exercice 1

void exemple_pointeur(void) {
    int ma_variable;
    ma_variable = 5;
    printf("Le contenu de ma variable : %d\n", ma_variable);
    printf("L'adresse memoire de ma variable : %p\n", &ma_variable); // & -> permet de récupérer l'adresse mémoire d'une variable
    int* mon_pointeur = &ma_variable;
    printf("L'adresse memoire de mon pointeur : %p\n", mon_pointeur);
    printf("Le contenu de mon pointeur : %d\n", *mon_pointeur); // * -> permet de récupérer le contenu d'une adresse mémoire si on a un pointeur
}

void exemple_tableau(char* tableau, int taille) {
    if(taille < 3) { return; }
    printf("La deuxième case du tableau se situe à l’adresse %p\n", tableau + 2);
    printf("Elle contient : %c\n", *(tableau + 2)); // *(tableau + 2) -> permet de récupérer le contenu de la case 2 du tableau
}

void caractere_suivant(char* pt_car) {
    *pt_car = *pt_car + 1; // *pt_car -> permet de récupérer le contenu de l'adresse mémoire pointée par pt_car (effet de bord)
}

int taille_chaine_de_caracteres(char* chaine) {
    int taille = 0;
    while(*(chaine + taille) != '\0') { // *(chaine + taille) -> permet de récupérer le contenu de la case taille du tableau chaine dynamiquement
        taille++;
    }
    return taille;
}

void affiche_tableau(int* tableau, int taille) {
    for(int i = 0; i < taille; i++) {
        printf("%d", tableau[i]);
        if (i < taille - 1) { // Si on est pas à la dernière case du tableau on affiche un / pour séparer les cases
            printf(" / ");
        }
    }
    printf("\n");
}

// Exercice 2

bouquet_t* nouveau_bouquet(void) {
    bouquet_t* bouquet = malloc(sizeof(bouquet_t)); // malloc -> permet d'allouer de la mémoire dynamiquement
    return bouquet;
}

void initialise_bouquet(bouquet_t* bouquet, int nb_roses, int nb_tulipes, int nb_pivoines) {
    bouquet->roses = nb_roses;
    bouquet->tulipes = nb_tulipes;
    bouquet->pivoines = nb_pivoines;
}

void affiche_bouquet(bouquet_t* bouquet) {
    printf("%d rose", bouquet->roses);
    if(bouquet->roses > 1) {
        printf("s");
    }
    printf(", %d tulipe", bouquet->tulipes);
    if(bouquet->tulipes > 1) {
        printf("s");
    }
    printf(" et %d pivoine", bouquet->pivoines);
    if(bouquet->pivoines > 1) {
        printf("s");
    }
    printf("\n");
}

void libere_bouquet(bouquet_t* bouquet) {
    free(bouquet); // free -> permet de libérer la mémoire allouée dynamiquement
}

bouquet_t* combine_bouquets(bouquet_t* bouquet_1, bouquet_t* bouquet_2) {
    bouquet_t* bouquet = nouveau_bouquet();
    initialise_bouquet(bouquet, bouquet_1->roses + bouquet_2->roses, bouquet_1->tulipes + bouquet_2->tulipes, bouquet_1->pivoines + bouquet_2->pivoines);
    free(bouquet_1);
    free(bouquet_2);
    return bouquet;
}