#ifndef BITS_H
#define BITS_H

#include <assert.h>
#include <ostream>
#include <bitset>
#include <iostream>

class Bits {
    using IType = unsigned long long; // We only have to change the integer type here, if desired
    enum {NBITS = sizeof(IType)*8};
    IType bits = 0;
public:
    Bits() = default;
    Bits(IType n) {
        bits = n;
    }
    static int size() {
        return NBITS;
    }
    bool at(int pos) const {  // Returns (tests) the bit at bit-position pos
        assert(0 <= pos && pos < NBITS);
        return bits & (IType(1) << pos);
    }
    void set(int pos);        // Sets the bit at position pos
    void set();               // Sets all bits
    void reset(int pos);      // Resets (makes zero) the bit at position pos
    void reset();             // Resets all bits
    void assign(int pos, bool val); // Sets or resets the bit at position pos depending on val
    void assign(IType n);     // Replaces the underlying integer with n
    void toggle(int pos);     // Flips the bit at position pos
    void toggle();            // Flips all bits
    void shift(int n);        // If n > 0, shifts bits right n places; if n < 0, shifts left
    void rotate(int n);       // If n > 0, rotates right n places; if n < 0, rotates left
    int ones() const {
        int sum = 0;
        for(unsigned int i = 0; i < this->size(); ++i){
            if(this->at(i) == IType(1)){
                sum += 1;
            }
        }
        return sum;
    };         // Returns how many bits are set in the underlying integer
    int zeroes() const {      // Returns how many bits are reset in the underlying integer
        return NBITS - ones();
    }
    IType to_int() const {
        return bits;
    }
    friend bool operator==(const Bits& b1, const Bits& b2) {
        return b1.bits == b2.bits;
    }
    friend bool operator!=(const Bits& b1, const Bits& b2) {
        return b1.bits != b2.bits;
    }
    friend std::ostream& operator<<(std::ostream& os, const Bits& b) {
        return os << std::bitset<NBITS>(b.bits);    // Be sure to #include <bitset>
    }

};

void Bits::set(int pos){
    assert(0 <= pos && pos < NBITS);
    bits |= (IType(1) << pos);
}

void Bits::set(){
    for(unsigned int i = 0; i < this->size(); ++i){
        bits |= (IType(1) << i);
    }
}

void Bits::reset(int pos){
    assert(0 <= pos && pos < NBITS);
    bits &= ~(IType(1) << pos);
}

void Bits::reset(){
    for(unsigned int i = 0; i < this->size(); ++i){
        bits &= ~(IType(1) << i);
    }
}

void Bits::assign(int pos, bool val){
    if((this->at(pos) == IType(1)) && (val == false)){
        this->reset(pos);
    } else if((this->at(pos) == IType(0)) && (val == true)) {
        this->set(pos);
    }
}

void Bits::assign(IType n){
    this->bits = n;
}

void Bits::toggle(int pos){
    if(this->at(pos) == IType(1)){
        this->reset(pos);
    } else if(this->at(pos) == IType(0)) {
        this->set(pos);
    }
}

void Bits::toggle(){
    for(unsigned int i = 0; i < this->size(); ++i){
        this->toggle(i);
    }
}

void Bits::shift(int n){
    if(n > 0){
        bits = bits >> n;
    } 
    if(n < 0) {
        bits = bits << (~n + 1);
    }
}

void Bits::rotate(int n){
    Bits tempBits = Bits(this->bits);
    if(n > 0){
        n = n % tempBits.size();
        tempBits.shift(-(tempBits.size()) + n);
        this->shift(n);
        std::cout << "tempBits: " << tempBits << std::endl;
        for(int i = 0; i < this->size(); ++i){
            if((this->at(i) == IType(1)) || tempBits.at(i) == IType(1)){
                this->set(i);
            }
        }
    }
    if(n < 0){
        this->rotate(this->size() + n);
    }
}

#endif
