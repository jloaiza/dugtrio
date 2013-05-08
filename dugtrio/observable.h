
#ifndef OBSERVABLE_H
#define OBSERVABLE_H

/** FIXME: Quitar esta clase y sustituirla por una no std **/
#include <set>
#include "observer.h"


class Observable {

protected:
    /**
     * @brief _isChanged
     *          Tell wether the current object has unreported updates
     */
    bool                    _isChanged  = false;

    /**
     * @brief _observers
     *          List all the observers binded to notify
     */
    std::set<Observer*>     _observers;

    /**
     * @brief setUnchanged
     *          Discard all the changes unnotified
     */
    void setUnchanged() {
        _isChanged = false;
    }

    /**
     * @brief isChanged
     *          Tells wether the object has been modified and not nofied
     * @return
     *          True when there are unnotified changes, false otherwise
     */
    bool isChanged(){
        return _isChanged;
    }

    /**
     * @brief notify
     *          Calls the update method of all subscribed observers
     * @param pMessage
     *          Appended message to send to the observers. It's on the observer side to
     *          decide what to do with the sent message.
     */
    void notify(void* pMessage){

        if (_isChanged){
            std::set<Observer*>::iterator it;

            for (it = _observers.begin(); it != _observers.end(); it++){
                (*it)->update(this, pType, pArg1, pAarg2);
            }
            setUnchanged();
        }
    }

public:

    /**
     * @brief setChanged
     *          State that there are unnotified messages
     */
    void setChanged() {
        _isChanged = true;
    }

    /**
     * @brief addObserver
     *          Add a new observer to the list of subscribed observers
     * @param ob
     *          The new observer to subscribe
     */
    void addObserver(Observer* ob){
        _observers.insert(ob);
    }

    /**
     * @brief removeObserver
     *          Remove a given observer from the subscriber list. If the observer is not subscribed
     *          then nothing happen
     * @param ob
     *          The observer to unsubscribe
     */
    void removeObserver(Observer* ob){
        _observers.erase(ob);
    }

};

#endif //OBSERVABLE_H
