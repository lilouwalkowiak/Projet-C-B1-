/**
 * Ce fichier permet de gérer les différentes formes : ellipse, rectangle et ligne.
 * Il garde en mémoire le type de forme utilisé et appelle les bonnes fonctions selon la forme choisie.
 */

#include <stdlib.h>
#include "../includes/shape.h"

/**
 * Demande à l'utilisateur les informations d'une forme, puis la crée.
 *
 * Réserve une shape_t avec malloc, y note le type reçu, puis appelle la
 * fonction de saisie correspondante (ask_for_ellipse, ask_for_rectangle
 * ou ask_for_line). La forme créée est rangée dans la case de l'union
 * qui correspond au type.
 *
 * @param type le type de forme à créer
 * @return l'adresse de la forme créée, à libérer avec free_shape
 */
shape_t *ask_for_shape(shape_type_t type)
{
    shape_t *shape = malloc(sizeof(shape_t));

    shape->type = type;
    switch (type)
    {
    case SHAPE_ELLIPSE:
        shape->data.ellipse = ask_for_ellipse();
        break;
    case SHAPE_RECTANGLE:
        shape->data.rectangle = ask_for_rectangle();
        break;
    case SHAPE_LINE:
        shape->data.line = ask_for_line();
        break;
    }
    return shape;
}

/**
 * Affiche une forme dans le terminal.
 *
 * Appelle la fonction d'affichage qui correspond au type de la forme
 * (print_ellipse, print_rectangle ou print_line).
 *
 * @param shape la forme à afficher (créée avec ask_for_shape)
 */
void print_shape(shape_t *shape)
{
    switch (shape->type)
    {
    case SHAPE_ELLIPSE:
        print_ellipse(shape->data.ellipse);
        break;
    case SHAPE_RECTANGLE:
        print_rectangle(shape->data.rectangle);
        break;
    case SHAPE_LINE:
        print_line(shape->data.line);
        break;
    }
}

/**
 * Propose à l'utilisateur de modifier une forme.
 *
 * Appelle la fonction de modification qui correspond au type de la forme
 * (modify_ellipse, modify_rectangle ou modify_line). Les modifications
 * sont faites directement sur la forme reçue.
 *
 * @param shape la forme à modifier (créée avec ask_for_shape)
 */

void modify_shape_content(shape_t *shape)
{
    switch (shape->type)
    {
    case SHAPE_ELLIPSE:
        modify_ellipse(shape->data.ellipse);
        break;

    case SHAPE_RECTANGLE:
        modify_rectangle(shape->data.rectangle);
        break;

    case SHAPE_LINE:
        modify_line(shape->data.line);
        break;
    }
}

/**
 * Libère la mémoire d'une forme et de tout ce qu'elle contient.
 *
 * Libère d'abord la forme contenue (free_ellipse, free_rectangle ou
 * free_line, qui libèrent aussi leurs points et leur style), puis la
 * shape_t elle-même. L'ordre est important : après le free de la
 * shape_t, son contenu n'est plus accessible. La forme ne doit plus être
 * utilisée après cet appel.
 *
 * @param shape la forme à libérer (créée avec ask_for_shape)
 */
void free_shape(shape_t *shape)
{
    switch (shape->type)
    {
    case SHAPE_ELLIPSE:
        free_ellipse(shape->data.ellipse);
        break;

    case SHAPE_RECTANGLE:
        free_rectangle(shape->data.rectangle);
        break;

    case SHAPE_LINE:
        free_line(shape->data.line);
        break;
    }

    free(shape);
}