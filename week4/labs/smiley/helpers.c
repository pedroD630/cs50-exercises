#include "helpers.h"
#include <stdio.h>

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    // rodar cada pixal da imagem
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // checar se o pixel é preto
            // se blue, green e red for 00 é preto
            if (!image[i][j].rgbtBlue && !image[i][j].rgbtGreen && !image[i][j].rgbtRed)
            {
                // alterar RGBTRIPLE para a cor que eu desejar.
                image[i][j].rgbtBlue = 255;
                image[i][j].rgbtGreen = 0;
                image[i][j].rgbtRed = 100;
            }
        }
    }
}
