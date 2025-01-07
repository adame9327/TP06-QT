#include <QCoreApplication>
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Utiliser directement l'adresse IP du serveur
    QString ipAdresse = "172.20.10.13";

    // Instanciation du client avec l'adresse IP donnée
    Client client(ipAdresse);
    client.demarrer();

    return a.exec();
}
