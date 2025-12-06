#include <iostream>

#include "Time.h"

int main() {
    Time t1;
    Time t2;
    Time t3;
    Time t4;
    t1 = Time(); //def
    t2 = Time(16, 30, 30); //paramentri
    t3 = Time(t1); //copia di t1
    t4 = Time(15, 30, 30);
    std::cout << t2.show(false);
    std::cout << "\n" << (t2 + 300).show(true);
}
