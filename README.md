# 🚀 Arcade Game - Prototype 2D Spatial

Ce projet est un prototype de jeu 2D se déroulant dans un univers spatial, développé en **C++** avec la bibliothèque **Raylib**.  
Il s'agit d'une base technique permettant d'explorer des mécaniques de gameplay simples (mouvement, tirs, menus) sur un fond étoilé en mouvement.

## 📁 Contenu du dépôt

- **Ressources/** : Images, sons et autres fichiers nécessaires au jeu.
- **ArcadeGame.sln** : Solution Visual Studio du projet.
- **ArcadeGame.vcxproj / ArcadeGame.vcxproj.filters** : Fichiers de configuration du projet Visual Studio.
- **Sources principales** :
  - `main.cpp` : Point d'entrée du jeu.
  - `Game.cpp` / `Game.h` : Gestion générale de la boucle de jeu.
  - `Gameplay.cpp` / `Gameplay.h` : Logique de gameplay (joueur, tirs, ennemis...).
  - `MenuPrincipal.cpp` / `MenuPrincipal.h` : Menu principal.
  - `PauseMenu.cpp` / `PauseMenu.h` : Gestion du menu pause.
  - `Gameover.cpp` / `Gameover.h` : Écran de fin de partie.
  - `Player.cpp` / `Player.h` : Comportement du joueur.
  - `Bullet.cpp` / `Bullet.h` : Gestion des projectiles.
  - `StarryBackground.cpp` / `StarryBackground.h` : Affichage d'un fond étoilé dynamique.
  - **Et d'autres modules** : `SceneManager`, `Button`, `RaylibWrapper`, `Sprite`, `Star`, `Cam2D`, etc.

- **Fichiers utilitaires** :
  - `Couleur.h`, `Vec2.h`, `Rect.cpp` / `Rect.h`, etc.

- **Fichiers de configuration** :
  - `.gitignore`, `.gitattributes`, `README.md`.
