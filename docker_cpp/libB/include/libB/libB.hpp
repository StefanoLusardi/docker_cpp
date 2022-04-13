#pragma once

#include "api.hpp"
#include <string_view>

namespace dkpp::B
{
// class API_LIB lib
class libB
{
public:
    explicit libB() noexcept;
    ~libB() noexcept;   
    void print(const std::string_view msg) const;
};

}
