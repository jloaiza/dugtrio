
/**
  VERSION: 1a
**/


#ifndef LSSMANAGER_H
#define LSSMANAGER_H

#include "lss.h"

/** TODO: check that this fordward declaration will correctly work **/
template <class LLS>
class DoubleLinkedList<LLS>;
class LSSNetworkHandler;
class LSSConsole;
class LSSOperations;

class LSSManager{

private:

    /**
     * @brief _lssList
     * @brief _networkHandler
     * @brief _console
     * @brief _logic
     */
    DoubleLinkedList<LSS>*  _lssList;
    LSSNetworkHandler*      _networkHandler;
    LSSConsole*             _console;
    LSSOperations*          _logic;


public:

    /**
     * @brief LSSManager
     */
    LSSManager();

    /** TODO:start, getters, setters **/

};

#endif // LSSMANAGER_H
