//
//  Singly Linked List
//
//  Created by Patrick Procter on 11/17/20.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

void printDiv() {
    std::cout << "\n======================================\n";
}
    
    template<class T>
    class Node {
    public:
        T data; //stored data
        Node<T>* next; //pointer to next node
    };
    
    template<class T>
    class List {
        Node<T> *head, *tail;
        unsigned int numCells;
    public:
        
        //Accessors
        //====================================================
        List();
        List(unsigned int);
        
        void addNode();
        
        Node<T>* front();
        
        Node<T>* back();
        
        T at(unsigned int);
        
        void assign(unsigned int, T);
        
        unsigned int size();
        //Mutators
        //====================================================
        
        void remove(unsigned int);
        void remove(unsigned int, unsigned int);
        
        void insert(unsigned int, T);
        void insert(unsigned int, List<T>&);
        
        void push_back(T);
        
    };
    
    template<class T>
    List<T>::List() {
        head = NULL;
        tail = NULL;
    }
    
    template<class T>
    List<T>::List(unsigned int num) {
        head = NULL;
        tail = NULL;
        
        for (int i = 0; i < num; i++) {
            List<T>::addNode();
        }
    }
    
    //Accessor Definitions
    //====================================================
    
    template<class T>
    void List<T>::addNode() {
        Node<T>* temp = new Node<T>;
        temp->next = NULL;
        temp->data = NULL;
        
        if (head == NULL) {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
        
    }
    
    template<class T>
    Node<T>* List<T>::front() {
        return head;
    }
    
    template<class T>
    Node<T>* List<T>::back() {
        return tail;
    }
    
    template<class T>
    T List<T>::at(unsigned int pos) {
        Node<T>* p = head;
        for (int i = 0; i < pos; i++) {
            p = p->next;
        }
        return p->data;
    }
    
    template<class T>
    void List<T>::assign(unsigned int pos, T inputData) {
        Node<T>* p = head;
        for (int i = 0; i < pos; i++) {
            p = p->next;
        }
        p->data = inputData;
    }
    
    template<class T>
    unsigned int List<T>::size() {
        unsigned int num = 1;
        Node<T>* p = head;
        while (p && p->next) {
            p = p->next;
            num++;
        }
        
        return num;
    }
    
    //Mutator Definitions
    //====================================================
    
    
    template<class T>
    void List<T>::remove(unsigned int index) {
        Node<T>* p = head;
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        
        if (p->next == NULL) {
            
        }
        else if (p->next->next == NULL) {
            p->next = NULL;
        }
        else {
            p->next = p->next->next;
        }
        
    }
    
    template<class T>
    void List<T>::remove(unsigned int s, unsigned int e) {
        for (int i = s; i < e + 1; i++) {
            List<T>::remove(s);
        }
    }
    
    template<class T>
    void List<T>::insert(unsigned int index, T data) {
        Node<T>* p = head;
        Node<T>* temp = head;
        Node<T>* createdNode = new Node<T>;
        
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next; //Gives pointer to node before index
        }
        
        for (int i = 0; i < index; i++) {
            p = p->next; //Gives pointer to node at index
        }
        createdNode->data = data;
        
        temp->next = createdNode;
        createdNode->next = p;
    }
    
    template<class T>
    void List<T>::insert(unsigned int index, List<T>& other) {
        Node<T>* p = head;
        Node<T>* temp = head;
        Node<T>* otherList = other.head;
        unsigned int numSkip;
        
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next; //Gives pointer to node before index
        }
        
        for (int i = 0; i < index; i++) {
            p = p->next; //Gives pointer to node at index
        }
        
        temp->next = other.front();
        numSkip = other.size();
        
        otherList = other.back();
        otherList->next = p;
    }
    
    template<class T>
    void List<T>::push_back(T data) {
        List<T>::addNode();
        List<T>::assign(List<T>::size() - 1, data);
    }



int main(void) {
    
    srand(time(NULL));
    
    std::cout << "Begin Linked List Testing Sequence:";
    printDiv();
    unsigned int numNodes = rand() % 12;
    numNodes = numNodes + 3;
    unsigned int randInd1 = rand() % numNodes, randInd2 = rand() % numNodes, randInd3 = rand() % numNodes;
    List<int> intTest(numNodes);
    std::cout << "List of (" << numNodes << ") random integers: ";
    
    for (int i = 0; i < intTest.size(); i++) {
        intTest.assign(i, rand() % 9999);
        std::cout << intTest.at(i) << " ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "First value using front(): " << intTest.front()->data << std::endl;
    std::cout << "Last value using back(): " << intTest.back()->data << std::endl << std::endl;
    
    std::cout << "Data values at a random positions using at():" << std::endl;
    std::cout << "Value at index " << randInd1 << ": " << intTest.at(randInd1) << std::endl << std::endl;
    
    unsigned int newVal = rand() % 9999;
    std::cout << "Reassigning data value at random position using assign():" << std::endl;
    std::cout << "Reassigning index " << randInd2 << " to " << newVal << "." << std::endl;
    intTest.assign(randInd2 - 1, newVal);
    std::cout << "New list: ";
    for (int i = 0; i < intTest.size(); i++) {
        std::cout << intTest.at(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}
