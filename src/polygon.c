#include "../includes/polygon.h"
#include "../includes/utils.h"

/** Créer un polygone en mémoire.
 *
 * @param points le tableau d'adresses de points
 * @param count le nombre de points
 * @param styles le style du polygone
 * @return l'adresse du polygone créé
 */
polygon_t *create_polygon(point_t **points, int count, styles_t *styles)
{
    polygon_t *polygon = malloc(sizeof(polygon_t));
    polygon->points = points;
    polygon->count = count;
    polygon->styles = styles;
    return polygon;
}

/**
 * Demande à l'utilisateur de saisir les paramètres d'un polygone.
 *
 * @return Pointeur vers le polygone créé à partir des saisies.
 */
polygon_t *ask_for_polygon(void)
{
    int count = ask_for_int("Combien de points pour le polygone? (au moins 3)\n");
    while (count < 3)
    {
        count = ask_for_int("Il faut au moins 3 points. Recommence : ");
    }

    point_t **points = malloc(sizeof(point_t *) * count);
    for (int i = 0; i < count; i++)
    {
        printf("Point numéro %d\n", i + 1);
        points[i] = ask_for_point("");
    }

    styles_t *styles = ask_for_styles();

    return create_polygon(points, count, styles);
}

/**
 * Modifie les propriétés d'un polygone via un menu.
 *
 * @param polygon Pointeur vers le polygone à modifier.
 */
void modify_polygon(polygon_t *polygon)
{
    int choice;
    int number;
    do
    {
        choice = ask_for_int("Choisis la modification du polygone : \n\t1. Un point\n\t2. Le style\n\t0.Quitter\n Choix : ");
        switch (choice)
        {
        case 1:
            printf("Le polygone a %d points.\n", polygon->count);
            number = ask_for_int("Quel point veux-tu modifier? (son numéro) : ");
            if (number < 1 || number > polygon->count)
            {
                printf("Numéro invalide.\n");
            }
            else
            {
                modify_point(polygon->points[number - 1]);
            }
            break;
        case 2:
            modify_styles(polygon->styles);
            break;
        }
    } while (choice != 0);
}

/**
 * Affiche un polygone dans le terminal : ses points et son style.
 *
 * @param polygon le polygone à afficher (créé avec create_polygon)
 */
void print_polygon(polygon_t *polygon)
{
    printf("POLYGON (");
    for (int i = 0; i < polygon->count; i++)
    {
        print_point(polygon->points[i]);
        printf(" ");
    }
    print_styles(polygon->styles);
    printf(")\n");
}

/**
 * Libère la mémoire d'un polygone, de ses points et de son style.
 *
 * @param polygon le polygone à libérer (créé avec create_polygon)
 */
void free_polygon(polygon_t *polygon)
{
    for (int i = 0; i < polygon->count; i++)
    {
        free_point(polygon->points[i]);
    }
    free(polygon->points);
    free_styles(polygon->styles);
    free(polygon);
}