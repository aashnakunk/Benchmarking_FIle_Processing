#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include "helper.h"
#include "process_file.h"


// code to just call measure time, to see time taken to read a file
int main(){
    long file_size = 524288000;

    system("sudo sh -c '/usr/bin/echo 3 > /proc/sys/vm/drop_caches'");
    float nc = measure_time("test4.txt", 524288, 1000,0);
    float c = measure_time("test4.txt", 524288, 1000,0);
    printf("Non-Cached Read : Took %.2f to read the file\n",nc);
    printf("Cached Read : Took %.2f to read the file\n",c);

    
    float cached[50], noncached[50];
    int i=0;
    for(int block_size=1000; block_size<=100000;block_size+=2000){
        int block_count = file_size/block_size;
        // printf("reading %d blocks of size %d bytes each\n", block_count, block_size);
        system("sudo sh -c '/usr/bin/echo 3 > /proc/sys/vm/drop_caches'");
        noncached[i] = measure_time("test4.txt", block_size, block_count,0);
        cached[i++] = measure_time("test4.txt", block_size, block_count,0);   
    }

    for(int i=0;i<50;i++){
        printf("%.2f, ", noncached[i]);
    }
    printf("\n");
    for(int i=0;i<50;i++){
        printf("%.2f, ", cached[i]);
    }
    printf("\n");

    
    return 0;
}