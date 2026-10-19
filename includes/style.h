#ifndef STYLES
#define STYLES

#include "point.h"

/** Représente le style d'une forme : couleurs, rotation et translation */
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
} styles_t;

styles_t *create_styles(
    int rotation,
    char *fill_color,
    char *outline_color,
    point_t *translate);   
styles_t* ask_for_styles(void);
void modify_styles(styles_t *styles);
void print_styles(styles_t *styles);
void free_styles(styles_t *styles);


#endif