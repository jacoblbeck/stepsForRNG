//
//  rng.hpp
//  assignment6
//
//  Created by Jacob Beck on 2/28/19.
//  Copyright © 2019 Jacob Beck. All rights reserved.
//

#ifndef rng_hpp
#define rng_hpp

#include <stdio.h>
#include <stdint.h>

class RandomNumberGenerator {
public:
    RandomNumberGenerator();
    ~RandomNumberGenerator();
    void seed(int s);
    uint32_t operator()(int);
protected:
    virtual uint32_t engine() = 0;
    uint32_t state;
};

class LinearCongruential : public RandomNumberGenerator
{
    uint32_t engine();
};

class MiddleSquare : public RandomNumberGenerator
{
    uint32_t engine();
};

class ParkMiller : public RandomNumberGenerator
{
    uint32_t engine();
};

class XORShift32 : public RandomNumberGenerator
{
    uint32_t engine();
};


#endif /* rng_hpp */
