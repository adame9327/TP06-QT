Projet Client TCP

Dans ce projet, on réalise un client TCP en C++ s'appuyant sur la bibliothèque Qt pour communiquer avec un serveur. Celui-ci permet d'envoyer et de recevoir des messages en mode interactif en utilisant le réseau.

Fonctionnalités

Se connecter à un serveur TCP à l'aide d'une adresse IP.Envoyer des messages en mode interactif à partir de la console.Recevoir des messages du serveur.Prendre en compte les erreurs de réseau.

Prérequis

Pour compiler et exécuter ce projet, il vous faudra :

Le Framework Qt (version 5 ou supérieure)Un IDE compatible avec Qt (Qt Creator est recommandé)CMake ou qmake pour la génération des fichiers de constructionUn serveur TCP fonctionnel pour tester la communication (par exemple, un serveur Python simple)

Structure du projet
-----------------------------------------------------
Projet_clientTCP/

├── main.cpp        # Point d'entrée principal

├── client.cpp      # Logique principale du client TCP

├── client.h        # Définition de la classe Client

├── Projet_clientTCP.pro # Fichier de projet Qt

└── README.md       # Documentation
-----------------------------------------------------

Configuration et Compilation

Cloner le dépôt :
git clone https://github.com/votre-utilisateur/Projet_clientTCP.git

 cd Projet_clientTCP
Configurer le projet avec Qt Creator :
Ouvrez le fichier clientTCP.pro
 dans Qt Creator.
Configurez un kit de développement (compilateur et version de Qt).
Compiler :

Utilisez loption de compilation dans Qt Creator, ou exécutez : qmake && make

4. Modifier l'adresse IP : dans main.cpp mettez a jour l'adresse IP du serveur si necessaire :

Qstring ipAdresse = "172.20.10.13"; // Adresse IP de votre serveur
Utilisation

Démarrer le serveur TCP : Assurez-vous quun serveur TCP est opérationnel à l'adresse IP et au port spécifiés (172.20.10.13:8000 par défaut).

Exécuter le client : Une fois compilé, exécutez le programme :

"./Projet_clientTCP"

Envoyer des messages :

    Saisissez un message dans la console pour l'envoyer au serveur.
    Les messages reçus du serveur seront affichés dans la console.

exemple de sorti
   "Instanciation de l'objet QTcpSocket"
  
   "Connexion au serveur" "172.20.10.13" : 8000
   
   "Connecté au serveur à l'adresse :" "172.20.10.13"
   
   "Port du serveur :" 8000
   
   "Entrez un message à envoyer :"
   
   "Message reçu :" "gdgd\n"
   
   "Message reçu :" "gg\n"


