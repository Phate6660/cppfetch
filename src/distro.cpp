#include <algorithm>
#include "functions.hpp"

// Parse `/etc/os-release` for the PRETTY_NAME string
// and extract the value of the variable.
// Returns the name of the distro.
// Example: Gentoo/Linux.
std::string distro() {
    std::string distro;
    std::string line_pre_array = parse("PRETTY_NAME", "/etc/os-release");
    std::vector<std::string> result = explode(line_pre_array, '=');
    distro = result[1]; // Second element.
    // Trim `"` from the string.
    distro.erase(std::remove(distro.begin(), distro.end(), '\"'), distro.end());
    return distro;
}
