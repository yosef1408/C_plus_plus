//
// Created by user on 4/26/2025.
//

#ifndef ROAD_H
#define ROAD_H
#include <list>

using namespace std;

class Road {

    //Given..

public:
    virtual double length() = 0;
    virtual int speed() = 0;
};

class Car {

public:
    virtual  double operator[](int index) = 0;
    virtual ~Car() {};
};


double getPetrol(list<Road*> roadsList,  Car& car) {

    double cost = 0;

    for(auto const& road : roadsList) {

        cost += road->length() * car[road->speed()];
    }
    return cost;

}

class Tarante : public Car {

private:
    int maxSpeed;

public:

    class TooFast : public exception {
        const char* what() {
            return "too Fast";
        }
    };

    explicit Tarante(int limit):maxSpeed(limit){};

    double operator[](int index) override {
        //implementation;
        return 5;
    }



private:


};

class SpeedyBus {




};
#endif //ROAD_H
