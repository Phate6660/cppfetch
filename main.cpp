#include <iostream>
#include "functions.h"

int main() {
    // Print the output the distro function.
    // It should be `PRETTY_NAME="$DISTRO"`.
    // Example: `PRETTY_NAME="Gentoo/Linux"`.
    std::cout << distro();
    return 0;
}
