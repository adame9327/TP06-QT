Projet Client TCP

Ce projet implémente un client TCP en C++ en s'appuyant sur la bibliothèque Qt pour communiquer avec un serveur. Il permet d'envoyer et de recevoir des messages en mode interactif via le réseau.
Fonctionnalités

    Connexion au serveur TCP : Se connecte à un serveur à l'aide d'une adresse IP et d'un port.
    Envoi de messages : Permet d'envoyer des messages via la console.
    Réception de messages : Affiche les messages reçus du serveur.
    Gestion des erreurs réseau : Prend en charge les erreurs liées à la connexion et à l'envoi des données.

Prérequis

Pour compiler et exécuter ce projet, vous aurez besoin de :

    Framework Qt (version 5 ou supérieure)
    Un IDE compatible Qt (comme Qt Creator)
    CMake ou qmake pour générer les fichiers de construction
    Un serveur TCP fonctionnel pour tester la communication (par exemple, un serveur Python simple)

Structure du projet

Projet_clientTCP/  
├── main.cpp            # Point d'entrée principal  
├── client.cpp          # Logique principale du client TCP  
├── client.h            # Définition de la classe Client  
├── Projet_clientTCP.pro # Fichier de configuration du projet Qt  
└── README.md           # Documentation  

Configuration et Compilation

    Cloner le dépôt

git clone https://github.com/votre-utilisateur/Projet_clientTCP.git  
cd Projet_clientTCP  

Configurer le projet avec Qt Creator

    Ouvrez le fichier Projet_clientTCP.pro dans Qt Creator.
    Configurez un kit de développement (compilateur et version de Qt).

Compiler le projet

    Utilisez Qt Creator ou exécutez les commandes suivantes dans un terminal :

    qmake && make  

Modifier l'adresse IP du serveur
Dans le fichier main.cpp, mettez à jour l'adresse IP si nécessaire :

    QString ipAdresse = "172.20.10.13"; // Adresse IP du serveur  

Utilisation

    Démarrer le serveur TCP
    Assurez-vous qu'un serveur TCP est opérationnel à l'adresse IP et au port spécifiés (par défaut 172.20.10.13:8000).

    Exécuter le client
    Une fois compilé, lancez le programme :

./Projet_clientTCP  

Envoyer des messages
Lorsque le client est connecté, saisissez un message dans la console :

    > Bonjour serveur !  

    Les messages envoyés et reçus s'afficheront dans la console.

Exemple de code

Connexion au serveur

Dans le fichier client.cpp, la méthode suivante initie la connexion au serveur :
-----------------------------------------------------------------------------------------------------
'''
void Client::demarrer()  
{  
    qDebug() << QString::fromUtf8("Connexion au serveur") << serverIp << ":" << PORT_SERVEUR;  
    tcpSocket->connectToHost(serverIp, PORT_SERVEUR);  
}  
'''
-----------------------------------------------------------------------------------------------------


Envoi d'un message

Le client lit un message depuis la console et l'envoie au serveur :
----------------------------------------------------------------------------------
'''
void Client::envoyer()  
{  
    if (tcpSocket->state() == QAbstractSocket::ConnectedState)  
    {  
        QString message = cin.readLine();  
        if (!message.isEmpty())  
        {  
            QByteArray data = message.toUtf8();  
            qint64 ecrits = tcpSocket->write(data);  
            if (ecrits != -1)  
            {  
                qDebug() << QString::fromUtf8("Message envoyé :") << message;  
            }  
        }  
    }  
    else  
    {  
        qDebug() << QString::fromUtf8("La socket n'est pas connectée !");  
    }  
}  
'''
----------------------------------------------------------------------------------
Réception d'un message

Le client gère les messages reçus avec la méthode suivante :
----------------------------------------------------------------------------------
'''
void Client::recevoir()  
{  
    QByteArray data = tcpSocket->readAll();  
    qDebug() << QString::fromUtf8("Message reçu :") << QString::fromUtf8(data);  
}  
'''
----------------------------------------------------------------------------------
Exemple de sortie

"Instanciation de l'objet QTcpSocket"  
"Connexion au serveur" "172.20.10.13" : 8000  
"Connecté au serveur à l'adresse :" "172.20.10.13"  
"Port du serveur :" 8000  
"Entrez un message à envoyer :"  
> Bonjour serveur !  
"Message envoyé :" "Bonjour serveur !"  
"Message reçu :" "Bienvenue !"  


