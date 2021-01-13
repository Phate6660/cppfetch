#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// Thank you StackOverflow.
bool isWanted(const std::string & line) {
    return (line.find("PRETTY_NAME") != std::string::npos);
}

// The current point of this function is for testing different
// operations on open files being read.
// Currently it reads a file and extracts the line containing "PRETTY_NAME".
// TODO: Figure out how to split the line into an array or vector
// that is delimited by an "=".
std::string distro() {
    std::ifstream osrelease("/etc/os-release");
    std::string distro,line;
    while (getline(osrelease, line)) {
        if (isWanted(line))
        std::cout << line << std::endl;
    }
    osrelease.close();
    return line;
}
