//
//  main.cpp
//  Permutations
//
//  Created by Javi Gomez on 3/16/17.
//  Copyright © 2017 Javi Gomez. All rights reserved.
//

#include <iostream>
#include"Permutation.hpp"

using namespace std;

void permute(string);
int main(int argc, const char * argv[]) {
    
    
    string x ;
    x.append("birds");
    Permute y(x) ;
   // y.print();
    y.printPermutations();
    return 0;
}

void permute(string word){
    for ( auto iter = word.begin(); iter != word.end(); iter ++){
        cout << *iter;
    }
}
