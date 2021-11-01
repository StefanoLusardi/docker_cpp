#pragma once

#include "api.hpp"

#include <string>
#include <memory>

namespace dkpp
{
class API_LIB lib
{
public:
    explicit lib() noexcept;
    ~lib() noexcept;   
    void print() const;
};

}
