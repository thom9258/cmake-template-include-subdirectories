
// Loremipsum - the actual library we include
#include <LoremIpsum/LoremIpsum.hpp>
// TW - a dependency to loremipsum exposed as public, so we can use it aswell
#include <TW/TermWriter.hpp>

#include <iostream>

int main(/*int argc, char** argv*/) {
    std::cout << "main:" << std::endl;

    std::cout << "calling lorem ipsum lib" << std::endl;
    loremipsum::Lorem lorem;
    std::cout << lorem.ipsum() << std::endl;

    tw::writeln("I can also call the public lib of loremipsum 'tw' directly");
    return 0;
}
