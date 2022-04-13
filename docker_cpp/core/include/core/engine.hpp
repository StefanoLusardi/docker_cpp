#pragma once

#include "api.hpp"
#include <string_view>

namespace dkpp::core
{
// class API_LIB lib
class engine
{
public:
    explicit engine() noexcept;
    ~engine() noexcept;
    
    int run();
};

}
