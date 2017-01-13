#include <QCoreApplication>
#include "socket.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Socket client;
    client.Connect();
    return a.exec();
}
