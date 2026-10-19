#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"
#include "style.h"

/**
 * Représente un rectangle
 * Un carré est un rectangle dont la longueur et la largeur sont égales.
 */
typedef struct rectangle_s
{
    /** Longueur du rectangle. */
    int length;
    /** Largeur du rectangle. */
    int width;
    /** Coin en haut à gauche du rectangle. */
    point_t *origine;
    /** Style du rectangle. */
    styles_t *styles;
} rectangle_t;

rectangle_t *create_rectangle(
    int length,
    int width,
    point_t *origine,
    styles_t *styles);
rectangle_t* ask_for_rectangle(void);
void modify_rectangle(rectangle_t *rectangle);
void print_rectangle(rectangle_t *rectangle);
void free_rectangle(rectangle_t *rectangle);

#endif