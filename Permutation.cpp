/*
 Class Function: saves a string reference when instantiated. After that uses the methods within the class to calculate the total number of permutations 
 the word can udergo. A permutation is a reassembly of elements where each element is different and order matters. For example; in the set
 {B, I, R, D} BIRD and BRID are different permutations. 
 Equation: permutation = n!/(k-n)!


*/
#include "Permutation.hpp"
//    prints information about the string used in the permutation class.
void permutation:: print(){
    cout << word << endl << "The length is : " << length << endl;
    cout << "Total Permutations are: " << totalPerm << endl;
}

void permutation::parseWord(){
    // counts chracters in word
    for (auto iter = word.begin(); iter != word.end(); iter ++){
        length ++;
    }
     totalPerm = calculatePerm(length);
    
    }


/* recursively counts the number of permutations available for given word. 
        P(4,4) = 4!/(4-4)! = 4!
 */

int permutation::calculatePerm(int p){
    if (p > 0)
    return totalPerm = p * calculatePerm(-- p );
    return 1;
}

int permutation::getLength(){
    return this -> length;
}

void permutation::printPermutations(){
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
void permutation::recursivePrint(int depth, string word){
    if (depth != length){
        string placeholder;
        placeholder = word;
        
        char current;
        auto nextIter = placeholder.begin();
        auto currIter = placeholder.begin();
        
        for (unsigned i = 0; i < depth; i ++){
            nextIter ++;
        }
        for (unsigned i = 0; i < depth - 1; i ++){
            currIter ++ ;
        }
        
        for (unsigned j = 0; j < length - depth + 1  ; j++){
            recursivePrint(depth + 1, placeholder);
            
            placeholder = word;
            current = * currIter;
            *currIter = *nextIter;
            *nextIter= current;
            nextIter ++;
        }
        
        return;
        
    }
    else if(depth == length){
        cout << word << endl;
        return;
    }
    
        return;
    
}
