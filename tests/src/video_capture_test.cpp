#include <video_capture_test.hpp>

namespace dkpp::test
{

TEST_F(video_capture_test, error_callback)
{ 
    // Test Error callback using a free function
    vc->set_log_callback(&error_cb, vc::log_level::error);
    const auto fc = vc->get_frame_count();
    ASSERT_EQ(error_msg, "Video path must be opened first.");
}

TEST_F(video_capture_test, info_callback)
{ 
    // Test Info callback using a lambda
    std::string info_msg = std::string();
    auto info_cb = [&](const std::string& s){ 
        info_msg = s;
    };

    vc->set_log_callback(info_cb, vc::log_level::info);
    vc->open(test_data_directory + "testsrc_10sec_4fps.mkv");
    ASSERT_EQ(info_msg, "Video Capture is initialized");
}


// T EST_F(video_capture_test, all_callback){ }
// T EST_F(video_capture_test, open_default_decode){ }
// T EST_F(video_capture_test, open_sw_decode){ }
// T EST_F(video_capture_test, open_hw_decode){ }
// T EST_F(video_capture_test, get_frame_count){ }
// T EST_F(video_capture_test, get_duration){ }
// T EST_F(video_capture_test, get_frame_size){ }
// T EST_F(video_capture_test, get_frame_size_in_bytes){ }
// T EST_F(video_capture_test, get_fps){ }
// T EST_F(video_capture_test, next){ }
// T EST_F(video_capture_test, next_frame){ }
// T EST_F(video_capture_test, release){ }

}