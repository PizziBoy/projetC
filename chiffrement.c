#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "chiffrement.h"



//Partie algorithmes de chiffrement

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

//Partie construction de la clé Cesar

int processCle(int* userKey){ //Retourne une clé de Cesar
	int cesEntier = (userKey[0] * userKey[2] / userKey[1]) % 26;
	if (cesEntier == 0) { cesEntier = cesEntier + 1;}
	return cesEntier;
}

int* fabrikCle(int code1, int code2, int code3){ //Fabrique une clé de Cesar avec l'aide de l'utilisateur
	int* userKeyArray = NULL;
	userKeyArray = malloc(TAILLE * sizeof(int));
	if (userKeyArray == NULL){
		exit(0);
	}
	if (code1 == 0 ||code2 == 0 ||code3 == 0) {
		exit(0);		
	}
	userKeyArray[0] = code1;
	userKeyArray[1] = code2;
	userKeyArray[2] = code3;
	return userKeyArray;
	free(userKeyArray);
}

//Partie conversion des accents 
