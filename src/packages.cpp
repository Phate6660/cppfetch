#include <fstream>
#include <iostream>

/// Run the command and count the lines of output, 
/// optionally subtract from the count to account for extra lines,
/// then assemble and return the message as a string.
std::string count(std::string cmd, std::string manager, int remove = 0) {
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

std::string packages() {
    // pkg -- emerge frontend written in Rust.
    if (std::system("which pkg > /dev/null 2>&1")) {
        // qlist -- list package info for Portage.
        if (std::system("which qlist > /dev/null 2>&1")) {
            // apk -- package manager for Alpine Linux.
            if (std::system("which apk > /dev/null 2>&1")) {
                // apt -- package manager for Debian/Ubuntu-based distros.
                if (std::system("which apt > /dev/null 2>&1")) {
                    // dnf -- package manager for Red Hat distros.
                    if (std::system("which dnf > /dev/null 2>&1")) {
                        // dpkg -- same as apt.
                        if (std::system("which dpkg-query > /dev/null 2>&1")) {
                            // eopkg -- Solus package manager.
                            if (std::system("which eopkg > /dev/null 2>&1")) {
                                // pacman -- Arch package manager.
                                if (std::system("which pacman > /dev/null 2>&1")) {
                                    // rpm -- like dnf.
                                    if (std::system("which rpm > /dev/null 2>&1")) {
                                        // xbps -- Void Linux's package manager.
                                        if (std::system("which xbps-query > /dev/null 2>&1")) {
                                            return "N/A (no support package managers found)";
                                        } else {
                                            return count("xbps-query -l", "xbps");
                                        }
                                    } else {
                                        return count("rpm -qa", "rpm");
                                    }
                                } else {
                                    return count("pacman -Qq", "pacman");
                                }
                            } else {
                                return count("eopkg list-installed", "eopkg");
                            }
                        } else {
                            return count("dpkg-query -f '${binary:Package}\n' -W", "dpkg");
                        }
                    } else {
                        return count("dnf list installed", "dnf");
                    }
                } else {
                    return count("apt list --installed", "apt", 1);
                }
            } else {
                return count("apk info", "apk");
            }
        } else {
            return count("qlist -I", "Portage");
        }
    } else {
        return count("pkg -l", "Portage");
    }
}
