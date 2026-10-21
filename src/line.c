#include "../includes/line.h"
#include "../includes/utils.h"

/** Créer une ligne droite en mémoire.
 *
 * @param start le point de départ
 * @param finish le point d'arrivée
 * @param styles le style de la ligne
 * @return l'adresse de la ligne créée
 */
line_t *create_line(
    point_t *start,
    point_t *finish,
    styles_t *styles)
{
    line_t *line = malloc(sizeof(line_t));
    line->start = start;
    line->finish = finish;
    line->styles = styles;
    return line;
}

/**
 * Demande à l'utilisateur de saisir les paramètres d'une ligne.
 *
 * @return Pointeur vers la ligne créée à partir des saisies.
 */
line_t *ask_for_line(void)
{
    point_t *start = ask_for_point("D'où le point de départ de la ligne doit commencer?\n");
    point_t *finish = ask_for_point("D'où le point de d'arrivée de la ligne doit finir?\n");
    styles_t *styles = ask_for_styles();

    return create_line(start, finish, styles);
}
/**
 * Modifie les propriétés d'une ligne via un menu.
 *
 * @param line Pointeur vers la ligne à modifier.
 */
void modify_line(line_t *line)
{
    int choice;
    do
    {
        choice = ask_for_int("Choisi la modification de la ligne : \n\t1. Le point de départ\n\t2. Le point d'arrivée\n\t3. Le style\n\t0.Quitter\n Choix : ");
        switch (choice)
        {
        case 1:
            modify_point(line->start);
            break;
        case 2:
            modify_point(line->finish);
            break;
        case 3:
            modify_styles(line->styles);
            break;
        }
    } while (choice != 0);
}

/**
 * Affiche une ligne dans le terminal : ses deux points et son style.
 *
 * @param line la ligne à afficher (créée avec create_line)
 */
void print_line(line_t *line)
{
    printf("LINE");
    print_point(line->start);
    print_point(line->finish);
    print_styles(line->styles);
    printf(")\n");
}

/**
 * Libère la mémoire d'une ligne, de ses deux points et de son style.
 *
 * @param line la ligne à libérer (créée avec create_line)
 */
void free_line(line_t *line)
{
    free_point(line->start);
    free_point(line->finish);
    free_styles(line->styles);
    free(line);
}