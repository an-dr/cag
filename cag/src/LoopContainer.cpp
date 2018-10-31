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
void LoopContainer<T>::print()
{
    for(int i = 0; i<m_size; i++)
        cout<< m_looped[i] << endl;
}


#endif //CAG_LOOPCONTAINER_CPP