#ifndef NODE_H  
#define NODE_H  

#include "Student.h"  

/**
 * Name: Abdikarim Jimale
 * Project02 = Knapsack problem. 
 * 
 */


class Node {
private:
    Student student;  
    int priority;     
    Node* next;   

public:
    // Constructor
    Node(Student s, int p) {
        student = s; 
        priority= p;
        next = nullptr;
    }

    // Getter methods: 

    Student getStudent() { 
        return student; 
        }

    int getPriority() { 
        return priority; 
        }

    void setPriority(int p) { 
        priority = p; 
        }

    Node* getNext() { 
        return next; 
        }

    void setNext(Node* n) { 
        next = n; 
        }
};

#endif 
