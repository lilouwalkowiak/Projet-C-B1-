#ifndef VIEWPORT_H
#define VIEWPORT_H

/**
 * Représente le viewport : la fenêtre à travers laquelle on voit le dessin.
 * Seules les formes qui se trouvent dans cette fenêtre sont visibles.
 */
typedef struct viewport_s
{
    /** Largeur de la fenêtre. */
    int width;
    /** Hauteur de la fenêtre. */
    int height;
} viewport_t;

/**
 * Crée un viewport en mémoire.
 *
 * @param width la largeur de la fenêtre
 * @param height la hauteur de la fenêtre
 * @return l'adresse du viewport créé
 */
viewport_t *create_viewport(int width, int height);

/**
 * Demande à l'utilisateur la largeur et la hauteur, puis crée le viewport.
 *
 * @return l'adresse du viewport créé
 */
viewport_t *ask_for_viewport(void);

/**
 * Affiche un viewport dans le terminal : sa largeur et sa hauteur.
 *
 * @param viewport le viewport à afficher (créé avec create_viewport)
 */
void print_viewport(viewport_t *viewport);

/**
 * Libère la mémoire d'un viewport.
 *
 * @param viewport le viewport à libérer (créé avec create_viewport)
 */
void free_viewport(viewport_t *viewport);

#endif