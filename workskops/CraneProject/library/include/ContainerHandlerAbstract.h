//
// Created by Oleksii Budzinskyi on 25/11/2023.
//

#ifndef CRANEPROJECT_CONTAINERHANDLERABSTRACT_H
#define CRANEPROJECT_CONTAINERHANDLERABSTRACT_H

#include "Container.h"
#include "ContainerStack.h"

class ContainerHandlerAbstract {

private:
    Container container;
    int MAX_STACKS;
    ContainerStack* storage;

public:
    // default constructor
    ContainerHandlerAbstract(int MAX_STACKS): MAX_STACKS(MAX_STACKS){
        storage = new ContainerStack[MAX_STACKS];
        for (int i = 0; i < MAX_STACKS; ++i) {
            storage[i] = ContainerStack();
        }
    };

    // destructor
    virtual ~ContainerHandlerAbstract(){
        delete[] storage;
    }

    // pure virtual methods
    virtual bool isLoaded() = 0;
    virtual bool isUnloaded() = 0;
    virtual bool isWaitingEmpty() = 0;
    virtual bool isWaitingFull() = 0;
    virtual void load(Container& container) = 0;
    virtual Container unload() = 0;
    virtual void pickUp() = 0;
    virtual void putDown() = 0;
    virtual ContainerStack& stackAt(int position) = 0;
    virtual bool canPutDown() = 0;

    // defined method
    Container& getContainer(){
        return container;
    }
    void setContainer(Container& container_input){ // set container to specific container
        this->container = container_input;
    }


    void setContainer(){ // set container to empty
        this->container = Container();
    }

    ContainerStack* getStorage() {
        return storage;
    }

    void addStack(ContainerStack& stack) {
        if (storage->getSize() == MAX_STACKS) {
            throw std::runtime_error("Storage is full");
        }

        for (int i = 0; i < MAX_STACKS; ++i) {
            if (storage[i].getSize() == 0) {
                storage[i] = stack;
                break;
            }
        }
    }
};


#endif //CRANEPROJECT_CONTAINERHANDLERABSTRACT_H
