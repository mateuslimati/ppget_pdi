#include <opencv2/opencv.hpp>
#include "halftoning.hpp"

int main(int argc, char *argv[])
{
    cv::Mat source_image = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    cv::Mat target_image;

    target_image = halftoning(source_image);
    cv::imwrite("target.jpg", target_image);
    return 0;
}