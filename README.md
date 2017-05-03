Filler est un jeu algorithmique qui consiste à remplir une grille d’une taille connue à l’avance avec des pièces de taille et de formes aléatoires, sans que les pièces ne se superposent
de plus d’une seule case et sans qu’elles ne depassent de la grille. 
Si l’une de ces conditions n’est pas remplie, la partie s’arrête. Chaque pièce posée avec succès rapporte un certain nombre de points, et a un seul joueur, le but du jeu pourrait être d’obtenir le meilleur score possible. 
Cepedant, c’est avec deux joueurs que le filler prend tout son intérêt. Chaque joueur a pour but de poserun maximum de pièces tout en tentant d’empêcher son adversaire de le faire. 
A la fin de la partie, celui avec le plus de point remporte le match.

Après avoir compilé le projet, copiiez l executable dans le dossier resources/player/ puis lancé une partie avec la commande:
./resources/filler_vm -f resources/maps/"nom d une map" -p1 resources/players/ramichia.filler -p2 resources/players/"nom d un joueur" | ./resources/show.filler
