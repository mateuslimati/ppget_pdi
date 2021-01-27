/**
 * @file halftoning.hpp
 * @author Mateus Lima Alves (mateuslima.ti@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <opencv2/opencv.hpp>

// Padrões de pixel em meio-tom.
static uint8_t halftone_source[10][3][3] =
    {
        {{0, 0, 0},
         {0, 0, 0},
         {0, 0, 0}},
        {{0, 255, 0},
         {0, 0, 0},
         {0, 0, 0}},
        {{0, 255, 0},
         {0, 0, 0},
         {0, 0, 255}},
        {{255, 255, 0},
         {0, 0, 0},
         {0, 0, 255}},
        {{255, 255, 0},
         {0, 0, 0},
         {255, 0, 255}},
        {{255, 255, 255},
         {0, 0, 0},
         {255, 0, 255}},
        {{255, 255, 255},
         {0, 0, 255},
         {255, 0, 255}},
        {{255, 255, 255},
         {0, 0, 255},
         {255, 255, 255}},
        {{255, 255, 255},
         {255, 0, 255},
         {255, 255, 255}},
        {{255, 255, 255},
         {255, 255, 255},
         {255, 255, 255}},
};

cv::Mat halftoning(cv::Mat source_image);