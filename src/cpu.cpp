#include <regex>
#include "functions.hpp"

std::string cpu() {
    std::string cpu;
    std::string line_pre_array = parse("model name", "/proc/cpuinfo");
    std::vector<std::string> result = explode(line_pre_array, ':');
    cpu = result[1];
    cpu = std::regex_replace(cpu, std::regex("^ +"), "");
    return cpu;
}
