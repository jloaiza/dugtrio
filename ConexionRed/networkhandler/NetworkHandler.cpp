/**
*************************************************************
* @file: Servidor.CPP
* @brief: Creando un server TCP usando Threads!!!!
* @author Yeison Arturo Cruz León :)
* @Universidad: Instituto Tecnológico de Costa Rica.
* @Carnet: 201258348.
* @date 06/07/08 de mayo del 2013
************************************************************
*/

#include "NetworkHandler.h"

/**
 * Constructor del servidor, inicializa todas las variables necesarias para
 * que el servidor funcione correctamente.
 */

NetworkHandler::NetworkHandler()
{
    _sizeAddr = 0;
    _run = 1;
    _indicatorMessage = 0;
    _serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    _serverIP.sin_family = AF_INET ;
    _serverIP.sin_port = htons(PORT);
    _serverIP.sin_addr.s_addr = INADDR_ANY ;
    _sizeAddr = sizeof(struct sockaddr_in);
}

int NetworkHandler::MeetClient(int pSocket, sockaddr_in pIP)
{
    int run = 0; /* Verificador del ciclo. */   
    int exitcode = 0; /* Código de salida por defecto */         

    while (!run)
    {
        /* Setear el buffer a cero. */
        memset(_inBuffer, 0, BUFFERSIZE);
        /* Recivimos la información y al mismo tiempo evaluamos si llego correctamente. */
        if ((_byteCount = recv(pSocket, _inBuffer, BUFFERSIZE, 0))== -1)
        {
            Error(5, "No se pudo recibir la información.");
        }
        if(_byteCount == 0)
        {
            std::cout << "!ATENCIÓN! El cliente " << inet_ntoa(_clientIP.sin_addr) <<  " se ha desconectado inesperadamente, conexión perdida." << std::endl;
            run = 1;
        }
        /* Se convierte el _inBuffer de char a string para un manejo más fácil. */
        std::string inMessageBuffer = _inBuffer;
        
        /* Evaluamos si el mensaje de entrada es disconnect o closeserver, de no ser así
         * se envia a inMessage para su posterior evaluación.
         */
        
        /* Comando "discconect", cierra la conexión actual del cliente. */
        if (strncmp(_inBuffer, "disconnect", 10)==0)
        { 
            run = 1;
        }
        /* Comando "closeserver", cierra el servidor actual. */
        else if (strncmp(_inBuffer, "closeserver", 11)==0)
        {
            run = 1;
            exitcode = 99;        
        }
        /* Sino, se envia el mensaje a otro método para su posterior evaluación. */
        else
        {
            inMessage(inMessageBuffer, pSocket);
        }
    }
    close(pSocket); /* Se cierra la conexión del cliente. */
    return exitcode; /* Retorna el codigo de salida */
}

/**
 * 
 * @param pMessage: Corresponde al mensaje que será enviado hacia el cliente.
 * @param pSocket: Corresponde al socket por el cual será enviado el mensaje.
 */
void NetworkHandler::outMessage(std::string pMessage, int pSocket)
{
    const char *pMessageOut = pMessage.c_str();
    memset(_inBuffer, 0, BUFFERSIZE);
    sprintf(_inBuffer, pMessageOut); 
    if((_byteCount = send(pSocket, _inBuffer, strlen(_inBuffer), 0))== -1)
    {
        Error(6, "No se pudo enviar la información.");
    }
}

/**
 * 
 * @param pCode: Corresponde al código de error de algun error X.
 * @param pSpecification: Corresponde a la especificación del error anterior.
 */

void NetworkHandler::Error(int pCode, std::string pSpecification)
{
    std::cout << "Error con codigo: " << pCode << " | " << " Especificación: " << pSpecification << std::endl;
    exit(1);
}

/**
 * 
 * @param pLoop: Mensaje de esperando conexión.
 */

void NetworkHandler::WaitConnectionMsg(int pLoop)
{
    if (pLoop == 0)
    {
        std::cout << "[SERVER] Esperando conexión: " << std::endl;
        _indicatorMessage++;
    }
}

/**
 * Errores que se verifican antes de levantar el servidor, previendo posibles altercados.
 */

void NetworkHandler::verifyLiftErrors()
{
    if (_serverSocket == -1)
    {
        Error(1, "No se puede inicializar el socket.");
    }
    
    if (bind( _serverSocket, (struct sockaddr*) &_serverIP, sizeof(_serverIP) ) == -1)
    {
        Error(2, "El puerto está en uso."); 
    }

    if (listen( _serverSocket, 10) == -1 )
    {
        Error(3, "No se puede escuchar en el puerto especificado, ya está siendo usado");
    } 
}

/**
 * Verificar si hay algun nuevo cliente ingresando al servidor.
 */

void NetworkHandler::verifyNewClient()
{
    /* Se tiene que verificar si la conexión entrante es valida. */
    if (select(_serverSocket+1, &_rfds, NULL, NULL, &_timeAccept))
    {
        /* Si es valida se verifica si puede ser aceptada. */
        if ((_clientSocket = accept( _serverSocket, (struct sockaddr*)&_clientIP, &_sizeAddr))!= -1)
        {
            /* Se reinicia el mensaje de esperando conexión. */
            _indicatorMessage = 0; 
            /* Se imprime un mensaje de confirmación. */
            std::cout << "Se ha conectado la IP: " << inet_ntoa(_clientIP.sin_addr) << " por el puerto: " << _clientIP.sin_port << std::endl;
            switch ( _childPid = fork() )
            {
                case -1:  
                    /* Error al crear el nuevo cliente.*/
                    Error(4, "No se puede crear un nuevo cliente.");
                    break;
                case 0:   
                    /* Somos un nuevo cliente. */                           
                    _exit = MeetClient(_clientSocket, _clientIP);
                    /* Se libera el cliente. */
                    exit(_exit); 
                default:  
                    /* Se libera el socket del cliente, ya que del mismo se encarga el hilo creado.*/ 
                    close(_clientSocket); 
                    break;
            }
        }
        else
        {
            std::cout << "Error al aceptar la conexión, reintentelo." << std::endl;
        }
    } 
}

/**
 * Verificar si algun cliente ha pedido la desconección.
 */

void NetworkHandler::verifyDeadClient()
{
    /* Miramos si se ha cerrado algún cliente últimamente. */
    
    _childPid = waitpid(0, &_pidStatus, WNOHANG);
    
    if (_childPid > 0)
    {  
        if (WIFEXITED(_pidStatus))
        {
            std::cout << "Se ha desconectado el cliente: " << inet_ntoa(_clientIP.sin_addr) << std::endl;
            if ( WEXITSTATUS(_pidStatus) == 99)
            {
                /* Se ha pedido el cierre del servidor por parte del usuario. */
                std::cout << "Se ha pedido el cierre del servidor por parte de algun usuario." << std::endl;
                _run = 0;
            }
        }
        /* Se reinicia el mensaje de esperando conexión */
        _indicatorMessage = 0;
    }  
}

/**
 * Ciclo que mantiene el servidor corriendo a la espera de conexiones.
 */

void NetworkHandler::Run()
{  
    /* Se verifican los errores principales antes de levantar el servidor. */
    verifyLiftErrors();
    
    while(_run)
    {
        /* Imprime que se esta esperando alguna conexión. */
        
        WaitConnectionMsg(_indicatorMessage);
        
        /* Se carga el valor de rfdsn (Utilizados para la conexión) */
        
        FD_ZERO(&_rfds);
        FD_SET(_serverSocket, &_rfds);

        /* Se carga el valor de time. */        
        _timeAccept.tv_sec = 0;
        
        /* Se carga el valor del tiempo de espera */
        
        _timeAccept.tv_usec = 500000;  
        
        /* Se verifica si hay alguna conexión (Cliente) nueva. */
        
        verifyNewClient();
        
        /* Se verifica si alguna conexión (Cliente) murio. */
        
        verifyDeadClient();   
    }
    
    /* Se cierra el socket del servidor. */
    close(_serverSocket);
}
