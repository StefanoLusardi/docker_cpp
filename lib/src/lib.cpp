#include <lib/lib.hpp>
#include <spdlog/spdlog.h>

namespace dkpp
{
lib::lib() noexcept
{
}

lib::~lib() noexcept
{
}

void lib::print(const std::string_view msg) const
{
    spdlog::info(msg);
}

}
