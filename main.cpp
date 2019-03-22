#include <iostream>
#include <numeric>
#include <algorithm>
#include <stdint.h>
#include <string>

#include "rng.hpp"
 

int couponCollector(RandomNumberGenerator& rng,int n)
{
    // Draw from the random number generator until all integers between 0 and n-1 have been sampled at least once.
    // Return the number of steps until this happens
    
    // YOU FILL THIS IN
    
    // HINT: calling rng(n) draws exactly one integer from the range 0 and n-1
    int * A = new int[n-1];
    //int A[n-1];
    int steps = 0;
    bool test = false;
    int count = 0;
    
    while(test != true){
        steps++;
        int temp = rng.operator()(n);
        if(A[temp] != temp){
        A[temp] = temp;
        }
        for(int i = 0; i < n-1; i++){
            if(A[i] == i) {
                count++;
            }
        }
        if(count != n-1){
            count = 0;
        }
        else{
            test = true; 
        }
    }
    return steps;
}

double testRNG(RandomNumberGenerator& rng, int n, int ntrials)
{
    // Perform ntrials experiments of couponCollector(rng,n) and return
    // the average (arithmetic mean) steps to collect all n integers in
    // the range
    
    int avg;
    int total = 0;
    int temp = 0;
    for(int i = 0; i < ntrials; i++){
        temp = couponCollector(rng,n);
        total = temp + total;
    }
    avg = (total/ntrials);
    
    return avg;
}


// The command interface
int main()
{
    char choice ;
    std::string comment;
    bool interact = true ;
    int n, trials, seed;
    
    RandomNumberGenerator* rng = 0;
    
    if ( interact )  std::cout << "\nChoose a pseudorandom number generator: (l)inear congruential, (m)iddle-square, \n"
        << "(p)ark-miller, (x)or-shift\n" << std::endl;
    std::cin >> choice ;
    while ( !std::cin.eof() ) {
        switch ( choice ) {
            case 'l':
                rng = new LinearCongruential;
                break ;
            case 'm':
                rng = new MiddleSquare;
                break ;
            case 'p':
                rng = new ParkMiller;
                break ;
            case 'x':
                rng = new XORShift32;
                break ;
            case '#':
                std::cout << '#' ; getline(std::cin, comment) ;
                std::cout << comment << "\n\n" ;
                break ;
            default:
                std::cout << "Illegal choice: " << choice << std::endl ;
        }
        
        if (rng){
            std::cout << "Enter range:  "; std::cin >> n;
            std::cout << "Enter trials: "; std::cin >> trials;
            std::cout << "Enter random seed: "; std::cin >> seed;
            
            rng->seed(seed);
            std::cout << "Result: " << testRNG(*rng,n,trials) << std::endl;
            delete rng;
            rng = 0;
        }
        
        if ( interact )  std::cout << "\nChoose a pseudorandom number generator: (l)inear congruential, (m)iddle-square, \n"
            << "(p)ark-miller, (x)or-shift\n" << std::endl;
        std::cin >> choice ;
    }
    std::cout << std::endl ;
    return 0;
}


