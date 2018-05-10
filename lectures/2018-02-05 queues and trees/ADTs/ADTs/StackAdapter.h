#ifndef STACK_ADAPTER_H
#define STACK_ADAPTER_H

#include "IndexedCollection.h"
#include "Stack.h"
template <typename T>
class StackAdapter : Stack<T>
{
private:
    IndexedCollection<T> *_container = nullptr;

public:
    StackAdapter(IndexedCollection<T> *container)
        : _container(container)
    {

    }

    virtual void push(const T& item)
    {
        _container->addElement(item);
    }

    virtual const T& getTop() const
    {
        int last = _container->getSize() - 1;
        return _container->getElementAt(last);
    }

    virtual T& getTop()
    {
        int last = _container->getSize() - 1;
        return _container->getElementAt(last);
    }

    
    virtual T pop()
    {
        int last = _container->getSize() - 1;
        T top = _container->getElementAt(last);
        _container->removeElementAt(last);
        return top;
    }

    virtual int getSize() const
    {
        return _container->getSize();
    }
};

#endif // !STACK_ADAPTER_H
