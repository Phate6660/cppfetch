#include <fstream>
#include <vector>
#include "../helpers/functions.hpp"

std::string uptime() {
    std::ifstream uptime_file("/proc/uptime"); // Open the file for reading.
    std::string line,uptime_pre_calculation;
    int uptime;
    uptime_pre_calculation.assign(
                                  (std::istreambuf_iterator<char>(uptime_file)),
                                  (std::istreambuf_iterator<char>())
                                  );
    uptime_file.close(); // Close the file.
    // Create the vector from the string with the delimiter.
    std::vector<std::string> result = explode(uptime_pre_calculation, ' ');
    result = explode(result[0], '.');
    uptime = std::stoi(result[0]);
    if (uptime > 86400) {
        int days = uptime / 60 / 60 / 24;
        int hours = (uptime / 60 / 60) % 24;
        int minutes = (uptime / 60) % 60;
        std::string output = std::to_string(days) + "d "
            + std::to_string(hours) + "h "
            + std::to_string(minutes) + "m";
        return output;
    } else if (uptime > 3600) {
        int hours = (uptime / 60 / 60) % 24;
        int minutes = (uptime / 60) % 60;
        std::string output = std::to_string(hours) + "h "
            + std::to_string(minutes) + "m";
        return output;
    } else if (uptime > 60) {
        int minutes = (uptime / 60) % 60;
        return std::to_string(minutes) + "m";
    } else {
	return "<1m";
    }
}
