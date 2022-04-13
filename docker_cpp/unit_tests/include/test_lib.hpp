#pragma once 

#include <gtest/gtest.h>
#include <lib/lib.hpp>

namespace dkpp::test
{

class test_lib : public ::testing::Test
{
protected:
    explicit test_lib() : _lib{ std::make_unique<dkpp::lib>()} { }
    virtual ~test_lib() { }
    virtual void SetUp() override { }
    virtual void TearDown() override { }

    std::unique_ptr<dkpp::lib> _lib;

private:
    template<typename... Args>
    void log(Args&&... args) const
    {
        ((std::cout << std::forward<Args>(args) << ' ') , ...) << std::endl;
    }
};

}