#include "../includes/point.h"
#include "../includes/utils.h"

/** Créer un point en mémoire.
 *
 * @param x l'abscisse du point
 * @param y l'ordonnée du point
 * @return l'adresse du point créé
 */
point_t *create_point(int x, int y)
{
    point_t *point = malloc(sizeof(point_t));
    point->x = x;
    point->y = y;
    return point;
}

/**
 * Demande à l'utilisateur les deux coordonnées d'un point, puis crée le point.
 *
 * @param message le titre affiché avant de demander les coordonnées
 * @return l'adresse du point créé
 */
point_t *ask_for_point(char *message)
{
    printf("%s", message);
    int x = ask_for_int("Quelle abscisse souhaitez-vous? (Entrez un entier)\n");
    int y = ask_for_int("Quelle ordonnée souhaitez-vous? (Entrez un entier)\n");

    return create_point(x, y);
}

/**
 * Modifie les coordonnées d'un point via un menu.
 *
 * @param point Pointeur vers le point à modifier.
 */
void modify_point(point_t *point)
{
    int choice;
    do
    {
        choice = ask_for_int("Choisis la modification :\n\t1. x L'abscisse\n\t2. y L'ordonnée\n\t0.Quitter\n Choix : ");
        switch (choice)
        {
        case 1:
            point->x = ask_for_int("Sélectionne l'abscisse x : ");
            break;
        case 2:
            point->y = ask_for_int("Sélectionne l'ordonnée y : ");
            break;
        }
    } while (choice != 0);
}

/**
 * Affiche un point dans le terminal.
 *
 * @param point le point à afficher (créé avec create_point)
 */
void print_point(point_t *point)
{
    printf("POINT (%d %d)", point->x, point->y);
}

/** Libère la mémoire d'un point.
 *
 * @param point le point à libérer (créé avec create_point)
 */
void free_point(point_t *point)
{
    free(point);
}