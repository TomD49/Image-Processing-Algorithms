#include <Halftone.h>


unsigned char *halftone(unsigned char *img, int num_of_cols, int num_of_rows)
{
    unsigned char pixel;
    float pixel_range;

    unsigned char *temp = (unsigned char *)malloc(num_of_cols * num_of_rows * 4);

    for (int i = 0; i < num_of_rows; i++)
    {
        for (int j = 0; j < num_of_cols; j++)
        {
            pixel = img[i * num_of_cols + j];
            pixel_range = (float)pixel / 256.0;
            if (pixel_range <= 0.2)
            {
                temp[2 * i * num_of_cols * 2 + 2 * j] = 0;
                temp[2 * i * num_of_cols * 2 + 2 * j + 1] = 0;
                temp[(2 * i + 1) * num_of_cols * 2 + 2 * j] = 0;
                temp[(2 * i + 1) * num_of_cols * 2 + 2 * j + 1] = 0;
            }
            else if (pixel_range <= 0.4)
            {
                temp[2 * i * num_of_cols * 2 + 2 * j] = 0;
                temp[2 * i * num_of_cols * 2 + 2 * j + 1] = 0;
                temp[(2 * i + 1) * num_of_cols * 2 + 2 * j] = 255;
                temp[(2 * i + 1) * num_of_cols * 2 + 2 * j + 1] = 0;
            }
            else if (pixel_range <= 0.6)
            {
                temp[2 * i * num_of_cols * 2 + 2 * j] = 0;
                temp[2 * i * num_of_cols * 2 + 2 * j + 1] = 255;
                temp[(2 * i + 1) * num_of_cols * 2 + 2 * j] = 255;
                temp[(2 * i + 1) * num_of_cols * 2 + 2 * j + 1] = 0;
            }
            else if (pixel_range <= 0.8)
            {
                temp[2 * i * num_of_cols * 2 + 2 * j] = 0;
                temp[2 * i * num_of_cols * 2 + 2 * j + 1] = 255;
                temp[(2 * i + 1) * num_of_cols * 2 + 2 * j] = 255;
                temp[(2 * i + 1) * num_of_cols * 2 + 2 * j + 1] = 255;
            }
            else
            {
                temp[2 * i * num_of_cols * 2 + 2 * j] = 255;
                temp[2 * i * num_of_cols * 2 + 2 * j + 1] = 255;
                temp[(2 * i + 1) * num_of_cols * 2 + 2 * j] = 255;
                temp[(2 * i + 1) * num_of_cols * 2 + 2 * j + 1] = 255;
            }
        }
    }

    return temp;
}
