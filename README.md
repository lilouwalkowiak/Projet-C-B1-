# Projet C — Éditeur de formes graphiques

## Description

Ce projet consiste à développer une interface en ligne de commande en langage C permettant de créer, modifier, enregistrer, charger et visualiser des structures graphiques inspirées du format SVG.

Le SVG (Scalable Vector Graphics) est un format graphique vectoriel qui permet de représenter des formes en deux dimensions sans perte de qualité lors d'un agrandissement.

Une structure graphique est composée :

* D'un **viewport** (zone d'affichage), qui définit la zone visible du dessin.
* D'une liste d'éléments graphiques qui peuvent être positionnés et stylisés.

## Formes prises en charge

Le programme doit permettre de manipuler les formes suivantes :

* Les cercles
* Les ellipses
* Les carrés
* Les rectangles
* Les lignes
* Les enchaînements de lignes (polylignes)
* Les polygones
* Les trajectoires (chemins)
* Les groupes de formes

## Fonctionnalités prévues

* Créer de nouvelles formes graphiques
* Modifier les propriétés des formes
* Déplacer les formes dans le plan
* Modifier les dimensions des formes
* Modifier les couleurs et les contours
* Enregistrer les structures graphiques dans un fichier
* Charger une structure graphique depuis un fichier
* Visualiser le résultat du dessin
* Gérer des groupes de formes

Les fonctionnalités seront précisées et complétées au fur et à mesure du développement.

## Contraintes techniques

* Langage de programmation : C
* Standard utilisé : C99
* Compilateur : GCC
* Bibliothèques : bibliothèques natives autorisées uniquement, sauf autorisation de l'enseignant
* Documentation du code : commentaires au format Javadoc
* Compilation et nettoyage : utilisation d'un `Makefile`

## Prérequis

* GCC compatible avec le standard C99
* GNU Make (outil qui automatise certaines tâches du projet, notamment la compilation du programme C)
* Un navigateur web pour visualiser les fichiers SVG, si cette méthode de visualisation est retenue

## Compilation

Pour compiler le programme, exécuter :

```bash
make build
```

## Nettoyage

Pour supprimer les fichiers générés par la compilation, exécuter :

```bash
make clean
```

## Utilisation

Les instructions d'utilisation seront ajoutées lorsque les fonctionnalités du programme seront implémentées.

## Organisation du projet

* `main.c` : point d'entrée du programme
* `Makefile` : commandes de compilation et de nettoyage
* `README.md` : présentation du projet et instructions d'utilisation

D'autres fichiers pourront être ajoutés si nécessaire pour organiser le code.

## Tests et fiabilité

Le programme devra être testé afin de vérifier :

* Le bon fonctionnement des fonctionnalités
* La gestion correcte des fichiers
* La validité des données saisies
* L'absence de plantages et de fuites mémoire

## Gestion des versions

Le projet utilise Git pour conserver un historique des étapes du développement.

* `git status` : vérifier l'état des fichiers.
* `git add` : préparer les fichiers à enregistrer.
* `git commit -m "message"` : créer un point de sauvegarde.
* `git log --oneline` : consulter l'historique des commits.

Le dépôt Git est actuellement local

## Références

* [Documentation MDN sur l'élément SVG](https://developer.mozilla.org/fr/docs/Web/SVG/Reference/Element/svg)

## État du projet

Projet en cours de développement.
