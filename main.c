#include <string.h>
#include <stdlib.h>

#include "chiffrement.h"
#define TmaxMessageApp 64

void main() {
	int choixChiffrerOuDechiffrer = 3;
	int choixMethodeChiffrement = 3;
	char cle[TmaxMessageApp];
	char message[TmaxMessageApp];
	
	int cleCesar;
	int entier1;
	int entier2;
	int entier3;
	

   		while (choixChiffrerOuDechiffrer != 1 && choixChiffrerOuDechiffrer != 2) {
			printf("%s\n", "Voulez-vous crypter ou décrypter un message (César/Vigenère)?");
			printf("%s\n", "[1] chiffrer | [2] déchiffrer | [0] sortir");
			scanf("%d", &choixChiffrerOuDechiffrer);
			if (choixChiffrerOuDechiffrer == 0) { exit(0);}
		} 

		//CHIFFREMENT
		if (choixChiffrerOuDechiffrer == 1) {
			while (choixMethodeChiffrement != 1 && choixMethodeChiffrement != 2) {
				printf("%s\n", "Vous avez choisi de chiffrer un message");
				printf("%s\n", "[1] Vigenère | [2] César | [0] sortir");
				scanf("%d", &choixMethodeChiffrement);
				if (choixMethodeChiffrement == 0) { exit(0);}
			}
			if (choixMethodeChiffrement == 1) {
				printf("%s\n", "Veuillez entrer un mot sans espaces qui servira de clé (notez cette clé)");
				scanf("%s", &cle);
				printf("%s\n", "Veuillez entrer le message à chiffrer en Vigenère (max 64 caractères): ");
				scanf("%s", &message);
				printf("%s", "Votre message chiffré en Vigenère est le suivant: ");
				printf("%s\n", vigenere(message, cle , 0));
			} else {
				printf("%s", "Veuillez entrer le message à chiffrer en Cesar (max 64 caractères): ");
				scanf("%s", &message);
				printf("%s\n", "Veuillez entrer votre clé cesar(3nombres 1 par 1): ");
				scanf("%d", &entier1);
				scanf("%d", &entier2);
				scanf("%d", &entier3);
				cleCesar = processCle(fabrikCle(entier1, entier2, entier3));
				printf("%s", "Votre message chiffré en Cesar est le suivant: ");
				printf("%s\n", cesar(cleCesar, message, 0));
			}
		}

		//DECHIFFREMENT
		if (choixChiffrerOuDechiffrer == 2) {
			while (choixMethodeChiffrement != 1 && choixMethodeChiffrement != 2) {
				printf("%s\n", "Vous avez choisi de déchiffrer un message");
				printf("%s\n", "[1] Vigenère | [2] César | [0] sortir");
				scanf("%d", &choixMethodeChiffrement);
				if (choixMethodeChiffrement == 0) { exit(0);}
			}
			if (choixMethodeChiffrement == 1) {
				printf("%s\n", "Veuillez entrer un mot sans espaces qui servira de clé (notez cette clé)");
				scanf("%s", &cle);
				printf("%s\n", "Veuillez entrer le message à déchiffrer en Vigenère (max 64 caractères): ");
				scanf("%s", &message);
				printf("%s", "Votre message déchiffré en Vigenère est le suivant: ");
				printf("%s\n", vigenere(message, cle , 1));
			} else {
				printf("%s", "Veuillez entrer le message à déchiffrer en Cesar (max 64 caractères): ");
				scanf("%s", &message);
				printf("%s\n", "Veuillez entrer votre clé cesar(3nombres 1 par 1): ");
				scanf("%d", &entier1);
				scanf("%d", &entier2);
				scanf("%d", &entier3);
				cleCesar = processCle(fabrikCle(entier1, entier2, entier3));
				printf("%s", "Votre message déchiffré en Cesar est le suivant: ");
				printf("%s\n", cesar(cleCesar, message, 1));
			}
	}


	
	
}
