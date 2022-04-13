#include <core/engine.hpp>
#include <memory>

int main(int argc, char** argv)
{
    const auto engine { std::make_unique<dkpp::core::engine>() };
    return engine->run();
}