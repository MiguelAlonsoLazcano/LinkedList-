//
// Created by alonso on 8/23/18.
//

#pragma once
#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H


#include <Node.h>
#include <cstdio>
#include <initializer_list>
#include <cassert>

template <typename T>
class SingleList {
public:
    using size_type = size_t;
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;

    /*
     * @brief Default Contructor
     * */
    SingleList() = default;

    /*
     * @brief Param Constructor
     * */
    SingleList(size_type count, const_reference value){
        assert(count!= 0);
        add(value);
        if (count == 1)
            return;
        auto tmpNode = m_head;
        for (size_type i = 1; i < count; ++i, tmpNode = tmpNode->getNext())
            tmpNode->setNext(new Node<value_type>{value});
        m_size = count;

    }

    /*
     * @biref Contructor that accepts a initialized list
     * */
    SingleList(std::initializer_list<value_type> list){
        auto itr = list.begin();
        add(*itr++);
        auto tmpNode = m_head;
        while (itr != list.end()){
            tmpNode->setNext(new Node<value_type>{*itr++});
            tmpNode = tmpNode->getNext();
        }

    }

    /*
     * @brief Copy Contructor
     * */
    SingleList(const SingleList<value_type> &other){
        if(other.empty())
            return;
        copy(other);
    }

    /*
     * @brief Copy Contructor
     * */
    SingleList &operator =(const SingleList<value_type> &other){
        if (this != &other){
            clear();
            copy(other);
        }
        return *this;
    }

    /*
     * @brief Move Operators, Move Contructor
     * moves the resources in the current list
     * */
    SingleList(SingleList<value_type> &&other){
        m_size = other.m_size;
        m_head = other.m_head;
        other.m_head = nullptr;
        other.m_size = 0;

    }

    /*
     * @brief Move assigment
     * */
    SingleList &operator =(SingleList<value_type> &&other){
        if(this != &other){
            m_size = other.m_size;
            m_head = other.m_head;
            other.m_head = nullptr;
            other.m_size = 0;
        }
        return *this;

    }

    /*
     * @brief Destructor
     * */
    ~SingleList(){
        clear();
    }

    const_reference front() const {}

    bool empty()const {}

    /*
     * @brief Deletes all the nodes from the list
     * */
    void clear(){
        if(m_size == 0)
            return;
        auto p_head = m_head;
        do{
            m_head = m_head->getNext();
            delete p_head;
            p_head = m_head;
        }while(p_head != nullptr);
        m_size = 0;
    }

    Node<value_type> * getHead() const {
        return m_head;
    }

    /*
     * @breif Add operation add a new node in the list if it is empty,
     * if the list is not empty, it create a new node and assign the
     * head of the list to this new node, this operation will be a
     * const time operation
     * */
    void add(const_reference element){
        if (m_size == 0)
            m_head = new Node<value_type>{element};
        else{
            Node<value_type> *t = new Node<value_type>{element};
            t->next = m_head;
            m_head = t;
        }
        ++m_size;

    }

    void insert(){}

    void remove(){}

private:

    /*
     * @brief copy functionality to copy the nodes from
     * 'other' SingleList to 'this'
     * */
    void copy(const SingleList &other){
        // add the head from 'other' to 'this' head
        auto other_head = other.m_head;
        add(other_head->value);
        other_head = other_head->getNext();
        auto tmpNode = m_head;
        while(other_head != nullptr){
            tmpNode->setNext(new Node<value_type>{other_head->getValue()});
            tmpNode = tmpNode->getNext();
            other_head = other_head->getNext();
        }
        m_size = other.m_size;
    }

    Node<value_type> *m_head{};
    size_type m_size{};

};


#endif //LINKEDLIST_LINKEDLIST_H
