# cplusplus-linked-list

## Problem
This project was coded for academic purposes. It is a singly linked list implementation for the C++ language. It was designed with the idea of using arbitrary datatypes in mind.

## Functionality
### List Object Default Constructor
The default constructor for the List object sets two pointers, head and tail, to NULL.

### List Object Overloaded Constructor
The usual constructor for the List object initializes the head and tail pointers to NULL, then implements the addNode function (described below) a number of times defined by the user when called.

##Accessor Functionalities
### addNode()
Each time the addNode() function is called, it creates a temporary pointer to a new Node. If no nodes exist, the List object's head and tail pointers are both set to the new Node pointer. Otherwise, the last Node in the linked list is updated to point to the newly created Node.

### List::front() & List::back()
The front() and back() functions, respectively, return the head and tail Nodes of a given List object.

### List::at()
The at() function returns the metadata of a particular Node. 

### List::assign()
The assign() function assigns the metadata of a particular Node to a piece of user-inputted data.

### List::size()
The size() function returns, as an unsigned integer, the number of Nodes in a user-defined List object.
