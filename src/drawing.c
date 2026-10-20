/**
 * Gestion du dessin : la liste de toutes les formes.
 *
 * ????? (suite)
 */

#include <stdlib.h>
#include <stdio.h>
#include "../includes/drawing.h"
#include "../includes/shape.h"
#include "../includes/utils.h"

/** Définir la capacité des formes dans le dessin. */
#define SVG_SIZE 50

drawing_t *drawing_create(void)
{
    drawing_t *drawing = malloc(sizeof(drawing_t));
    drawing->capacity = SVG_SIZE;
    drawing->shapes = malloc(sizeof(shape_t *) * SVG_SIZE);
    return drawing;
}

void insert_shape(drawing_t *drawing, int index)
{
    if (index > drawing->capacity - 1)
    {
        printf("Index invalide.\n");
        return;
    }

    if (drawing->shapes[index] != NULL)
    {
        printf("Il y a déjà une forme à cette index : supprime-la ou choisis un autre index.\n");
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

void modify_shape(drawing_t *drawing, int index)
{
    if (index > drawing->capacity - 1)
    {
        printf("Index invalide.\n");
        return;
    }

    if (drawing->shapes[index] == NULL)
    {
        printf("Il y a aucune forme à cette index.\n");
        return;
    }

    modify_shape_content(drawing->shapes[index]);
}

void drawing_print(drawing_t *drawing)
{
    for (int i = 0; i < SVG_SIZE; i++)
    {
        if (drawing->shapes[i] == NULL)
            continue;
        print_shape(drawing->shapes[i]);
    }
    return;
}

void delete_shape(drawing_t *drawing, int index)
{
    if (index > drawing->capacity - 1)
    {
        printf("Index invalide.\n");
        return;
    }

    if (drawing->shapes[index] == NULL)
    {
        printf("Il y a aucune forme à cette index.\n");
        return;
    }

    free_shape(drawing->shapes[index]);
    drawing->shapes[index] = NULL;
}

void drawing_free(drawing_t *drawing)
{
    for (int i = 0; i < SVG_SIZE; i++)
    {
        delete_shape(drawing, i);
    }
    free(drawing->shapes);
    free(drawing);
}
