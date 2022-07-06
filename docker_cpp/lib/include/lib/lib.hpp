#pragma once

#include "api.hpp"
#include <string_view>

namespace dkpp
{
// class API_LIB lib
class lib
{
public:
    explicit lib() noexcept;
    ~lib() noexcept;   
    void print(std::string_view msg) const;
};

}
