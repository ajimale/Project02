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

private:
     Node* head;
     int itemCount;

public:
     PriorityQueue() : head(nullptr), itemCount(0) {}
     
     void enqueue(Student element, int priority) {
          // enqueue implementation

          Node* newNode = new Node(element, priority); //Create a new node 

          //Insert at the front if the queue empty or has high priority
          if (!head || priority < head->getPriority()){
               newNode-> setNext(head); 
               head = newNode;
          }
          else{ 
               Node* current = head;

               //search for the correct position
               for(; current->getNext() && current-> 
                    getNext()-> getPriority() <= priority; current = current-> getNext()); 
               
               newNode-> setNext(current-> getNext());
               current-> setNext(newNode);
          }
          ++itemCount;
     }  
     // Other methods to be implemented
     
     Student front() const {
          if (isEmpty()) {
               std::cerr << "Queue is empty. \n";
               return Student();
          }
          return head-> getStudent();
     }

     // Removes the student at the front of the queue
     void dequeue() {
          if (isEmpty()) {
               std::cerr << "Can't dequeue from an empty queue. \n";
               return;
          }

          Node* temp = head; 
          head = head-> getNext();
          delete temp;   //Free memory for the old head
          --itemCount;
     }

     //Removes all student from the queue
     void clear() { 
          for (Node* temp = head; head != nullptr; temp = head) {
               head = head->getNext();
               delete temp;
          }
          itemCount = 0;
     }

     //Remove and returns the student at the front of the queue
     Student topandpop(){
          if (isEmpty()){ 
               std::cerr << "Queue is empty! Returning default Student. \n"; 
               return Student();
          }

          Student topStudent = head-> getStudent(); 
          dequeue(); 
          return topStudent; 
     } 

     bool isEmpty() const{ 
          return head == nullptr; 
     }

     // Returns the number of students in the queue
     int size() const{ 
          return itemCount;
     }

     // Prints all students in the queue
     void printQueue() const{ 
          if (isEmpty()) { 
               std::cout << "The queue is empty. \n";
               return;
          }

          for (Node* current = head; current != nullptr; current = current-> getNext()) {
               Student s = current->getStudent();
               std::cout << "ID: " << s.getID()
                         << ", Name: " << s.getName()
                         << ", GPA: " << s.getGPA() << '\n';
          }
     }
};

#endif