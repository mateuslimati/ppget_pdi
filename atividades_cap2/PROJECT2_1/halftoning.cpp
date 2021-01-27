/**
 * @file halftoning.cpp
 * @author Mateus Lima Alves (mateuslima.ti@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "halftoning.hpp"

cv::Mat halftoning(cv::Mat source_image)
{

    // Captura os limites de pixels da imagem.
    uint32_t source_rows = source_image.rows,
             source_cols = source_image.cols;

    // Cria a imagem resultante sendo 9 vezer maior que a fonte,
    // com 8 bits por canal e com apenas 1 canal
    cv::Mat target_image(source_rows * 3, source_cols * 3, CV_8UC1);

    // Gera os padrões de pixels.
    cv::Mat halftone_matrix[10];
    for (int i = 0; i <= 9; i++)
    {
        halftone_matrix[i] = cv::Mat(3, 3, CV_8UC1, halftone_source[i]);
    }

    // Cria a imagem em meio-tom
    for (uint32_t i = 0; i < source_rows; i++)
    {
        for (uint32_t j = 0; j < source_cols; j++)
        {
            // Captura a intesidade do pixel tomando o valor do pixel (0-255) e normalizando
            // para 9, ou seja: intensidade = (pixel/255)*9.
            uint8_t pixel_intensity = source_image.at<uint8_t>(i, j) / 28.3;

            // Copia o padrão de pixel (matrix 3x3) para a respectiva posição na imagem resultante.
            halftone_matrix[pixel_intensity].copyTo(
                target_image(cv::Rect_<uint32_t>(j * 3, i * 3, 3, 3)));
        }
    }
    return target_image;
}