#include "../includes/polyline.h"
#include "../includes/utils.h"

/** Créer une polyligne en mémoire.
 *
 * @param points le tableau d'adresses de points
 * @param count le nombre de points
 * @param styles le style de la polyligne
 * @return l'adresse de la polyligne créée
 */
polyline_t *create_polyline(point_t **points, int count, styles_t *styles)
{
    polyline_t *polyline = malloc(sizeof(polyline_t));
    polyline->points = points;
    polyline->count = count;
    polyline->styles = styles;
    return polyline;
}

/**
 * Demande à l'utilisateur de saisir les paramètres d'une polyligne.
 *
 * @return Pointeur vers la polyligne créée à partir des saisies.
 */
polyline_t *ask_for_polyline(void)
{
    int count = ask_for_int("Combien de points pour la polyligne? (au moins 2)\n");
    while (count < 2)
    {
        count = ask_for_int("Il faut au moins 2 points. Recommence : ");
    }

    point_t **points = malloc(sizeof(point_t *) * count);
    for (int i = 0; i < count; i++)
    {
        printf("Point numéro %d\n", i + 1);
        points[i] = ask_for_point("");
    }

    styles_t *styles = ask_for_styles();

    return create_polyline(points, count, styles);
}

/**
 * Modifie les propriétés d'une polyligne via un menu.
 *
 * @param polyline Pointeur vers la polyligne à modifier.
 */
void modify_polyline(polyline_t *polyline)
{
    int choice;
    int number;
    do
    {
        choice = ask_for_int("Choisis la modification de la polyligne : \n\t1. Un point\n\t2. Le style\n\t0.Quitter\n Choix : ");
        switch (choice)
        {
        case 1:
            printf("La polyligne a %d points.\n", polyline->count);
            number = ask_for_int("Quel point veux-tu modifier? (son numéro) : ");
            if (number < 1 || number > polyline->count)
            {
                printf("Numéro invalide.\n");
            }
            else
            {
                modify_point(polyline->points[number - 1]);
            }
            break;
        case 2:
            modify_styles(polyline->styles);
            break;
        }
    } while (choice != 0);
}

/**
 * Affiche une polyligne dans le terminal : ses points et son style.
 *
 * @param polyline la polyligne à afficher (créée avec create_polyline)
 */
void print_polyline(polyline_t *polyline)
{
    printf("POLYLINE (");
    for (int i = 0; i < polyline->count; i++)
    {
        print_point(polyline->points[i]);
        printf(" ");
    }
    print_styles(polyline->styles);
    printf(")\n");
}

/**
 * Libère la mémoire d'une polyligne, de ses points et de son style.
 *
 * @param polyline la polyligne à libérer (créée avec create_polyline)
 */
void free_polyline(polyline_t *polyline)
{
    for (int i = 0; i < polyline->count; i++)
    {
        free_point(polyline->points[i]);
    }
    free(polyline->points);
    free_styles(polyline->styles);
    free(polyline);
}