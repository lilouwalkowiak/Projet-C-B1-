#ifndef STYLE_H
#define STYLE_H

#include "point.h"

/** Représente le style d'une forme : couleurs, rotation, translation et inversion*/
typedef struct styles_s
{
    /** Angle de rotation de la forme, en degrés. */
    int rotation;
    /** Couleur de remplissage de la forme. */
    char *fill_color;
    /** Couleur du contour de la forme. */
    char *outline_color;
    /** Décalage de la forme : déplacement en x et en y. */
    point_t *translate;
    /** Inversion (miroir) de la forme : 0 aucune, 1 selon l'axe X (haut ↔ bas), 2 selon l'axe Y (gauche ↔ droite). */
    int flip;
} styles_t;

/** Créer les styles en mémoire.
 *
 * @param rotation l'angle de rotation, en degrés
 * @param fill_color la couleur de remplissage
 * @param outline_color la couleur du contour
 * @param translate le décalage de la forme
 * @param flip l'inversion : 0 aucune, 1 selon l'axe X (haut ↔ bas), 2 selon l'axe Y (gauche ↔ droite).
 * @return l'adresse du style créé
 */
styles_t *create_styles(
    int rotation,
    char *fill_color,
    char *outline_color,
    point_t *translate,
    int flip);

/**
 * Demande à l'utilisateur les informations d'un style, puis crée le style.
 *
 * Les informations demandées sont la rotation, la couleur de remplissage,
 * la couleur du contour, le décalage et l'inversion de la forme
 *
 * Précondition : la rotation saisie doit être un entier.
 *
 * @return l'adresse du style créé, que la forme qui le reçoit devra libérer
 */
styles_t *ask_for_styles(void);

/**
 * Modifie les propriétés d'un style via un menu.
 *
 * @param styles Pointeur vers le style à modifier.
 */
void modify_styles(styles_t *styles);

/**
 * Affiche un style dans le terminal : rotation, couleurs, point de
 * translation et inversion.
 *
 * @param styles le style à afficher (créé avec create_styles)
 */
void print_styles(styles_t *styles);

/** Libère la mémoire d'un style et de son point de translation.
 *
 * @param styles le style à libérer (créé avec create_styles)
 */
void free_styles(styles_t *styles);

#endif