#ifndef TEMPFORMAT_H
#define TEMPFORMAT_H

#include <iostream>
#include <stdexcept>

using namespace std;

class Format {
    const char* str;
    ostream& os;

public:
    Format(const char* str, ostream& os) : str(str), os(os) {}

    template<class T>
    Format& operator<<(const T& t) {
        while (*str != '%' && *str != '\0') {
            os << *str;
            ++str;
        }

        if (*str != '%')
            throw runtime_error("Not enough placeholders (%) in format string");

        ++str;  // Move past the '%'
        os << t;
        return *this;
    }

    ~Format() {
        while (*str) {
            os << *str;
            ++str;
        }
    }
};

class TempFormat {
    const char* str;
public:
    TempFormat(const char* str) : str(str) {}

    friend Format operator<<(ostream& os, TempFormat& f) {
        return Format(f.str, os);  // Return by value, not reference!
    }
};

// Correct version of the helper function:
inline TempFormat format(const char* str) {
    return TempFormat(str);
}

#endif // TEMPFORMAT_H
