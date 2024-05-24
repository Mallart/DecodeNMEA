Dépôt git: https://github.com/Mallart/DecodeNMEA/
Dépôt gitlab: https://gitlab.info.iut-tlse3.fr/llm5249a/DecodeNMEA

# Decode NMEA - EN
## What is it ?
This project was intended to be a school project.
One can use it to decode NMEA 0183 frames (GPGGA norm) and display all of its data in a more readable form.
## How to use it ?
Launch it from a console, with or without additional arguments.
DecodeNMEA.exe takes from zero to two additional arguments, and can be the following:

`decodenmea [NMEA frame / 0] [Record file path]`

DecodeNMEA will next save the frame in a file, or read the provided "Record file path" and display its data in the console if the provided frame is "0".
> [!WARNING]
> Using the makefile on Linux or Cygwin will lead to an executable named "nmea". So instead of typing "decodenmea [...]", you'll have to type "./nmea [...]" to run it.

> [!TIP]
> Use "make clean" to automatically remove all object files and saved frames on Linux or Cygwin.

## Can I use your code ?
Of course, just mention the project's contributors where you use it.

> [!NOTE]
> This project is entierly commented in French, as our school asked us to. However, all functions and variables are written in english and should be clear enough not to need any comment added to them.

# Decode NMEA - FR
## Qu'est-ce que c'est ?
Ce projet était destiné à être un projet scolaire.
On peut l'utiliser pour décoder des trames NMEA 0183 (norme GPGGA) and en afficher les données sous forme plus lisible.
## Comment l'utiliser ?
Pour ce faire, il suffit de le lancer depuis la console, avec ou sans paramètres additionnels.
DecodeNMEA.exe accepte de zéro à deux arguments et peuvent être les suivants:
`decodenmea [Trame NMEA / 0] [Chemin du fichier d'enregistrement]`

DecodeNMEA ira ensuite sauvegarder ladite trame dans un fichier, ou lire le "Chemin du fichier d'enregistrement" et en lire les données pour les afficher dans la console si la "Trame NMEA" donnée par l'utilisateur est "0".

> [!WARNING]
> Utilisez le makefile sous Linux ou Cygwin entraînera la création d'un exécutable appelé "nmea". Par conséquent, au lieu de taper "decodenmea [...]", vous devrez taper "./nmea [...]" pour l'exécuter.

> [!TIP]
> Utilisez "make clean" pour nettoyer le dossier de tous les objets de compilation et des trames sauvegardées sous Linux ou Cygwin.

## Puis-je utiliser votre code ?
Bien sûr, mentionnez juste le nom et le lien du dépôt originel et des contributeurs à celui-ci.

> [!NOTE]
> Le code du projet est commenté en anglais suite à des recommandations scolaires. Cependant, l'intégralité des variables et fonctions sont en anglais et censées être lisibles et compréhensible sans nul besoin d'explicitations supplémentaires.
