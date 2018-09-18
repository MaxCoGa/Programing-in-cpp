#include <iostream>

void affiche(int lower, int upper) {
    // print values from lower up to and //but not including upper
    int newline_ctr = 0;
    for (int val = lower; val != upper; ++val) {
        std::cout << val << " ";
        ++newline_ctr; // increment
        //counter to indicate another
        //value printed
        if (newline_ctr == 10) { // if
            //we’ve already printed 10 values
            std::cout << std::endl;
            //print this line
            newline_ctr = 0; // and reset
            //the counter to 0
        }
    }
    std::cout << std::endl;
}
