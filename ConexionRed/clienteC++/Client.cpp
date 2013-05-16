/**
*************************************************************
* @file: Client.CPP
* @brief: Creando un cliente TCP!!!!
* @author Yeison Arturo Cruz León :)
* @Universidad: Instituto Tecnológico de Costa Rica.
* @Carnet: 201258348.
* @date 10 de mayo del 2013
************************************************************
*/

#include <string>

#include "Client.h"

/**
 * Constructor de la clase, llama a los métodos para iniciar la conexión.
 * @param pIp: Ip a la cual se quiere conectar.
 * @param pPort: Puerto por el cual se quiere conectar.
 */

Client::Client(std::string pIp, int pPort) 
{
    setIp(pIp);
    setPort(pPort);
    openSocket();
    setSocket();
}

/**
 * Muestra errores que se puedan dar al realizar las conexiones.
 * @param pError: Recive la especificación del error.
 */

void Client::Error(std::string pError)
{
    exit( (perror(pError.c_str()), -1) );
}

/**
 * Método que se encarga de abrir el socket para poder trabajar con las conexiones.
 */

void Client::openSocket()
{
    _socket = socket(PF_INET, SOCK_STREAM, 0);
    if (_socket < 0)
    {
        Error("No se pudo crear el socket, reintentelo.");
    }
}

/**
 * Método que se encarga de setear las variables principales del socket
 * para poder realizar uan conexión exitosa.
 */

void Client::setSocket()
{
    _connection.sin_family = AF_INET;
    _connection.sin_port = htons(getPort());
    inet_aton(getIp().c_str(), &_connection.sin_addr);
}

/**
 * Método que conecta hacia la IP dada al instanciar la clase junto con su puerto.
 */

void Client::Connect()
{
    if( connect(_socket, (_socketDirection) &_connection, sizeof(_connection)) < 0)
    {
        Error("La conexión no se pudo establecer, lo sentimos.");
    }
}

/**
 * Se encarga de enviar un mensaje hacia la IP dada al construir la clase, 
 * llamese mensaje a un string con algúna instrucción.
 * @param pMessage: El comando o la instrucción a enviar por la red.
 */

void Client::sendMessage(std::string pMessage)
{
    if (write (_socket, pMessage.data(), pMessage.size()) < 0)
    {
        Error("No se pudo enviar el mensaje, reintentelo de nuevo.");
    }
    usleep(10000);
}

/**
 * Método que se encarga de leer desde el socket todo lo recivido al enviar algún
 * comando por medio de la red, es decir, la respuesta del servidor.
 */

char* Client::readMessage()
{
     if (read(_socket, _inMessage, sizeof(_inMessage)) < 0)
     {
         Error ("No se pudo leer el mensaje correctamente.");
     }
     return _inMessage;
}
