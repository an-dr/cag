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
    void add(T newone);
    void print();
    T& get(int val);
    class iterator;
    iterator begin();
    iterator end();
};

template <class T>
class LoopContainer<T>::iterator{
private:
    int m_val;
    LoopContainer& m_lc_ref;
public:
    iterator(int val, LoopContainer& lc_ref);
    T operator*();
    iterator operator++();
    const iterator operator++(int);
    bool operator==(const iterator& other);
    bool operator!=(const iterator& other);

};

#include "../src/LoopContainer.cpp"

#endif //CAG_LOOPCONTAINER_H
