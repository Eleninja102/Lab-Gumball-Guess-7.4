//
//  Header.h
//  Lab: Gumball Guess 7.4
//
//  Created by Coleton Watt on 3/2/22.
//

#pragma once
#include <memory>
#include <sstream>
#include <string>
#include <stack>
#include "Person.h"


using namespace std;


template<class Type>
struct Node{
    Type data;
    //Node<Type> *next;
    shared_ptr <Node<Type> > next;
};

template<class Type>
class Queue;

template<class Type>
ostream& operator<< (ostream& out, const Queue<Type>& list);


template<class Type>
class Queue{
public:
    Queue(): front(nullptr), back(nullptr), count(0) {}
    Queue(const Queue<Type> &lst);
    void enqueue(Type data);
    Type peek();
    void dequeue();
    void clear();
    bool isEmpty();
    
    friend ostream& operator<< <>(ostream& out, const Queue<Type>& lst);
    void operator = (const Queue<Type>& list);

protected:

    //Node<Type> *front;
    //Node<Type> *back;
    shared_ptr <Node<Type> > front;
    shared_ptr <Node<Type> > back;
    int count = 0;
};

template<class Type>
void Queue<Type>::operator = (const Queue<Type>& lst){
    auto temp = lst.front;
    for (int i = 0; i < lst.count; i++) {
      enqueue(temp->data);
      temp = temp->next;
    }
}

template<class Type>
Queue<Type>::Queue(const Queue<Type> &lst) {
   auto temp = lst.front;
   for (int i = 0; i < lst.count; i++) {
     enqueue(temp->data);
     temp = temp->next;
   }
}

template<class Type>
void Queue<Type>::enqueue(Type data){
    //auto temp = new Node<Type>();
    auto temp = make_shared<Node<Type>> ();
    temp->data = data;
    temp->next = nullptr;
    if(!front){
        front = temp;
        back = temp;
    }
    else{
        back->next = temp;
        back = temp;
    }
    count++;
}
template<class Type>
Type Queue<Type>::peek(){
    int ndx = 0;
    if(count == 0){
        throw runtime_error("Out of range");
    }

    int currNodeNum = 0;
    auto currentNode = front;

    while(currNodeNum < ndx){
        currNodeNum++;
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

template<class Type>
void Queue<Type>::dequeue(){
    if(count == 0){
        throw runtime_error("Out of range");
    }
    auto toDelete = front;
    front = toDelete->next;
    //delete toDelete;
    count --;
    return;
   
    
}

template<class Type>
void Queue<Type>::clear(){
    
    if(count == 0){
        throw runtime_error("Out of range");
    }
    auto toDelete = front;
    front = nullptr;
    //delete toDelete;
    count = 0;
    return;
 
    
}

template<class Type>
bool Queue<Type>::isEmpty(){
    return 0 == count;
}

template<class Type>
ostream& operator<< (ostream& out, const Queue<Type>& list){
    auto curr = list.front;

    while(curr){
        out << curr->data;
        if(curr->next){
            out << " ";
        }
        curr = curr->next;
    }
    return out;
}


