#include <lib/lib.hpp>
#include <memory>

int main(int argc, char** argv)
{
    const auto docker_cpp { std::make_unique<dkpp::lib>() };
    docker_cpp->print("Hello docker_cpp!");
	return 0;
}