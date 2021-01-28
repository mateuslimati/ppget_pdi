#include <opencv2/opencv.hpp>
#include <stdlib.h>

#define PIXEL_VALUE(PIXEL_INTENSITY, PIXEL_MASK) ((PIXEL_INTENSITY & PIXEL_MASK) == PIXEL_MASK) ? 0xFF : (PIXEL_INTENSITY & PIXEL_MASK)

int main(int argc, char *argv[])
{
    cv::Mat source_image = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    uint8_t intensity_level = (uint8_t)strtoul(argv[2], NULL, 10);
    uint8_t intensity_mask = 0xFF;

    for (uint8_t i = 0; i < 8; i++)
    {
        if (intensity_level & 0x01)
        {
            intensity_mask = (uint8_t)0xFF << (8 - i);
            break;
        }
        intensity_level >>= 1;
    }

    // Captura os limites de pixels da imagem.
    uint32_t source_rows = source_image.rows,
             source_cols = source_image.cols;

    cv::Mat target_image(source_rows, source_cols, CV_8UC1);

    // Modifica os pixels da imagem
    for (uint32_t i = 0; i < source_rows; i++)
    {
        for (uint32_t j = 0; j < source_cols; j++)
        {
            target_image.at<uint8_t>(i, j) = PIXEL_VALUE(source_image.at<uint8_t>(i, j), intensity_mask);
        }
    }
    cv::imwrite("target.jpg", target_image);
    return 0;
}