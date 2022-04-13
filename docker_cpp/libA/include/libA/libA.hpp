#pragma once

#include "api.hpp"
#include <string_view>

namespace dkpp::A
{
// class API_LIB lib
class libA
{
public:
    explicit libA() noexcept;
    ~libA() noexcept;   
    void print(const std::string_view msg) const;
};

}
