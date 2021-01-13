#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Thank you StackOverflow.
bool isWanted(const std::string & line) {
    return (line.find("PRETTY_NAME") != string::npos);
}

// The current point of this function is for testing different
// operations on open files being read.
// Currently it reads a file and extracts the line containing "PRETTY_NAME".
string distro() {
    ifstream osrelease("/etc/os-release");
    string distro,line;
    while (getline(osrelease, line)) {
        if (isWanted(line))
        cout << line << endl;
    }
    osrelease.close();
    return line;
}
