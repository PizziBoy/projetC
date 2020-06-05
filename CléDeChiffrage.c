#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 5

char mess[TAILLE] = "c";
int cesEntier;

cesarEntier(char* message);

void main (){
	cesarEntier(mess);
	printf("%d\n", cesEntier);
}

int cesarEntier(char* message){
	cesEntier = ((strlen(mess) * (strlen(mess) * 2)) / 2) % 5;
	return cesEntier;
}
