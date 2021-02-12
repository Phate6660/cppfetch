#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include "functions.hpp"

/* 
 * Credits to https://www.techiedelight.com/trim-string-cpp-remove-leading-trailing-spaces/
 * for WHITESPACE, ltrim, rtrim, and trim.
 */

const std::string WHITESPACE = " \n\r\t\f\v";

std::string ltrim(const std::string& s) {
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rtrim(const std::string& s) {
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
std::string trim(const std::string& s) {
    return rtrim(ltrim(s));
}

std::string name(int ppid) {
    std::string ppid_string{ std::to_string(ppid) };
    std::string path = "/proc/" + ppid_string + "/status";
    std::string line = parse("PPid", path);
    std::string pppid = trim(explode(line, ':')[1]);
    std::string new_path = "/proc/" + pppid + "/status";
    std::string new_line = parse("Name", new_path);
    return trim(explode(new_line, ':')[1]);
}

std::string terminal() {
    int ppid{ getppid() };
    return name(ppid);
}
