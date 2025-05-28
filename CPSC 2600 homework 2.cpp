//Zain-Abbas Merchant
// 4/24/2023
// CPSC 2600 homework 2.cpp 

#include <iostream>
#include "CPSC 2600 homework 2.h"

int main()
{
    //get set A
    std::cout << "Pleaser enter values for Set A: ";
    int a = 0;//start with an empty set
    while (true) {//keep accepting input until user enters number outside of set range
        int d;//variable to store user input
        std::cin >> d;
        if (d < 0 || d > 9) {//exit if user inputs value outside of set range
            break;
        }//if
        int y = 1;// most right bit position
        y = y << d;//find the bit for the digit
        // y -> the bit or digit you are moving (always represented as "1")
        // d -> number of places to move (in base 2 system so 2^d to move it d is like index starts at 0
        // 01 -> 1 in binary (d = 0) 2^0 = 1 (special)
        // 10 -> 2 in binary (d = 1)
        //100 -> 4 in binary etc. (d = 2)
        //1000 -> 8 in binary (d = 3)

        //std::cout << "y: " << y;
        a = a | y; // mark belongs (mark that d belongs to set A) (preforms bitwise or) keep adding to bitstring for every
        //user input (each value user inputs is stored as bitstring and compared to previous using bitwise or)
        //std::cout << "\na: " << a;
    }//while

    //get set B
    std::cout << "Pleaser enter values for Set B: ";
    int b = 0;
    while (true) {
        int d;
        std::cin >> d;
        if (d < 0 || d > 9) {
            break;
        }//if
        int y = 1;
        y = y << d;//find the bit for the digit
        b = b | y; // mark belongs (mark that d belongs to set B)
    }//while

    //implement union
    int c = a | b; // a union b
    int d = a & b; // a intersect b
    // 
    int e = a & ~b; // a - b  (a intersect b complement) ~ = bitwise not/inverst/complement (negation for each bit)
    std::cout << "a ";
    printSet(a); //printing Set A
    std::cout << "b ";
    printSet(b); // printing Set B
    //below it prints union, intersection and difference of Set A and Set B
    std::cout << "a union b ";
    printSet(c);
    std::cout << "a intersect b ";
    printSet(d);
    std::cout << "a - b ";
    printSet(e);

}//main
void printSet(int c)
{
    std::cout << "{";
    for (int d = 0; d < 10; d++) {// go through all bit positions
        int m = 1 << d;// m is the mask (bit mask)
        int x = c & m;//checking whether value exists at bit string (returns 0 if bit string c and m do not match)
        // are not both 1 at some point
        if (x == 0) {// d does not belong to c (bit strings do not match) 
            continue;//check next bit position 
        }//if
        std::cout << " " << d;
    }//for
    std::cout << " }\n";
}//print Set
//main


