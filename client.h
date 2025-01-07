#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QDebug>
#include <QTextStream>
#include <QTimer>

#define PORT_SERVEUR 8000 // Port utilisé pour la communication

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(const QString &ipAdresse, QObject *parent = nullptr);
    ~Client();
    void demarrer();

private:
    QTcpSocket *tcpSocket;  // Socket TCP
    QTextStream cin;        // Pour lire l'entrée utilisateur depuis la console
    QTimer *timer;          // Timer pour gérer les envois périodiques
    QString serverIp;       // Adresse IP du serveur

signals:

public slots:
    void estConnectee();
    void estDeconnectee();
    void gestionErreur(QAbstractSocket::SocketError);
    void recevoir();
    void envoyer();
};

#endif // CLIENT_H
