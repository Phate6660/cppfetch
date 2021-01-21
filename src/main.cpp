#include <iostream>
#include "config.h"
#include "main.hpp"

void logo() {
    std::cout <<
            " ██████╗██████╗ ██████╗ ███████╗███████╗████████╗ ██████╗██╗  ██╗" << std::endl << 
            "██╔════╝██╔══██╗██╔══██╗██╔════╝██╔════╝╚══██╔══╝██╔════╝██║  ██║" << std::endl <<
            "██║     ██████╔╝██████╔╝█████╗  █████╗     ██║   ██║     ███████║" << std::endl <<
            "██║     ██╔═══╝ ██╔═══╝ ██╔══╝  ██╔══╝     ██║   ██║     ██╔══██║" << std::endl <<
            "╚██████╗██║     ██║     ██║     ███████╗   ██║   ╚██████╗██║  ██║" << std::endl <<
            " ╚═════╝╚═╝     ╚═╝     ╚═╝     ╚══════╝   ╚═╝    ╚═════╝╚═╝  ╚═╝" << std::endl;
}

void output() {
    std::cout <<
        "CPU:         " << cpu() << std::endl <<
        "Distro:      " << distro() << std::endl <<
        "Editor:      " << editor() << std::endl <<
        "Environment: " << de_wm() << std::endl <<
        "Memory:      " << memory() << std::endl <<
        #ifdef MUSIC
        "Music:       " << music() << std::endl <<
        #endif
        "Shell:       " << shell() << std::endl <<
        "Uptime:      " << uptime() << std::endl <<
        "User:        " << user() << std::endl;
}

int main(int argc, char** argv) {
    if (argc > 1) {
        std::string arg = argv[1];
        // Print help if `h` or `help` is passed.
        if (arg == "h" || arg == "help") {
            std::cout <<
                "`l` or `logo` -- enable logo" <<
                std::endl;
            return 0;
        }
        if (arg == "l" || arg == "logo") {
            logo();
            output();
        }
    } else {
        output();
        return 0;
    }
}
