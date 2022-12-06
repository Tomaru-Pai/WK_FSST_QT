#include <QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Apllication wird gestarten
    Server server;
    server.start();

    return a.exec();
}


/* Starte Programm
 * Gehe auf Ausgabe und schaue nach Port
 * Gehe in PUTTY
 * Wähle "other" statt "SSH" aus
 * Gebe bei hostname: "localhost" ein
 * Gebe bei PORT: "5000" ein.
 * Gehe auf "Verbinden"
 * Jetzt Funktioniert es
*/
