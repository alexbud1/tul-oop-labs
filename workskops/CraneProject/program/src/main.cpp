#include <iostream>
#include "Container.h"
#include "ContainerStack.h"
#include "Crane.h"
#include "MovableAbstract.h"
#include "ContainerHandlerAbstract.h"


using namespace std;

void display(Container c) {
    cout << "Container Information:" << endl;
    cout << "Number: " << c.getNumber() << endl;
    cout << "Tare Weight: " << c.getTare() << " kg" << endl;
    cout << "Max Weight: " << c.getMaxWeight() << " kg" << endl;
    cout << "Strength: " << c.getStrength() << " kg" << endl;
    cout << "Net Weight: " << c.getNetWeight() << " kg" << endl;
    cout << "Gross Weight: " << c.getGrossWeight() << " kg" << endl;
    cout << "Max Cargo: " << c.getMaxCargo() << " kg" << endl;
    cout << "---------------------------------" << endl;
}

void testLocalObject(){
    Container container1(1);
    container1.setMaxWeight(1000);
    container1.setTare(100);
    container1.setStrength(1000);
    container1.loadCargo(500);
    display(container1);
}

void displayCargo(Container& c){
    cout << "Cargo: " << c.getNetWeight() << " kg" << endl;
}

void loadAndSend(Container& c, double goods){
    displayCargo(c);
    c.setTare(10.0);
    c.setMaxWeight(100.0);
    c.loadCargo(goods);
    displayCargo(c);
}

Container* prepare(int number, double goods){
    auto *container = new Container(number);
    container->setTare(10.0);
    container->setMaxWeight(100.0);
    container->loadCargo(goods);
    return container;
}

void display(Container* p){
    cout << "Container Information:" << endl;
    cout << "Number: " << p->getNumber() << endl;
    cout << "Tare Weight: " << p->getTare() << " kg" << endl;
    cout << "Max Weight: " << p->getMaxWeight() << " kg" << endl;
    cout << "Strength: " << p->getStrength() << " kg" << endl;
    cout << "Net Weight: " << p->getNetWeight() << " kg" << endl;
    cout << "Gross Weight: " << p->getGrossWeight() << " kg" << endl;
    cout << "Max Cargo: " << p->getMaxCargo() << " kg" << endl;
    cout << "---------------------------------" << endl;
    cout << p << endl;
}

void testDynamicObject(){
    auto *container1 =  prepare(2, 20);
    display(container1);
    delete container1;
}

int main() {
    return 0;
}