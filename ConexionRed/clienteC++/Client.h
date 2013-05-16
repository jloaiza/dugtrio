/**
*************************************************************
* @file: Client.h
* @brief: Creando un cliente TCP!!!!
* @author Yeison Arturo Cruz León :)
* @Universidad: Instituto Tecnológico de Costa Rica.
* @Carnet: 201258348.
* @date 10 de mayo del 2013
************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>

/* Tamaño del buffer. */

#define BUFFERSIZE 512

class Client 
{
    public:
        /* Todos los métodos ya fueron documentados en el CPP*/
        Client(std::string pIp, int pPort);
        void Error(std::string pError);
        void openSocket();
        void setSocket();
        void Connect();
        void sendMessage(std::string pMessage);
        char* readMessage();
        
    private:
        /* Getters y setters para el puerto y la IP. */
        void setPort(int _port){this->_port = _port;}
        int getPort() const{return _port;}
        void setIp(std::string _ip){this->_ip = _ip;}
        std::string getIp() const{return _ip;}
        
        /* Variables para el manejo de conexión de red dentro del protocolo.*/
        typedef struct sockaddr *_socketDirection;
        std::string _ip;
        int _port;
        int _socket;
        int cto;
        struct sockaddr_in _connection;
        char _inMessage[BUFFERSIZE];
};

