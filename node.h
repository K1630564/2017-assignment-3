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

    NodeIterator<T> & operator++ (){
        current = current->next;
        return *this;
    }

    bool operator== (NodeIterator<T> & toCompare){
        NodeIterator<T> itr2 = NodeIterator<T> (toCompare);
        NodeIterator<T> itr = NodeIterator<T> (current);
        if(*itr2 == *itr){
            return true;
        }
        return false;
    }

    bool operator!= (NodeIterator<T> & toCompare) {

        NodeIterator<T> itr2 = NodeIterator<T> (toCompare);
        NodeIterator<T> itr = NodeIterator<T> (current);
        if (*itr2 == *itr){
            return false;
        }
        return true;
    }

    
};

// do not edit below this line

#endif
