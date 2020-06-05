#include <stdio.h>
#include <stdlib.h>
#define TAILLE 3

char userKeyArray[TAILLE];
int cesEntier; //Clé de Cesar

int processCle(int* userKey);
int* fabrikCle(int code1, int code2, int code3);

void main (){
	printf("%d\n", fabrikCle(7,2,8));
}

int processCle(int* userKey){ //Retourne une clé de Cesar
	cesEntier = userKeyArray[0] * userKeyArray[2] / userKeyArray[1];
	return cesEntier;
}

int* fabrikCle(int code1, int code2, int code3){ //Fabrique une clé de Cesar avec l'aide de l'utilisateur
	int* userKeyArray = NULL;
	userKeyArray = malloc(TAILLE * sizeof(int));
	if (userKeyArray == NULL){
		exit(0);
	}
	userKeyArray[1] = code1;
	userKeyArray[2] = code2;
	userKeyArray[3] = code3;
	return userKeyArray;
	free(userKeyArray);
}
