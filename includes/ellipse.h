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

ellipse_t *create_ellipse(int rx,
                          int ry,
                          point_t *center,
                          styles_t *styles);
ellipse_t* ask_for_ellipse(void);
void modify_ellipse(ellipse_t *ellipse);
void print_ellipse(ellipse_t *ellipse);
void free_ellipse(ellipse_t *ellipse);


#endif