#include "helpers.h"

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float mediaRGB;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            mediaRGB = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            image[i][j].rgbtBlue = round(mediaRGB);
            image[i][j].rgbtGreen = round(mediaRGB);
            image[i][j].rgbtRed = round(mediaRGB);
        }
    }

    return;
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE(*tmp)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    for (int i = 0; i < height; i++)
    {
        for (int j = width - 1; j >= 0; j--)
        {
            tmp[i][(width - 1) - j].rgbtBlue = image[i][j].rgbtBlue;
            tmp[i][(width - 1) - j].rgbtGreen = image[i][j].rgbtGreen;
            tmp[i][(width - 1) - j].rgbtRed = image[i][j].rgbtRed;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
        }
    }

    free(tmp);
    return;
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*tmp)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    float average[3];
    float divide;

    for (int i = 0; i < height; i++)
    {
        for (int j = width - 1; j >= 0; j--)
        {
            divide = 0;

            for (int n = 0; n < 3; n++)
            {
                average[n] = 0;
            }

            for (int y = -1; y < 2; y++)
            {
                for (int x = -1; x < 2; x++)
                {
                    if (i + y >= 0 && i + y < height)
                    {
                        if (j + x >= 0 && j + x < width)
                        {
                            average[0] = image[i + y][j + x].rgbtBlue + average[0];
                            average[1] = image[i + y][j + x].rgbtGreen + average[1];
                            average[2] = image[i + y][j + x].rgbtRed + average[2];
                            divide++;
                        }
                    }
                }
            }

            if (average[0] != 0)
            {
                tmp[i][j].rgbtBlue = round(average[0] / divide);
            }

            if (average[1] != 0)
            {
                tmp[i][j].rgbtGreen = round(average[1] / divide);
            }

            if (average[2] != 0)
            {
                tmp[i][j].rgbtRed = round(average[2] / divide);
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
        }
    }

    free(tmp);
    return;
}

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*tmp)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    double sum[6];
    double root_square;
    int multiply;

    for (int i = 0; i < height; i++)
    {
        for (int j = width - 1; j >= 0; j--)
        {
            for (int n = 0; n < 6; n++)
            {
                sum[n] = 0;
            }

            for (int y = -1; y < 2; y++)
            {
                for (int x = -1; x < 2; x++)
                {
                    multiply = x;

                    if (y == 0)
                    {
                        multiply = x * 2;
                    }

                    if (i + y >= 0 && i + y < height)
                    {
                        if (j + x >= 0 && j + x < width)
                        {
                            sum[0] = (image[i + y][j + x].rgbtBlue * multiply) + sum[0];
                            sum[1] = (image[i + y][j + x].rgbtGreen * multiply) + sum[1];
                            sum[2] = (image[i + y][j + x].rgbtRed * multiply) + sum[2];
                        }
                    }

                    if (i + x >= 0 && i + x < height)
                    {
                        if (j + y >= 0 && j + y < width)
                        {
                            sum[3] = (image[i + x][y + j].rgbtBlue * multiply) + sum[3];
                            sum[4] = (image[i + x][y + j].rgbtGreen * multiply) + sum[4];
                            sum[5] = (image[i + x][y + j].rgbtRed * multiply) + sum[5];
                        }
                    }
                }

                root_square = sqrt(pow(sum[0], 2) + pow(sum[3], 2));

                if (root_square < 256)
                {
                    tmp[i][j].rgbtBlue = round(root_square);
                }
                else
                {
                    tmp[i][j].rgbtBlue = 255;
                }

                root_square = sqrt(pow(sum[1], 2) + pow(sum[4], 2));

                if (root_square < 256)
                {
                    tmp[i][j].rgbtGreen = round(root_square);
                }
                else
                {
                    tmp[i][j].rgbtGreen = 255;
                }

                root_square = sqrt(pow(sum[2], 2) + pow(sum[5], 2));

                if (root_square < 256)
                {
                    tmp[i][j].rgbtRed = round(root_square);
                }
                else
                {
                    tmp[i][j].rgbtRed = 255;
                }
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
        }
    }

    free(tmp);
    return;
}