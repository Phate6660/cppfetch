#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// Thank you StackOverflow.
bool isWanted(const std::string & line) {
    return (line.find("PRETTY_NAME") != std::string::npos);
}

// Also thanks to StackOverflow, using this to split a string based on a delimiter.
std::vector<std::string> explode(const std::string& str, const char& ch) {
    std::string next;
    std::vector<std::string> result;

    // For each character in the string.
    for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
        // If we've hit the terminal character.
        if (*it == ch) {
            // If we have some characters accumulated.
            if (!next.empty()) {
                // Add them to the result vector.
                result.push_back(next);
                next.clear();
            }
        } else {
            next += *it; // Accumulate the next character into the sequence.
        }
    }
    if (!next.empty())
         result.push_back(next);
    return result;
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
