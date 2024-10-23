#include <iostream>
#include "PriorityQueue.h"

/**
 * Name: Abdikarim Jimale
 * Project02 = Knapsack problem. 
 * 
 */


int main() {
    PriorityQueue s;

    std::cout << "Test 1: Empty queue\n";
    s.printQueue();  // Should print: No elements in the queue

    std::cout << "\nTest 2: Enqueue and print\n";
    Student one(1, 3.4, "Lindsay");
    Student two(2, 4.5, "Alan");
    Student three(3, 3.3, "Simon");
    Student four(4, 1.5, "Casey");
    Student five(5, 3.3, "Sandy");
    Student six(6, 3.4, "That other dude");
    s.enqueue(one, 1);
    s.enqueue(two, 5);
    s.enqueue(three, 2);
    s.enqueue(four, 2);
    s.enqueue(five, 3);
    s.enqueue(six, 1);
    s.printQueue();
    std::cout << "Size: " << s.size() << std::endl;  // Should print: 6

    std::cout << "\nTest 3: Front and dequeue\n";
    std::cout << "Front: " << s.front().getName() << std::endl;  // Should print: Lindsay
    s.dequeue();
    std::cout << "After dequeue, front: " << s.topandpop().getName() << std::endl;  // Should print: That other dude
    s.printQueue();
    std::cout << "Size: " << s.size() << std::endl;  // Should print: 4

    std::cout << "\nTest 4: Front of remaining queue\n";
    std::cout << "Front ID: " << s.front().getID() << std::endl;  // Should print: 3

    std::cout << "\nTest 5: Clear and check empty\n";
    s.clear();
    std::cout << "Size after clear: " << s.size() << std::endl;  // Should print: 0
    if (s.isEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
    }

    std::cout << "\nTest 6: Dequeue empty queue\n";
    s.dequeue();  // Should print: Cannot dequeue from an empty queue.

    std::cout << "\nTest 7: Enqueue after clear\n";
    Student seven(7, 3.2, "Seven");
    s.enqueue(seven, 6);
    s.printQueue();

    std::cout << "\nTest 8: Check not empty\n";
    if (!s.isEmpty()) {
        std::cout << "Queue is not empty!" << std::endl;
    }

    return 0;
}