#include <algorithm>
#include <filesystem>
#include <fstream>
#include "../helpers/functions.hpp"

std::string extract(std::string file) {
    std::string distro;
    std::string line_pre_array = parse("PRETTY_NAME", file);
    std::vector<std::string> result = explode(line_pre_array, '=');
    distro = result[1]; // Second element.
    // Trim `"` from the string.
    distro.erase(std::remove(distro.begin(), distro.end(), '\"'), distro.end());
    return distro;
}

// Parse `/etc/os-release` for the PRETTY_NAME string
// and extract the value of the variable.
// Returns the name of the distro.
// Example: Gentoo/Linux.
std::string distro() {
    // Check if running Android.
    if (std::system("which getprop > /dev/null 2>&1")) {
        // No getprop command, resume as normal.
        std::filesystem::path bedrock_file = "/bedrock/etc/os-release";
        std::filesystem::path normal_file = "/etc/os-release";
        std::filesystem::path weird_file = "/var/lib/os-release";
        if (std::filesystem::exists(bedrock_file)) {
            return extract("/bedrock/etc/os-release");
        } else if (std::filesystem::exists(normal_file)) {
            return extract("/etc/os-release");
        } else if (std::filesystem::exists(weird_file)) {
            return extract("/var/lib/os-release");
        } else {
            return "N/A (could not read '/bedrock/etc/os-release', '/etc/os-release', nor '/var/lib/os-release')";
        }
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
        message.erase(std::remove(message.begin(), message.end(), '\n'), message.end());
        return message;
    }
}
