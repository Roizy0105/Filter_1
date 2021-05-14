#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //iterate through rows
    for (int i = 0; i < height; i++)
    {
        //iterate through columns
        for (int j = 0; j < width; j++)
        {
            double sum = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            double avrage = round(sum / 3);
            //get the abvrage of the rgb and aggaign that to the pixel
            image[i][j].rgbtBlue = avrage;
            image[i][j].rgbtGreen = avrage;
            image[i][j].rgbtRed = avrage;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //itarate through the rows
    for (int i = 0; i < height; i++)
    {
        //iterate through the columns
        int counter = 0;
        for (int j = width - 1; j > counter; j--)
        {
            //swap the first value with the last value
            RGBTRIPLE temp = image[i][counter];
            image[i][counter] = image[i][j];
            image[i][j] = temp;
            counter++;
        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE copy[height][width];
    //iterate through the rows of the image
    for (int i = 0; i < height; i++)
    {
        //iterate therough the columes in the image
        for (int j = 0; j < width; j++)
        {
            int blurRed = 0;
            int blurGreen = 0;
            int blurBlue = 0;

            //if this pixel is at the top left of the image
            if (i == 0 && j == 0)
            {
                //sum of red
                double sumRed = image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed;

                //sum of green
                double sumGreen = image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                  image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen;

                //sum of blue
                double sumBlue = image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                 image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue;


                //avrage
                double avrageRed = round(sumRed / 4);
                double avrageGreen = round(sumGreen / 4);
                double avrageBlue = round(sumBlue / 4);

                blurRed = avrageRed;
                blurGreen = avrageGreen;
                blurBlue = avrageBlue;
            }


            //if the pixel is at the top right of the image
            else if (i == 0 && j == width - 1)
            {

                double sumRed = image[i][j - 1].rgbtRed + image[i][j].rgbtRed +
                                image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed;

                double sumGreen = image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen +
                                  image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen;

                double sumBlue = image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue +
                                 image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue;


                //avrage
                double avrageRed = round(sumRed / 4);
                double avrageGreen = round(sumGreen / 4);
                double avrageBlue = round(sumBlue / 4);

                blurRed = avrageRed;
                blurGreen = avrageGreen;
                blurBlue = avrageBlue;
            }


            //if the pixel is at the bottom left of the screen
            else if (i == height - 1 && j == 0)
            {

                double sumRed = image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                                image[i][j].rgbtRed + image[i][j + 1].rgbtRed;

                double sumGreen = image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                                  image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen;

                double sumBlue = image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                                 image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue;


                //avrage
                double avrageRed = round(sumRed / 4);
                double avrageGreen = round(sumGreen / 4);
                double avrageBlue = round(sumBlue / 4);

                blurRed = avrageRed;
                blurGreen = avrageGreen;
                blurBlue = avrageBlue;
            }


            //if the pixel is at the bottom right of the image
            else if (i == height - 1 && j == width - 1)
            {

                double sumRed = image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed +
                                image[i][j - 1].rgbtRed + image[i][j].rgbtRed;

                double sumGreen = image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen +
                                  image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen;

                double sumBlue = image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue +
                                 image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue;


                //avrage
                double avrageRed = round(sumRed / 4);
                double avrageGreen = round(sumGreen / 4);
                double avrageBlue = round(sumBlue / 4);

                blurRed = avrageRed;
                blurGreen = avrageGreen;
                blurBlue = avrageBlue;
            }


            //if the pixel is on the top row of the image
            else if (i == 0 && j > 0 && j < width - 1)
            {

                double sumRed = image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed;

                double sumGreen = image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                  image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen;

                double sumBlue = image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                 image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue;


                //avrage
                double avrageRed = round(sumRed / 6);
                double avrageGreen = round(sumGreen / 6);
                double avrageBlue = round(sumBlue / 6);

                blurRed = avrageRed;
                blurGreen = avrageGreen;
                blurBlue = avrageBlue;
            }


            //if the pixel is on the bottom row of the image
            else if (i == height - 1 && j > 0 && j < width - 1)
            {

                double sumRed = image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                                image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed;

                double sumGreen = image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                                  image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen;

                double sumBlue = image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                                 image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue;


                //avrage
                double avrageRed = round(sumRed / 6);
                double avrageGreen = round(sumGreen / 6);
                double avrageBlue = round(sumBlue / 6);

                blurRed = avrageRed;
                blurGreen = avrageGreen;
                blurBlue = avrageBlue;
            }


            //if the pixel is in the first column
            else if (j == 0 && i > 0 && i < height - 1)
            {

                double sumRed = image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                                image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed;

                double sumGreen = image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                                  image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                  image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen;

                double sumBlue = image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                                 image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                 image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue;


                //avrage
                double avrageRed = round(sumRed / 6);
                double avrageGreen = round(sumGreen / 6);
                double avrageBlue = round(sumBlue / 6);

                blurRed = avrageRed;
                blurGreen = avrageGreen;
                blurBlue = avrageBlue;
            }


            //if the pixel is in the last column
            else if (j == width - 1 && i > 0 && i < height - 1)
            {

                double sumRed = image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed +
                                image[i][j - 1].rgbtRed + image[i][j].rgbtRed +
                                image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed;

                double sumGreen = image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen +
                                  image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen +
                                  image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen;

                double sumBlue = image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue +
                                 image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue +
                                 image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue;


                //avrage
                double avrageRed = round(sumRed / 6);
                double avrageGreen = round(sumGreen / 6);
                double avrageBlue = round(sumBlue / 6);

                blurRed = avrageRed;
                blurGreen = avrageGreen;
                blurBlue = avrageBlue;
            }

            //if the pixel is anyware else in the image
            else
            {

                double sumRed = image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                                image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed;

                double sumGreen = image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                                  image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                  image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen;

                double sumBlue = image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                                 image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                 image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue;


                //avrage
                double avrageRed = round(sumRed / 9);
                double avrageGreen = round(sumGreen / 9);
                double avrageBlue = round(sumBlue / 9);

                blurRed = avrageRed;
                blurGreen = avrageGreen;
                blurBlue = avrageBlue;
            }
            //assign new values to rgb
            copy[i][j].rgbtRed = blurRed;
            copy[i][j].rgbtGreen = blurGreen;
            copy[i][j].rgbtBlue = blurBlue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //store some of X
            double sumRedGx  = 0;
            double sumGreenGx = 0;
            double sumBlueGx = 0;

            //stor sum of Y
            double sumRedGy = 0;
            double sumGreenGy = 0;
            double sumBlueGy = 0;



            if (i == 0 && j == 0)
            {
                //adding values for the X
                sumRedGx = - 1 * 0 + 0 * 0 + 1 * 0
                           - 2 * 0 + 0 * image[i][j].rgbtRed + 2 * image[i][j + 1].rgbtRed
                           - 1 * 0 + 0 * image[i + 1][j].rgbtRed + 1 * image[i + 1][j + 1].rgbtRed;

                sumGreenGx = - 1 * 0 + 0 * 0 + 1 * 0
                             - 2 * 0 + 0 * image[i][j].rgbtGreen + 2 * image[i][j + 1].rgbtGreen
                             - 1 * 0 + 0 * image[i + 1][j].rgbtGreen + 1 * image[i + 1][j + 1].rgbtGreen;

                sumBlueGx = - 1 * 0 + 0 * 0 + 1 * 0
                            - 2 * 0 + 0 * image[i][j].rgbtBlue + 2 * image[i][j + 1].rgbtBlue
                            - 1 * 0 + 0 * image[i + 1][j].rgbtBlue + 1 * image[i + 1][j + 1].rgbtBlue;


                //adding values for Y
                sumRedGy = - 1 * 0 - 2 * 0 - 1 * 0
                           + 0 * 0 + 0 * image[i][j].rgbtRed + 0 * image[i][j + 1].rgbtRed
                           + 1 * 0 + 2 * image[i + 1][j].rgbtRed + 1 * image[i + 1][j + 1].rgbtRed;

                sumGreenGy = - 1 * 0 - 2 * 0 - 1 * 0
                             + 0 * 0 + 0 * image[i][j].rgbtGreen + 0 * image[i][j + 1].rgbtGreen
                             + 1 * 0 + 2 * image[i + 1][j].rgbtGreen + 1 * image[i + 1][j + 1].rgbtGreen;

                sumBlueGy = - 1 * 0 - 2 * 0 * 0
                            + 0 * 0 + 0 * image[i][j].rgbtBlue + 0 * image[i][j + 1].rgbtBlue
                            + 1 * 0 + 2 * image[i + 1][j].rgbtBlue + 1 * image[i + 1][j + 1].rgbtBlue;

            }

            else if (i == 0 && j == width - 1)
            {
                //adding values for the X
                sumRedGx = - 1 * 0 + 0 * 0 + 1 * 0
                           - 2 * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + 2 * 0
                           - 1 * image[i + 1][j - 1].rgbtRed + 0 * image[i + 1][j].rgbtRed + 1 * 0;

                sumGreenGx = - 1 * 0 + 0 * 0 + 1 * 0
                             - 2 * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 2 * 0
                             - 1 * image[i + 1][j - 1].rgbtGreen + 0 * image[i + 1][j].rgbtGreen + 1 * 0;

                sumBlueGx = - 1 * 0 + 0 * 0 + 1 * 0
                            - 2 * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 2 * 0
                            - 1 * image[i + 1][j - 1].rgbtBlue + 0 * image[i + 1][j].rgbtBlue + 1 * 0;


                //adding values for Y
                sumRedGy = - 1 * 0 - 2 * 0 - 1 * 0
                           + 0 * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + 0 * 0
                           + 1 * image[i + 1][j - 1].rgbtRed + 2 * image[i + 1][j].rgbtRed + 1 * 0;

                sumGreenGy = - 1 * 0 - 2 * 0 - 1 * 0
                             + 0 * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 0 * 0
                             + 1 * image[i + 1][j - 1].rgbtGreen + 2 * image[i + 1][j].rgbtGreen + 1 * 0;

                sumBlueGy = - 1 * 0 - 2 * 0 - 1 * 0
                            + 0 * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 0 * 0
                            + 1 * image[i + 1][j - 1].rgbtBlue + 2 * image[i + 1][j].rgbtBlue + 1 * 0;

            }


            else if (i == height - 1 && j == 0)
            {
                //adding values for the X
                sumRedGx = - 1 * 0 + 0 * image[i - 1][j].rgbtRed + 1 * image[i - 1][j + 1].rgbtRed
                           - 2 * 0 + 0 * image[i][j].rgbtRed + 2 * image[i][j + 1].rgbtRed
                           - 1 * 0 + 0 * 0 + 1 * 0;

                sumGreenGx = - 1 * 0 + 0 * image[i - 1][j].rgbtGreen + 1 * image[i - 1][j + 1].rgbtGreen
                             - 2 * 0 + 0 * image[i][j].rgbtGreen + 2 * image[i][j + 1].rgbtGreen
                             - 1 * 0 + 0 * 0 + 1 * 0;

                sumBlueGx = - 1 * 0 + 0 * image[i - 1][j].rgbtBlue + 1 * image[i - 1][j + 1].rgbtBlue
                            - 2 * 0 + 0 * image[i][j].rgbtBlue + 2 * image[i][j + 1].rgbtBlue
                            - 1 * 0 + 0 * 0 + 1 * 0;


                //adding values for Y
                sumRedGy = - 1 * 0 - 2 * image[i - 1][j].rgbtRed - 1 * image[i - 1][j + 1].rgbtRed
                           + 0 * 0 + 0 * image[i][j].rgbtRed + 0 * image[i][j + 1].rgbtRed
                           + 1 * 0 + 2 * 0 + 1 * 0;

                sumGreenGy = - 1 * 0 - 2 * image[i - 1][j].rgbtGreen - 1 * image[i - 1][j + 1].rgbtGreen
                             + 0 * 0 + 0 * image[i][j].rgbtGreen + 0 * image[i][j + 1].rgbtGreen
                             + 1 * 0 + 2 * 0 + 1 * 0;

                sumBlueGy = - 1 * 0 - 2 * image[i - 1][j].rgbtBlue - 1 * image[i - 1][j + 1].rgbtBlue
                            + 0 * 0 + 0 * image[i][j].rgbtBlue + 0 * image[i][j + 1].rgbtBlue
                            + 1 * 0 + 2 * 0 + 1 * 0;

            }
            else if (i == height - 1 && j == width - 1)
            {
                //adding values for the X
                sumRedGx = - 1 * image[i - 1][j - 1].rgbtRed + 0 * image[i - 1][j].rgbtRed + 1 * 0
                           - 2 * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + 2 * 0
                           - 1 * 0 + 0 * 0 + 1 * 0;

                sumGreenGx = - 1 * image[i - 1][j - 1].rgbtGreen + 0 * image[i - 1][j].rgbtGreen + 1 * 0
                             - 2 * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 2 * 0
                             - 1 * 0 + 0 * 0 + 1 * 0;

                sumBlueGx = - 1 * image[i - 1][j - 1].rgbtBlue + 0 * image[i - 1][j].rgbtBlue + 1 * 0
                            - 2 * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 2 * 0
                            - 1 * 0 + 0 * 0 + 1 * 0;


                //adding values for Y
                sumRedGy = - 1 * image[i - 1][j - 1].rgbtRed - 2 * image[i - 1][j].rgbtRed - 1 * 0
                           + 0 * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + 0 * 0
                           + 1 * 0 + 2 * 0 + 1 * 0;

                sumGreenGy = - 1 * image[i - 1][j - 1].rgbtGreen - 2 * image[i - 1][j].rgbtGreen - 1 * 0
                             + 0 * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 0 * 0
                             + 1 * 0 + 2 * 0 + 1 * 0;

                sumBlueGy = - 1 * image[i - 1][j - 1].rgbtBlue - 2 * image[i - 1][j].rgbtBlue - 1 * 0
                            + 0 * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 0 * 0
                            + 1 * 0 + 2 * 0 + 1 * 0;

            }
            else if (i == 0)
            {
                //adding values for the X
                sumRedGx = - 1 * 0 + 0 * 0 + 1 * 0
                           - 2 * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + 2 * image[i][j + 1].rgbtRed
                           - 1 * image[i + 1][j - 1].rgbtRed + 0 * image[i + 1][j].rgbtRed + 1 * image[i + 1][j + 1].rgbtRed;

                sumGreenGx = - 1 * 0 + 0 * 0 + 1 * 0
                             - 2 * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 2 * image[i][j + 1].rgbtGreen
                             - 1 * image[i + 1][j - 1].rgbtGreen + 0 * image[i + 1][j].rgbtGreen + 1 * image[i + 1][j + 1].rgbtGreen;

                sumBlueGx = - 1 * 0 + 0 * 0 + 1 * 0
                            - 2 * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 2 * image[i][j + 1].rgbtBlue
                            - 1 * image[i + 1][j - 1].rgbtBlue + 0 * image[i + 1][j].rgbtBlue + 1 * image[i + 1][j + 1].rgbtBlue;


                //adding values for Y
                sumRedGy = - 1 * 0 - 2 * 0 - 1 * 0
                           + 0 * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + 0 * image[i][j + 1].rgbtRed
                           + 1 * image[i + 1][j - 1].rgbtRed + 2 * image[i + 1][j].rgbtRed + 1 * image[i + 1][j + 1].rgbtRed;

                sumGreenGy = - 1 * 0 - 2 * 0 - 1 * 0
                             + 0 * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 0 * image[i][j + 1].rgbtGreen
                             + 1 * image[i + 1][j - 1].rgbtGreen + 2 * image[i + 1][j].rgbtGreen + 1 * image[i + 1][j + 1].rgbtGreen;

                sumBlueGy = - 1 * 0 - 2 * 0 - 1 * 0
                            + 0 * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 0 * image[i][j + 1].rgbtBlue
                            + 1 * image[i + 1][j - 1].rgbtBlue + 2 * image[i + 1][j].rgbtBlue + 1 * image[i + 1][j + 1].rgbtBlue;

            }

            else if (j == 0)
            {
                //adding values for the X
                sumRedGx = - 1 * 0 + 0 * image[i - 1][j].rgbtRed + 1 * image[i - 1][j + 1].rgbtRed
                           - 2 * 0 + 0 * image[i][j].rgbtRed + 2 * image[i][j + 1].rgbtRed
                           - 1 * 0 + 0 * image[i + 1][j].rgbtRed + 1 * image[i + 1][j + 1].rgbtRed;

                sumGreenGx = - 1 * 0 + 0 * image[i - 1][j].rgbtGreen + 1 * image[i - 1][j + 1].rgbtGreen
                             - 2 * 0 + 0 * image[i][j].rgbtGreen + 2 * image[i][j + 1].rgbtGreen
                             - 1 * 0 + 0 * image[i + 1][j].rgbtGreen + 1 * image[i + 1][j + 1].rgbtGreen;

                sumBlueGx = - 1 * 0 + 0 * image[i - 1][j].rgbtBlue + 1 * image[i - 1][j + 1].rgbtBlue
                            - 2 * 0 + 0 * image[i][j].rgbtBlue + 2 * image[i][j + 1].rgbtBlue
                            - 1 * 0 + 0 * image[i + 1][j].rgbtBlue + 1 * image[i + 1][j + 1].rgbtBlue;


                //adding values for Y
                sumRedGy = - 1 * 0 - 2 * image[i - 1][j].rgbtRed - 1 * image[i - 1][j + 1].rgbtRed
                           + 0 * 0 + 0 * image[i][j].rgbtRed + 0 * image[i][j + 1].rgbtRed
                           + 1 * 0 + 2 * image[i + 1][j].rgbtRed + 1 * image[i + 1][j + 1].rgbtRed;

                sumGreenGy = - 1 * 0 - 2 * image[i - 1][j].rgbtGreen - 1 * image[i - 1][j + 1].rgbtGreen
                             + 0 * 0 + 0 * image[i][j].rgbtGreen + 0 * image[i][j + 1].rgbtGreen
                             + 1 * 0 + 2 * image[i + 1][j].rgbtGreen + 1 * image[i + 1][j + 1].rgbtGreen;

                sumBlueGy = - 1 * 0 - 2 * image[i - 1][j].rgbtBlue - 1 * image[i - 1][j + 1].rgbtBlue
                            + 0 * 0 + 0 * image[i][j].rgbtBlue + 0 * image[i][j + 1].rgbtBlue
                            + 1 * 0 + 2 * image[i + 1][j].rgbtBlue + 1 * image[i + 1][j + 1].rgbtBlue;

            }

            else if (i == height - 1)
            {
                //adding values for the X
                sumRedGx = - 1 * image[i - 1][j - 1].rgbtRed + 0 * image[i - 1][j].rgbtRed + 1 * image[i - 1][j + 1].rgbtRed
                           - 2 * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + 2 * image[i][j + 1].rgbtRed
                           - 1 * 0 + 0 * 0 + 1 * 0;

                sumGreenGx = - 1 * image[i - 1][j - 1].rgbtGreen + 0 * image[i - 1][j].rgbtGreen + 1 * image[i - 1][j + 1].rgbtGreen
                             - 2 * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 2 * image[i][j + 1].rgbtGreen
                             - 1 * 0 + 0 * 0 + 1 * 0;

                sumBlueGx = - 1 * image[i - 1][j - 1].rgbtBlue + 0 * image[i - 1][j].rgbtBlue + 1 * image[i - 1][j + 1].rgbtBlue
                            - 2 * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 2 * image[i][j + 1].rgbtBlue
                            - 1 * 0 + 0 * 0 + 1 * 0;


                //adding values for Y
                sumRedGy = - 1 * image[i - 1][j - 1].rgbtRed - 2 * image[i - 1][j].rgbtRed - 1 * image[i - 1][j + 1].rgbtRed
                           + 0 * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + 0 * image[i][j + 1].rgbtRed
                           + 1 * 0 + 2 * 0 + 1 * 0;

                sumGreenGy = - 1 * image[i - 1][j - 1].rgbtGreen - 2 * image[i - 1][j].rgbtGreen - 1 * image[i - 1][j + 1].rgbtGreen
                             + 0 * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 0 * image[i][j + 1].rgbtGreen
                             + 1 * 0 + 2 * 0 + 1 * 0;

                sumBlueGy = - 1 * image[i - 1][j - 1].rgbtBlue - 2 * image[i - 1][j].rgbtBlue - 1 * image[i - 1][j + 1].rgbtBlue
                            + 0 * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 0 * image[i][j + 1].rgbtBlue
                            + 1 * 0 + 2 * 0 + 1 * 0;

            }

            else if (j == width - 1)
            {
                //adding values for the X
                sumRedGx = - 1 * image[i - 1][j - 1].rgbtRed + 0 * image[i - 1][j].rgbtRed + 1 * 0
                           - 2 * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + 2 * 0
                           - 1 * image[i + 1][j - 1].rgbtRed + 0 * image[i + 1][j].rgbtRed + 1 * 0;

                sumGreenGx = - 1 * image[i - 1][j - 1].rgbtGreen + 0 * image[i - 1][j].rgbtGreen + 1 * 0
                             - 2 * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 2 * 0
                             - 1 * image[i + 1][j - 1].rgbtGreen + 0 * image[i + 1][j].rgbtGreen + 1 * 0;

                sumBlueGx = - 1 * image[i - 1][j - 1].rgbtBlue + 0 * image[i - 1][j].rgbtBlue + 1 * 0
                            - 2 * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 2 * 0
                            - 1 * image[i + 1][j - 1].rgbtBlue + 0 * image[i + 1][j].rgbtBlue + 1 * 0;


                //adding values for Y
                sumRedGy = - 1 * image[i - 1][j - 1].rgbtRed - 2 * image[i - 1][j].rgbtRed - 1 * 0
                           + 0 * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + 0 * 0
                           + 1 * image[i + 1][j - 1].rgbtRed + 2 * image[i + 1][j].rgbtRed + 1 * 0;

                sumGreenGy = - 1 * image[i - 1][j - 1].rgbtGreen - 2 * image[i - 1][j].rgbtGreen - 1 * 0
                             + 0 * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 0 * 0
                             + 1 * image[i + 1][j - 1].rgbtGreen + 2 * image[i + 1][j].rgbtGreen + 1 * 0;

                sumBlueGy = - 1 * image[i - 1][j - 1].rgbtBlue - 2 * image[i - 1][j].rgbtBlue - 1 * 0
                            + 0 * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 0 * 0
                            + 1 * image[i + 1][j - 1].rgbtBlue + 2 * image[i + 1][j].rgbtBlue + 1 * 0;

            }
            else
            {
                //adding values for the X
                sumRedGx = - 1 * image[i - 1][j - 1].rgbtRed + 0 * image[i - 1][j].rgbtRed + 1 * image[i - 1][j + 1].rgbtRed
                           - 2 * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + 2 * image[i][j + 1].rgbtRed
                           - 1 * image[i + 1][j - 1].rgbtRed + 0 * image[i + 1][j].rgbtRed + 1 * image[i + 1][j + 1].rgbtRed;

                sumGreenGx = - 1 * image[i - 1][j - 1].rgbtGreen + 0 * image[i - 1][j].rgbtGreen + 1 * image[i - 1][j + 1].rgbtGreen
                             - 2 * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 2 * image[i][j + 1].rgbtGreen
                             - 1 * image[i + 1][j - 1].rgbtGreen + 0 * image[i + 1][j].rgbtGreen + 1 * image[i + 1][j + 1].rgbtGreen;

                sumBlueGx = - 1 * image[i - 1][j - 1].rgbtBlue + 0 * image[i - 1][j].rgbtBlue + 1 * image[i - 1][j + 1].rgbtBlue
                            - 2 * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 2 * image[i][j + 1].rgbtBlue
                            - 1 * image[i + 1][j - 1].rgbtBlue + 0 * image[i + 1][j].rgbtBlue + 1 * image[i + 1][j + 1].rgbtBlue;


                //adding values for Y
                sumRedGy = - 1 * image[i - 1][j - 1].rgbtRed - 2 * image[i - 1][j].rgbtRed - 1 * image[i - 1][j + 1].rgbtRed
                           + 0 * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + 0 * image[i][j + 1].rgbtRed
                           + 1 * image[i + 1][j - 1].rgbtRed + 2 * image[i + 1][j].rgbtRed + 1 * image[i + 1][j + 1].rgbtRed;

                sumGreenGy = - 1 * image[i - 1][j - 1].rgbtGreen - 2 * image[i - 1][j].rgbtGreen - 1 * image[i - 1][j + 1].rgbtGreen
                             + 0 * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 0 * image[i][j + 1].rgbtGreen
                             + 1 * image[i + 1][j - 1].rgbtGreen + 2 * image[i + 1][j].rgbtGreen + 1 * image[i + 1][j + 1].rgbtGreen;

                sumBlueGy = - 1 * image[i - 1][j - 1].rgbtBlue - 2 * image[i - 1][j].rgbtBlue - 1 * image[i - 1][j + 1].rgbtBlue
                            + 0 * image[i][j - 1].rgbtBlue     + 0 * image[i][j].rgbtBlue     + 0 * image[i][j + 1].rgbtBlue
                            + 1 * image[i + 1][j - 1].rgbtBlue + 2 * image[i + 1][j].rgbtBlue + 1 * image[i + 1][j + 1].rgbtBlue;

            }



            //get the square root of the the total X and Y to the power of 2
            double totalRed = sqrt(pow(sumRedGx, 2) + pow(sumRedGy, 2));
            double totalGreen = sqrt(pow(sumGreenGx, 2) + pow(sumGreenGy, 2));
            double totalBlue  = sqrt(pow(sumBlueGx, 2) + pow(sumBlueGy, 2));

            //round the float the the nearst int
            int newRed = round(totalRed);
            int newGreen = round(totalGreen);
            int newBlue = round(totalBlue);

            //if the number is greater then 255 then change it to 255
            if (newRed > 255)
            {
                newRed = 255;
            }
            if (newGreen > 255)
            {
                newGreen = 255;
            }
            if (newBlue > 255)
            {
                newBlue = 255;
            }
            
            //put the result in a temp file
            copy[i][j].rgbtRed = newRed;
            copy[i][j].rgbtGreen = newGreen;
            copy[i][j].rgbtBlue = newBlue;
        }
    }
    
    //place the info from the temp file into the output file
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
    return;
}
