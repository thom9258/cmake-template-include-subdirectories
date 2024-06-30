#include <string>
#include <TW/TermWriter.hpp>

namespace loremipsum
{

class Lorem {
public:
    Lorem() = default;
    ~Lorem() = default;

    [[nodiscard]]
    std::string ipsum();
    bool ipsum_print();
};

}    
