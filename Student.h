#ifndef STUDENT_H  
#define STUDENT_H  

/**
 * Name: Abdikarim Jimale
 * Project02 = Knapsack problem. 
 * 
 */

#include <string>  

class Student {
private:
    int id;          
    double gpa;       
    std::string name; 

public:
    // Constructor 
    Student(int i, double g, std::string n) {
        id = i;
        gpa = g;
        name = n;
    }

    // Getter methods: 

    int getID() { 
        return id; 
        }

    double getGPA() { 
        return gpa; 
        }

    std::string getName() { 
        return name; 
        }
};

#endif
