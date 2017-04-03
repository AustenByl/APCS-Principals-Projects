/**
 * scale.c
 *
 * CS50 AP
 * Whodunit
 *
 * Scales and image
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./scale infile outfile size_transformatin\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[1];
    char* outfile = argv[2];
    int sizeIncrease = atoi(argv[3]);
    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    // Creates structs for output file
    BITMAPFILEHEADER of;
    BITMAPINFOHEADER oi;
    // Changes header values for output file
    of = bf;
    oi = bi;
    oi.biWidth = bi.biWidth * sizeIncrease;
    oi.biHeight = bi.biHeight * sizeIncrease;
    // Detirmine padding for outfile and use in calculating header file
    int paddingOutfile =  (4 - (oi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    oi.biSizeImage = (oi.biWidth * sizeof(RGBTRIPLE) + paddingOutfile) * abs(oi.biHeight);
    of.bfSize = sizeof(BITMAPINFOHEADER) + sizeof(BITMAPFILEHEADER) + oi.biSizeImage;
    // write outfile's BITMAPFILEHEADER
    fwrite(&of, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&oi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // Triple for current row being replicated n times
        RGBTRIPLE width[bi.biWidth];
        // iterate over pixels in scanline
        // temporary storage
        RGBTRIPLE triple;
        // read RGB triple from infile
        // Read this into an array, the loop through the individual n times and later write all lines in one loop instead of seperatly
        fread(&width, sizeof(RGBTRIPLE), bi.biWidth, inptr);
        // Prints the other rows that need to be replicated sizeincrese times
        for(int l = 0; l < sizeIncrease; l++)
        {
            // Prints the current row
            for(int m = 0; m < bi.biWidth; m++)
            {
                triple = width[m];
                for(int n = 0; n < sizeIncrease; n++)
                {
                    // Writes individual pixels
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            // Adds padding for that line
            for (int k = 0; k < paddingOutfile; k++)
            {
                fputc(0x00, outptr);
            }
        }
        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
