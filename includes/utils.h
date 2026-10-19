#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Modifie les propriétés d'un style via un menu.
 * 
 * @param style Pointeur vers le style à modifier.
 */
int ask_for_int(char *message);

/**
 * Demande un mot (sans espace) à l'utilisateur, par exemple une couleur.
 *
 * Affiche le message, puis lit un mot au clavier. Seuls les 49 premiers
 * caractères sont conservés. Le texte est copié dans une zone de mémoire
 * réservée avec malloc.
 *
 * @param message la question affichée avant la saisie
 * @return l'adresse du mot saisi (vide si la saisie échoue)
 */
char* ask_for_string(char *message);

#endif