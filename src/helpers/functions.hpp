#include <iostream>
#include <vector>
#pragma once

bool isWanted(const std::string & line, std::string field);
std::vector<std::string> explode(const std::string& str, const char& ch);
std::string parse(std::string field, std::string file);
