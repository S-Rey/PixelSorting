#include <stdlib.h>
#include <stdio.h>
#include "read_write.h"


int main(int argc, char *argv[]) {
	if(argc != 3) abort();
	printf("Hello\n");
	read_png_file("");

//  read_png_file(argv[1]);
//  process_png_file();
//  write_png_file(argv[2]);

	return 0;
}
