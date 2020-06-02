#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define taille 26

char alphabet[taille + 1] = "abcdefghijklmnopqrstuvwxyz0";
char mess[taille] = "yomecsavabg";




char* vigenere(char message[], char code[], int choixUtilisateur);						//Chiffrement de Vigenère
char* cesar(int decalage, char message[], int choixUtilisateur);						//Chiffrement de César
char petitDecalage(int decalage, char caractere, int choixUtilisateur);					//Exerce un décalage sur un caractère donné via l'alphabet, 0 vers la droite, 1 vers la gauche
int rechercheAlphabet(char caractere);													//Fonction de recherche de position d'un caractère dans l'alphabet
int mod (int a, int b);																	//Fonction modulo (qui marche avec les nombres négatifs)

void main() {
	printf("%s\n", cesar(40, mess, 0));
	printf("%s\n", cesar(40, cesar(40, mess, 0), 1));
	printf("%c\n", petitDecalage(1, 'a', 0));
	printf("%s\n", vigenere(mess, "salutsavatoi", 0));
	printf("%s\n", vigenere(vigenere(mess, "salutsavatoi", 0), "salutsavatoi", 1));

	
}

int mod (int a, int b)
{
   if(b < 0)
     return -mod(-a, -b);   
   int res = a % b;
   if(res < 0)
     res+=b;
   return res;
}

char petitDecalage(int decalage, char caractere, int choixUtilisateur) {
	int i;
	int temp;
	int ii;
	char result;
	ii = rechercheAlphabet(caractere);
	if (choixUtilisateur == 0) {
		result = alphabet[mod((ii + decalage), 26)];	
	}
	else {
		result = alphabet[mod((ii - decalage), 26)];
	}
	return result;
}




int rechercheAlphabet(char caractere) {
	int i;
	int ii;
	for (i = 0; i < taille; i++) {
		if (caractere == alphabet[i]) { ii = i; break; }
	}
	return ii ;
}




char* cesar(int decalage, char message[], int choixUtilisateur) {
	char* memTabChiffre = NULL;
	memTabChiffre = malloc(strlen(message) * sizeof(char)); //Je créer un tableau dynamique qui va accueillir la chaine chiffrée
	if (memTabChiffre == NULL) {
        	exit(0);
   	}
	int i;
		for(i = 0; i < strlen(message); i++) {
				memTabChiffre[i] = petitDecalage(decalage, message[i], choixUtilisateur);
	}
	return memTabChiffre;
	free(memTabChiffre);									//Je libère le tableau dynamiquement alloué après l'avoir retourné
}


char* vigenere(char message[], char code[], int choixUtilisateur) {
	char* tabCode = NULL;
	char* pattern = NULL;
	tabCode = malloc(strlen(message) * sizeof(char));
	pattern = malloc(strlen(message) * sizeof(char));
	if (pattern == NULL || pattern == NULL) {
        	exit(0);
   	}
	int i;
	for (i = 0; i < strlen(message); i ++) {
		pattern[i] = code[mod(i, strlen(code))];
	}
	for (i = 0; i < strlen(message); i++) {
		tabCode[i] = petitDecalage(rechercheAlphabet(pattern[i]), message[i], choixUtilisateur);
	}
	return tabCode;
	free(tabCode);
	free(pattern);
}

