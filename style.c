/**
 * Fonctions de création, d'affichage et de suppression des points, des
 * styles et des formes, et fonctions de saisie des valeurs au clavier.
 *
 * Chaque fonction create_... réserve de la mémoire avec malloc et renvoie
 * l'adresse de l'élément créé. Les éléments reçus en paramètre (point,
 * style) ne sont pas copiés : la forme les garde, et c'est elle qui les
 * libère dans sa fonction free_...
 */

#include <stdio.h>
#include <stdlib.h>
#include "style.h"

/** Créer un point en mémoire.
 *
 * @param x l'abscisse du point
 * @param y l'ordonnée du point
 * @return l'adresse du point crée
 */
point_t *create_point(int x, int y)
{
    point_t *point = malloc(sizeof(point_t));
    point->x = x;
    point->y = y;
    return point;
}

/** Créer les styles en mémoire.
 *
 * @param rotation l'angle de rotation, en degrés
 * @param fill_color la couleur de remplissage
 * @param outline_color la couleur du contour
 * @param translate le décalage de la forme
 * @return l'adresse du style crée
 */
styles_t *create_styles(
    unsigned int rotation,
    char *fill_color,
    char *outline_color,
    point_t *translate)
{
    styles_t *styles = malloc(sizeof(styles_t));
    styles->rotation = rotation;
    styles->fill_color = fill_color;
    styles->outline_color = outline_color;
    styles->translate = translate;
    return styles;
}

/** Créer une ellipse en mémoire.
 * 
 * @param rx le rayon horizontal
 * @param ry le rayon vertical
 * @param center le centre de l'ellipse
 * @param styles le style de l'ellipse
 * @return l'adresse de l'ellipse crée
 */
ellipse_t *create_ellipse(unsigned int rx,
                          unsigned int ry,
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

/** Créer un rectangle en mémoire.
 * 
 * @param length la longueur du rectangle
 * @param width la largeur du rectangle
 * @param origine le coin en haut à gauche
 * @param styles le style du rectangle
 * @return l'adresse du rectangle crée
 */
rectangle_t *create_rectangle(
    unsigned int length,
    unsigned int width,
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

/** Créer une ligne droite en mémoire.
 * 
 * @param start le point de départ
 * @param finish le point d'arrivée
 * @param styles le style de la ligne
 * @return l'adresse de la ligne crée
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

/** Libère la mémoire d'un point .
 * 
 * @param point le point à libérer (crée avec create_point)
*/
void free_point(point_t *point)
{
    free(point);
}

/** Libère la mémoire d'un style et de son point de translation.  
 * 
 * @param styles le style à libérer (crée avec create_styles)
*/
void free_styles(styles_t *styles)
{
    free(styles->fill_color);
    free(styles->outline_color);
    free_point(styles->translate);
    free(styles);
}

/**
 * Libère la mémoire d'une ellipse, de son centre et de son style.
 * 
 * @param ellipse l'ellipse à libérer (créée avec create_ellipse)
 */
void free_ellipse(ellipse_t *ellipse)
{
    free(ellipse->center);
    free(ellipse->styles);
    free(ellipse);
}

/** 
 * Libère la mémoire d'un rectangle, de son origine et de son style.
 * 
 * @param rectangle le rectangle à libérer (créé avec create_rectangle)
*/
void free_rectangle(rectangle_t *rectangle)
{
    free(rectangle->origine);
    free(rectangle->styles);
    free(rectangle);
}

/**
 * Libère la mémoire d'une ligne, de ses deux points et de son style.
 * 
 * @param line la ligne à libérer (créée avec create_line)
 */
void free_line(line_t *line)
{
    free(line->start);
    free(line->finish);
    free(line->styles);
    free(line);
}

/**
 * Affiche un point dans le terminal.
 *
 * @param point le point à afficher (créé avec create_point)
 */
void print_point(point_t *point)
{
    printf("POINT (%d %d)\n", point->x, point->y);
}

/**
 * Affiche un style dans le terminal : rotation, couleurs et point de
 * translation.
 *
 * @param styles le style à afficher (créé avec create_styles)
 */

void print_styles(styles_t *styles)
{
    printf("STYLES (%d %s %s", styles->rotation, styles->fill_color, styles->outline_color);
    print_point(styles->translate);
    printf(")\n");
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
 * Affiche une ligne dans le terminal : ses deux points et son style.
 *
 * @param line la ligne à afficher (créée avec create_line)
 */
void print_line(line_t *line)
{
    printf("Line");
    print_point(line->start);
    print_point(line->finish);
    print_styles(line->styles);
    printf(")\n");
}

/**
 * Demande un nombre entier à l'utilisateur.
 *
 * Affiche le message, puis lit la réponse au clavier.
 *
 * @param message la question affichée avant la saisie
 * @return l'entier saisi par l'utilisateur
 */
int ask_for_int(char *message)
{
    printf("%s", message);
    int v = 0;
    scanf("%d", &v);
    return v;
}

/**
 * Demande un caractère à l'utilisateur.
 *
 * Affiche le message, puis lit un seul caractère au clavier. 
 *
 * @param message la question affichée avant la saisie
 * @return le caractère saisi par l'utilisateur
 */
char* ask_for_string(char *message)
{
    printf("%s", message);
    char* text = malloc(sizeof(char) * 50);
    scanf("%s", text);
    return text;
}

/**
 * Demande à l'utilisateur les deux coordonnées d'un point, puis crée le point.
 *
 * @param message le titre affiché avant de demander les coordonnées
 * @return l'adresse du point créé
 */
point_t* ask_for_point(char* message)
{
    printf("%s", message);
    int x = ask_for_int("Quelle abscisse souhaitez-vous? (Entrez un entier)\n");
    int y = ask_for_int("Quelle ordonnée souhaitez-vous? (Entrez un entier)\n");

    return create_point(x,y);
} 

/**
 * Demande à l'utilisateur les informations d'un style, puis crée le style.
 *
 * Les informations demandées sont la rotation, la couleur de remplissage,
 * la couleur du contour et le décalage de la forme.
 *
 * Précondition : la rotation saisie doit être un entier positif.
 *
 * @return l'adresse du style créé, que la forme qui le reçoit devra libérer
 */
styles_t* ask_for_styles(void)
{
    int rotation = ask_for_int("Quelle est la rotation (en degrés) que vous souhaitez? (Entrez un entier)\n");
    char* fill_color = ask_for_string("Quelle couleur de remplissage voulez-vous?\n");
    char* outline_color = ask_for_string("Quelle couleur de contour voulez-vous?\n");
    point_t* translate = ask_for_point("De combien voulez-vous déplacer la forme? (Entrez un entier)\n");

    return create_styles(rotation, fill_color, outline_color,translate);
}

ellipse_t* ask_for_ellipse(void)
{
    int rx = ask_for_int("Quelle mesure voulez-vous donner à votre rayon horizontal? (Entrez un entier)\n");
    int ry = ask_for_int("Quelle mesure voulez-vous donner à votre rayon vertical? (Entrez un entier)\n");
    point_t* center = ask_for_point("Quelle mesure souhaitez-vous pour le centre de cette forme?\n");
    styles_t* styles = ask_for_styles ();
    
    return create_ellipse(rx, ry, center, styles);
}

rectangle_t* ask_for_rectangle(void)
{
    int length = ask_for_int ("Quelle longueur pour le rectangle souhaitez-vous? (Entrez un entier)\n");
    int width = ask_for_int ("Quelle largeur pour le rectangle souhaitez-vous? (Entrez un entier)\n");
    point_t* origine = ask_for_point ("D'où voulez-vous que le rectangle parte?\n");
    styles_t* styles = ask_for_styles ();

    return create_rectangle(length, width, origine, styles);
}

line_t* ask_for_line(void)
{
    point_t* start = ask_for_point ("D'où le point de départ de la ligne doit commencer?\n");
    point_t* finish = ask_for_point ("D'où le point de d'arrivée de la ligne doit finir?\n");
    styles_t* styles = ask_for_styles();

    return create_line(start, finish, styles);
}

void modify_point(point_t *point)
{
    int choice;
    do
    {
        choice = ask_for_int("Choisi la modification :\n\t1. x L'abscisse\n\t2. y L'ordonnée\n\t0.Quitter\n Choix : ");
        switch (choice)
        {
        case 1: point->x = ask_for_int("Selectionne l'abscisse x : "); break;
        case 2: point->y = ask_for_int("Selectionne l'ordonnée y : "); break;
        
        }
    } while (choice != 0);
    
}

void modify_styles(styles_t *styles)
{
    int choice;
    do 
    {
        choice = ask_for_int("Chosi la modification du style : \n\t1. La couleur de remplissage\n\t2. La couleur du contour\n\t3. L'angle de rotation\n\t4. Décalage de la forme\n\t0.Quitter\n Choix : ");
        switch (choice)
        {
        case 1: styles->fill_color = ask_for_string("Sélectionne la couleur de remplissage : "); break;
        case 2: styles->outline_color = ask_for_string("Sélectionne la couleur du contour : "); break;
        case 3: styles->rotation = ask_for_int("Sélectionne l'angle de la rotation : "); break;
        case 4: modify_point(styles->translate); break;
        }
    }
    while (choice != 0);
}

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

void modify_line(line_t *line)
{
    int choice;
    do
    {
        choice = ask_for_int ("Choisi la modification de la ligne : \n\t1. Le point de départ\n\t2. Le point d'arrivée\n\t3. Le style\n\t0.Quitter\n Choix : ");
        switch (choice)
        {
            case 1: modify_point(line->start); break;
            case 2: modify_point(line->finish); break;
            case 3: modify_styles(line->styles); break;
        }
    } while (choice !=0);
}