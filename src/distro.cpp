#include <algorithm>
#include <fstream>
#include <regex>
#include "functions.hpp"

// Parse `/etc/os-release` for the PRETTY_NAME string
// and extract the value of the variable.
// Returns the name of the distro.
// Example: Gentoo/Linux.
std::string distro() {
    // Check if running Android.
    if (std::system("which getprop > /dev/null 2>&1")) {
        // No getprop command, resume as normal.
        std::string distro;
        std::string line_pre_array = parse("PRETTY_NAME", "/etc/os-release");
        std::vector<std::string> result = explode(line_pre_array, '=');
        distro = result[1]; // Second element.
        // Trim `"` from the string.
        distro.erase(std::remove(distro.begin(), distro.end(), '\"'), distro.end());
        return distro;
    } else {
        // getprop command found, return Android version.
        const std::string& command = "getprop ro.build.version.release";
        std::system((command + " > temp.txt").c_str());
 
        std::ifstream ifs("temp.txt");
        std::string ret{ std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() };
        ifs.close(); // must close the inout stream so the file can be cleaned up
        if (std::remove("temp.txt") != 0) {
            perror("Error deleting temporary file");
        }
        std::string message = "Android " + ret;
        message = std::regex_replace(message, std::regex("^ +"), "");
        return message;
    }
}
