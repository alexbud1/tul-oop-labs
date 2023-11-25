//
// Created by Oleksii Budzinskyi on 08/11/2023.
//

#ifndef CRANEPROJECT_CONTAINERSTACK_H
#define CRANEPROJECT_CONTAINERSTACK_H

#include "Container.h"
#include "LoadableAbstract.h"
#include <vector>

constexpr unsigned MAX_HEIGHT = 10;

class ContainerStack: public LoadableAbstract {
public:
    ContainerStack();

    ContainerStack(const ContainerStack& orig); // copy constructor
    virtual ~ContainerStack(); // destructor

    unsigned int getCapacity() const; // get capacity of stack
    unsigned int getSize() const; // get size of stack
    Container at(int height) const; // get container reference at specific height
    void give(Container& container); // put container on top of stack
    void take(); // take container from top of stack

private:
    std::vector<Container> containers;
};

#endif //CRANEPROJECT_CONTAINERSTACK_H
