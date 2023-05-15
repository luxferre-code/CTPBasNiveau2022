#include <stdio.h>

// Définition des fonctions
void exemple_pointeur(void);
void exemple_tableau(char* tableau, int taille);
void caractere_suivant(char* pt_car);
int taille_chaine_de_caracteres(char* chaine);
void affiche_tableau(int* tableau, int taille);

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

void exemple_pointeur(void) {
    int ma_variable;
    ma_variable = 5;
    printf("Le contenu de ma variable : %d\n", ma_variable);
    printf("L'adresse memoire de ma variable : %p\n", &ma_variable);
    int* mon_pointeur = &ma_variable;
    printf("L'adresse memoire de mon pointeur : %p\n", mon_pointeur);
    printf("Le contenu de mon pointeur : %d\n", *mon_pointeur);
}

void exemple_tableau(char* tableau, int taille) {
    if(taille < 3) { return; }
    printf("La deuxième case du tableau se situe à l’adresse %p\n", tableau + 2);
    printf("Elle contient : %c\n", *(tableau + 2));
}

void caractere_suivant(char* pt_car) {
    // Ajoute un au caractère avec un effet de bord (donc si on point vers 'a', on obtient 'b')
    *pt_car = *pt_car + 1;
}

int taille_chaine_de_caracteres(char* chaine) {
    int taille = 0;
    while(*(chaine + taille) != '\0') {
        taille++;
    }
    return taille;
}

void affiche_tableau(int* tableau, int taille) {
    for(int i = 0; i < taille; i++) {
        printf("%d", tableau[i]);
        if (i < taille - 1) {
            printf(" / ");
        }
    }
    printf("\n");
}