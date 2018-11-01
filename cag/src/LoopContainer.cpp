//
// Created by Andrey Gramakov on 31-Oct-18.
//

#ifndef CAG_LOOPCONTAINER_CPP
#define CAG_LOOPCONTAINER_CPP

#include "LoopContainer.h"

using namespace std;

template<class T>
LoopContainer<T>::LoopContainer()
{
#   ifdef DEBUGOUT
    cout << "default" << endl;
#   endif
};

template<class T>
LoopContainer<T>::LoopContainer(int size)
        : m_size(size), m_pos(0)
{
#   ifdef DEBUGOUT
    cout << "new" << endl;
#   endif
    m_looped = new T[m_size];

}

template<class T>
LoopContainer<T>::~LoopContainer()
{
#   ifdef DEBUGOUT
    cout << "delete" << endl;
#   endif
    delete[] m_looped;
}

template<class T>
void LoopContainer<T>::add(T newone)
{
    m_looped[m_pos++] = newone;
    if (m_pos==m_size) m_pos = 0;
}

template<class T>
T& LoopContainer<T>::get(int val)
{
    return m_looped[val];
}

template<class T>
void LoopContainer<T>::print()
{
    for (int i = 0; i<m_size; i++)
        cout << m_looped[i] << endl;
}

template<class T>
auto LoopContainer<T>::begin() -> LoopContainer<T>::iterator
{
    return iterator(0, *this);
}

template<class T>
auto LoopContainer<T>::end() -> LoopContainer<T>::iterator
{
    return iterator(m_size, *this);
}

template<class T>
LoopContainer<T>::iterator::iterator(int val, LoopContainer& lc_ref)
        : m_val(val), m_lc_ref(lc_ref) { }


template<class T>
T LoopContainer<T>::iterator::operator*()
{
    return m_lc_ref.m_looped[m_val];
}

template<class T>
auto LoopContainer<T>::iterator::operator++() -> LoopContainer<T>::iterator
{
    m_val++;
    return *this;
}

template<class T>
auto LoopContainer<T>::iterator::operator++(int) -> const LoopContainer<T>::iterator
{
    auto const r = *this;
    m_val++;
    return r;
}

template<class T>
bool LoopContainer<T>::iterator::operator==(const LoopContainer<T>::iterator &other)
{
    return m_val == other.m_val;
}

template<class T>
bool LoopContainer<T>::iterator::operator!=(const LoopContainer<T>::iterator &other)
{
    return !(*this==other);
}

#endif //CAG_LOOPCONTAINER_CPP