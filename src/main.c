#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <getopt.h>
#include "read_write.h"


int main(int argc, char **argv) 
{
	char *input = NULL, *output = NULL;		// input and output file
	double angle = 0.0;							// the angle used for pixelsorting
	double black_threshold;					// 

	int index = 0;
	int c;
	int threshold_value = 20;
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

	// If input and output are given
	if (input && output) {
		read_png_file(input);
		process_png_file(threshold_value);
//		pixel_sort();
		write_png_file(output);
	}

	

	return 0;
}
