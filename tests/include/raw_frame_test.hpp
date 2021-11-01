#pragma once 

#include <gtest/gtest.h>

namespace vc { class raw_frame; }

namespace vc::test
{

class raw_frame_test : public ::testing::Test
{
protected:
    explicit raw_frame_test() { }
    virtual ~raw_frame_test() { }
    virtual void SetUp() override { }
    virtual void TearDown() override { }

    std::unique_ptr<vc::raw_frame> raw_frame;

private:
    template<typename... Args>
    void log(Args&&... args) const
    {
        ((std::cout << std::forward<Args>(args) << ' ') , ...) << std::endl;
    }
};

}