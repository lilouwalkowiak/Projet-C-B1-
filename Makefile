# Makefile du projet : éditeur de formes graphiques (style SVG).
#
# Commandes disponibles :
#   make build   compile le projet
#   make run     compile (si besoin) puis lance le programme
#   make clean   supprime le programme créé
#

# Compilateur utilisé (GCC installé avec Homebrew sur macOS).
CC = gcc-16

# Options de compilation : norme C99, avertissements activés.
CFLAGS = -std=c99 -Wall -Wextra -Wpedantic

# Fichiers à compiler : ajouter ici chaque nouveau fichier .c.
SRC = main.c style.c

# Nom du programme créé.
TARGET = main

# build, run et clean sont des actions, pas des fichiers.
.PHONY : build run clean

#
# Compile tous les fichiers .c en un seul programme.
#
# Utilisation : make build
# Résultat    : le programme "main" est créé dans le dossier du projet.
#
build:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

#
# Compile le projet si besoin, puis lance le programme.
#
# Utilisation : make run
#
run : build
	./$(TARGET)

#
# Supprime le programme créé, pour repartir de zéro.
#
# Utilisation : make clean
#
clean:
	rm -f $(TARGET)