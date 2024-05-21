#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "helper.h"
#include "process_file.h"
#include<math.h>

int main(){

    printf("Performance in MiB/s without lseek:\n");

    for(int i=2;i<=pow(2,20);i*=2){
        process_file("test5.txt", "-w", 1,i, false);
        float bytes_per_sec = (i/measure_time("test5.txt", 1, i,0));
        float mib = bytes_per_sec/pow(2,20);
	    printf("%.2f, ", mib);
    }
    printf("\n");

    printf("Performance in MiB/s with lseek: \n");

     for(int i=2;i<=pow(2,20);i*=2){

        process_file("test6.txt", "-w", 1,i, false);
        float bytes_per_sec = (i/measure_time("test6.txt", 1, i,1));
        float mib = bytes_per_sec/pow(2,20);
	    printf("%.2f, ", mib);
    }
    printf("\n");
    return 0;
}




