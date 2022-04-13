#include <libB/libB.hpp>
#include <spdlog/spdlog.h>

namespace dkpp::B
{
libB::libB() noexcept
{
}

libB::~libB() noexcept
{
}

void libB::print(const std::string_view msg) const
{
    spdlog::info(msg);
}

}
