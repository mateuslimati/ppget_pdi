#include <opencv2/opencv.hpp>
#include "halftoning.hpp"

int main(int argc, char *argv[])
{
    // Captura os limites de pixels da imagem (256x256).
    uint32_t source_rows = 256,
             source_cols = 256;

    // Cria a imagem fonte,
    // com 8 bits por canal e com apenas 1 canal
    cv::Mat source_image(source_rows, source_cols, CV_8UC1);

    // Cria a imagem em meio-tom
    for (uint32_t i = 0; i < source_cols; i++)
    {
        for (uint32_t j = 0; j < source_rows; j++)
        {
            // Copia o padrão de pixel (matrix 3x3) para a respectiva posição na imagem resultante.
            source_image.at<uint8_t>(j, i) = (uint8_t)i;
        }
    }

    cv::Mat target_image;

    target_image = halftoning(source_image);
    cv::imwrite("target.jpg", target_image);
    return 0;
}