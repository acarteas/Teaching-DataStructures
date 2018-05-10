#ifndef  QUEUE_ADAPTER_H
#define  QUEUE_ADAPTER_H

#include "IndexedCollection.h"
#include "Queue.h"
template <typename T>
class QueueAdapter : public Queue<T>
{
private:
    IndexedCollection<T> *_data;

public:
    QueueAdapter(IndexedCollection<T> *data)
    {
        _data = data;
    }
    virtual T &getFirst()
    {
        return _data->getElementAt(0);
    }
    virtual const T &getFirst() const
    {
        return _data->getElementAt(0);
    }
    virtual void enqueue(const T& item)
    {
        _data->addElement(item);
    }
    virtual T dequeue()
    {
        T first = getFirst();
        _data->removeElementAt(0);
        return first;
    }
    virtual int getSize() const
    {
        return _data->getSize();
    }
};

#endif // ! QUEUE_ADAPTER_H
