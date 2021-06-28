#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include "../helpers/functions.hpp"

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

std::string get_pid(std::string pid) {
    std::string path = "/proc/" + pid + "/status";
    std::string line = parse("PPid", path);
    return trim(explode(line, ':')[1]);
}

std::string get_pname(std::string pid) {
    std::string pppid = get_pid(pid);
    std::string new_path = "/proc/" + pppid + "/status";
    std::string new_line = parse("Name", new_path);
    return trim(explode(new_line, ':')[1]);
}

std::string find_terminal(std::string ppid) {
    std::string pppid = get_pid(ppid);
    std::string pppname = get_pname(ppid);
    /* If the process name is "bash", keep going to look for an actual terminal.
     * TODO: Add more exceptionms, IIRC from other fetch programs I worked on, I need
     * to add workarounds for running in scripts, tmux, and
     * I believe there was a systemd issue too. */
    if (pppname == "bash") {
        return get_pname(pppid);
    } else {
        return pppname;
    }
}

std::string terminal() {
    std::string ppid{ std::to_string(getppid()) };
    return find_terminal(ppid);
}
