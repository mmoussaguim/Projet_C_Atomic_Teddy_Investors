Dans ce répertoire vous trouverez  deux sous-répertoires : src et tst. 

*Le répertoire Src contient les fichiers:

- good.h et stockex.h où sont définis les prototypes des diférentes fonctions données par le sujet;
- good.c et stockex.c où sont implémentées les fonctions;
-teddy.h qui contient la structure des ours;
- queue.c et queue.h où vous trouverez les prototypes et les fonctions en rapport avec la queue de priorité des ours;
- define.h où sont définies nos variables de substitutions;
- et project-0.c où est programmée la boucle de jeu 

*Le répertoire tst contient un unique fichier test-0.c où sont réalisés les tests permettant de vérifier le fonctionnement des différents programmes. 

*Il y'a également un fichier Makefile dans ce repertoire; permettant de compiler les differents fichiers .c et d'executer le jeu.

Pour faire tourner le jeu, vous pouvez chosir le nombre de joueurs et le nombre de tours que vous voulez. Il suffit , après saisie et exécution de la commande make, de saisir : ./project -n x -m y -s z où :
- l'option -n x désigne le nombre de joueurs x;
- l'option -m y est pour le choix du nombre tours y;
- et l'option -s z pour initialiser le génerateur aléatoire.

En ce qui concerne les tests, vous pouvez y avoir accées avec la comande "make test".
