#include "../includes/rectangle.h"
#include "../includes/utils.h"

/** Créer un rectangle en mémoire.
 * 
 * @param length la longueur du rectangle
 * @param width la largeur du rectangle
 * @param origine le coin en haut à gauche
 * @param styles le style du rectangle
 * @return l'adresse du rectangle crée
 */
rectangle_t *create_rectangle(
    int length,
    int width,
    point_t *origine,
    styles_t *styles)
{
    rectangle_t *rectangle = malloc(sizeof(rectangle_t));
    rectangle->length = length;
    rectangle->width = width;
    rectangle->origine = origine;
    rectangle->styles = styles;
    return rectangle;
}

/**
 * Demande à l'utilisateur de saisir les paramètres d'un rectangle.
 * 
 * @return Pointeur vers le rectangle créée à partir des saisies. 
 */
rectangle_t* ask_for_rectangle(void)
{
    int length = ask_for_int ("Quelle longueur pour le rectangle souhaitez-vous? (Entrez un entier)\n");
    int width = ask_for_int ("Quelle largeur pour le rectangle souhaitez-vous? (Entrez un entier)\n");
    point_t* origine = ask_for_point ("D'où voulez-vous que le rectangle parte?\n");
    styles_t* styles = ask_for_styles ();

    return create_rectangle(length, width, origine, styles);
}

/**
 * Modifie les propriétés d'un rectangle via un menu.
 * 
 * @param rectangle Pointeur vers le rectangle à modifier.
 */
void modify_rectangle(rectangle_t *rectangle)
{
    int choice;
    do
    {
        choice = ask_for_int ("Choisi la modification de ton rectangle : \n\t1. L'origine\n\t2. Le style\n\t3. La longueur\n\t4. La largeur\n\t0.Quitter\n Choix : ");
        switch (choice)
        {
        case 1: modify_point(rectangle->origine); break;
        case 2: modify_styles(rectangle->styles); break;
        case 3: rectangle->length = ask_for_int ("Choisi la longueur du rectangle : "); break;
        case 4: rectangle->width = ask_for_int ("Choisi la largeur du rectangle : "); break;
        }
        
    } while (choice !=0);
}

/**
 * Affiche un rectangle dans le terminal : sa longueur, sa largeur, son
 * origine et son style.
 *
 * @param rectangle le rectangle à afficher (créé avec create_rectangle)
 */
void print_rectangle(rectangle_t *rectangle)
{
    printf("RECTANGLE (%d %d", rectangle->length, rectangle->width);
    print_point(rectangle->origine);
    print_styles(rectangle->styles);
    printf(")\n");
}

/** 
 * Libère la mémoire d'un rectangle, de son origine et de son style.
 * 
 * @param rectangle le rectangle à libérer (créé avec create_rectangle)
*/
void free_rectangle(rectangle_t *rectangle)
{
    free_point(rectangle->origine);
    free_styles(rectangle->styles);
    free(rectangle);
}