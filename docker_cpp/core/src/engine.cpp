#include <core/engine.hpp>
#include <memory>
#include <libA/libA.hpp>
#include <libB/libB.hpp>

namespace dkpp::core
{
engine::engine() noexcept
{
}

engine::~engine() noexcept
{
}

int engine::run()
{
    const auto lib_a { std::make_unique<dkpp::A::libA>() };
    lib_a->print("Hello libA!");

    const auto lib_b { std::make_unique<dkpp::B::libB>() };
    lib_b->print("Hello libB!");

	return 0;
}

}
