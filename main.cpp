#include <iostream>
#include "bits.h"


int main() {
    // std::cout << "Hello World!\n";
    // Bits test1 = Bits();
    // std::cout << test1 << std::endl;
    // std::cout << test1.size() << std::endl;
    // std::cout << test1.at(0) << std::endl;

    // std::cout << " " << std::endl;

    // Bits test2 = Bits(1);
    // std::cout << test2 << std::endl;
    // std::cout << test2.size() << std::endl;
    // std::cout << test2.at(0) << std::endl;

    // Testing set(pos) method
    // std::cout << " " << std::endl;
    // Bits test3 = Bits(5);
    // std::cout << test3 << std::endl;
    // std::cout << test3.size() << std::endl;
    // std::cout << test3.at(0) << std::endl;
    // std::cout << test3.at(1) << std::endl;
    // test3.set(1);
    // std::cout << test3.at(1) << std:: endl;
    // std::cout << test3 << std::endl;

    // Testing set() method
    // std::cout << "Testing set()" << std::endl;
    // Bits test4 = Bits(5);
    // std::cout << "Before test4.set(): " << std::endl;
    // std::cout << test4 << std::endl;
    // test4.set();
    // std::cout << "After test4.set(): " << std::endl;
    // std::cout << test4 << std::endl;

    // Testing reset(pos) method
    std::cout << "Testing reset()" << std::endl;
    Bits test5 = Bits(7);
    std::cout << "Bits: " << test5 << std::endl;
    std::cout << "Bits size: " << test5.size() << std::endl;
    std::cout << "Bit at pos 1: " << test5.at(1) << std::endl;
    test5.reset(1);
    std::cout << "Bit at pos 1 after test3.reset(1): " << test5.at(1) << std:: endl;
    std::cout << "Bits: " << test5 << std::endl;
}