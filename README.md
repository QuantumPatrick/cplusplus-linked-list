# cplusplus-linked-list

## Problem
This project was coded for academic purposes. It is a singly linked list implementation for the C++ language. It was designed with the idea of using arbitrary datatypes in mind.

## Functionality
Two objects are used in this implementation. They are the List object, and the Node object. The Node object acts as a container for a single piece of data with an arbitrary data type. The List object acts as a container for an arbitrary number of Node objects, creating the singly linked list. All functions below are member functions of a the List object.

### List Object Constructor
The default constructor for the List object sets two pointers, head and tail, to NULL. This implementation creates an empty List containing zero Node objects.

An overloaded constructor takes an unsigned int as an argument. It will produce a List with that number of Nodes. Node metadata is NULL by default.

## Accessor Functionalities
The following functions access particular Nodes within a created List.

### front() & back()
The front() and back() functions, respectively, return the first and last Nodes of a given List object. Using front()->data or back()->data allows direct access to metadata at the first and last Nodes, respectively.

### at()
The at() function returns the metadata of a particular Node. 

### assign()
The assign() function assigns the metadata of a particular Node to a piece of user-inputted data. If the Node in question already has metadata, it is overwritten.

### size()
The size() function returns, as an unsigned integer, the number of Nodes in a user-defined List object.

## Mutator Functionalities
The following functions are used to edit the Nodes within a List.

### addNode()
Each time the addNode() function is called, it creates a temporary pointer to a new Node. If no nodes exist, the List object's head and tail pointers are both set to the new Node pointer. Otherwise, the last Node in the linked list is updated to point to the newly created Node. This is a default action of sorts, and always adds a Node to the end.

### remove()
The remove() function can take a single unsigned int as an argument. When presented with one unsigned int, the Node at that index is removed from the List.

The function can also take two unsigned ints as arguments, a starting and ending index. The function will remove all Nodes in that range. (Given start = 3 and end = 6, Nodes at indicies 3, 4, 5, and 6 are removed.)

### insert()
The insert function has two possible implementations. The first implementation takes an unsigned int "index" and an arbitrarily typed piece of data "data" as arguments. The function will insert a single, new Node into that index, and assign that Node's data member.

The second implementation allows for the insertion of one List into another. It takes two arguments, an unsigned int "index" and an arbitrarily typed List "other". It will assign the Node at the given index to point to the first Node in the List, then assign the last Node in the inserted List's pointer to the Node at index + 1 of the original List.

### push_back()
This function takes an arbitrary piece of data as an argument. It then adds a new node using the addNode() function, then assigns the data member of the new Node with the data given.
