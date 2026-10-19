#ifndef POINT_H
#define POINT_H

/** Représente un point dans le plan.  */
typedef struct point_s
{
    /** Abscisse du point (position horizontale). */
    int x;
    /** Ordonnée du point (position verticale). */
    int y;
} point_t;

point_t *create_point(int x, int y);
point_t* ask_for_point(char* message);
void modify_point(point_t *point);
void print_point(point_t *point);
void free_point(point_t *point);

#endif