/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Student.cpp
 * Author: Marcin Kwapisz
 * 
 * Created on September 26 2016, 20:15
 */

#include "Student.h"

using namespace std;

Student::Student(string firstName, string lastName) {
    this->firstName=firstName;
    this->lastName=lastName;
}

Student::Student(const Student& orig) {
}

Student::~Student() {
}

string Student::getFirstName(){
    return firstName;
}

string Student::getLastName(){
    return lastName;
}
