#include "../inc/TW/TermWriter.hpp"

#include <iostream>

namespace tw {

bool write(const char* str) {
    std::cout << str;
    return true;
}

bool write(const std::string& str) {
    return write(str.c_str());
}

bool writeln(const char* str) {
    std::cout << str << std::endl;
    return true;
}

bool writeln(const std::string& str) {
    return write(str.c_str());
}

}    
