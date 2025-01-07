#include "client.h"
#include <QtNetwork/QHostAddress>

Client::Client(const QString &ipAdresse, QObject *parent)
    : QObject(parent), cin(stdin), timer(new QTimer(this)), serverIp(ipAdresse)
{
    qDebug() << QString::fromUtf8("Instanciation de l'objet QTcpSocket");
    tcpSocket = new QTcpSocket(this);

    // Connexions des signaux et slots
    connect(tcpSocket, &QTcpSocket::connected, this, &Client::estConnectee);
    connect(tcpSocket, &QTcpSocket::disconnected, this, &Client::estDeconnectee);
    connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::errorOccurred), this, &Client::gestionErreur);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Client::recevoir);

    // Connexion du timer pour permettre l'envoi interactif
    connect(timer, &QTimer::timeout, this, &Client::envoyer);
}

Client::~Client()
{
    qDebug() << QString::fromUtf8("Fermeture de la socket");
    tcpSocket->close();
}

void Client::demarrer()
{
    qDebug() << QString::fromUtf8("Connexion au serveur") << serverIp << ":" << PORT_SERVEUR;
    tcpSocket->connectToHost("172.20.10.13", PORT_SERVEUR);  // Adresse IP du serveur directement ici
}


void Client::estConnectee()
{
    qDebug() << QString::fromUtf8("Connecté au serveur à l'adresse :") << tcpSocket->peerAddress().toString();
    qDebug() << QString::fromUtf8("Port du serveur :") << tcpSocket->peerPort();
    qDebug() << QString::fromUtf8("Entrez un message à envoyer :");

    // Démarre le timer pour envoyer des messages interactifs
    timer->start(100);
}

void Client::estDeconnectee()
{
    qDebug() << QString::fromUtf8("Le client est déconnecté");
    timer->stop();
}

void Client::gestionErreur(QAbstractSocket::SocketError erreur)
{
    qDebug() << QString::fromUtf8("Erreur :") << tcpSocket->errorString();
}

void Client::recevoir()
{
    QByteArray data = tcpSocket->readAll();
    qDebug() << QString::fromUtf8("Message reçu :") << QString::fromUtf8(data);
}

void Client::envoyer()
{
    if (tcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        // Lire l'entrée utilisateur depuis la console
        QString message = cin.readLine();
        if (!message.isEmpty())
        {
            QByteArray data = message.toUtf8();
            qint64 ecrits = tcpSocket->write(data);
            if (ecrits == -1)
            {
                qDebug() << QString::fromUtf8("Erreur lors de l'envoi du message !");
            }
            else
            {
                qDebug() << QString::fromUtf8("Message envoyé :") << message;
                qDebug() << QString::fromUtf8("Octets envoyés :") << ecrits;
            }
        }
    }
    else
    {
        qDebug() << QString::fromUtf8("La socket n'est pas connectée !");
    }
}
