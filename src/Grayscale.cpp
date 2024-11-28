#include <Grayscale.h>


void gray_scale(unsigned char *img)
{
    for (size_t i = 0; i < strlen((const char *)img); i = i + 4)
    {
        char avg = (img[i] + img[i + 1] + img[i + 2]) / 3;
        img[i] = avg;
        img[i + 1] = avg;
        img[i + 2] = avg;
    }
}

void gray_scale2(unsigned char *img)
{
    for (size_t i = 0; i < strlen((const char *)img); i = i + 4)
    {
        char avg = (img[i] * 0.587 + img[i + 1] * 0.114 + img[i + 2] * 0.2989);
        img[i] = avg;
        img[i + 1] = avg;
        img[i + 2] = avg;
    }
}

unsigned char *GrayScale_Rep(unsigned char *origin_img)
{
    unsigned char *buffer = (unsigned char *)malloc(strlen((const char *)origin_img) / 4);
    int j = 0;
    for (size_t i = 0; i < strlen((const char *)origin_img); i += 4)
    {
        buffer[j] = origin_img[i];
        j++;
    }
    return buffer;
}
