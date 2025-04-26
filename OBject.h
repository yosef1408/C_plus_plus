//
// Created by user on 4/26/2025.
//

#ifndef OBJECT_H
#define OBJECT_H

#include <stdexcept>
#include<string>

using namespace std;



class OBject {

    virtual string toString() = 0;
    virtual OBject* clone() = 0;
    virtual bool equal (const OBject& obj) = 0;

    virtual ~OBject();

    class NotClonable : public runtime_error{};

};



#endif //OBJECT_H
