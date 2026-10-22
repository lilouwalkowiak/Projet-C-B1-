#ifndef POLYGON_H
#define POLYGON_H

#include "point.h"
#include "style.h"

/**
 * Représente un polygone : une forme fermée faite de points reliés entre eux.
 * Le dernier point est relié au premier.
 */
typedef struct polygon_s
{
    /** Tableau d'adresses de points (une case par point). */
    point_t **points;
    /** Nombre de points du polygone. */
    int count;
    /** Style du polygone. */
    styles_t *styles;
} polygon_t;

/** Créer un polygone en mémoire.
 *
 * @param points le tableau d'adresses de points
 * @param count le nombre de points
 * @param styles le style du polygone
 * @return l'adresse du polygone créé
 */
polygon_t *create_polygon(point_t **points, int count, styles_t *styles);

/**
 * Demande à l'utilisateur de saisir les paramètres d'un polygone.
 *
 * @return Pointeur vers le polygone créé à partir des saisies.
 */
polygon_t *ask_for_polygon(void);

/**
 * Modifie les propriétés d'un polygone via un menu.
 *
 * @param polygon Pointeur vers le polygone à modifier.
 */
void modify_polygon(polygon_t *polygon);

/**
 * Affiche un polygone dans le terminal : ses points et son style.
 *
 * @param polygon le polygone à afficher (créé avec create_polygon)
 */
void print_polygon(polygon_t *polygon);

/**
 * Libère la mémoire d'un polygone, de ses points et de son style.
 *
 * @param polygon le polygone à libérer (créé avec create_polygon)
 */
void free_polygon(polygon_t *polygon);

#endif