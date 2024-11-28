#include <iostream>
#include <stb/stb_image.h>
#include <stb/stb_image_write.h>
#include "Grayscale.h"
#include "Canny.h"
#include "Halftone.h"
#include "FloyedSteinberg.h"

int main(void)
{
    int result;
    std::string filepath = "res/textures/Lenna.png";
    int width, height, comps;
    int req_comps = 4;

    // Load the original image
    unsigned char *buffer = stbi_load(filepath.c_str(), &width, &height, &comps, req_comps);

    // Step 1: Convert to grayscale
    gray_scale(buffer);
    unsigned char *new_buffer = GrayScale_Rep(buffer);
    result = stbi_write_png("res/textures/GrayScale_Lenna.png", width, height, 1, new_buffer, width * 1);
    std::cout << result << std::endl;
    stbi_image_free(buffer);
    free(new_buffer);

    // Change req_comps and filepath after Step 1 (grayscale image)
    req_comps = 1;
    filepath = "res/textures/GrayScale_Lenna.png";

    // Step 2: Apply Canny edge detection
    buffer = stbi_load(filepath.c_str(), &width, &height, &comps, req_comps);
    blur(buffer, width, height);
    std::vector<float> angles = gradientCalculation(buffer, width, height);
    nonMaxSuppression(buffer, width, height, angles);
    doubleTresholding(buffer, width, height);
    hysteresis(buffer, width, height);
    result = stbi_write_png("res/textures/Canny_Lenna.png", width, height, req_comps, buffer, width * req_comps);
    std::cout << result << std::endl;
    stbi_image_free(buffer);

    // Step 3: Apply halftoning
    buffer = stbi_load(filepath.c_str(), &width, &height, &comps, req_comps);
    new_buffer = halftone(buffer, width, height);
    result = stbi_write_png("res/textures/Halftone_Lenna.png", width * 2, height * 2, req_comps, new_buffer, width * req_comps * 2);
    std::cout << result << std::endl;
    free(new_buffer);
    stbi_image_free(buffer);

    // Step 4: Apply Floyd-Steinberg dithering
    buffer = stbi_load(filepath.c_str(), &width, &height, &comps, req_comps);
    floyedSteinberg(buffer, width, height);
    result = stbi_write_png("res/textures/FloyedSteinberg_Lenna.png", width, height, req_comps, buffer, width * req_comps);
    std::cout << result << std::endl;
    stbi_image_free(buffer);
    return 0;
}
