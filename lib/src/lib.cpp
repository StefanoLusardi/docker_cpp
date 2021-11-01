#include <lib/lib.hpp>
#include <iostream>
#include "spdlog/spdlog.h"

namespace dkpp
{
lib::lib() noexcept
{
}

lib::~lib() noexcept
{
}

void lib::print() const
{
    spdlog::info("Hello docker_cpp!");
    // std::cout << "Hello docker_cpp!" << std::endl;
}

}
