//
// Created by Oleksii Budzinskyi on 25/11/2023.
//

#ifndef CRANEPROJECT_TRUCK_H
#define CRANEPROJECT_TRUCK_H

#include "LoadableAbstract.h"

const unsigned int TRUCK_CAPACITY = 2;

class Truck: public LoadableAbstract {
public:
    Truck();
    virtual ~Truck();

    unsigned int getCapacity() const override;
    unsigned int getSize() const override;
    Container at(int index) const override;
    void give(Container& container) override;
    void take() override;

private:
    Container trailer[TRUCK_CAPACITY];
};



#endif //CRANEPROJECT_TRUCK_H
