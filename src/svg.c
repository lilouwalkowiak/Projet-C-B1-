#include "../includes/svg.h"

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
void export_styles_svg(FILE *file, styles_t *styles, int center_x, int center_y)
{
    fprintf(file, " fill='%s'", styles->fill_color);
    fprintf(file, " stroke='%s'", styles->outline_color);
    fprintf(file, " transform='translate(%d %d)", styles->translate->x, styles->translate->y);
    fprintf(file, " rotate(%d %d %d)'", styles->rotation, center_x, center_y);
}

/**
 * Écrit une ellipse dans un fichier SVG, sur une ligne.
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
 * Écrit une forme dans un fichier SVG.
 *
 * Appelle la fonction d'export qui correspond au type de la forme
 * (export_ellipse_svg, export_rectangle_svg ou export_line_svg).
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