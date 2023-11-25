//
// Created by Oleksii Budzinskyi on 24/11/2023.
//

#ifndef CRANEPROJECT_MOVABLEABSTRACT_H
#define CRANEPROJECT_MOVABLEABSTRACT_H

#include <stdexcept>
#include <iostream>

using namespace std;

class MovableAbstract {

private:
    int position = -1;
    int forwardLimit;
    int backwardLimit;

public:

    MovableAbstract(int MAX_STACKS, int TRUCK_CAPACITY){ // assign forward limit
        forwardLimit = MAX_STACKS - 1;
        backwardLimit = -TRUCK_CAPACITY;
    }

    virtual void forward(int numSteps){
        if (numSteps <= 0){
            throw runtime_error("Number of steps must be positive");
        }
        if (position + numSteps > forwardLimit){
            throw runtime_error("Crane is out of range");
        }
        position += numSteps;
    }

    virtual void backward(int numSteps){
        if (numSteps <= 0){
            throw runtime_error("Number of steps must be positive");
        }
        if (position - numSteps < backwardLimit){
            throw runtime_error("Crane is out of range");
        }
        position -= numSteps;
    }

    int getPosition() const{
        return position;
    }

    void setPosition(int pos){
        if (pos > forwardLimit || pos < backwardLimit){
            throw runtime_error("Crane is out of range");
        }
        this->position = pos;
    }
//    void setForwardLimit(int limit){
//        forwardLimit = limit;
//    }
//
//    void setBackwardLimit(int limit){
//        backwardLimit = limit;

//    }

    virtual ~MovableAbstract() = default;  // Virtual destructor
};

#endif //CRANEPROJECT_MOVABLEABSTRACT_H
