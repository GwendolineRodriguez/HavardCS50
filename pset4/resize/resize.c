/**
 * Copies a BMP piece by piece, just because.
 */

#include <stdio.h>
#include <stdlib.h>
#include  <math.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize f infile outfile\n");
        return 1;
    }

    // convert string argument to float
    float f;
    sscanf(argv[1], " %f", &f);

    //exit if f is invalid
    if (f > 100.0 || f < 0.0)
    {
        fprintf(stderr, "Usage: ./resize f infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, bfOut;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bfOut = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, biOut;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    biOut = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // determine padding for inScanLines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //update BITMAPINFOHEADER for new resized file
    biOut.biWidth = floor(bi.biWidth * f);
    //if bi.biHeight is positive, convert to nagative.
    biOut.biHeight = floor((bi.biHeight > 0 ? -bi.biHeight : bi.biHeight) * f);

    // determine padding for outScanLines
    int paddingOut = (4 - biOut.biWidth * sizeof(RGBTRIPLE) % 4) % 4;

    // calculate output file image size header
    biOut.biSizeImage = ((sizeof(RGBTRIPLE) * biOut.biWidth) + paddingOut) * abs(biOut.biHeight);

    //update BITMAPFILEHEADER for new resized file
    bfOut.bfSize = biOut.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bfOut, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&biOut, sizeof(BITMAPINFOHEADER), 1, outptr);

    // read file into array (without padding) and also handle bottom-up DIB.
    int cols = abs(bi.biHeight);

    int i, j, k, l, indJ, indI;
    RGBTRIPLE inScanLines[cols][bi.biWidth];
    
    // resize horizontally
    if (bi.biHeight < 0)
    {
        // top-down bmp
        for (i = 0; i < abs(bi.biHeight); i++)
        {
            for (j = 0; j < bi.biWidth; j++)
            {
                // read RGB triple from infile
                fread(&(inScanLines[i][j]), sizeof(RGBTRIPLE), 1, inptr);
            }
            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);
        }
    }
    else
    {
        // bottom-up bmp
        for (i = bi.biHeight - 1; i >= 0; i--)
        {
            for (j = 0; j < bi.biWidth; j++)
            {
                // read RGB triple from infile
                fread(&(inScanLines[i][j]), sizeof(RGBTRIPLE), 1, inptr);
            }
            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);
        }
    }

    cols = abs(biOut.biHeight);
    RGBTRIPLE outScanLines[cols][biOut.biWidth];

    // generate output file's scanline array, outScanLines
    for (i = 0; i < abs(bi.biHeight); i++)
    {
        indI = floor(i * f);
        for (j = 0; j < bi.biWidth; j++)
        {
            indJ = ceil(f * j);
            outScanLines[indI][indJ] = inScanLines[i][j];
            for (k = floor(f) - 1; k > 0; k--)
            {
                outScanLines[indI][indJ + k] = inScanLines[i][j];
            }
        }
        for (l = floor(f) - 1; l > 0; l--)
        {
            for (j = 0; j < bi.biWidth; j++)
            {
                indJ = ceil(f * j);
                outScanLines[indI + l][indJ] = inScanLines[i][j];
                for (k = floor(f) - 1; k > 0; k--)
                {
                    outScanLines[indI + l][indJ + k] = inScanLines[i][j];
                }
            }
        }
    }

    // write outScanLines array to output file with padding
    for (i = 0; i < abs(biOut.biHeight); i++)
    {
        // iterate over pixels in scanline
        for (j = 0; j < biOut.biWidth; j++)
        {
            fwrite(&outScanLines[i][j], sizeof(RGBTRIPLE), 1, outptr);
        }

        // padding
        for (k = 0; k < paddingOut; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
