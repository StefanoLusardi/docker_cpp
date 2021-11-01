#include <iostream>
#include <lib/lib.hpp>

int main(int argc, char** argv)
{
    auto docker_cpp = std::make_unique<dkpp::lib>();
    docker_cpp->print();
	return 0;
}