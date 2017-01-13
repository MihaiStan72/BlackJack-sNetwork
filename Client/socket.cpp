#include "socket.h"

Socket::Socket(QObject *parent) : QObject(parent)
{

}
Socket::log Socket::Login()
{
    Socket::log l;
    std::cout<<"Server IP please: ";
    std::cin>>l.IP;
    std::cout<<"Login \n User:";
    std::cin>>l.user;
    std::cout<<"Password: ";
    std::cin>>l.password;
    return l;
}

void Socket::Connect()
{
    log info=Login();
    socket = new QTcpSocket(this);
    //QHostAddress::QHostAddress("192.168.1.155");
    socket->connectToHost(/*info.IP*/"192.168.1.154",1234);
    //connect
    while(socket->waitForConnected(1500))
    {
        qDebug()<<"Connected";
        //send
        char* p;
        p=iToChar(hash_password(info.password));
        strcpy(info.password, p);
        char a[10];
        qDebug()<<a;
        if(!strcmp(a,"exit"))
        {
            socket->close();
            qDebug()<<"Not Connected";
            break;
        }
        socket->write(info.user);
        socket->waitForBytesWritten(1000);
        socket->write(" ");
        socket->write(info.password);
        socket->waitForBytesWritten(1000);
        socket->write(" ");

        socket->waitForReadyRead(3000);
        qDebug()<<"Reading:"<<socket->bytesAvailable();

        qDebug()<<socket->readAll();
        std::cin>>a;


    }
    qDebug()<<"Not Connected";


    //sent

    //got

    //close
}
long long Socket::hash_password(char pass[20])
{
    int n=strlen(pass), number;
    long long hash_number=0, pow;
    for(int i=0;i<n;i++)
    {
        number=(pass[i]-'a');
        pow=power(i,number);
        //hash_number=((pow*number)%10)+hash_number*10;
        hash_number=(hash_number<<3)^(((pow*number)%10)+hash_number*10);
    }
    return hash_number;
}
long long Socket::power(int a, long long int b)
{
    int i;
    for(i=0;i<a;i++, b=(b%10)*7);
    return b;
}
char* Socket::iToChar(long long int num)
{
    char c[100];
    char* pass;
    pass=c;
    int lg=0;
    while(num)
    {
        pass[lg++]=(num%10)+'0';
        num/=10;
    }
    //pass[lg]=NULL;
    return pass;
}
