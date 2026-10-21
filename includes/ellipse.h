#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "point.h"
#include "style.h"

/**
 * Représente une ellipse
 *
 * Un cercle est une ellipse dont les deux rayons sont égaux.
 */
typedef struct ellipse_s
{
    /** Premier rayon (horizontal). */
    int rx;
    /** Second rayon (vertical). */
    int ry;
    /** Centre de l'ellipse. */
    point_t *center;
    /** Style de l'ellipse. */
    styles_t *styles;
} ellipse_t;

/** Créer une ellipse en mémoire.
 *
 * @param rx le rayon horizontal
 * @param ry le rayon vertical
 * @param center pointeur vers le point central de l'ellipse
 * @param styles pointeur vers le style de l'ellipse
 * @return l'adresse de l'ellipse créée
 */
ellipse_t *create_ellipse(int rx,
                          int ry,
                          point_t *center,
                          styles_t *styles);

/**
 * Demande à l'utilisateur de saisir les paramètres d'une ellipse.
 *
 * @return Pointeur vers l'ellipse créée à partir des saisies.
 */
ellipse_t *ask_for_ellipse(void);

/**
 * Modifie les propriétés d'une ellipse via un menu.
 *
 * @param ellipse Pointeur vers l'ellipse à modifier.
 */
void modify_ellipse(ellipse_t *ellipse);

/**
 * Affiche une ellipse dans le terminal : ses deux rayons, son centre et
 * son style.
 *
 * @param ellipse l'ellipse à afficher (créée avec create_ellipse)
 */
void print_ellipse(ellipse_t *ellipse);

/**
 *
 * Libère la mémoire allouée pour une ellipse, son centre et ses styles.
 *
 * @param ellipse Pointeur vers l'ellipse à libérer.
 */
void free_ellipse(ellipse_t *ellipse);

#endif