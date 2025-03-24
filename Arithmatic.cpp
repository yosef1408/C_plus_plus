#include <iostream>

using namespace std;
class precision {

private:
int val;


public:
    precision(int val):val(val){};
    friend ostream& operator << (ostream& os , const precision &p){
    os.precision(p.val);
        return os;
    }

};


int main() {
    double a = 1.2345, b = 2.0;
    cout << precision(5) << a << " " << precision(2) << b << endl;
}
