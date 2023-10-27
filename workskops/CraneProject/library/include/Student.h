/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Student.h
 * Author: Marcin Kwapisz
 *
 * Created on September 26 2016, 20:15
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    Student(std::string firstName, std::string lastName);
    Student(const Student& orig);
    virtual ~Student();
    
    std::string getFirstName();
    std::string getLastName();
private:
    
    std::string firstName;
    std::string lastName;

};

#endif /* STUDENT_H */

