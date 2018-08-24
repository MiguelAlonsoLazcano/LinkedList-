//
// Created by alonso on 8/23/18.
//

#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

#include "SingleList.h"

/*
 * @brief Node class
 * */
template <typename T>
class Node {
public:
    /*
     * @brief param constructor
     * */
    Node(const T & value): value{value}{}


    T getValue(){
        return value;
    }

    void setValue(int i){
        value = i;
    }

    void setNext(Node* node){
        next = node;
    }

    Node<T>* getNext(){
        return next;
    }

    T value{};
    Node* next{};

};


#endif //LINKEDLIST_NODE_H
