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
    int m_cursor;
    int m_size;
    T* m_looped;
    void rshift();
    void lshift();

public:
    LoopContainer();
    explicit LoopContainer(int size);
    ~LoopContainer();
    void add(T newone);
    void print();
    T& get(int val);
    void return_cursor();
    void set_cursor(int new_pos);
    void shift_r(int n_times = 1);
    void shift_l(int n_times = 1);
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
