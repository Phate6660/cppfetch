#include <iostream>
#include <vector>
#include "functions.hpp"

std::string memory() {
    std::string total_line = parse("MemTotal", "/proc/meminfo");
    std::vector<std::string> total_line_vector = explode(total_line, ' ');
    int total_size = std::stoi(total_line_vector[1]);
    if (total_size > 10000) {
        int total = total_size / 10000;
        std::string message_total = std::to_string(total);
        std::string message = message_total.substr(0,2) + "GB";
        return message;
    } else if (total_size > 1000) {
        int total = total_size / 1000;
        std::string message_total = std::to_string(total);
        std::string message = message_total + "MB";
        return message;
    } else {
        std::string message_total = std::to_string(total_size);
        std::string message = message_total + "KB";
        return message;
    }
}
