#include <iostream>
#include "main.hpp"

int main(int argc, char** argv) {
    if (argc > 1) {
        std::string arg = argv[1];
        // Print help if `h` or `help` is passed.
        if (arg == "h") {
            std::cout <<
                "There is no help yet, this is a test." <<
                std::endl;
            return 0;
        } else if (arg == "help") {
            std::cout <<
                "There is no help yet, this is a test." <<
                std::endl;
            return 0;
        } else {
            std::cout <<
                "Invalid argument: only h and help are supported." <<
                std::endl;
            return 1;
        }
    } else {
        // Print the output.
        std::cout <<
            "CPU:    " << cpu() << std::endl <<
            "Distro: " << distro() << std::endl <<
            "Editor: " << editor() << std::endl <<
            "Shell:  " << shell() << std::endl <<
            "Uptime: " << uptime() << std::endl <<
            "User:   " << user() << std::endl;
        return 0;
    }
}
