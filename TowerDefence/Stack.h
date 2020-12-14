//
// Created by Данил Морозов on 14/12/2020.
//

#ifndef TOWERDEFENCE_STACK_H
#define TOWERDEFENCE_STACK_H

#include <iostream>
#include <cstdlib>
#include <string>

template<typename T>
class Stack;


template<typename T>
class Stack
{
public:
    Stack();
    ~Stack();

    void push(const T& value);
    T pop();

    inline T peek();
    inline bool is_empty() const;
    inline void clear();

private:

    struct node
    {
        T value;
        node* next;
    } *top;

    std::size_t _size;

};



template<typename T>
Stack<T>::Stack():top(nullptr), _size(0) {}

template<typename T>
Stack<T>::~Stack()
{
    clear();
}

template<typename T>
void Stack<T>::push(const T& value)
{
    node *tmp  = new node;
    tmp->value = value;
    tmp->next  = top;
    top        = tmp;

    ++_size;
}

template<typename T>
T Stack<T>::pop()
{
    if (is_empty())
    {
        throw "Тут больше ловить нечего. Стек пуст";
    }

    node *tmp  = top->next;
    T 	 value = top->value;

    delete top;
    top = tmp;

    --_size;

    return value;
}


template<typename T>
inline T Stack<T>::peek()
{
    if (is_empty())
    {
        throw "Тут больше ловить нечего. Стек пуст";
    }

    return top->value;
}

template<typename T>
inline bool Stack<T>::is_empty() const
{
    return !top;
}

template<typename T>
inline void Stack<T>::clear()
{
    while(!is_empty())
    {
        pop();
    }

    top   = nullptr;
    _size = 0;
}


#endif //TOWERDEFENCE_STACK_H
