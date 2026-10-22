#ifndef SVG_H
#define SVG_H

#include <stdio.h>
#include "style.h"
#include "ellipse.h"
#include "rectangle.h"
#include "line.h"
#include "polyline.h"
#include "polygon.h"
#include "shape.h"
#include "drawing.h"

/**
 * Écrit dans un fichier SVG les attributs de style d'une forme.
 *
 * Écrit la couleur de remplissage, la couleur du contour, puis la
 * transformation : déplacement (translate), rotation (rotate) et
 * inversion (scale).
 *
 * L'inversion est un miroir : scale(1 -1) retourne la forme de haut en bas
 * (axe X), scale(-1 1) la retourne de gauche à droite (axe Y), scale(1 1)
 * ne change rien. Comme scale agit autour du point (0,0), on déplace
 * d'abord le centre de la forme en (0,0), on fait le miroir, puis on
 * remet le centre à sa place. Le SVG applique les transformations de
 * droite à gauche : d'abord l'inversion, puis la rotation, puis le
 * déplacement.
 *
 * @param file le fichier SVG ouvert en écriture
 * @param styles les styles à écrire
 * @param center_x l'abscisse du centre de la forme (centre de rotation et d'inversion)
 * @param center_y l'ordonnée du centre de la forme (centre de rotation et d'inversion)
 */
void export_styles_svg(FILE *file, styles_t *styles, int center_x, int center_y);

/**
 * Écrit une ellipse dans un fichier SVG.
 *
 * @param file le fichier SVG ouvert en écriture
 * @param ellipse l'ellipse à écrire
 */
void export_ellipse_svg(FILE *file, ellipse_t *ellipse);

/**
 * Écrit un rectangle dans un fichier SVG.
 *
 * @param file le fichier SVG ouvert en écriture
 * @param rectangle le rectangle à écrire
 */
void export_rectangle_svg(FILE *file, rectangle_t *rectangle);

/**
 * Écrit une ligne dans un fichier SVG.
 *
 * @param file le fichier SVG ouvert en écriture
 * @param line la ligne à écrire
 */
void export_line_svg(FILE *file, line_t *line);

/**
 * Écrit une polyligne dans un fichier SVG.
 *
 * @param file le fichier SVG ouvert en écriture
 * @param polyline la polyligne à écrire
 */
void export_polyline_svg(FILE *file, polyline_t *polyline);

/**
 * Écrit un polygone dans un fichier SVG.
 *
 * @param file le fichier SVG ouvert en écriture
 * @param polygon le polygone à écrire
 */
void export_polygon_svg(FILE *file, polygon_t *polygon);

/**
 * Écrit une forme dans un fichier SVG.
 *
 * Appelle la fonction d'export qui correspond au type de la forme
 * (export_ellipse_svg, export_rectangle_svg, export_line_svg, export_polyline_svg ou export_polygon_svg).
 *
 * @param file le fichier SVG ouvert en écriture
 * @param shape la forme à écrire
 */
void export_shape_svg(FILE *file, shape_t *shape);

/**
 * Exporte tout le dessin dans un fichier SVG.
 *
 * Crée le fichier, écrit l'en-tête avec la taille du viewport, puis
 * écrit chaque forme du dessin (les cases vides sont ignorées).
 * Les formes sont écrites dans l'ordre des cases : la dernière est
 * dessinée par-dessus les autres.
 *
 * @param drawing le dessin à exporter
 * @param filename le nom du fichier à créer (par exemple "dessin.svg")
 */
void drawing_export_svg(drawing_t *drawing, char *filename);

#endif