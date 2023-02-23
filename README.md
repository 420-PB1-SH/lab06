# Laboratoire 06 - Programmation TCP

Dans ce laboratoire, vous aurez à programmer un jeu de Tic Tac Toe permettant
à 2 joueurs de s'affronter à travers un réseau. Pour ce faire, vous devez partir
d'un jeu de Tic Tac Toe hors ligne qui vous est fourni, et le transformer pour
en faire un jeu en ligne.

Cette fois-ci, il n'y aura pas de programmes distincts pour le client et le serveur.
Les deux joueurs lanceront le même programme, et celui-ci demandera à chaque personne
à l'ouverture si elle veut créer une partie (et donc agir comme serveur) ou bien
joindre une partie créée par quelqu'un d'autre (et donc agir comme client).

Le dépôt de départ contient une solution Visual Studio 2022 comprenant le projet de départ.
Celui-ci est déjà configuré pour pouvoir utiliser le module réseau de SFML.

Commencez par cloner le dépôt localement et vous assurer que vous pouvez démarrer le projet.

## Résultat attendu

[Cette vidéo](https://youtu.be/ibomvG5TbuY) montre le résultat attendu du laboratoire.
Elle montre aussi comment lancer deux exécutions du même programme dans Visual Studio 2022.

## Consignes

### Étape 1 - Prendre connaissance du projet existant

Prenez le temps d'explorer le code existant dans les fichiers de départ, et d'exécuter
le projet pour bien comprendre le fonctionnement du programme. Observez surtout le code
de la fonction `jouer` et assurez-vous de le comprendre.

Durant le laboratoire, vous aurez seulement à modifier le `main` et la fonction `jouer`. Vous
n'aurez pas à modifier la classe `TicTacToe`.

### Étape 2 - Décommenter le code du `main`

Vous devez décommenter le code qui se trouve présentement dans le `main`, puis supprimer
la ligne indiquée par un commentaire. Testez le programme à nouveau. Vous devriez voir ceci:

```console
TIC TAC TOE
===========
Choisir une option:
1. Créer une partie
2. Joindre une partie
Votre choix: 
```

Lorsque l'option 1 est choisie, la fonction `jouer` est appelée en passant `true`
à son paramètre `estServeur`. Lorsque l'option 2 est choisie, la valeur `false`
est passée à ce paramètre.

En d'autres mots, l'hôte qui crée la partie doit agir comme serveur, et celui qui
la joint doit agir comme client.

## Étape 3 - Établir la connexion



## Références utiles

* [Tutoriel du module réseau de SFML](https://www.sfml-dev.org/tutorials/2.5/index-fr.php#module-rceseau)
* [Documentation des classes du module réseau de SFML](https://www.sfml-dev.org/documentation/2.5.1-fr/group__network.php)
