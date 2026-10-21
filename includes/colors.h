#ifndef COLORS_H
#define COLORS_H

/**
 * Les couleurs sont définies avec des codes ANSI.
 * Ils permettent de colorer le texte dans le terminal.
 *
 * Le format utilisé est :
 * \033[38;2;R;G;Bm
 *
 * - \033 : caractère spécial qui commence la séquence ANSI.
 * - [38;2 : indique qu'on choisit une couleur pour le texte
 *   en utilisant le format RGB.
 * - R : quantité de rouge, de 0 à 255.
 * - G : quantité de vert, de 0 à 255.
 * - B : quantité de bleu, de 0 à 255.
 * - m : termine la commande de couleur.
 *
 * Pour obtenir une couleur pastel, on choisit généralement
 * des couleurs assez claires et douces, souvent en mélangeant
 * les couleurs avec beaucoup de blanc.
 *
 * Le blanc correspond à RGB(255, 255, 255).
 * Plus les valeurs se rapprochent du blanc, plus la couleur
 * devient claire.
 */

/** Réinitialise la couleur du texte à la valeur normale du terminal. */
#define RESET "\033[0m"

/** Couleurs pastel */

/** Bleu pastel : RGB(100, 149, 190). */
#define BLEU "\033[38;2;100;149;190m"
/** Vert menthe : RGB(105, 165, 135). */
#define MENTHE "\033[38;2;105;165;135m"
/** Rose pastel : RGB(205, 125, 155). */
#define ROSE "\033[38;2;205;125;155m"
/** Pêche pastel : RGB(205, 145, 115). */
#define PECHE "\033[38;2;205;145;115m"
/** Lavande pastel : RGB(160, 140, 195). */
#define LAVANDE "\033[38;2;160;140;195m"
/** Gris très clair, proche du blanc : RGB(230, 230, 240). */
#define BLANC "\033[38;2;230;230;240m"

#endif
