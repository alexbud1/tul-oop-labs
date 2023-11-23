//
// Created by Oleksii Budzinskyi on 22/11/2023.
//
#include "ContainerStack.h"
#include <stdexcept>
#include "Crane.h"
#include <iostream>

using namespace std;

// empty constructor
Crane::Crane()= default;

// constructor with all parameters
Crane::Crane(int position, ContainerStack storage[MAX_STACKS], Container container){
    this->position = position;
    this->container = container;
    for (int i = 0; i < MAX_STACKS; ++i) {
        this->storage[i] = storage[i];
    }
}

// copy constructor
Crane::Crane(const Crane& orig){
    position = orig.position;
    container = orig.container;
    for (int i = 0; i < MAX_STACKS; ++i) {
        storage[i] = orig.storage[i];
    }
}

// destructor
Crane::~Crane()= default;

bool Crane::isParked() const{
    return position == -1; // -1 means parked
}

bool Crane::isLoaded() const{
    return container.getNumber() != 0;
}

bool Crane::isUnloaded() const{
    return container.getNumber() == 0;
}

bool Crane::isWaitingEmpty() const{
    return isUnloaded();
}

bool Crane::isWaitingFull() const{
    return isLoaded();
}

void Crane::park(){
    if (isParked()){
        throw runtime_error("Crane is already parked");
    }
    if (isLoaded()){
        throw runtime_error("Crane is loaded");
    }
    position = -1;
}

void Crane::toTrailer(){
    if (getPosition() == -2){
        throw runtime_error("Crane is already near the trailer");
    }
    position = -2;
}

void Crane::load(Container& container){
    if (isLoaded()){
        throw runtime_error("Crane is already loaded");
    }
    if (position != -2){
        throw runtime_error("Crane is not over the trailer");
    }
    this->container = container;
}

Container Crane::unload(){
    if (isUnloaded()){
        throw runtime_error("Crane is already unloaded");
    }
    if (position != -2){
        throw runtime_error("Crane is not over the trailer");
    }
    Container temp = container;
    container = Container();
    return temp;
}

void Crane::forward(int numSteps){
    if (position + numSteps >= MAX_STACKS-1){
        throw runtime_error("Crane is out of range");
    }
    position += numSteps;
}

void Crane::backward(int numSteps){
    if (position - numSteps < -2){
        throw runtime_error("Crane is out of range");
    }
    position -= numSteps;
}

void Crane::pickUp(){
    if (isWaitingFull()){
        throw runtime_error("Crane is already loaded");
    }
    if (position < 0){
        throw runtime_error("Crane is not over the stack");
    }
    container = storage[position].at(storage[position].getSize()-1);
    storage[position].take();
}

void Crane::putDown(){
    if (isWaitingEmpty()){
        throw runtime_error("Crane is already unloaded");
    }
    if (position < 0){
        throw runtime_error("Crane is not over the stack");
    }
    storage[position].give(container);
    container = Container();
}

int Crane::getPosition() const{
    return position;
}

Container& Crane::getContainer(){
    return container;
}

ContainerStack& Crane::stackAt(int position){
    if (position < 0 || position >= MAX_STACKS){
        throw runtime_error("Position is out of range");
    }
    return storage[position];
}

bool Crane::canPutDown() {
    if (isWaitingEmpty()){
        return false;
    }
    if (position < 0){
        return false;
    }
    return storage[position].getSize() < stackAt(position).getCapacity();
}


