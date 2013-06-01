#include "parserxml.h"

int main(int argc, char *argv[]) 
{

    QApplication app(argc, argv);
    parserxml* prueba = new parserxml();
    prueba->createDocument("/home/bugtraq/Desktop/XML/test.xml");
    prueba->createRoot("home");
    prueba->createRootChild("bugtraq");
    prueba->createChildAttribute("Attribute1","1");
    prueba->createChildValue("VALOR :D1");
    prueba->createRootChild("CHILD2");
    prueba->createChildAttribute("Attribute2","2");
    prueba->createChildValue("VALOR :D2");
    prueba->createOtherChild("bugtraq/","AVEMARIA");
    prueba->createChildAttribute("Attribute3","3");
    prueba->createChildValue("FUNCIONA");
    prueba->eraseChild("bugtraq/","AVEMARIA");
    prueba->updateDocument();
    prueba->tourXML("CHILD2[3]/");
    return app.exec();
}