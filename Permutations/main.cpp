/*
 V 1.0
 Class Function : basic usablilty of Permutation class. Should be used as a reference to how the class works
 
 */

#include <iostream>
#include"Permutation.hpp"
using namespace std;
// creates two string instances with bird and cat as their value. Then creates two permutaion instances passing the two strings, 1 to each permute
//instance
int main(int argc, const char * argv[]) {
    string word1, word2 ;
    word1.append("CAT");
    word2.append("CAT");
    permutation permutation1(word1), permutation2(word2) ;
    permutation1.print();
    permutation1.printPermutations();
    return 0;
}

