#include <benchmark/benchmark.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "helper.h"
#include "process_file.h"

static void BM_ProcessFile(benchmark::State& state) {
    for (auto _ : state) {
        process_file("test3.txt", "-w", state.range(0), 1, false);
    }
}

BENCHMARK(BM_ProcessFile)->Range(10000, 2000000)->Unit(benchmark::kMillisecond);

static void BM_MeasureTime(benchmark::State& state) {
    for (auto _ : state) {
        float mib = (state.range(0) / measure_time("test3.txt", state.range(0), 1, 0)) / 1048576;
        benchmark::DoNotOptimize(mib);
    }
}

BENCHMARK(BM_MeasureTime)->Range(10000, 2000000)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();
