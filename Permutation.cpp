//...........
//  Permutation.cpp
//  Permutations
//
//  Created by Javi Gomez on 3/16/17.
//  Copyright © 2017 Javi Gomez. All rights reserved.
//

#include "Permutation.hpp"

/*
    prints information about the string used in the permutation class.
 */

void Permute:: print(){
    cout << word << endl << "The length is : " << length << endl;
    cout << "Total Permutations is: " << totalPerm << endl;
}
void Permute::parseWord(){
    // counts chracters in word
    for (auto iter = word.begin(); iter != word.end(); iter ++){
        length ++;
    }
    // calculates the number of permutations
     totalPerm = calculatePerm(length);
    
    }


/* recursively counts the number of permutations available for given word. 
        P(4,4) = 4!/(4-4)! = 4!
 */

int Permute::calculatePerm(int p){
    if (p > 0)
    return totalPerm = p * calculatePerm(-- p );
    return 1;
}

int Permute::getLength(){
    return this -> length;
}

void Permute::printPermutations(){
    recursivePrint(1, word);

}
/*
    recursivley calls function to print out all permutations for a given sequence of characters.
        The idea behind it is that .......... you have a word (B I R D) going through the method calls. 
        Starting at the right and ending at the left hand side, the function starts swapping starting at current index and only swaping wiht elements to its right.
        The permutation gets printed out at the very end of the calls and letters are swapped starting from the right hand side. (B I D R) being the first sequence after first swap.
 
        Any time there are swaps the method recursively calls itself. When reaching the limit of calls (stirngs length) a permutation gets printed. Moving from the ending of the word to the begginging there should be more and more swaps as more letters become reachable.
        For example, in the word B I R D the last letter is swapped 0 times but with a total of 1 ways of arranging it { D } and at this point depth should be equal to length so it gets printed out.
        Before that (since recursion works on a stack) the third letter (R) is swapped with the last letter (D) (1 swap, 2 possiblitties { (RD), (DR) } ).
        The second letter (I) gets swapped with the letter R and the letter D (2 swaps, 6 possiblities { (IRD), (IDR), (RID), (RDI), (DRI), (DIR) } ).
        The first letter (B) gets swapped with the letters I, R and D (3 swaps, x possiblities)
 */
void Permute::recursivePrint(int depth, string temp){
    if (depth != length){
        string w;
        w = temp;
        
        char current;
        auto next = w.begin();
        auto iter = w.begin();
        
        for (unsigned i = 0; i < depth; i ++){
            next ++;
        }
        for (unsigned i = 0; i < depth - 1; i ++){
            iter ++ ;
        }
        
        for (unsigned j = 0; j < length - depth + 1  ; j++){
            recursivePrint(depth + 1, w);
            
            w = temp;
            current = * iter;
            *iter = *next;
            *next= current;
            next ++;
        }
        
        return;
        
    }
    else if(depth == length){
        cout << temp << endl;
        return;
    }
     
        
        return;
    
    
}
