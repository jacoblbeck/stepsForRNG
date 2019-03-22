//
//  rng.cpp
//  assignment6
//
//  Created by Jacob Beck on 2/28/19.
//  Copyright © 2019 Jacob Beck. All rights reserved.
//

#include "rng.hpp"


RandomNumberGenerator::RandomNumberGenerator()
{
}

RandomNumberGenerator::~RandomNumberGenerator()
{
}

void RandomNumberGenerator::seed(int s)
{
    state = s;
}

// return a random number between 0 and range-1
uint32_t RandomNumberGenerator::operator()(int range)
{
    return engine() % range;
}

uint32_t LinearCongruential::engine() {
    state = (1664525 * state + 1) % 2147483648;
    return state;
}

uint32_t MiddleSquare::engine() {
    static uint64_t x = state, w = 0;
    x *= x;
    x += (w += 0xb5ad4eceda1ce2a9);
    x = (x>>32) | (x<<32);
    return x;
}

uint32_t ParkMiller::engine() {
    state = ((uint64_t)state * 48271u) % 0x7fffffff;
    return state;
}

uint32_t XORShift32::engine() {
    uint32_t x = state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    state = x;
    return x;
}
