#include <fstream>
#include <iostream>

std::string packages() {
    // pkg -- emerge frontend written in Rust.
    if (std::system("which pkg > /dev/null 2>&1")) {
        // qlist -- list package info for Portage.
        if (std::system("which qlist > /dev/null 2>&1")) {
            // Nothing found.
            return "N/A (no support package managers found)";
        } else {
            const std::string& command = "qlist -I | wc -l";
            std::system((command + " > temp.txt").c_str());
 
            std::ifstream ifs("temp.txt");
            std::string ret{ std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() };
            ifs.close(); // must close the inout stream so the file can be cleaned up
            if (std::remove("temp.txt") != 0) {
                perror("Error deleting temporary file");
            }
            std::string message = ret + " (Portage)";
            message.erase(std::remove(message.begin(), message.end(), '\n'), message.end());
            return message;
        }
    } else {
        const std::string& command = "pkg -l | wc -l";
        std::system((command + " > temp.txt").c_str());
 
        std::ifstream ifs("temp.txt");
        std::string ret{ std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() };
        ifs.close(); // must close the inout stream so the file can be cleaned up
        if (std::remove("temp.txt") != 0) {
            perror("Error deleting temporary file");
        }
        std::string message = ret + " (Portage)";
        message.erase(std::remove(message.begin(), message.end(), '\n'), message.end());
        return message;
    }
}
