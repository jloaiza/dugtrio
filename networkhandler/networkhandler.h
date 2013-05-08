
#include <fcntl.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>
#include <resolv.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>


#define PORT 9999
#define BUFFERSIZE 512

class NetworkHandler
{
    public:  
        /* Todos los metodos ya fueron documentados en el CPP.*/
        NetworkHandler(); 
        virtual void inMessage(std::string pMessage, int pSocket) = 0;
        void outMessage(std::string pMessage, int pSocket);
    private:
        void WaitConnectionMsg(int pLoop);
        void verifyLiftErrors();
        void Error(int pCode, std::string pSpecification);
        int MeetClient(int pSocket, struct sockaddr_in pIP);
        void verifyNewClient();
        void verifyDeadClient();
        void Run(); 

        /* Conjunto de parametros de red a vigilar */

        fd_set _rfds;  
        socklen_t _sizeAddr;

        /* Corresponden a la IP de los clientes y servidor, asimismo el tiempo de acceso.*/

        struct sockaddr_in _clientIP;
        struct sockaddr_in _serverIP;
        struct timeval _timeAccept;   

        /* Corresponde al buffer que recive los datos y los envia por red. */

        char _inBuffer[BUFFERSIZE];

        /* Variables generales de uso.*/

        int _serverSocket;
        int _clientSocket;
        int _exit;
        int _childPid;
        int _pidStatus;
        int _run;
        int _indicatorMessage;
        int _byteCount;
};

