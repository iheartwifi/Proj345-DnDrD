
#ifndef Dice_hpp
#define Dice_hpp

#include <iostream>

//only one dice object is to be initialized
//if multiple dice are initialized in the same second then they get the same seed and produce identical results
class Dice{
private:
    static int roll(int n, int d, int z);
public:
    //Dice(); not used
    //! Rolls dice according to string input. Returns -1 for invalid input.
    static int roll(std::string s);
    int rollFour();
};


#endif /* Dice_hpp */
