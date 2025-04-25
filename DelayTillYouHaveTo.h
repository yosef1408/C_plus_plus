//
// Created by user on 4/24/2025.
//

#ifndef DELAYTILLYOUHAVETO_H
#define DELAYTILLYOUHAVETO_H
#include <ostream>
#include <queue>
#include <string>
using namespace std;


class LazyStream {
    ostream& os;
    queue<string> buffer;

    void flush() {
        while (buffer.size() != 0) {
            this->os << buffer.front();
            buffer.pop();
        }
    }

public:
    LazyStream(ostream& output) : output(output) { }
    ~LazyStream() { flush(); }

    LazyStream& operator++() {

        if(buffer.size() != 0) {
            auto str = buffer.front();
            cout << str;
        }
        return *this;

    }

};



#endif //DELAYTILLYOUHAVETO_H
