#include <FloyedSteinberg.h>

void floyedSteinberg(unsigned char *img, int num_of_cols, int num_of_rows)
{
    unsigned char pixel;
    unsigned char new_pixel;
    unsigned char pixel_err;

    vector<float> temp(num_of_cols * num_of_rows);

    for (int i = 0; i < num_of_cols * num_of_rows; i++)
    {
        temp[i] = img[i];
    }

    for (int i = 0; i < num_of_rows - 1; i++)
    {
        // first pixel in each row
        pixel = temp[i * num_of_cols];
        new_pixel = (pixel / 16) * 16;
        pixel_err = pixel - new_pixel;
        temp[i * num_of_cols] = new_pixel;
        temp[i * num_of_cols + 1] += (8.0 / 16) * pixel_err;
        temp[(i + 1) * num_of_cols] += (6.0 / 16) * pixel_err;
        temp[(i + 1) * num_of_cols + 1] += (2.0 / 16) * pixel_err;

        for (int j = 1; j < num_of_cols - 1; j++)
        {
            pixel = temp[i * num_of_cols + j];
            new_pixel = (pixel / 16) * 16;
            pixel_err = pixel - new_pixel;
            temp[i * num_of_cols + j] = new_pixel;
            temp[i * num_of_cols + j + 1] += (7.0 / 16) * pixel_err;
            temp[(i + 1) * num_of_cols + j - 1] += (3.0 / 16) * pixel_err;
            temp[(i + 1) * num_of_cols + j] += (5.0 / 16) * pixel_err;
            temp[(i + 1) * num_of_cols + j + 1] += (1.0 / 16) * pixel_err;
        }
        // last pixel in each row
        pixel = temp[i * num_of_cols + num_of_cols - 1]; // num_of_cols -1 = last pixel in each row
        new_pixel = (pixel / 16) * 16;
        pixel_err = pixel - new_pixel;
        temp[i * num_of_cols + num_of_cols - 1] = new_pixel;
        temp[(i + 1) * num_of_cols + num_of_cols - 2] += (6.0 / 16) * pixel_err;
        temp[(i + 1) * num_of_cols + num_of_cols - 1] += (10.0 / 16) * pixel_err;
    }
    // last row
    for (int j = 0; j < num_of_cols - 1; j++)
    {
        pixel = temp[(num_of_rows - 1) * num_of_cols + j]; // num_of_cols -1 = last pixel in each row
        new_pixel = (pixel / 16) * 16;
        pixel_err = pixel - new_pixel;
        temp[(num_of_rows - 1) * num_of_cols + j] = new_pixel;
        temp[(num_of_rows - 1) * num_of_cols + j + 1] += pixel_err;
    }
    // last pixel last row
    pixel = temp[(num_of_rows - 1) * num_of_cols + num_of_cols - 1]; // num_of_cols -1 = last pixel in each row
    new_pixel = (pixel / 16) * 16;
    temp[(num_of_rows - 1) * num_of_cols + num_of_cols - 1] = new_pixel;

    for (int i = 0; i < num_of_cols * num_of_rows; i++)
    {
        img[i] = temp[i];
    }
}
