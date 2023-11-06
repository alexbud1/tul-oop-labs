//
// Created by Oleksii Budzinskyi on 27/10/2023.
//

#ifndef CRANEPROJECT_CONTAINER_H
#define CRANEPROJECT_CONTAINER_H

class Container {
public:
    Container();
    explicit Container(int number);
    Container(const Container& orig); // copy constructor
    virtual ~Container(); // destructor

    int getNumber() const;
    double getTare() const; // weight of empty container
    void setTare(double weight);
    double getMaxWeight() const; // max weight of container with a load, determined by regulations
    void setMaxWeight(double weight);
    double getStrength() const; // max sum of weights that can be placed on top of the container
    void setStrength(double strength);
    double getGrossWeight() const; // weight of the container with the load
    double getNetWeight() const; // weight of the load in the container
    double getMaxCargo() const; // max weight of the load that can be placed in the container
    void unloadCargo(double amount);
    void loadCargo(double amount); // protect from overloading

private:
    int number;
    double tareWeight;
    double maxWeight;
    double strength;
    double cargo;
};

#endif //CRANEPROJECT_CONTAINER_H