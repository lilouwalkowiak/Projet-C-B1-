/**
 * Représentation d'une forme quelconque du dessin (ellipse, rectangle, ligne,
 * polyligne ou free_polygon), pour pouvoir les ranger toutes dans une même liste.
 */

#ifndef SHAPE_H
#define SHAPE_H

#include "point.h"
#include "style.h"
#include "ellipse.h"
#include "rectangle.h"
#include "line.h"
#include "polyline.h"
#include "polygon.h"

/** Type d'une forme du dessin. */
typedef enum
{
    SHAPE_ELLIPSE,
    SHAPE_RECTANGLE,
    SHAPE_LINE,
    SHAPE_POLYLINE,
    SHAPE_POLYGON
} shape_type_t;

/**
 * Représente une forme quelconque du dessin.
 *
 * Le champ type indique quelle forme est réellement stockée. Une seule
 * des cinq adresses de l'union est utilisée à la fois.
 */
typedef struct shape_s
{
    shape_type_t type;
    union
    {
        ellipse_t *ellipse;
        rectangle_t *rectangle;
        line_t *line;
        polyline_t *polyline;
        polygon_t *polygon;
    } data;
} shape_t;

/**
 * Demande à l'utilisateur les informations d'une forme, puis la crée.
 *
 * @param type le type de forme à créer
 * @return l'adresse de la forme créée, à libérer avec free_shape
 */
shape_t *ask_for_shape(shape_type_t type);

/**
 * Affiche une forme dans le terminal.
 *
 * @param shape la forme à afficher (créée avec ask_for_shape)
 */
void print_shape(shape_t *shape);

/**
 * Propose à l'utilisateur de modifier une forme.
 *
 * @param shape la forme à modifier (créée avec ask_for_shape)
 */
void modify_shape_content(shape_t *shape);

/**
 * Libère la mémoire d'une forme et de tout ce qu'elle contient.
 *
 * @param shape la forme à libérer (créée avec ask_for_shape)
 */
void free_shape(shape_t *shape);

#endif