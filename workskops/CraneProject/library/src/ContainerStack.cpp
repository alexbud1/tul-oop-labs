//
// Created by Oleksii Budzinskyi on 08/11/2023.
//

#include "ContainerStack.h"
#include <stdexcept>

using namespace std;

// empty constructor
ContainerStack::ContainerStack()= default;

// copy constructor
ContainerStack::ContainerStack(const ContainerStack& orig){
    containers = orig.containers;
}

// destructor
ContainerStack::~ContainerStack()= default;

// get capacity of stack
int ContainerStack::getCapacity() {
    return MAX_HEIGHT;
}

// get size of stack
int ContainerStack::getSize() const{
    return containers.size();
}

// get container reference at specific height
Container ContainerStack::at(int height) const{
    if (height < 0 || height >= containers.size()){
        throw runtime_error("Height is out of range");
    }
    return containers.at(height);
}

// put container on top of stack
void ContainerStack::give(Container& container){
    if (containers.size() >= MAX_HEIGHT){
        throw runtime_error("Stack is full");
    }
    containers.push_back(container);
}

// take container from top of stack
void ContainerStack::take(){
    if (containers.empty()){
        throw runtime_error("Stack is empty");
    }
    containers.pop_back();
}