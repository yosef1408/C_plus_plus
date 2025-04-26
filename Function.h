//
// Created by user on 4/25/2025.
//

#ifndef FUNCTION_H
#define FUNCTION_H

#include <ostream>
using namespace std;


class Function {

public:
    virtual double value (double x) = 0;
    virtual ~Function();
    virtual Function* clone() = 0;

    friend ostream& operator<< (ostream& os, const Function& fun) = 0;

};

class Monomial : public Function {

public:

    //Constructor and Destructor and C'tor
    Monomial (int coefficient , int exp ): cof(coefficient),exp(exp) {

        // throw Exception;... if the exp is negative;
    }
    Monomial(const Monomial& mn);
    ~Monomial();


    //Operatos;

    Monomial operator=(const Monomial& monimal) {

        //return value;
    };

    Monomial& operator*=(const Monomial& mon) {
        //Implementation;
    }

    friend Monomial operator*(const Monomial& m1, const Monomial& m2) {
        //return;
    }



    //Pure Virtual Functions;
    double value (double x) override {
        //implementation...;
        return 2.0;
    }

    Monomial* clone() override {
        //return new Monomial(*this);
    }
    friend ostream&  operator<<(ostream& os, const Monomial& mn);

private:
    int exp;
    int cof;
};


#endif //FUNCTION_H
