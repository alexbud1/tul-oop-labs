//
// Created by Oleksii Budzinskyi on 25/11/2023.
//

#include "Truck.h"
#include <stdexcept>

using namespace std;

// default constructor
Truck::Truck()= default;

// destructor
Truck::~Truck()= default;

// get capacity of truck
unsigned int Truck::getCapacity() const{
    return TRUCK_CAPACITY;
}

// get size of truck
unsigned int Truck::getSize() const{
    unsigned int size = 0;
    for (const Container& container: trailer){
        if (container.getNumber() != 0){
            size++;
        }
    }
    return size;
}

// get container reference at specific index
Container Truck::at(int index) const{
    if (index < 0 || index >= TRUCK_CAPACITY){
        throw runtime_error("Index is out of range");
    }
    return trailer[index];
}

// put container on top of truck
void Truck::give(Container& container){
    if (getSize() >= TRUCK_CAPACITY){
        throw runtime_error("Truck is full");
    }
    for (Container& trailerContainer: trailer){
        if (trailerContainer.getNumber() == 0){
            trailerContainer = container;
            break;
        }
    }
}

// take container from top of truck
void Truck::take(){
    if (getSize() <= 0){
        throw runtime_error("Truck is empty");
    }
    for (Container& trailerContainer: trailer){
        if (trailerContainer.getNumber() != 0){
            trailerContainer = Container();
            break;
        }
    }
}


