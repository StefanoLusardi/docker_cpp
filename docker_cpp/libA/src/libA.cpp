#include <libA/libA.hpp>
#include <spdlog/spdlog.h>
// #include <opencv2/opencv.hpp>

namespace dkpp::A
{
libA::libA() noexcept
{
    // cv::Mat m = cv::Mat::eye(3, 3, CV_8U);
    // auto s = m.size();
    // spdlog::warn("Mat size: {} x {}", s.height, s.width);
}

libA::~libA() noexcept
{
}

void libA::print(const std::string_view msg) const
{
    spdlog::info(msg);
}

}
