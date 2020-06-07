#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char accents[] = "àâãäûūüúùïìīíîéêēëèėôóõôöòō";
char sansAccents[] = "aaaauuuuuiiiiieeeeeeooooooo";


char* conversionAccents(char messageNonConverti[]);

void main() {
	char* tab = conversionAccents("azérty");
	printf("%s\n", tab);
}



char* conversionAccents(char messageNonConverti[]) {
	char* messageSansAccents = NULL;
	messageSansAccents = malloc(strlen(messageNonConverti) * sizeof(char));
	if (messageSansAccents == NULL){
		exit(0);
	}
	memcpy(messageSansAccents, messageNonConverti, strlen(messageNonConverti) * sizeof(char));
	int i = 0;
	int t = 0;
	while (i < strlen(messageSansAccents)) {
		while (t < 28) {
			if (messageSansAccents[i] == accents[t]) {messageSansAccents[i] = sansAccents[t];}
			t++;
		}
	t = 0;
	i++;
	}
	return messageSansAccents;
	free(messageSansAccents);
}
