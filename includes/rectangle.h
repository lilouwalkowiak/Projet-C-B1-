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

/** Créer un rectangle en mémoire.
 *
 * @param length la longueur du rectangle
 * @param width la largeur du rectangle
 * @param origine le coin en haut à gauche
 * @param styles le style du rectangle
 * @return l'adresse du rectangle créé
 */
rectangle_t *create_rectangle(
    int length,
    int width,
    point_t *origine,
    styles_t *styles);

/**
 * Demande à l'utilisateur de saisir les paramètres d'un rectangle.
 *
 * @return Pointeur vers le rectangle créé à partir des saisies.
 */
rectangle_t *ask_for_rectangle(void);

/**
 * Modifie les propriétés d'un rectangle via un menu.
 *
 * @param rectangle Pointeur vers le rectangle à modifier.
 */
void modify_rectangle(rectangle_t *rectangle);

/**
 * Affiche un rectangle dans le terminal : sa longueur, sa largeur, son
 * origine et son style.
 *
 * @param rectangle le rectangle à afficher (créé avec create_rectangle)
 */
void print_rectangle(rectangle_t *rectangle);

/**
 * Libère la mémoire d'un rectangle, de son origine et de son style.
 *
 * @param rectangle le rectangle à libérer (créé avec create_rectangle)
 */
void free_rectangle(rectangle_t *rectangle);

#endif