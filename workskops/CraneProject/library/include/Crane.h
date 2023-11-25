//
// Created by Oleksii Budzinskyi on 22/11/2023.
//

#ifndef CRANEPROJECT_CRANE_H
#define CRANEPROJECT_CRANE_H

#include "ContainerStack.h"
#include "Container.h"
#include "MovableAbstract.h"
#include "ContainerHandlerAbstract.h"

const int MAX_STACKS = 5;
const int TRUCK_CAPACITY = 2; // number of containers that can be loaded on truck, it also defines backwardLimit as -3
const int PARKED_POSITION = -1;

class Crane: public MovableAbstract, public ContainerHandlerAbstract {

public:
    Crane(); // default constructor
    ~Crane() override; // destructor

    // UNIQUE methods especially for Crane
    bool isParked() const;
    void park();
    void toTrailer();

    // methods from ContainerHandlerAbstract
    bool isLoaded() override;
    bool isUnloaded() override;
    bool isWaitingEmpty() override;
    bool isWaitingFull() override;
    void load(Container& container) override;
    Container unload() override;
    void pickUp() override;
    void putDown() override;
    ContainerStack& stackAt(int position) override;
    bool canPutDown() override;
};


#endif //CRANEPROJECT_CRANE_H
