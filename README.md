# Projet C — Éditeur de formes graphiques

## Description

Ce projet est une interface en ligne de commande en langage C qui permet de créer, modifier, afficher, supprimer et exporter des formes graphiques inspirées du format SVG.

Le SVG (Scalable Vector Graphics) est un format graphique vectoriel qui représente des formes en deux dimensions sans perte de qualité lors d'un agrandissement. Un SVG est composé :

* D'un **viewport** (zone d'affichage), qui définit la fenêtre visible du dessin.
* D'une liste d'éléments graphiques qui peuvent être positionnés et stylisés.

Le dessin est exporté dans un fichier `.svg`, qui s'ouvre dans un navigateur web.

## Fonctionnalités

### Déjà réalisées

* Ajouter une forme dans une case du dessin (50 cases au maximum)
* Afficher toutes les formes du dessin
* Modifier une forme existante (dimensions, position, couleurs, rotation, translation)
* Supprimer une forme
* Exporter le dessin dans un fichier `.svg` visible dans un navigateur
* Un viewport (largeur et hauteur de la fenêtre) de 800 × 600 par défaut

### Formes prises en charge

* Les ellipses
* Les rectangles
* Les lignes
* Les cercles et les carrés s'obtiennent avec une ellipse dont les deux rayons sont égaux, et un rectangle dont la longueur est égale à la largeur.

### Non réalisé (bonus)

* Les enchaînements de lignes (polylignes)
* Les polygones
* Les trajectoires (chemins)
* Les groupes de formes
* L'enregistrement et le chargement d'un dessin dans un fichier du programme (seul l'export SVG existe)

## Contraintes techniques

* Langage de programmation : C
* Standard utilisé : C99
* Compilateur : GCC
* Bibliothèques : uniquement les bibliothèques natives (`stdio.h`, `stdlib.h`)
* Documentation du code : commentaires au format Javadoc
* Compilation et nettoyage : `Makefile`

## Prérequis

* GCC compatible avec le standard C99. Le `Makefile` utilise `gcc-16` ; si ton GCC s'appelle autrement, change la ligne `CC = gcc-16` en haut du `Makefile`.
* GNU Make (outil qui automatise la compilation du programme C)
* Un navigateur web pour visualiser les fichiers SVG

## Compilation

```bash
make build
```

Cette commande crée le programme `main`.

## Lancement

```bash
./main
```

Ou, pour compiler puis lancer :

```bash
make run
```

## Nettoyage

```bash
make clean
```

Cette commande supprime le programme `main`.

## Utilisation

Au lancement, un menu coloré s'affiche :

| Choix | Action |
|---|---|
| 1 | Ajouter une forme : choisir une case (de 0 à 49), puis le type (1 ellipse, 2 rectangle, 3 ligne), puis ses valeurs |
| 2 | Afficher les formes du dessin, avec le numéro de leur case |
| 3 | Modifier une forme : choisir sa case, puis la propriété à changer |
| 4 | Supprimer une forme : choisir sa case |
| 5 | Exporter le dessin en SVG : donner un nom de fichier qui finit par `.svg` |
| 0 | Quitter le programme |

### Exemple

1. Taper `1`, case `0`, type `1` (ellipse), rayons `80` et `40`, centre `200` puis `150`, rotation `0`, couleurs `red` et `black`, translation `0` et `0`.
2. Taper `5` et donner le nom `dessin.svg`.
3. Taper `0` pour quitter.
4. Ouvrir `dessin.svg` dans un navigateur.

Les couleurs doivent être des noms ou codes SVG valides (`red`, `blue`, `green`, `#ff0000`…). Une couleur et un nom de fichier ne peuvent pas contenir d'espace.

## Organisation du projet

* `main.c` : point d'entrée du programme et menu interactif
* `Makefile` : commandes de compilation et de nettoyage
* `README.md` : présentation du projet
* `includes/` : les fichiers d'en-tête `.h` (structures et prototypes)
* `src/` : les fichiers `.c` (le code)

| Notion | Fichiers | Rôle |
|---|---|---|
| Point | `point.h`, `point.c` | un point (x, y) |
| Styles | `style.h`, `style.c` | couleurs, rotation et translation d'une forme |
| Ellipse | `ellipse.h`, `ellipse.c` | une ellipse |
| Rectangle | `rectangle.h`, `rectangle.c` | un rectangle |
| Ligne | `line.h`, `line.c` | une ligne |
| Forme | `shape.h`, `shape.c` | une forme quelconque (ellipse, rectangle ou ligne) |
| Viewport | `viewport.h`, `viewport.c` | la fenêtre du dessin |
| Dessin | `drawing.h`, `drawing.c` | le tableau de formes |
| SVG | `svg.h`, `svg.c` | l'export en fichier SVG |
| Outils | `utils.h`, `utils.c` | lecture d'un entier ou d'un mot au clavier |
| Couleurs | `colors.h` | couleurs du menu dans le terminal |

## Choix de conception

* **Un tableau de 50 cases** : chaque case est vide (`NULL`) ou contient une forme. On choisit une case grâce à son index, sans rien décaler quand on supprime. Le tableau est créé avec `calloc` pour que toutes les cases soient vides au départ.
* **Une `union` dans `shape_t`** : elle permet de ranger une ellipse, un rectangle ou une ligne dans le même tableau. Le champ `type` indique laquelle est stockée.
* **Un fichier par notion** : chaque `.h` contient la structure et les prototypes, chaque `.c` le code. Le projet reste lisible.
* **Tout le format SVG est dans `svg.c`** : pour changer de format, il suffit de modifier ce fichier.
* **Mémoire** : chaque forme libère ce qu'elle contient (points et styles), puis elle-même. Le dessin libère ses formes, son tableau, son viewport, puis lui-même.

## Difficultés rencontrées
## Difficultés rencontrées

**Démarrer le projet.** Je n'avais aucune base en algorithmique ni en langage C, et je ne savais pas par où commencer. Je me sentais perdue, j'ai eu beaucoup d'angoisse et je pensais que je n'y arriverais jamais. Je ne connaissais pas du tout les fonctions, ni comment elles s'utilisent.

**Organiser le code.** Je ne savais pas comment découper le projet en fichiers, ni quoi mettre dans un `.h` et un `.c`. L'intervenant nous a montré une arborescence pour découper le projet. J'ai donc fait un fichier par notion (point, style, ellipse, rectangle, ligne, forme, viewport, dessin, SVG), avec les `.h` dans `includes/` et les `.c` dans `src/`.

**Comprendre les messages d'erreur.** Les messages du compilateur sont en anglais et difficiles à comprendre : je ne savais pas à quoi ils faisaient référence. J'ai du demandé de l'aide à mes camarades, à l'intervenant et à une IA.

**Gérer la mémoire.** Il faut libérer dans le bon ordre : le contenu d'une forme avant la forme elle-même. J'ai vérifié avec `leaks` qu'il n'y avait plus de fuite.

**Avancer avec l'aide de l'intervenant.** Il nous a aidés petit à petit avec des exemples : il commençait le code et on continuait. J'ai avancé par petites étapes, en testant à chaque fois.

**Ce qui reste difficile.** J'ai peur de ne pas savoir tout refaire seule si je recommençais.

## Limites et améliorations possibles

* Le tableau est limité à 50 formes.
* La taille du viewport est fixée à 800 × 600 et ne peut pas être changée depuis le menu.
* Rien ne vérifie que les tailles (rayons, longueurs) sont positives.
* Les couleurs ne sont pas vérifiées : une couleur invalide donne un SVG sans couleur.
* Il n'est pas possible de charger un dessin depuis un fichier.

## Tests et fiabilité

Le programme a été testé sur :

* l'ajout, l'affichage, la modification et la suppression de chaque forme ;
* les saisies invalides (lettres, index négatif, index trop grand, case déjà occupée) ;
* l'export SVG, ouvert dans un navigateur ;
* les fuites mémoire, avec la commande :

```bash
leaks --atExit -- ./main
```

## Gestion des versions

Le projet utilise Git pour suivre les modifications. Le dépôt distant est hébergé sur GitHub.

Commandes principales :

* `git status` : consulter l'état des fichiers.
* `git add` : préparer les modifications.
* `git commit -m "message"` : enregistrer un point de sauvegarde local.
* `git push` : envoyer les commits sur GitHub.
* `git log --oneline` : consulter l'historique des commits.

## Références

* [Documentation MDN sur l'élément SVG](https://developer.mozilla.org/fr/docs/Web/SVG/Reference/Element/svg)

## État du projet

Version fonctionnelle : création, modification, affichage, suppression et export SVG de trois types de formes. Les autres formes et le chargement de fichier sont laissés en bonus.