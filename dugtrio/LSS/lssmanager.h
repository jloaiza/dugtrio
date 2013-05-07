
/**
  VERSION: 1a
**/


#ifndef LSSMANAGER_H
#define LSSMANAGER_H

#include "lss.h"

/** TODO: check that this fordward declaration will correctly work **/
class DoubleLinkedList;
class LSSNetworkHandler;
class LSSConsole;
class LSSOperations;

class LSSManager{

private:
    DoubleLinkedList<LSS>*  _lssList;
    LSSNetworkHandler*      _networkHandler;
    LSSConsole*             _console;
    LSSOperations*          _logic;


public:
    LSSManager();

    /** TODO:start, getters, setters **/

};

#endif // LSSMANAGER_H
