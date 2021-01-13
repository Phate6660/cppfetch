#include <iostream>
#include "functions.h"

int main() {
    // Print the output.
    std::cout <<
        "Distro: " << distro() << std::endl <<
        "Editor: " << editor() << std::endl <<
        "Shell:  " << shell() << std::endl <<
        "User:   " << user() << std::endl;
    return 0;
}
