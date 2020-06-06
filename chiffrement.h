#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define taille 26
#define TAILLE 3
#define alphabet "abcdefghijklmnopqrstuvwxyz0"
#define mess "yomecsavabg"



//Partie algorithmes de chiffrement

char* vigenere(char message[], char code[], int choixUtilisateur);	//Chiffrement de Vigenère
char* cesar(int decalage, char message[], int choixUtilisateur);	//Chiffrement de César

char petitDecalage(int decalage, char caractere, int choixUtilisateur);	//Exerce un décalage sur un caractère donné via l'alphabet, 0 vers la droite, 1 vers la gauche
int rechercheAlphabet(char caractere);					//Fonction de recherche de position d'un caractère dans l'alphabet
int mod (int a, int b);							//Modulo qui prend en compte les entiers négatifs



//Partie construction de la clé Cesar

int processCle(int* userKey);
int* fabrikCle(int code1, int code2, int code3);


//Partie conversion des accents 
