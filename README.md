# projetC
Bienvenue dans notre projet C (C comme confiné) qui porte sur le sujet du cryptage de messages. 
Cette application a pour objectif de chiffrer et déchiffrer un message donné via 2 clés (César ou Vigenère).
Amaury Joudiou: gestion des accents, Sébastien Bougouin: gestion des clés de cryptage,  Guilhaume de Gineste: gestion des algorithmes de cryptage

Fonctions : 

1. Algorithmes de chiffrement 

  Calcule le modulo de 2 entiers a et b
int mod (int a, int b); 

  Décale un caractère dans l'alphabet dans les deux sens (avant/arrière)
char petitDecalage(int decalage, char caractere, int choixUtilisateur);

  Recherche l'emplacement d'un caractère donné en paramètre dans l'alphabet
int rechercheAlphabet(char caractere);

  Chiffre ou déchiffre un message via une clé de César
char* cesar(int decalage, char message[], int choixUtilisateur);

  Chiffre ou déchiffre un message via une clé de Vigenère
char* vigenere(char message[], char code[], int choixUtilisateur);

2. Construction de la clé de César

  Retourne une clé de César (paramètre : userKey qui est la clé rentrée par l'utilisateur)
int processCle(int* userKey);

  Fabrique une clé de César avec aide de l'utilisateur (paramètres : 3 entiers donnés par l'utilisateur)
int* fabrikCle(int code1, int code2, int code3);

3. Gestion des accents

  Récupère le message donné par l'utilisateur et retire les accents si il y en a (paramètre : tableau contenant le message)
char* conversionAccents(char messageNonConverti[]);

Cas d'erreur :

1. Dans le cas de l'utilisation d'une clé de César l'utilisateur entre un 0 afin de construire la clé.
Conséquence -> Arrêt de l'application

2. Le message contient un accent
Conséquence -> Chiffrage/Déchiffrage incorrect sur le caractère accentué


Remarque : La partie sur la gestion des accents ne fonctionne pas et n'a pas pu être finalisée. 

Sébastien Bougouin, Amaury Joudiou, Guilhaume de Gineste
Groupe S2F
