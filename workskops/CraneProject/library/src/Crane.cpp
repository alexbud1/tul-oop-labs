//
// Created by Oleksii Budzinskyi on 22/11/2023.
//
#include "ContainerStack.h"
#include <stdexcept>
#include "Crane.h"
#include "MovableAbstract.h"
#include "ContainerHandlerAbstract.h"

using namespace std;

// default constructor
Crane::Crane()
        : MovableAbstract(::MAX_STACKS, TRUCK_CAPACITY),
        ContainerHandlerAbstract(::MAX_STACKS) {
}

// destructor
Crane::~Crane()= default;







//******* definition of methods UNIQUE for Crane *******//

bool Crane::isParked() const{
    return getPosition() == PARKED_POSITION;
}


void Crane::park(){
    if (isParked()){
        throw runtime_error("Crane is already parked");
    }
    if (isLoaded() || isWaitingFull()){
        throw runtime_error("Crane is loaded");
    }
    setPosition(PARKED_POSITION);
}

void Crane::toTrailer(){
    if (getPosition() == -TRUCK_CAPACITY){
        throw runtime_error("Crane is already near the trailer");
    }
    setPosition(-TRUCK_CAPACITY);
}

//******* *******//





//******* definition of methods from ContainerHandlerAbstract *******//
bool Crane::isLoaded(){
    return getContainer().getNumber() != 0 && getPosition() == -TRUCK_CAPACITY;
}

bool Crane::isUnloaded(){
    return getContainer().getNumber() == 0 && getPosition() == -TRUCK_CAPACITY;
}

bool Crane::isWaitingEmpty(){
    return getContainer().getNumber() == 0 && getPosition() >= 0;
}

bool Crane::isWaitingFull(){
    return getContainer().getNumber() != 0 && getPosition() >= 0;
}

void Crane::load(Container& container){
    if (isLoaded()){
        throw runtime_error("Crane is already loaded");
    }
    if (getPosition() != -TRUCK_CAPACITY){
        throw runtime_error("Crane is not over the trailer");
    }
    setContainer(container);
}

Container Crane::unload(){
    if (isUnloaded()){
        throw runtime_error("Crane is already unloaded");
    }
    if (getPosition() != -TRUCK_CAPACITY){
        throw runtime_error("Crane is not over the trailer");
    }
    Container temp = getContainer();
    setContainer();
    return temp;
}

void Crane::pickUp(){
    if (isWaitingFull()){
        throw runtime_error("Crane is already loaded");
    }
    if (getPosition() < 0){
        throw runtime_error("Crane is not over the stack");
    }
    ContainerStack* storage = getStorage();
    int position = getPosition();
    Container container = storage[position].at(storage[position].getSize() - 1);
    setContainer(container);
    storage[position].take();
}

void Crane::putDown(){
    if (isWaitingEmpty()){
        throw runtime_error("Crane is already unloaded");
    }
    if (getPosition() < 0){
        throw runtime_error("Crane is not over the stack");
    }
    ContainerStack* storage = getStorage();
    int position = getPosition();
    storage[position].give(getContainer());
    setContainer();
}


ContainerStack& Crane::stackAt(int position){
    if (position < 0 || position >= ::MAX_STACKS){
        throw runtime_error("Position is out of range");
    }
    ContainerStack* storage = getStorage();
    return storage[position];
}

bool Crane::canPutDown() {
    if (isWaitingEmpty()){
        return false;
    }
    if (getPosition() < 0){
        return false;
    }
    ContainerStack* storage = getStorage();
    int position = getPosition();
    return storage[position].getSize() < stackAt(position).getCapacity();
}

//******* *******//