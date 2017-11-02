#ifndef READ_WRITE
#define READ_WRITE

#include <stdlib.h>
#include <stdio.h>
#include <png.h>

int width, height;
png_byte color_type;
png_byte bit_depth;
png_bytep *row_pointers;


void read_png_file(char *filename)
{
    FILE *fp = fopen(filename, "rb");

    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if(!png) abort();

    png_infop info = png_create_info_struct(png);
    if(!info) abort();

    if(setjmp(png_jmpbuf(png))) abort();

    png_init_io(png, fp);

    png_read_info(png, info);

    width      = png_get_image_width(png, info);
    height     = png_get_image_height(png, info);
    color_type = png_get_color_type(png, info);
    bit_depth  = png_get_bit_depth(png, info);

    // Read any color_type into 8bit depth, RGBA format.
    // See http://www.libpng.org/pub/png/libpng-manual.txt

    if(bit_depth == 16)
        png_set_strip_16(png);

    if(color_type == PNG_COLOR_TYPE_PALETTE)
        png_set_palette_to_rgb(png);

    // PNG_COLOR_TYPE_GRAY_ALPHA is always 8 or 16bit depth.
    if(color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
        png_set_expand_gray_1_2_4_to_8(png);

    if(png_get_valid(png, info, PNG_INFO_tRNS))
        png_set_tRNS_to_alpha(png);

    // These color_type don't have an alpha channel then fill it with 0xff.
    if(color_type == PNG_COLOR_TYPE_RGB ||
            color_type == PNG_COLOR_TYPE_GRAY ||
            color_type == PNG_COLOR_TYPE_PALETTE)
        png_set_filler(png, 0xFF, PNG_FILLER_AFTER);

    if(color_type == PNG_COLOR_TYPE_GRAY ||
            color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
        png_set_gray_to_rgb(png);

    png_read_update_info(png, info);

    row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * height);
    for(int y = 0; y < height; y++) {
        row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png,info));
    }

    png_read_image(png, row_pointers);

    fclose(fp);
}

void write_png_file(char *filename)
{
    int y;
    FILE *fp = fopen(filename, "wb");
    if(!fp) abort();

    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) abort();

    png_infop info = png_create_info_struct(png);
    if (!info) abort();

    if (setjmp(png_jmpbuf(png))) abort();

    png_init_io(png, fp);

    // Output is 8bit depth, RGBA format.
    png_set_IHDR(
            png,
            info,
            width, height,
            8,
            PNG_COLOR_TYPE_RGBA,
            PNG_INTERLACE_NONE,
            PNG_COMPRESSION_TYPE_DEFAULT,
            PNG_FILTER_TYPE_DEFAULT
            );
    png_write_info(png, info);

    // To remove the alpha channel for PNG_COLOR_TYPE_RGB format,
    // Use png_set_filler().
    //png_set_filler(png, 0, PNG_FILLER_AFTER);

    printf("Writing…\n");
    png_write_image(png, row_pointers);
    png_write_end(png, NULL);

    for(int y = 0; y < height; y++) {
        free(row_pointers[y]);
    }

    free(row_pointers);

    fclose(fp);
}

int convert_grayscale(const png_bytep px)
{
    int gray = (int)(px[0]* 0.299 + px[1] * 0.587 + px[2] * 0.114);
    return gray;
}


int compare_light(const void *p, const void *q)
{
    int x = convert_grayscale(p);
    int y = convert_grayscale(q);

    /* Avoid return x - y, which can cause undefined behaviour
       because of signed integer overflow. */
    if (x < y)
        return -1;  // Return -1 if you want ascending, 1 if you want descending order.
    else if (x > y)
        return 1;   // Return 1 if you want ascending, -1 if you want descending order.

    return 0;
}

int threshold(png_bytep px, int value)
{
    return convert_grayscale(px) < value;
}


void process_png_file(threshold_value)
{
    printf("Processing…\n");

    // Create a table for the pixels

    for(int y = 0; y < height; y++) {
        png_bytep row = row_pointers[y];
        //printf("Line n°%d\n", y);
        int begin = -1;
        int inside = 0;
        for(int x = 0; x < width; x++) {
            png_bytep px = &(row[x * 4]);

            if (threshold(px, threshold_value) ||
                ((x + 1) == width)) {
                // If this is the first px to trigger the threshold
                if (begin == -1 && inside == 0) {
                    begin = x;
                    inside = 1;
                // Inside a dark zone, adjust the beginning of boundary
                } else if (begin != -1 && inside == 1 ) {
                    begin = x;
                // If triggered by an other px outside the dark zone
                } else if (begin != -1 && inside == 0) {
                    qsort(&row[(begin+1)*4], x - begin, 4, compare_light);
                // Reinitialize the boundary
                    begin = -1;
                    inside = 0;
                }
            } else {
                inside = 0;
            }
        }
    }
}


#endif
