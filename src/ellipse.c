#include "../includes/ellipse.h"
#include "../includes/utils.h"

/** Créer une ellipse en mémoire.
 * 
 * @param rx le rayon horizontal
 * @param ry le rayon vertical
 * @param center pointeur vers le point central de l'ellipse
 * @param styles pointeur vers le style de l'ellipse
 * @return l'adresse de l'ellipse crée
 */
ellipse_t *create_ellipse(int rx,
                          int ry,
                          point_t *center,
                          styles_t *styles)
{
    ellipse_t *ellipse = malloc(sizeof(ellipse_t));
    ellipse->rx = rx;
    ellipse->ry = ry;
    ellipse->center = center;
    ellipse->styles = styles;
    return ellipse;
}

/**
 * Demande à l'utilisateur de saisir les paramètres d'une ellipse.
 * 
 * @return Pointeur vers l'ellipse créée à partir des saisies. 
 */
ellipse_t* ask_for_ellipse(void)
{
    int rx = ask_for_int("Quelle mesure voulez-vous donner à votre rayon horizontal? (Entrez un entier)\n");
    int ry = ask_for_int("Quelle mesure voulez-vous donner à votre rayon vertical? (Entrez un entier)\n");
    point_t* center = ask_for_point("Quelle mesure souhaitez-vous pour le centre de cette forme?\n");
    styles_t* styles = ask_for_styles ();
    
    return create_ellipse(rx, ry, center, styles);
}

/**
 * Modifie les propriétés d'une ellipse via un menu.
 * 
 * @param ellipse Pointeur vers l'ellipse à modifier.
 */
void modify_ellipse(ellipse_t *ellipse)
{
    int choice;
    do
    {
        choice = ask_for_int ("Choisi la modification de ton ellipse : \n\t1. Le centre\n\t2. Le style\n\t3. Le premier rayon\n\t4. Le second rayon\n\t0.Quitter\n Choix : ");
        switch (choice)
        {
        case 1: modify_point(ellipse->center); break;
        case 2: modify_styles(ellipse->styles); break;
        case 3: ellipse->rx = ask_for_int ("Choisi le premier rayon de l'ellipse : "); break;
        case 4: ellipse->ry = ask_for_int ("Choisi le second rayon de l'ellipse : "); break;
        }
        
    } while (choice != 0);  
}

/**
 * Affiche une ellipse dans le terminal : ses deux rayons, son centre et
 * son style.
 *
 * @param ellipse l'ellipse à afficher (créée avec create_ellipse)
 */
void print_ellipse(ellipse_t *ellipse)
{
    printf("ELLIPSE (%d %d", ellipse->rx, ellipse->ry);
    print_point(ellipse->center);
    print_styles(ellipse->styles);
    printf(")\n");
}

/**
 * Libère la mémoire d'une ellipse, de son centre et de son style.
 * 
 * @param ellipse l'ellipse à libérer (créée avec create_ellipse)
 */
void free_ellipse(ellipse_t *ellipse)
{
    free_point(ellipse->center);
    free_styles(ellipse->styles);
    free(ellipse);
}