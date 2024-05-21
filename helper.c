#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

#include "helper.h"
#include "process_file.h"

#define NANOSECONDS_PER_SECOND 1000000000L


double measure_time(char *filename, float block_size, int block_count,bool lseek) {
    int file_descriptor;
    char *buffer = (char *)malloc(block_size);
    char* mode;
    if(lseek)
    {
        mode="-l";
    }else{
        mode = "-r";
    }

    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    process_file(filename,mode,block_size,block_count,false);


    clock_gettime(CLOCK_MONOTONIC, &end_time);


    free(buffer);
    return (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / (double)NANOSECONDS_PER_SECOND;
}
