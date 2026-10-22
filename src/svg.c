#include "../includes/svg.h"

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
void export_styles_svg(FILE *file, styles_t *styles, int center_x, int center_y)
{
    int scale_x = 1;
    int scale_y = 1;
    if (styles->flip == 1)
    {
        scale_y = -1;
    }
    if (styles->flip == 2)
    {
        scale_x = -1;
    }
    fprintf(file, " fill='%s'", styles->fill_color);
    fprintf(file, " stroke='%s'", styles->outline_color);
    fprintf(file, " transform='translate(%d %d)", styles->translate->x, styles->translate->y);
    fprintf(file, " rotate(%d %d %d)", styles->rotation, center_x, center_y);
    fprintf(file, " translate(%d %d) scale(%d %d) translate(%d %d)'", center_x, center_y, scale_x, scale_y, -center_x, -center_y);
}

/**
 * Écrit une ellipse dans un fichier SVG.
 *
 * @param file le fichier SVG ouvert en écriture
 * @param ellipse l'ellipse à écrire
 */
void export_ellipse_svg(FILE *file, ellipse_t *ellipse)
{
    fprintf(file, "<ellipse");
    fprintf(file, " cx='%d'", ellipse->center->x);
    fprintf(file, " cy='%d'", ellipse->center->y);
    fprintf(file, " rx='%d'", ellipse->rx);
    fprintf(file, " ry='%d'", ellipse->ry);
    export_styles_svg(file, ellipse->styles, ellipse->center->x, ellipse->center->y);
    fprintf(file, " />\n");
}

/**
 * Écrit un rectangle dans un fichier SVG.
 *
 * @param file le fichier SVG ouvert en écriture
 * @param rectangle le rectangle à écrire
 */
void export_rectangle_svg(FILE *file, rectangle_t *rectangle)
{
    int center_x = rectangle->origine->x + rectangle->length / 2;
    int center_y = rectangle->origine->y + rectangle->width / 2;

    fprintf(file, "<rect");
    fprintf(file, " x='%d'", rectangle->origine->x);
    fprintf(file, " y='%d'", rectangle->origine->y);
    fprintf(file, " width='%d'", rectangle->length);
    fprintf(file, " height='%d'", rectangle->width);
    export_styles_svg(file, rectangle->styles, center_x, center_y);
    fprintf(file, " />\n");
}

/**
 * Écrit une ligne dans un fichier SVG.
 *
 * @param file le fichier SVG ouvert en écriture
 * @param line la ligne à écrire
 */
void export_line_svg(FILE *file, line_t *line)
{
    int center_x = (line->start->x + line->finish->x) / 2;
    int center_y = (line->start->y + line->finish->y) / 2;

    fprintf(file, "<line");
    fprintf(file, " x1='%d'", line->start->x);
    fprintf(file, " y1='%d'", line->start->y);
    fprintf(file, " x2='%d'", line->finish->x);
    fprintf(file, " y2='%d'", line->finish->y);
    export_styles_svg(file, line->styles, center_x, center_y);
    fprintf(file, " />\n");
}

/**
 * Écrit une polyligne dans un fichier SVG.
 *
 * @param file le fichier SVG ouvert en écriture
 * @param polyline la polyligne à écrire
 */
void export_polyline_svg(FILE *file, polyline_t *polyline)
{
    int sum_x = 0;
    int sum_y = 0;

    for (int i = 0; i < polyline->count; i++)
    {
        sum_x = sum_x + polyline->points[i]->x;
        sum_y = sum_y + polyline->points[i]->y;
    }

    int center_x = sum_x / polyline->count;
    int center_y = sum_y / polyline->count;

    fprintf(file, "<polyline points='");
    for (int i = 0; i < polyline->count; i++)
    {
        fprintf(file, "%d,%d ", polyline->points[i]->x, polyline->points[i]->y);
    }
    fprintf(file, "'");
    export_styles_svg(file, polyline->styles, center_x, center_y);
    fprintf(file, " />\n");
}

/**
 * Écrit un polygone dans un fichier SVG.
 *
 * @param file le fichier SVG ouvert en écriture
 * @param polygon le polygone à écrire
 */
void export_polygon_svg(FILE *file, polygon_t *polygon)
{
    int sum_x = 0;
    int sum_y = 0;

    for (int i = 0; i < polygon->count; i++)
    {
        sum_x = sum_x + polygon->points[i]->x;
        sum_y = sum_y + polygon->points[i]->y;
    }

    int center_x = sum_x / polygon->count;
    int center_y = sum_y / polygon->count;

    fprintf(file, "<polygon points='");
    for (int i = 0; i < polygon->count; i++)
    {
        fprintf(file, "%d,%d ", polygon->points[i]->x, polygon->points[i]->y);
    }
    fprintf(file, "'");
    export_styles_svg(file, polygon->styles, center_x, center_y);
    fprintf(file, " />\n");
}

/**
 * Écrit une forme dans un fichier SVG.
 *
 * Appelle la fonction d'export qui correspond au type de la forme
 * (export_ellipse_svg, export_rectangle_svg, export_line_svg, export_polyline_svg ou export_polygon_svg).
 *
 * @param file le fichier SVG ouvert en écriture
 * @param shape la forme à écrire
 */
void export_shape_svg(FILE *file, shape_t *shape)
{
    switch (shape->type)
    {
    case SHAPE_ELLIPSE:
        export_ellipse_svg(file, shape->data.ellipse);
        break;
    case SHAPE_RECTANGLE:
        export_rectangle_svg(file, shape->data.rectangle);
        break;
    case SHAPE_LINE:
        export_line_svg(file, shape->data.line);
        break;
    case SHAPE_POLYLINE:
        export_polyline_svg(file, shape->data.polyline);
        break;
    case SHAPE_POLYGON:
        export_polygon_svg(file, shape->data.polygon);
        break;
    }
}
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
void drawing_export_svg(drawing_t *drawing, char *filename)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Impossible de créer le fichier %s.\n", filename);
        return;
    }

    fprintf(file, "<svg xmlns='http://www.w3.org/2000/svg'");
    fprintf(file, " width='%d' height='%d'", drawing->viewport->width, drawing->viewport->height);
    fprintf(file, " viewBox='0 0 %d %d'>\n", drawing->viewport->width, drawing->viewport->height);

    for (int i = 0; i < drawing->capacity; i++)
    {
        if (drawing->shapes[i] != NULL)
        {
            fprintf(file, "  ");
            export_shape_svg(file, drawing->shapes[i]);
        }
    }

    fprintf(file, "</svg>\n");
    fclose(file);
    printf("Dessin exporté dans %s\n", filename);
}