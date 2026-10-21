#include <stdio.h>
#include <stdlib.h>
#include "../includes/viewport.h"
#include "../includes/utils.h"

/**
 * Crée un viewport en mémoire.
 *
 * @param width la largeur de la fenêtre
 * @param height la hauteur de la fenêtre
 * @return l'adresse du viewport créé
 */
viewport_t *create_viewport(int width, int height)
{
    viewport_t *viewport = malloc(sizeof(viewport_t));
    viewport->width = width;
    viewport->height = height;
    return viewport;
}

/**
 * Demande à l'utilisateur la largeur et la hauteur, puis crée le viewport.
 *
 * @return l'adresse du viewport créé
 */
viewport_t *ask_for_viewport(void)
{
    int width = ask_for_int("Quelle largeur pour la fenêtre ? : ");
    int height = ask_for_int("Quelle hauteur pour la fenêtre ? : ");

    return create_viewport(width, height);
}

/**
 * Affiche un viewport dans le terminal : sa largeur et sa hauteur.
 *
 * @param viewport le viewport à afficher (créé avec create_viewport)
 */
void print_viewport(viewport_t *viewport)
{
    printf("VIEWPORT (%d %d)", viewport->width, viewport->height);
}

/**
 * Libère la mémoire d'un viewport.
 *
 * @param viewport le viewport à libérer (créé avec create_viewport)
 */
void free_viewport(viewport_t *viewport)
{
    free(viewport);
}