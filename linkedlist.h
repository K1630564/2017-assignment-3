#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

template<typename T>
class LinkedList{

public:

    Node<T>* head;

    Node<T>* tail;

    int listSize;

    LinkedList():
            head(nullptr), tail(nullptr), listSize(0){
    }
        // deconstructor not tested
    ~LinkedList(){

           while(listSize > 0){
               Node<T>* temp = tail;
               if(head == tail){
                   head = nullptr;
               }
               tail->next = nullptr;
               tail = tail->previous;

               delete temp;

               listSize--;

           }

    }


    void push_front(T toPushFront){
      Node<T>* temp = new Node<T>(toPushFront);

        if(head == nullptr){
            head = temp;
            tail = temp;
        }
        else{ //what about tail?
            head->previous = temp;
            temp->next = head;
            head = temp;

        }
        listSize++;
    }

    T &front(){
        return  head->data;
    }


    void push_back(T toPushBack){
        Node<T>* temp = new Node<T>(toPushBack);

        if(tail == nullptr){
            head = temp;
            tail = temp;
        } else{
            tail->next = temp;
            temp->previous = tail;
            tail = temp;
        }
        listSize++;
    }

    T &back(){
        return tail->data;
    }


    int size(){
        return listSize;
    }


    NodeIterator<T> begin(){
         NodeIterator<T>* temp = new NodeIterator<T>(head);
        return *temp;
    }


    //not tested
    NodeIterator<T> end(){
        NodeIterator<T>* temp = new NodeIterator<T>(tail->next);
        return *temp;
    }



};


// do not edit below this line

#endif
