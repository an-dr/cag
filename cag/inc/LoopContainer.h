//
// Created by Andrey Gramakov on 31-Oct-18.
//

#ifndef CAG_LOOPCONTAINER_H
#define CAG_LOOPCONTAINER_H

#define DEBUGOUT

#ifdef DEBUGOUT
#include <iostream>
#endif

template <class T>
class LoopContainer
{
private:
    int m_pos;
    int m_size;
    T* m_looped;

public:
    LoopContainer();
    explicit LoopContainer(int size);
    ~LoopContainer();
//    class iterator;
    void add(T newone);
    void print();
};

//class LoopContainer<T>::iterator{
//
//};

#include "../src/LoopContainer.cpp"

#endif //CAG_LOOPCONTAINER_H
