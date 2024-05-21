#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "process_file.h"
#include <string.h>
#include <stdbool.h>
void process_file(char *filename, char* mode, int block_size, int block_count, bool print){

    // printf("Doing mode:%s with block_size:%d and count:%d\n",mode, block_size, block_count);

    int file_descriptor;

    if (mode[0] == '-' && mode[1] == 'w') {
        // Write mode
        if ((file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        char *buffer = (char *)malloc(block_size);
        memset(buffer, '#', block_size);

        for (int i = 0; i < block_count; ++i) {
            if (write(file_descriptor, buffer, block_size) == -1) {
                perror("write");
                close(file_descriptor);
                free(buffer);
                exit(EXIT_FAILURE);
            }
        }

        free(buffer);
    } else if (mode[0] == '-' && mode[1] == 'r') {
        // Read mode
        if ((file_descriptor = open(filename, O_RDONLY)) == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        char *buffer = (char *)malloc(block_size);

        for (int i = 0; i < block_count; ++i) {
            if (read(file_descriptor, buffer, block_size) == -1) {
                perror("read");
                close(file_descriptor);
                free(buffer);
                exit(EXIT_FAILURE);
            }

            if(print){
		        printf("%.*s", (int)block_size, buffer);
	        }
        }
        if(print) printf("\n");
        free(buffer);
    }  else if (mode[0] == '-' && mode[1] == 'l') {

        char *buffer = (char *)malloc(block_size);

        if ((file_descriptor = open(filename, O_RDONLY)) == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < block_count; ++i) {
            if (lseek(file_descriptor, block_size, SEEK_SET) == -1) {
                perror("lseek");
                close(file_descriptor);
                exit(EXIT_FAILURE);
            }
            if (read(file_descriptor, buffer, block_size) == -1) {
                perror("read");
                close(file_descriptor);
                free(buffer);
                exit(EXIT_FAILURE);
            }
        }

        if (print) {
            printf("\n");
        }

        free(buffer);
        }

        else{
        fprintf(stderr, "Invalid mode\n");
        exit(EXIT_FAILURE);
    }

    close(file_descriptor);
}
