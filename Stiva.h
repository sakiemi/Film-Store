#pragma once

#include <exception>
#include "StackException.h"

using namespace std;
template <class T>

class Stiva
{
public:
    Stiva() { m_front = -1; }
    void push(T elem);
    bool pop();
    T front(bool& ok);
    size_t size();
    bool isEmpty();
    bool isFull();

private:
    size_t m_front;
    T m_arr[100];
};

template <class T>
T Stiva<T>::front(bool& ok)
{
    ok = false;
    if (isEmpty() == false)
    {
        ok = true;
    }
    return m_arr[m_front];
}


template <class T>
bool Stiva<T>::isEmpty()
{
    return m_front == -1;
}

template <class T>
bool Stiva<T>::isFull()
{
    return m_front == 99;
}



template <class T>
size_t Stiva<T>::size()
{
    return m_front + 1;
}

template <class T>
bool Stiva<T>::pop() {
    if (isEmpty())
    {
        return false;
    }
    else
    {
        m_front--;
        return true;
    }
}

template <class T>
void Stiva<T>::push(T elem) {
    if (isFull())
        throw StackException("Pushing while stiva is full");
    m_arr[++m_front] = elem;
}