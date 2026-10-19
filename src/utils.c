#include "../includes/utils.h"

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
 * Demande un mot (sans espace) à l'utilisateur, par exemple une couleur.
 *
 * Affiche le message, puis lit un mot au clavier. Seuls les 49 premiers
 * caractères sont conservés. Le texte est copié dans une zone de mémoire
 * réservée avec malloc : l'appelant doit la libérer avec free (ou la
 * confier à un style, qui la libère dans free_styles).
 *
 * @param message la question affichée avant la saisie
 * @return l'adresse du mot saisi (vide si la saisie échoue)
 */
char* ask_for_string(char *message)
{
    printf("%s", message);
    char* text = malloc(sizeof(char) * 50);
    scanf("%49s", text);
    return text;
}