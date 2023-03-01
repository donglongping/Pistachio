//
// Created by dz on 2023/3/1.
//

#ifndef PISTACHIO_SINGLETON_H
#define PISTACHIO_SINGLETON_H

#include "nocopyable.h"

#include <forward_list>


template<class T>
class Singleton : public nocopyable
{
public:
    template<typename... Args>
    static T* instance(Args&&... args)
    {
        if (m_instance == nullptr) {
            m_instance = new T(std::forward<Args>(args)...);
        }
        return m_instance;
    }

    static void destroy()
    {
        if(m_instance) {
            delete m_instance;
        }
        m_instance = nullptr;
    }

protected:
    Singleton() {}

private:
    static T* m_instance;

};

template<class T>
T* Singleton<T>::m_instance = nullptr;


#endif //PISTACHIO_SINGLETON_H
