#ifndef SOCKET_H
#define SOCKET_H
#include <iostream>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <cstring>


class Socket : public QObject
{
        Q_OBJECT
    public:
    struct log{
        char IP[100]={}, user[100]={}, password[100]={};
        //long long int password_hashed;
    };


    explicit Socket(QObject *parent = 0);
      void Connect();
      log Login();
      long long hash_password(char pass[20]);
      long long power(int, long long);
      char* iToChar(long long int num);
signals:

public slots:
private:
      QTcpSocket *socket;
};

#endif // SOCKET_H
