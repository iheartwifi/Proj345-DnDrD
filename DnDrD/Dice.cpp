//
//  Dice.cpp
//  COMP 345 Assignment 1
//
//  Created by Nelson Frank on 2016-10-02.
//
/*! \brief Implementation for Dice class
 *
 */
#include "Dice.hpp"
#include <sstream>
#include <regex>
#include <random> // for mersenne twister random number generator

//computes any dice rolls
int Dice::roll(int n, int d, int z){
    
    std::random_device rd;
    std::mt19937 mersenne(rd()); // init mersenne twister with random seed
    int sum = 0;
    for(int i = 0; i < n; i++){
        
        sum += mersenne() % d + 1;
    }
    sum += z;
    
    return sum;
}

//interprets string to roll allowed dice
int Dice::roll(std::string s){
    //verify string with regex: xdy(+z)
    bool match = regex_match(s, std::regex("^\\d+d\\d+(?:\\+\\d+)?$"));
    
    if(!match){
        return -1; //return of -1 signifies incorrect input;
    }
    int x,y,z;
    
    //since we know that the input follows a strict pattern, we don't need to be careful extracting the ints;
    std::stringstream *sstream = new std::stringstream(s);
    std::string temp;
    getline(*sstream, temp, 'd');
    x = stoi(temp);
    getline(*sstream, temp, '+');
    y = stoi(temp);
    if(getline(*sstream,temp)){
        z = stoi(temp);
    }
    else{
        z = 0;
    }
    delete sstream;
    
    //allow only specific dice rolls, return -1 on not allowed die
    switch(y){
        case 4:
        case 6:
        case 8:
        case 10:
        case 12:
        case 20:
        case 100: return roll(x,y,z); break;
        default: return -1; break;
    }
}

int Dice::rollFour(){
    std::random_device rd;
    std::mt19937 mersenne(rd()); // init mersenne twister with random seed
    int temp = 9999;
    int temp2 = 0 ;
    int sum = 0;
    for(int i = 0; i < 4; i++){
        temp2 = mersenne() % 6;
        if(temp > temp2)
            temp =temp2;
        sum += temp2 + 1;
    }
    sum-=temp;
    return sum;
};
