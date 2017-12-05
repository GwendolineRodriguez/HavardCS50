#include "recover.h"

void fail(int out, char *error)
{
    fprintf(stderr, "%s\n", error);
    exit(out);
}

int createJPEG(FILE *image, char *filename)
{
    static int nb = 0;

    // close previous image completed
    fclose(image);

    // create new image name
    sprintf(filename, "%03i.jpg", nb++);

    // open new image
    image = fopen(filename, "w");
    return 0;
}

int isJPEGHeader(BYTE *buffer)
{
    if (buffer[0] == 0xff &&
        buffer[1] == 0xd8 &&
        buffer[2] == 0xff &&
        (buffer[3] & 0xf0) == 0xe0)
        return 1;
    return 0;
}

int searchJPEG(FILE *inptr, char *filename)
{
    // Using buffer array where each element is of one byte
    BYTE buffer[512];

    FILE *image = fopen(filename, "w");
    if (image == NULL)
        fail(2, "Could not create image.");

    // Browse file byte by byte until end of block
    while (fread(buffer, 1, 512, inptr) == 512)
    {
        // Look for JPEGHEADER Bytes - Beginning of jpeg file
        if (isJPEGHeader(buffer))
            createJPEG(image, filename);

        // write block into jpeg file
        fwrite(buffer, 1, 512, image);
    }

    // Safely close files
    fclose(image);
    fclose(inptr);
    return 0;
}

int main(int ac, char **av)
{
    // ensure proper usage
    if (ac != 2)
        fail(1, "Usage: ./recover image");

    // remember filenames
    char *infile = av[1];

    // open image.raw
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
        fail(2, "Could not open file.");

    char *filename = malloc(8);
    if (filename == NULL)
        fail(1, "Could not allocate memory to a new jpeg.");
    sprintf(filename, "000.jpg");

    searchJPEG(inptr, filename);
    return 0;
}