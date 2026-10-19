#ifndef LINE_H
#define LINE_H

#include "point.h"
#include "style.h"

/** Représente une ligne droite entre deux points. */
typedef struct line_s
{
    /** Point de départ de la ligne */
    point_t *start;
    /** Point d'arrivée de la ligne */
    point_t *finish;
    /** Style de la ligne */
    styles_t *styles;
} line_t;

/** Créer une ligne droite en mémoire.
 * 
 * @param start le point de départ
 * @param finish le point d'arrivée
 * @param styles le style de la ligne
 * @return l'adresse de la ligne crée
 */
line_t *create_line(
    point_t *start,
    point_t *finish,
    styles_t *styles);
   
/**
 * Demande à l'utilisateur de saisir les paramètres d'une ligne.
 * 
 * @return Pointeur vers la ligne créée à partir des saisies. 
 */
line_t* ask_for_line(void);

/**
 * Modifie les propriétés d'une ligne via un menu.
 * 
 * @param line Pointeur vers la ligne à modifier.
 */
void modify_line(line_t *line);

/**
 * Affiche une ligne dans le terminal : ses deux points et son style.
 *
 * @param line la ligne à afficher (créée avec create_line)
 */
void print_line(line_t *line);

/**
 * Libère la mémoire d'une ligne, de ses deux points et de son style.
 * 
 * @param line la ligne à libérer (créée avec create_line)
 */
void free_line(line_t *line);

#endif