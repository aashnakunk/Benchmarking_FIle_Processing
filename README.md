# File Read Performance Benchmarking

This project benchmarks the performance of file reading operations using both custom timing functions and the Google Benchmark library. The primary objective is to measure and compare the time taken for cached and non-cached reads of a file with varying block sizes.

## Project Structure

- **main.cpp**: Contains the main function that performs the file read performance benchmarking using custom timing functions.
- **BM_benchmark.cpp**: Uses the Google Benchmark library to measure the performance of file processing functions.
- **helper.h**: Header file that includes declarations for helper functions used in the benchmarks.
- **process_file.h**: Header file that declares the `process_file` function.
- **test4.txt**: Sample text file used for benchmarking.

## main.cpp Overview

The main file conducts performance benchmarking by:
1. Dropping the file system cache to ensure non-cached reads.
2. Measuring and printing the time taken for non-cached and cached reads of a 500 MB file.
3. Iterating over various block sizes to measure the read times for both non-cached and cached reads, storing the results in arrays.

### Key Steps

- **Drop Cache**: Uses a system call to drop the file system cache, ensuring that subsequent reads are non-cached.
- **Measure Time**: Calls the `measure_time` function to record the time taken to read a file with specified parameters.
- **Block Sizes**: Varies the block sizes from 1,000 to 100,000 bytes to evaluate performance differences.

## BM_benchmark.cpp Overview

The benchmark file utilizes the Google Benchmark library to systematically measure the performance of:
- `process_file`: A function that processes a file with various parameters.
- `measure_time`: A function that measures the time taken to read a file.

### Benchmarks

- **BM_ProcessFile**: Benchmarks the `process_file` function over a range of input sizes, measuring execution time in milliseconds.
- **BM_MeasureTime**: Benchmarks the `measure_time` function, calculating throughput and measuring performance over a range of input sizes.

## Usage

### Running main.cpp

1. Ensure you have the necessary permissions to drop the file system cache.
2. Compile and run the `main.cpp` file to see the benchmark results for non-cached and cached reads.

### Running BM_benchmark.cpp

1. Ensure you have the Google Benchmark library installed.
2. Compile and run the `BM_benchmark.cpp` file to see the detailed benchmark results.

## Example Compilation Command

```sh
g++ -std=c++11 -isystem benchmark/include -Lbenchmark/build/src -lbenchmark -lpthread main.cpp -o main_benchmark
g++ -std=c++11 -isystem benchmark/include -Lbenchmark/build/src -lbenchmark -lpthread BM_benchmark.cpp -o bm_benchmark
```

Replace `main.cpp` and `BM_benchmark.cpp` with the names of your source files if different. Ensure all necessary source and header files are included in the compilation.

## Conclusion

This project provides a framework for benchmarking file reading operations, enabling performance analysis and optimization. The use of both custom timing functions and the Google Benchmark library offers a comprehensive approach to understanding the performance characteristics of file processing functions.
