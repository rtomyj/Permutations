//
//  Permutation.hpp
//  Permutations
//
//  Created by Javi Gomez on 3/16/17.
//  Copyright © 2017 Javi Gomez. All rights reserved.
//
/*
 Class to count permutations and print them out to standard out.
 Uses recursion to calculate permutations (factorials) and to determine them
 */

#ifndef Permutation_hpp
#define Permutation_hpp

#include <stdio.h>
#include<iostream>
#include<list>

using namespace std;

class Permute{
private:
    string word;
    int length;
    int totalPerm;
    void parseWord();
    int calculatePerm(int);
    void recursivePrint(int, string);
    
public:
    Permute(string w = "", int l = 0, int p = 1):word(w), length(l), totalPerm(p) { this ->parseWord(); } ; // sets defualt values on variables(word, length, and totalPerm. Defualt constructor takes a string as an argument and sets word var to it. Calls calculate method.
    ~Permute(){}
    int getLength();
    void printPermutations();
    void print();
    
};

#endif /* Permutation_hpp */
