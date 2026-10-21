/**
 * Gestion du dessin : la liste de toutes les formes.
 *
 * Le dessin contient un tableau de cases. Chaque case est vide (NULL)
 * ou contient une forme. On choisit une case grâce à son index.
 * Ce fichier permet de créer le dessin, d'ajouter, de modifier,
 * d'afficher et de supprimer des formes, puis de libérer la mémoire.
 */
#include <stdlib.h>
#include <stdio.h>
#include "../includes/drawing.h"
#include "../includes/shape.h"
#include "../includes/utils.h"

/** Nombre de cases du dessin : on peut ranger 50 formes au maximum. */
#define SVG_SIZE 50

/**
 * Crée un nouveau dessin vide.
 *
 * Réserve la mémoire du dessin et de son tableau de cases.
 * On utilise calloc pour que toutes les cases soient à NULL (vides).
 *
 * @return l'adresse du dessin créé, à libérer avec drawing_free
 */
drawing_t *drawing_create(void)
{
    drawing_t *drawing = malloc(sizeof(drawing_t));
    drawing->capacity = SVG_SIZE;
    drawing->shapes = calloc(SVG_SIZE, sizeof(shape_t *));
    return drawing;
}

/**
 * Ajoute une forme dans une case du dessin.
 *
 * Vérifie que l'index est valide et que la case est libre, puis demande
 * à l'utilisateur le type de forme (1 ellipse, 2 rectangle, 3 ligne).
 * La forme créée est rangée dans la case.
 *
 * @param drawing le dessin dans lequel on ajoute la forme
 * @param index le numéro de la case (de 0 à capacity - 1)
 */
void insert_shape(drawing_t *drawing, int index)
{
    if (index < 0 || index > drawing->capacity - 1)
    {
        printf("Index invalide.\n");
        return;
    }

    if (drawing->shapes[index] != NULL)
    {
        printf("Il y a déjà une forme à cet index : supprime-la ou choisis un autre index.\n");
        return;
    }

    int type = ask_for_int("Quel type de forme?\n\t1. Ellipse\n\t2. Rectangle\n\t3. Ligne\n\tChoix :");
    shape_t *shape = NULL;
    switch (type)
    {
    case 1:
        shape = ask_for_shape(SHAPE_ELLIPSE);
        break;
    case 2:
        shape = ask_for_shape(SHAPE_RECTANGLE);
        break;
    case 3:
        shape = ask_for_shape(SHAPE_LINE);
        break;
    }

    if (shape == NULL)
    {
        printf("Cette forme n'existe pas.\n");
        return;
    }

    drawing->shapes[index] = shape;
}

/**
 * Modifie la forme qui se trouve dans une case du dessin.
 *
 * Vérifie que l'index est valide et que la case contient une forme,
 * puis appelle le menu de modification de cette forme.
 *
 * @param drawing le dessin qui contient la forme
 * @param index le numéro de la case de la forme à modifier
 */
void modify_shape(drawing_t *drawing, int index)
{
    if (index < 0 || index > drawing->capacity - 1)
    {
        printf("Index invalide.\n");
        return;
    }

    if (drawing->shapes[index] == NULL)
    {
        printf("Il y a aucune forme à cet index.\n");
        return;
    }

    modify_shape_content(drawing->shapes[index]);
}

/**
 * Affiche toutes les formes du dessin, avec le numéro de leur case.
 *
 * Les cases vides sont ignorées. Si aucune forme n'est trouvée,
 * le message "Le dessin est vide." est affiché.
 *
 * @param drawing le dessin à afficher
 */
void drawing_print(drawing_t *drawing)
{
    int found = 0;

    for (int i = 0; i < drawing->capacity; i++)
    {
        if (drawing->shapes[i] != NULL)
        {
            printf("[%d] ", i);
            print_shape(drawing->shapes[i]);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("Le dessin est vide.\n");
    }
}

/**
 * Supprime la forme qui se trouve dans une case du dessin.
 *
 * Vérifie que l'index est valide et que la case contient une forme,
 * libère la mémoire de la forme, puis remet la case à NULL (vide).
 *
 * @param drawing le dessin qui contient la forme
 * @param index le numéro de la case de la forme à supprimer
 */
void delete_shape(drawing_t *drawing, int index)
{
    if (index < 0 || index > drawing->capacity - 1)
    {
        printf("Index invalide.\n");
        return;
    }

    if (drawing->shapes[index] == NULL)
    {
        printf("Il y a aucune forme à cet index.\n");
        return;
    }

    free_shape(drawing->shapes[index]);
    drawing->shapes[index] = NULL;
}

/**
 * Libère toute la mémoire utilisée par le dessin.
 *
 * Libère d'abord chaque forme, puis le tableau de cases,
 * puis le dessin lui-même. Le dessin ne doit plus être utilisé après.
 *
 * @param drawing le dessin à libérer (créé avec drawing_create)
 */
void drawing_free(drawing_t *drawing)
{
    for (int i = 0; i < drawing->capacity; i++)
    {
        if (drawing->shapes[i] != NULL)
        {
            free_shape(drawing->shapes[i]);
        }
    }
    free(drawing->shapes);
    free(drawing);
}
