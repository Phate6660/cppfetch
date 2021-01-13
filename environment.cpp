#include <iostream>

std::string env_var(std::string const & var) {
    char * val;
    val = std::getenv(var.c_str());
    std::string retval = "";                                                           
    if (val != NULL) {                                                                 
        retval = val;  
    }                                                                                  
    return retval;
}

std::string editor() {
    std::string editor{ env_var("EDITOR") };
    return editor;
}

std::string shell() {
    std::string shell{ env_var("SHELL") };
    return shell;
}

std::string user() {
    std::string user{ env_var("USER") };
    return user;
}
