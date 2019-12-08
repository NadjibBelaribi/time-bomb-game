# Introduction

Ce projet a été réalisé pour le cours d'IHM S5 de l'UFR Math Info à Strasbourg. L'objectif est de reproduire le jeu de cartes Time-Bomb, créé par Yusuke Sato.

* Pour en savoir plus sur les règle du jeu, cliquez [ici](time-bomb-rules.pdf).
* L'énoncé complet de ce projet est disponible [ici](enonce.pdf).

![Time Bomb](time-bomb.jpg)

# License

Ce programme est distribué sous licence GNU GPLv3.

# Auteurs

Nous avons réalisés ce projet à 6: Ilias Deligiannis, Florent Weber, Nadjib Belaribi, Danyl El-Kabir, Leonardo Nassabain et François Grabenstaetter.

# Utilisation

Ce projet est divisé en trois modules: le noyau (kernel), le module réseau (network) et la partie graphique (ui). Chaque module est à compiler à part dans le répertoire dédié:

Le répertoire tests/ permet de tester le noyau et le module réseau dans une interface console (très pratique !). Nous recommandons de compiler tout le projet comme ceci depuis la racine du projet:

```bash
make -C kernel/
make -C network/
make -C tests/
cd ui/
qmake TIMEBOMB.pro
make
```

**Programmes de tests**

```bash
# Dans tests/
# Test en local
./local <pseudo1> <pseudo2> ...

# Test en réseau (héberger puis rejoindre)
./network host <port> <nb_players> <pseudo>
./network join <ipv6> <port> <pseudo>
