#include <stdio.h>
#include <stdlib.h>
#define TAILLE 3


int processCle(int* userKey);
int* fabrikCle(int code1, int code2, int code3);

void main (){
	int* fab = fabrikCle(2, 1, 3);
	int cle = processCle(fab);
	
	printf("%d\n", cle);
}

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
