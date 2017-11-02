#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include "read_write.h"


int main(int argc, char **argv)
{
    char *input = NULL, *output = NULL;     // input and output file
    double angle = 0.0;                         // the angle used for pixelsorting
    int threshold_value = 20;

    int c;
    opterr = 0;

    // Argument parsing
    while ((c = getopt (argc, argv, "i:o:a:t:")) != -1) {
        switch (c) {
            case 'a':
                angle = atof(optarg);
                break;
            case 'i':
                input = optarg;
                break;
            case 'o':
                output = optarg;
                break;
            case 't':
                threshold_value = (int)(atof(optarg));
                break;
            case '?':
                if (optopt == 'i' || optopt == 'o') {
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                } else if (isprint (optopt)) {
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                } else {
                    fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
                    return 1;
                }
                abort();
            default:
                abort();
        }
    }


    int is_jpg = 0;
    int is_png = 0;

    // Get filename
    const char *dot = strrchr(input, '.');
    if(!dot || dot == input) abort();
    const char *ext = dot + 1;
    if (strcmp(ext, "jpeg") == 0
        || strcmp(ext, "jpg") == 0) {
        is_jpg = 1;
    }
    if (strcmp(ext, "png") == 0) {
        is_png = 1;
    }

    if (!(is_png || is_jpg)) {
        abort();
    }


    char *tmp = ".tmp.png";
    if (is_jpg) {
        printf("Converting JPG to PNG…\n");
        char cmd[512];
        strcpy(cmd, "convert ");
        strcat(cmd, input);
        strcat(cmd, " ");
        strcat(cmd, tmp);
        system(cmd);
    }

    // If input and output are given
    if (input && output) {
        if(is_jpg) {
            read_png_file(tmp);
        } else if (is_png) {
            read_png_file(input);
        }
        process_png_file(threshold_value);
//      pixel_sort();
        write_png_file(output);
    }

    if (is_jpg) {
        char *cmd[512];
        strcpy(cmd, "rm ");
        strcat(cmd, tmp);
        system(cmd);
    }


    return 0;
}

