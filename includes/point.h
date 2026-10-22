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

/** Créer un point en mémoire.
 *
 * @param x l'abscisse du point
 * @param y l'ordonnée du point
 * @return l'adresse du point créé
 */
point_t *create_point(int x, int y);

/**
 * Demande à l'utilisateur les deux coordonnées d'un point, puis crée le point.
 *
 * @param message le titre affiché avant de demander les coordonnées
 * @return l'adresse du point créé
 */
point_t *ask_for_point(char *message);

/**
 * Modifie les coordonnées d'un point via un menu.
 *
 * @param point Pointeur vers le point à modifier.
 */
void modify_point(point_t *point);

/**
 * Affiche un point dans le terminal.
 *
 * @param point le point à afficher (créé avec create_point)
 */
void print_point(point_t *point);

/** Libère la mémoire d'un point.
 *
 * @param point le point à libérer (créé avec create_point)
 */
void free_point(point_t *point);

#endif