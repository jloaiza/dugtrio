
#include "client.h"

Client::Client(std::string pIp, int pPort) 
{
    setIp(pIp);
    setPort(pPort);
    openSocket();
    setSocket();
}

void Client::Error(std::string pError)
{
    exit( (perror(pError.c_str()), -1) );
}

void Client::openSocket()
{
    _socket = socket(PF_INET, SOCK_STREAM, 0);
    if (_socket < 0)
    {
        Error("No se pudo crear el socket, reintentelo.");
    }
}

void Client::setSocket()
{
    _connection.sin_family = AF_INET;
    _connection.sin_port = htons(getPort());
    inet_aton(getIp().c_str(), &_connection.sin_addr);
}

void Client::Connect()
{
    if( connect(_socket, (_socketDirection) &_connection, sizeof(_connection)) < 0)
    {
        Error("La conexión no se pudo establecer, lo sentimos.");
    }
}

void Client::sendMessage(std::string pMessage)
{
    if (write (_socket, pMessage.data(), pMessage.size()) < 0)
    {
        Error("No se pudo enviar el mensaje, reintentelo de nuevo.");
    }
    usleep(10000);
}

std::string Client::readMessage()
{
     if (read(_socket, _inMessage, sizeof(_inMessage)) < 0)
     {
         Error ("No se pudo leer el mensaje correctamente.");
     }
     std::string pMessage = _inMessage;
     return pMessage;
}
