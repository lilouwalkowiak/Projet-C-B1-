#ifndef SVG_H
#define SVG_H

#include <stdio.h>
#include "style.h"
#include "ellipse.h"
#include "rectangle.h"
#include "line.h"
#include "shape.h"
#include "drawing.h"

/**
 * Écrit dans un fichier SVG les attributs de style d'une forme.
 *
 * Écrit la couleur de remplissage, la couleur du contour, puis la
 * translation et la rotation. La rotation se fait autour du point
 * (center_x, center_y), qui est le centre de la forme.
 *
 * @param file le fichier SVG ouvert en écriture
 * @param styles les styles à écrire
 * @param center_x l'abscisse du centre de la forme
 * @param center_y l'ordonnée du centre de la forme
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
 * Écrit une forme dans un fichier SVG.
 *
 * Appelle la fonction d'export qui correspond au type de la forme
 * (export_ellipse_svg, export_rectangle_svg ou export_line_svg).
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