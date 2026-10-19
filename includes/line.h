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

line_t *create_line(
    point_t *start,
    point_t *finish,
    styles_t *styles);
line_t* ask_for_line(void);
void modify_line(line_t *line);
void print_line(line_t *line);
void free_line(line_t *line);

#endif