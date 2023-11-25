//
// Created by Oleksii Budzinskyi on 25/11/2023.
//

#ifndef CRANEPROJECT_LOADABLEABSTRACT_H
#define CRANEPROJECT_LOADABLEABSTRACT_H

#include "Container.h"

class LoadableAbstract {
    public:
    virtual unsigned int getCapacity() const = 0;
    virtual unsigned int getSize() const = 0;
    virtual Container at(int index) const = 0;
    virtual void give(Container& container) = 0;
    virtual void take() = 0;

    bool canGive() {
        return (getSize() < getCapacity());
    }

    bool canTake() {
        return (getSize() > 0);
    }
};

#endif //CRANEPROJECT_LOADABLEABSTRACT_H
