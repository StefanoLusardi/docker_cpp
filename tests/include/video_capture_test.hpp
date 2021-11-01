#pragma once 

#include <gtest/gtest.h>
#include <video_capture/video_capture.hpp>


namespace vc::test
{

class video_capture_test : public ::testing::Test
{
protected:
    explicit video_capture_test()
    : vc{ std::make_unique<vc::video_capture>() }
    , test_data_directory{"../data/"}
    { }

    virtual ~video_capture_test() { vc->release(); }

    virtual void SetUp() override { }
    virtual void TearDown() override { }

    std::unique_ptr<vc::video_capture> vc;
    const std::string test_data_directory;

private:
    template<typename... Args>
    void log(Args&&... args) const
    {
        ((std::cout << std::forward<Args>(args) << ' ') , ...) << std::endl;
    }
};

}
