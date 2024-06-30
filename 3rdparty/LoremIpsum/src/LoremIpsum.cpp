#include "../LoremIpsum/LoremIpsum.hpp"

namespace loremipsum
{

std::string Lorem::ipsum() {
    return "Lorem Ipsum Dolores.";
}

bool Lorem::ipsum_print() {
    return tw::writeln(ipsum());
}



}    
