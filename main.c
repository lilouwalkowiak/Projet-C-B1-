/**
 * Programme principal : éditeur de formes en ligne de commande.
 *
 * Affiche un menu en couleurs pastel. L'utilisateur peut ajouter,
 * afficher, modifier et supprimer des formes, jusqu'à ce qu'il quitte.
 */
#include <stdio.h>
#include <stdlib.h>
#include "includes/colors.h"
#include "includes/utils.h"
#include "includes/shape.h"
#include "includes/drawing.h"
#include "includes/svg.h"

/**
 * Affiche le menu principal avec des couleurs pastel.
 *
 * Chaque option est numérotée : 1 ajouter, 2 afficher, 3 modifier,
 * 4 supprimer, 5 exporter en SVG et 0 quitter.
 */
void afficher_menu(void)
{
    printf("\n");
    printf(LAVANDE "====================================\n" RESET);
    printf(LAVANDE "          MENU PRINCIPAL\n" RESET);
    printf(LAVANDE "====================================\n" RESET);

    printf(BLEU "  1. " RESET BLANC "Ajouter une forme\n" RESET);
    printf(MENTHE "  2. " RESET BLANC "Afficher les formes\n" RESET);
    printf(PECHE "  3. " RESET BLANC "Modifier une forme\n" RESET);
    printf(ROSE "  4. " RESET BLANC "Supprimer une forme\n" RESET);
    printf(MENTHE "  5. " RESET BLANC "Exporter en SVG\n" RESET);
    printf(LAVANDE "  0. " RESET BLANC "Quitter\n" RESET);

    printf(LAVANDE "====================================\n" RESET);
}

/**
 * Lance le programme et répète le menu jusqu'à ce que l'utilisateur quitte.
 *
 * Crée un dessin vide, puis la boucle while demande un choix. Le switch
 * appelle la fonction du dessin qui correspond. À la fin, la mémoire
 * du dessin est libérée.
 *
 * @return 0 si le programme se termine normalement.
 */
int main(void)
{
    drawing_t *drawing = drawing_create();

    int choix = -1;
    int index;
    char *filename;

    while (choix != 0)
    {
        afficher_menu();
        choix = ask_for_int(BLEU "Votre choix : " RESET);

        switch (choix)
        {
        case 1:
            drawing_print(drawing);
            index = ask_for_int("Ajouter une forme : dans quelle case ? (numéro de 0 à 49) : ");
            insert_shape(drawing, index);
            break;

        case 2:
            drawing_print(drawing);
            break;

        case 3:
            drawing_print(drawing);
            index = ask_for_int("Modifier une forme : quelle case ? (numéro de 0 à 49) : ");
            modify_shape(drawing, index);
            break;

        case 4:
            drawing_print(drawing);
            index = ask_for_int("Supprimer une forme : quelle case ? (numéro de 0 à 49) : ");
            delete_shape(drawing, index);
            break;

        case 5:
            filename = ask_for_string("Nom du fichier (termine par .svg, par exemple dessin.svg) : ");
            drawing_export_svg(drawing, filename);
            free(filename);
            break;

        case 0:
            printf(LAVANDE "Vous sortez du programme. Au revoir !\n" RESET);
            break;

        default:
            printf(ROSE "Choix invalide. Veuillez réessayer.\n" RESET);
            break;
        }
    }

    drawing_free(drawing);

    return 0;
}
