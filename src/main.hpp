#include <iostream>
#include "config.h"

#pragma once

std::string cpu();
std::string de_wm();
std::string distro();
std::string editor();
std::string memory();
#ifdef MUSIC
std::string music();
#endif
std::string packages();
std::string shell();
std::string uptime();
std::string user();
