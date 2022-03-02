/*#pragma once
#include <memory>
#include <sstream>
#include <string>
#include <stack>

using namespace std;


template<class Type>
struct Node{
    Type data;
    //Node<Type> *next;
    shared_ptr <Node<Type> > next;
};

template<class Type>
class LinkedList;

template<class Type>
ostream& operator<< (ostream& out, const LinkedList<Type>& list);


template<class Type>
class LinkedList{
public:
    LinkedList(): front(nullptr), back(nullptr), count(0) {}
    LinkedList(const LinkedList<Type> &lst) {
       auto temp = lst.front;
       for (int i = 0; i < lst.count; i++) {
         insert(temp->data);
         temp = temp->next;
       }
   }
// Default constructor for the LinkedList.  Creates an empty list by setting front and back of the list to nulllptr
    //~LinkedList();           //Destructor for the LinkedList.  Creates an empty list by setting front and back of the list to nulllptr
    void insert(Type data);  //Adds to the back of the list
    Type peek(int ndx)const ;//Looks at an element at the given ndx value
    void remove(int ndx);    //Removes an element at the given ndx position
    string reverse();
    friend ostream& operator<< <>(ostream& out, const LinkedList<Type>& lst);// Returns an output stream for displaying the LinkedList
    void operator = (const LinkedList<Type>& list);

protected:

    //Node<Type> *front;
    //Node<Type> *back;
    shared_ptr <Node<Type> > front;
    shared_ptr <Node<Type> > back;
    int count;//Number of nodes in list
};

template<class Type>
void LinkedList<Type>::operator = (const LinkedList<Type>& lst){
    auto temp = lst.front;
    for (int i = 0; i < lst.count; i++) {
      insert(temp->data);
      temp = temp->next;
    }
}

template<class Type>
string LinkedList<Type>::reverse(){
    stack<int>s;
    stringstream ss;
    auto temp = make_shared<Node<Type>> ();
    temp = front;
    while(temp != NULL){
       // cout << "hi";
        s.push(temp->data);
        temp = temp->next;
        //cout << "tested";
    }
    while(!s.empty()){
        ss << s.top();
        s.pop();
        if(!s.empty()){
            ss << " ";
        }
    }
    return ss.str();
}



template<class Type>
void LinkedList<Type>::insert(Type data){
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
Type LinkedList<Type>::peek(int ndx)const {
    if(ndx >= count || ndx < 0){
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
void  LinkedList<Type>::remove(int ndx){
    if(ndx >= count || ndx < 0){
        throw runtime_error("Out of range");
    }

    //If removing the front
    if(ndx == 0){
        auto toDelete = front;
        front = toDelete->next;
        //delete toDelete;
        return;
    }//end if
    int currNodeNum = 0;
    auto currentNode = front;

    while(currNodeNum < ndx-1){
        currNodeNum++;
        currentNode = currentNode->next;
    }
    auto toDelete = currentNode->next;
    //Deleting from middle
    if(toDelete->next){
        currentNode->next = toDelete->next;
    }
    //Delete last node
    else{
        currentNode->next = nullptr;
        back = currentNode;
    }
    count --;
    //delete toDelete;
}//end remove

template<class Type>
ostream& operator<< (ostream& out, const LinkedList<Type>& list){
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
*/
