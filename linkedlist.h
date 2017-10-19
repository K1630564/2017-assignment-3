#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

template<typename T>
class LinkedList{
private:
    int listSize;

public:

    Node<T>* head;

    Node<T>* tail;

    Node<T>* last;



    LinkedList():
            listSize(0), head(nullptr), tail(nullptr), last(nullptr){
    }
    ~LinkedList(){

           while(size() > 0){
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
         NodeIterator<T> temp = NodeIterator<T>(head);
        return temp;
    }


    NodeIterator<T> end() {

        if (head == nullptr) {
            return begin();
        } else {          
            int test = 0;
            Node<T> *emptyNode = new Node<T>(test);
            tail->next = emptyNode;
            NodeIterator<T> itr = NodeIterator<T>(tail->next);

            delete emptyNode;
            return itr;

        }
    }



};


// do not edit below this line

#endif
