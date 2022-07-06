#include <lib/lib.hpp>
#include <spdlog/spdlog.h>

namespace dkpp
{
lib::lib() noexcept
{
    spdlog::warn("THIS IS A WARNING!");
}

lib::~lib() noexcept
{
}

void lib::print(std::string_view msg) const
{
    spdlog::info(msg);
}

}
