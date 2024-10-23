#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Student.h"
#include "Node.h"
#include <iostream>
/**
 * Name: Abdikarim Jimale
 * Project02 = Knapsack problem. 
 * 
 */


class PriorityQueue {
public:
     PriorityQueue() : head(nullptr), itemCount(0) {}
     
     void enqueue(Student element, int priority) {
          // enqueue implementation
     }
     
     // Other methods to be implemented
     
private:
     Node* head;
     int itemCount;
};

#endif