#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <initializer_list>
using std::initializer_list;


template<typename T>
class LinkedList{
private:
    int listSize;

public:

    Node<T>* head;

    Node<T>* tail;

    Node<T>* last ;

    //Node<T>* master;


    LinkedList(initializer_list <T> l): listSize(0), head(nullptr), tail(nullptr), last(nullptr) {


        for (int i = 0; i < 4; i++){

            this->push_back(l.begin()[i]);


        }




    }



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

    T &front() const{
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

    T &back() const{
        return tail->data;
    }


    int size() const{
        return listSize;
    }


    NodeIterator<T> begin() const{
        NodeIterator<T> temp = NodeIterator<T>(head);
        return temp;
    }


    NodeIterator<T> end() const {

        if (head == nullptr) {
            return begin();
        } else {

            int test = 0;
            Node<T> *emptyNode = new Node<T>(test);
            tail->next = emptyNode;

            NodeIterator<T> itr = NodeIterator<T>(emptyNode);

            delete emptyNode;
            return itr;

        }
    }

     NodeIterator<T> insert(NodeIterator<T> whereToInsert, T toInsert) {

        Node<T> *newNode = new Node<T>(toInsert);
        newNode->next = nullptr;
        Node<T> *curr = begin().nodePtr();


        for (int i = 0; i < size(); i++) {

        if (whereToInsert.nodePtr() == curr) {

            if(i == 0){
                this->push_front(toInsert);
                return newNode;

            }
            else if(i == size()-1){

                this->push_back(toInsert);
                return newNode;
            }

            else {

                newNode->previous = curr->previous;
                curr->previous = newNode;
                newNode->next = curr;
                newNode->previous->next = newNode;

                listSize++;

                return newNode;
            }
        } else {

            curr = curr->next;

        }

    }

         return nullptr;
    }

   NodeIterator<T> erase(NodeIterator<T> whereToErase)  {


       Node<T> *curr = begin().nodePtr();  //temp1



       for (int i = 0; i < size(); i++) {
           if (whereToErase.nodePtr() == curr) {


               if (i == 0) {
                   head = curr->next;
                   free(curr);
                   listSize --;
                   return head;
               }


                   else if (i == size() - 1) {

                       tail = curr->previous;

                       free(curr);
                        listSize --;
                       return tail->next;


                   }

                   else {
                        Node <T> *temp2 = curr->next;
                        temp2->previous = curr->previous;
                        curr->next= nullptr;
                        curr->previous = nullptr;

                       free(curr);
                        listSize --;
                       return temp2;
                   }

               }

           else {
                   curr = curr->next;
               }

       }

           return nullptr;



   }



};


// do not edit below this line

#endif