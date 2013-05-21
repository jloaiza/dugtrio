
#ifndef OBSERVER_H
#define OBSERVER_H


class Observable;
class Observer {
public:

    /**
     * @brief update
     *          Call made from a observable object to alert of an event detailed in pMessage
     * @param ob
     *          Observable object doing the call, normally "this"
     * @param pMessage
     *          Pointer to the message, depending of the implementation it has to be casted to a different
     *          type.
     */
    virtual void update(Observable* ob, void* pMessage) = 0;
};

#endif // OBSERVER_H
