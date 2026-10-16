#ifndef STYLES
#define STYLES

/** Représentation des styles et formes du projet.
*
* Ce fichier définit les structures de base: le point et le style (couleurs, rotation, translation), ainsi que les formes qui les utilisent.
*/

/** Représente un point dans le plan.  */
typedef struct point_s
{
    /** Abscisse du point (position horizontale). */
    int x;
    /** Ordonnée du point (position verticale). */
    int y;
} point_t;

/** Représente le style d'une forme : couleurs, rotation et translation */
typedef struct styles_s
{
    /** Angle de rotation de la forme, en degrés. */
    unsigned int rotation;
    /** Couleur de remplissage de la forme. */
    char* fill_color;
    /** Couleur du contour de la forme. */
    char* outline_color;
    /** Décalage de la forme : déplacement en x et en y. */
    point_t* translate;
} styles_t;

/**
* Représente une ellipse
*
* Un cercle est une ellips dont les deux rayons sont égaux. 
*/
typedef struct ellipse_s                
{
   /** Premier rayon (horizontal). */
    unsigned int rx;
    /** Second rayon (vertical). */
    unsigned int ry;
    /** Centre de l'ellipse. */
    point_t* center;
    /** Style de l'ellipse. */
    styles_t* styles;
} ellipse_t;

/** 
* Représente un rectangle
* Un carré est un rectangle dont la longueur et la largeur sont égales.
*/
typedef struct rectangle_s 
{ 
    /** Longueur du rectangle. */
    unsigned int length;
    /** Largeur du rectangle. */
    unsigned int width;
   /** Coin en haut à gauche du rectangle. */
    point_t* origine;                 
    /** Style du rectangle. */
    styles_t* styles;
} rectangle_t;

/** Représente une ligne droite entre deux points. */
typedef struct line_s
{
    /** Point de départ de la ligne */
    point_t* start;
    /** Point d'arrivée de la ligne */
    point_t* finish;
    /** Style de la ligne */
    styles_t* styles;
}line_t;


#endif