#ifndef POLYLINE_H
#define POLYLINE_H

#include "point.h"
#include "style.h"

/**
 * Représente une polyligne : une suite de points reliés entre eux.
 */
typedef struct polyline_s
{
    /** Tableau d'adresses de points (une case par point). */
    point_t **points;
    /** Nombre de points de la polyligne. */
    int count;
    /** Style de la polyligne. */
    styles_t *styles;
} polyline_t;

/** Créer une polyligne en mémoire.
 *
 * @param points le tableau d'adresses de points
 * @param count le nombre de points
 * @param styles le style de la polyligne
 * @return l'adresse de la polyligne créée
 */
polyline_t *create_polyline(point_t **points, int count, styles_t *styles);

/**
 * Demande à l'utilisateur de saisir les paramètres d'une polyligne.
 *
 * @return Pointeur vers la polyligne créée à partir des saisies.
 */
polyline_t *ask_for_polyline(void);

/**
 * Modifie les propriétés d'une polyligne via un menu.
 *
 * @param polyline Pointeur vers la polyligne à modifier.
 */
void modify_polyline(polyline_t *polyline);

/**
 * Affiche une polyligne dans le terminal : ses points et son style.
 *
 * @param polyline la polyligne à afficher (créée avec create_polyline)
 */
void print_polyline(polyline_t *polyline);

/**
 * Libère la mémoire d'une polyligne, de ses points et de son style.
 *
 * @param polyline la polyligne à libérer (créée avec create_polyline)
 */
void free_polyline(polyline_t *polyline);

#endif