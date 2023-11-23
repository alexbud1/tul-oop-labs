//
// Created by Oleksii Budzinskyi on 22/11/2023.
//

#ifndef CRANEPROJECT_CRANE_H
#define CRANEPROJECT_CRANE_H

#include "ContainerStack.h"
#include "Container.h"

const int MAX_STACKS = 5;

class Crane {
private:
    ContainerStack storage[MAX_STACKS];
    int position;
    Container container;
public:
    Crane(); // empty constructor
    Crane(int position, ContainerStack storage[MAX_STACKS], Container container); // constructor with position
    Crane(const Crane& orig); // copy constructor
    virtual ~Crane(); // destructor


    bool isParked() const;
    bool isLoaded() const;
    bool isUnloaded() const;
    bool isWaitingEmpty() const;
    bool isWaitingFull() const;
    void park();
    void toTrailer();
    void load(Container& container);
    Container unload();
    void forward(int numSteps);
    void backward(int numSteps);
    void pickUp();
    void putDown();
    int getPosition() const;
    Container& getContainer();
    ContainerStack& stackAt(int position);
    bool canPutDown();
};


#endif //CRANEPROJECT_CRANE_H
