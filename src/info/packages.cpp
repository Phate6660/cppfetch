#include <fstream>
#include <iostream>
#include "packages.hpp"

/// Run the command and count the lines of output, 
/// optionally subtract from the count to account for extra lines,
/// then assemble and return the message as a string.
static std::string count(std::string cmd, std::string manager, int remove = 0) {
    const std::string& command = cmd + "| wc -l";
    std::system((command + " > temp.txt").c_str());
 
    std::ifstream ifs("temp.txt");
    std::string ret{ std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() };
    ifs.close(); // must close the inout stream so the file can be cleaned up
    if (std::remove("temp.txt") != 0) {
        perror("Error deleting temporary file");
    }
    int amount = std::stoi(ret);
    amount = amount - remove;
    std::string message = ret + " (" + manager + ")";
    message.erase(std::remove(message.begin(), message.end(), '\n'), message.end());
    return message;
}

static PackageManager findPackageManager() {
    if (std::system("which apk > /dev/null 2>&1") == 0) {
        return APK;
    } else if (std::system("which dnf > /dev/null 2>&1") == 0) {
        return DNF;
    } else if (std::system("which dpkg-query > /dev/null 2>&1") == 0) {
        return DPKG;
    } else if (std::system("which eopkg > /dev/null 2>&1") == 0) {
        return EOPKG;
    } else if (std::system("which pacman > /dev/null 2>&1") == 0) {
        return PACMAN;
    } else if (std::system("which pkg > /dev/null 2>&1") == 0) {
        return PKG;
    } else if (std::system("which qlist > /dev/null 2>&1") == 0) {
        return QLIST;
    } else if (std::system("which rpm > /dev/null 2>&1") == 0) {
        return RPM;
    } else if (std::system("which xbps-query > /dev/null 2>&1") == 0) {
        return XBPS;
    } else {
        return UNKNOWN;
    }
}

// Return package counts.
std::string packages() {
    switch (findPackageManager()) {
        case APK:
            return count("apk info", "apk");
        case DNF:
            return count("dnf list installed", "dnf");
        case DPKG:
            return count("dpkg-query -f '${binary:Package}\n' -W", "dpkg");
        case EOPKG:
            return count("eopkg list-installed", "eopkg");
        case PACMAN:
            return count("pacman -Qq", "pacman");
        case PKG:
            return count("pkg -l", "Portage");
        case QLIST:
            return count("qlist -I", "Portage");
        case RPM:
            return count("rpm -qa", "rpm");
        case XBPS:
            return count("xbps-query -l", "xbps");
        default: return "N/A (no supported pacakge managers found)";
    }
}

