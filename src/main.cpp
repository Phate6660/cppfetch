#include <filesystem>
#include <fstream>
#include <iostream>
#include "config.h"
#include "main.hpp"

void logo() {
    char * val = std::getenv("HOME");
    std::string home = val;
    std::string logo_file = home.append("/.config/cppfetch/logo");
    std::filesystem::path f{ logo_file };
    // Automatically use custom ascii art if the file exists,
    // otherwise use the default hardcoded logo.
    if (std::filesystem::exists(f)) {
        std::ifstream ifs(logo_file);
        std::string ret{ std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() };
        ifs.close(); // must close the inout stream so the file can be cleaned up
        std::cout << ret;
    } else {
        std::cout <<
            " ██████╗██████╗ ██████╗ ███████╗███████╗████████╗ ██████╗██╗  ██╗" << std::endl << 
            "██╔════╝██╔══██╗██╔══██╗██╔════╝██╔════╝╚══██╔══╝██╔════╝██║  ██║" << std::endl <<
            "██║     ██████╔╝██████╔╝█████╗  █████╗     ██║   ██║     ███████║" << std::endl <<
            "██║     ██╔═══╝ ██╔═══╝ ██╔══╝  ██╔══╝     ██║   ██║     ██╔══██║" << std::endl <<
            "╚██████╗██║     ██║     ██║     ███████╗   ██║   ╚██████╗██║  ██║" << std::endl <<
            " ╚═════╝╚═╝     ╚═╝     ╚═╝     ╚══════╝   ╚═╝    ╚═════╝╚═╝  ╚═╝" << std::endl;
    }
}

void output(int skip = 0) {
    std::cout <<
        "CPU:         " << cpu() << std::endl <<
        "Distro:      " << distro() << std::endl <<
        "Editor:      " << editor() << std::endl <<
        "Environment: " << de_wm() << std::endl <<
        "Memory:      " << memory() << std::endl <<
        #ifdef MUSIC
        "Music:       " << music() << std::endl <<
        #endif
        "Packages:    " << packages(skip) << std::endl <<
        "Shell:       " << shell() << std::endl <<
        "Uptime:      " << uptime() << std::endl <<
        "User:        " << user() << std::endl;
}

void output_main() {
    if (packages().find("*") != std::string::npos) {
        output(1);
    } else {
        output();
    }
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
            output_main();
        }
    } else {
        output_main();
        return 0;
    }
}
