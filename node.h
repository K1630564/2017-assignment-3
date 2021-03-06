#ifndef NODE_H
#define NODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

template<typename T>
class Node {

public:

    T data;

    Node<T>* next;

    Node<T>* previous;

    Node(const T& dataIn)
            : data(dataIn), next(nullptr), previous(nullptr){
    }


};




template<typename T>
class NodeIterator {

private:

    Node<T>* current;

public:


    NodeIterator(Node<T>* currentIn)
            : current(currentIn) {
    }

    T & operator*() {
        return current->data;
    }

    Node<T>* nodePtr(){
        return current;
    }

    NodeIterator<T> & operator++ (){
        current = current->next;
        return *this;
    }

    bool operator== ( const NodeIterator<T> & toCompare) const{

        if(current == toCompare.current){
            return true;
        }
        return false;
    }

    bool operator!= ( const NodeIterator<T> & toCompare) const{


        if(current != toCompare.current){
            return true;
        }
        return false;
    }






};

// do not edit below this line

#endif