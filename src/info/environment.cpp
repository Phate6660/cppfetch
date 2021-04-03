#include <fstream>
#include <iostream>
#include <vector>
#include "../helpers/functions.hpp"

std::string de_wm() {
    char * val;
    
    // Desktop Environment checking.
    val = std::getenv("XDG_DESKTOP_SESSION");
    if (val != NULL) {
        std::string de = val;
        return de;
    }
    val = std::getenv("XDG_CURRENT_DESKTOP");
    if (val != NULL) {
        std::string de = val;
        return de;
    }
    val = std::getenv("DESKTOP_SESSION");
    if (val != NULL) {
        std::string de = val;
        return de;
    }

    // Window Manager checking.
    val = std::getenv("HOME");
    std::string home = val;
    std::string xinitrc{ 
        std::system("which getprop > /dev/null 2>&1") ? 
            home.append("/.xinitrc")
            : home.append("/.vnc/xstartup") };
        std::ifstream file;
    // Thank you StackOverflow for lines 34-53.
    // It reads the last line of the file by by going to one character before EOF
    // and then reading backwards until it hits a newline character.
    file.open(xinitrc.c_str(), std::fstream::in);
    if(file.is_open()) {
        // Got to the last character before EOF.
        file.seekg(-1, std::ios_base::end);
        if(file.peek() == '\n') {
            // Start searching for \n occurrences.
            file.seekg(-1, std::ios_base::cur);
            int i = file.tellg();
            for(;i > 0; i--) {
                if(file.peek() == '\n') {
                    //Found
                    file.get();
                    break;
                }
                // Move one character back.
                file.seekg(i, std::ios_base::beg);
            }
        }
        std::string lastline;
        getline(file, lastline);
        std::vector<std::string> wm_vector = explode(lastline, ' ');
        int n = wm_vector.size();
        int element{ 
            std::system("which getprop > /dev/null 2>&1")  ? 
                n - 1
                : 0 };
        std::string wm = wm_vector[element];
        return wm;
    } else {
        return "N/A (could not open " + xinitrc + ")";
    }
}

std::string editor() {
    char * val{ std::getenv("EDITOR") };
    if (val != NULL) {
        std::string editor = val;
        return editor;
    } else {
        return "N/A (could not read $EDITOR, is it set?)";
    }
}

std::string shell() {
    char * val{ std::getenv("SHELL") };
    if (val != NULL) {
        std::string shell = val;
        return shell;
    } else {
        return "N/A (could not read $SHELL)";
    }
}

std::string user() {
    char * val{ std::getenv("USER") };
    if (val != NULL) {
        std::string user = val;
        return user;
    } else {
        return "N/A (could not read $USER)";
    }
}
