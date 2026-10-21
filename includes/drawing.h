#ifndef DRAWING_H
#define DRAWING_H

#include "shape.h"
#include "viewport.h"

/**
 * Représente un dessin qui contient plusieurs formes.
 * Le dessin permet de garder toutes les formes au même endroit
 * pour pouvoir les ajouter, les afficher ou les supprimer.
 */
typedef struct drawing_s
{
    /**
     * Tableau de pointeurs vers les formes du dessin.
     * Chaque case contient l'adresse d'une forme :
     * une ellipse, un rectangle ou une ligne.
     */
    shape_t **shapes;
    /**
     * Nombre de cases du tableau (chaque case est vide ou contient une forme).
     */
    int capacity;
    /**
     * Fenêtre du dessin : sa largeur et sa hauteur.
     */
    viewport_t *viewport;
} drawing_t;

/**
 * Crée un nouveau dessin vide.
 * Réserve la mémoire nécessaire pour le dessin et son tableau de formes.
 *
 * @return Un pointeur vers le dessin créé.
 */
drawing_t *drawing_create(void);

/**
 * Insère une nouvelle forme dans le dessin.
 *
 * @param drawing Pointeur vers le dessin.
 * @param index L'index où insérer la forme.
 */
void insert_shape(drawing_t *drawing, int index);

/**
 * Modifie une forme existante dans le dessin.
 *
 * @param drawing Pointeur vers le dessin.
 * @param index L'index de la forme à modifier.
 */
void modify_shape(drawing_t *drawing, int index);

/**
 * Affiche toutes les formes du dessin.
 * Chaque forme est affichée à l'aide de print_shape().
 *
 * @param drawing Le dessin dont on veut afficher les formes.
 */
void drawing_print(drawing_t *drawing);

/**
 * Supprime une forme existante dans le dessin.
 *
 * @param drawing Pointeur vers le dessin.
 * @param index L'index de la forme à supprimer.
 */
void delete_shape(drawing_t *drawing, int index);

/**
 * Libère la mémoire utilisée par le dessin.
 * Libère d'abord chaque forme, puis le tableau et enfin le dessin.
 *
 * @param drawing Le dessin à libérer.
 */
void drawing_free(drawing_t *drawing);

#endif