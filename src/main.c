#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
//#include "read_write.h"


int main(int argc, char **argv) 
{
	char *input = NULL, *output = NULL;		// input and output file
	double angle;							// the angle used for pixelsorting
	double black_threshold;					// 

	int index = 0;
	int c;

	opterr = 0;


	while ((c = getopt (argc, argv, "::i:o:a:")) != -1) {
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
			case ':':
				++index;
				printf("%d", index);
				break;
			case '?':
				if (optopt == 'a' || optopt == 'i' || optopt == 'o')
					fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				else if (isprint (optopt))
					fprintf (stderr, "Unknown option `-%c'.\n", optopt);
				else
					fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
        		return 1;
			default:
				abort();
		}
	}	

	printf("-i %s -o %s -a %f\n", input, output, angle);


	return 0;
}
