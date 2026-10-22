#include "../includes/style.h"
#include "../includes/utils.h"

/** Créer les styles en mémoire.
 *
 * @param rotation l'angle de rotation, en degrés
 * @param fill_color la couleur de remplissage
 * @param outline_color la couleur du contour
 * @param translate le décalage de la forme
 * @param flip l'inversion : 0 aucune, 1 selon l'axe X (haut ↔ bas), 2 selon l'axe Y (gauche ↔ droite).
 * @return l'adresse du style créé
 */
styles_t *create_styles(
    int rotation,
    char *fill_color,
    char *outline_color,
    point_t *translate,
    int flip)
{
    styles_t *styles = malloc(sizeof(styles_t));
    styles->rotation = rotation;
    styles->fill_color = fill_color;
    styles->outline_color = outline_color;
    styles->translate = translate;
    styles->flip = flip;
    return styles;
}

/**
 * Demande à l'utilisateur les informations d'un style, puis crée le style.
 *
 * Les informations demandées sont la rotation, la couleur de remplissage,
 * la couleur du contour le décalage et l'inversion de la forme.
 *
 * Précondition : la rotation saisie doit être un entier.
 *
 * @return l'adresse du style créé, que la forme qui le reçoit devra libérer
 */
styles_t *ask_for_styles(void)
{
    int rotation = ask_for_int("Quelle est la rotation (en degrés) que vous souhaitez? (Entrez un entier)\n");
    char *fill_color = ask_for_string("Quelle couleur de remplissage voulez-vous?\n");
    char *outline_color = ask_for_string("Quelle couleur de contour voulez-vous?\n");
    point_t *translate = ask_for_point("De combien voulez-vous déplacer la forme? (Entrez un entier)\n");
    int flip = ask_for_int("Voulez-vous inverser la forme? (0 : non, 1 : selon l'axe X, 2 : selon l'axe Y)\n");
    while (flip < 0 || flip > 2)
    {
        flip = ask_for_int("Valeur invalide. Tape 0, 1 ou 2 : ");
    }
    return create_styles(rotation, fill_color, outline_color, translate, flip);
}

/**
 * Modifie les propriétés d'un style via un menu.
 *
 * @param styles Pointeur vers le style à modifier.
 */
void modify_styles(styles_t *styles)
{
    int choice;
    do
    {
        choice = ask_for_int("Chosis la modification du style : \n\t1. La couleur de remplissage\n\t2. La couleur du contour\n\t3. L'angle de rotation\n\t4. Décalage de la forme\n\t5. L'inversion de la forme\n\t0.Quitter\n Choix : ");
        switch (choice)
        {
        case 1:
            free(styles->fill_color);
            styles->fill_color = ask_for_string("Sélectionne la couleur de remplissage : ");
            break;
        case 2:
            free(styles->outline_color);
            styles->outline_color = ask_for_string("Sélectionne la couleur du contour : ");
            break;
        case 3:
            styles->rotation = ask_for_int("Sélectionne l'angle de la rotation : ");
            break;
        case 4:
            modify_point(styles->translate);
            break;
        case 5:
            styles->flip = ask_for_int("Inversion (0 : non, 1 : selon l'axe X, 2 : selon l'axe Y) : ");
            while (styles->flip < 0 || styles->flip > 2)
            {
                styles->flip = ask_for_int("Valeur invalide. Tape 0, 1 ou 2 : ");
            }
            break;
        }
    } while (choice != 0);
}

/**
 * Affiche un style dans le terminal : rotation, couleurs, point de
 * translation et inversion.
 *
 * @param styles le style à afficher (créé avec create_styles)
 */

void print_styles(styles_t *styles)
{
    printf("STYLES (%d %s %s", styles->rotation, styles->fill_color, styles->outline_color);
    print_point(styles->translate);
    printf(" %d)", styles->flip);
}

/** Libère la mémoire d'un style et de son point de translation.
 *
 * @param styles le style à libérer (créé avec create_styles)
 */
void free_styles(styles_t *styles)
{
    free(styles->fill_color);
    free(styles->outline_color);
    free_point(styles->translate);
    free(styles);
}