
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

/* Puerto  de la conexión. */
#define PORT 9999

/* Tamaño del buffer. */
#define BUFFERSIZE 512

class NetworkHandler
{
    public:  
        /**
        * Constructor del servidor, inicializa todas las variables necesarias para
        * que el servidor funcione correctamente.
        */
        NetworkHandler(); 
        /**
         * Método que se implementará dentro de cualquier clase que herede.
         * @param pMessage: Mensaje entrante desde el socket.
         * @param pSocket: Desde donde llega el mensaje.
         */
        virtual void inMessage(std::string pMessage, int pSocket) = 0;     
        /**
         * 
         * @param pMessage: Corresponde al mensaje que será enviado hacia el cliente.
         * @param pSocket: Corresponde al socket por el cual será enviado el mensaje.
         */
        void outMessage(std::string pMessage, int pSocket);
        /**
        * Ciclo que mantiene el servidor corriendo a la espera de conexiones.
        */
        void Run(); 
    private:
        /**
        * @param pLoop: Mensaje de esperando conexión.
        */
        void WaitConnectionMsg(int pLoop);
        /**
        * Errores que se verifican antes de levantar el servidor, previendo posibles altercados.
        */
        void verifyLiftErrors();
        /**
        * 
        * @param pCode: Corresponde al código de error de algun error X.
        * @param pSpecification: Corresponde a la especificación del error anterior.
        */
        void Error(int pCode, std::string pSpecification);
        /**
         * Método que antiende cada cliente que llega.
         * @param pSocket
         * @param pIP
         * @return 
         */
        int MeetClient(int pSocket, struct sockaddr_in pIP);
        /**
        * Verificar si hay algun nuevo cliente ingresando al servidor.
        */
        void verifyNewClient();
        /**
        * Verificar si algun cliente ha pedido la desconección.
        */
        void verifyDeadClient(); 

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
