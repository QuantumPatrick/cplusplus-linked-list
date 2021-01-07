//
//  main.hpp
//  LinkedList
//
//  Created by Patrick Procter on 11/16/20.
//

#ifndef main_h
#define main_h

template <class T>
class Node {
public:
    Node();
    Node(const T& item, Node<T>* ptrnext = NULL);
    T data;
    //Access to the next node
    Node<T>* NextNode();
    //List modification methods
    void InsertAfter(Node<T>* p);
    Node<T>* DeleteAfter();
    Node<T> * GetNode(const T& item, Node<T>* nextptr = NULL);
    
private:
    Node<T>* next;
};


#endif /* main_h */
