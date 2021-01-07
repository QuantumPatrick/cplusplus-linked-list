//
//  main.cpp
//  LinkedList
//
//  Created by Patrick Procter on 11/16/20.
//

#include <iostream>

#include "main.hpp"

template<class T>
Node<T>::Node() {
    //default constructor
    //allows us to create an object without initialization
}

//This constructor is just to set next pointer of a node and the data contained
template<class T>
Node<T>::Node(const T& item, Node<T>* ptrnext) {
    this->data = item;
    this->next = ptrnext;
}

template<class T>
Node<T>*Node<T>::NextNode() {
    return this->next;
}

//This method inserts a node just after the node that the method belongs to
//Consider a better implementation?

template<class T>
void Node<T>::InsertAfter(Node<T> *p) {
    // to not lose the rest of the list, we ought to link the rest
    // of the list to the Node<T>* p first
    p->next = this->next;
    
    // now we should link the previous Node to Node<T> *p, i.e. the
    //Node that we are inserting after
    this->next = p;
}

//Deletes the node from the list and returns the deleted node
template<class T>
Node<T>* Node<T>::DeleteAfter() {
    // store the next Node in a temporary Node
    Node<T>* tempNode = next;
    //check if there is a next Node
    if (next != NULL)
        next = next->next;
    
    return tempNode;
}







int main() {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
