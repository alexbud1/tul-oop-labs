//
// Created by Oleksii Budzinskyi on 04/11/2023.
//

#include "Container.h"
#include <stdexcept>

using namespace std;

// empty constructor with 0 number
Container::Container(){
    number = 0;
    tareWeight = 0;
    maxWeight = 0;
    strength = 0;
    cargo = 0;
}

// constructor with number (real one)
Container::Container(int number){
    this->number = number;
    tareWeight = 0;
    maxWeight = 0;
    strength = 0;
    cargo = 0;
}

// copy constructor
Container::Container(const Container& orig){
    number = orig.number;
    tareWeight = orig.tareWeight;
    maxWeight = orig.maxWeight;
    strength = orig.strength;
    cargo = orig.cargo;
}

// destructor
Container::~Container()= default;

// get number of container
int Container::getNumber() const{
    return number;
}

// get weight of empty container
double Container::getTare() const{
    return tareWeight;
}

// set weight of empty container
void Container::setTare(double weight){
    if (weight + cargo > maxWeight){
        throw runtime_error("Tare weight can't be more than max weight of container with a load");
    }
    this->tareWeight = weight;
}

// get max weight of container with a load, determined by regulations
double Container::getMaxWeight() const{
    return maxWeight;
}

// set max weight of container with a load, determined by regulations
void Container::setMaxWeight(double weight){
    if (weight < tareWeight + cargo){
        throw runtime_error("Max weight can't be less than current weight of container and cargo");
    }
    this->maxWeight = weight;
}

// get max sum of weights that can be placed on top of the container
double Container::getStrength() const{
    return strength;
}

// set max sum of weights that can be placed on top of the container
void Container::setStrength(double weight){
    this->strength = weight;
}

// get weight of the container with the load
double Container::getGrossWeight() const{
    return tareWeight + cargo;
}

// get weight of the load in the container
double Container::getNetWeight() const{
    return cargo;
}

// get max weight of the load that can be placed in the container
double Container::getMaxCargo() const{
    return maxWeight - tareWeight;
}

// load cargo to the container
void Container::loadCargo(double amount){
    if (cargo + amount > getMaxCargo()){
        throw runtime_error("Cargo weight limit exceeded");
    } else {
        cargo += amount;
    }
}

// unload cargo from the container
void Container::unloadCargo(double amount){
    if (cargo - amount < 0){
        throw runtime_error("Can't unload more than the cargo weights");
    } else {
        cargo -= amount;
    }
}