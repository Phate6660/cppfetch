#include <algorithm>
#include <fstream>
#include "functions.hpp"

// Thank you StackOverflow.
bool isWanted(const std::string & line) {
    return (line.find("PRETTY_NAME") != std::string::npos);
}

// Parse `/etc/os-release` for the PRETTY_NAME string
// and extract the value of the variable.
// Returns the name of the distro.
// Example: Gentoo/Linux.
std::string distro() {
    std::ifstream osrelease("/etc/os-release"); // Open the file for reading.
    std::string distro,line,line_pre_array;
    while (getline(osrelease, line)) {
        if (isWanted(line))
            line_pre_array = line;
    }
    osrelease.close(); // Close the file/
    // Create the vector from the string with the delimiter.
    std::vector<std::string> result = explode(line_pre_array, '=');
    distro = result[1]; // Second element.
    // Trim `"` from the string.
    distro.erase(std::remove(distro.begin(), distro.end(), '\"'), distro.end());
    return distro;
}
