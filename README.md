# Sorting

![Cmake](https://github.com/sridharsridha/sorting/workflows/CMake/badge.svg)
[![codecov](https://codecov.io/gh/sridharsridha/sorting/branch/master/graph/badge.svg)](https://codecov.io/gh/sridharsridha/sorting)
![language](https://img.shields.io/github/languages/top/sridharsridha/Sorting)
![version](https://img.shields.io/github/v/tag/sridharsridha/Sorting?label=version&sort=semver)
[![GitHub license](https://img.shields.io/github/license/sridharsridha/Sorting?style=plastic)](https://github.com/sridharsridha/Sorting/blob/master/LICENSE)

Sorting algorithms implementation using C++ template metaprogramming as a headonly
library. Benchmarking of these algorithms are performed using Catch2 benchmark and
google benchmarks.

```bash
Dataset size is set as: 10000

Benchmark random data
-------------------------------------------------------------------------------
benchmark name                            samples    iterations          mean
-------------------------------------------------------------------------------
Bubble Sort                                    100             1     46.285 ms
Selection Sort                                 100             1    47.3573 ms
std::sort Sort                                 100             1    475.706 us
std::stable_sort Sort                          100             1    499.681 us
-------------------------------------------------------------------------------

Benchmark sorted (ascending) data
-------------------------------------------------------------------------------
benchmark name                            samples    iterations          mean
-------------------------------------------------------------------------------
Bubble Sort                                    100             1      7.045 us
Selection Sort                                 100             1      6.475 us
std::sort Sort                                 100             1     12.262 us
std::stable_sort Sort                          100             1     50.565 us
-------------------------------------------------------------------------------

Benchmark sorted (descending) data
-------------------------------------------------------------------------------
benchmark name                            samples    iterations          mean
-------------------------------------------------------------------------------
Bubble Sort                                    100             1    65.8264 ms
Selection Sort                                 100             1    67.2234 ms
std::sort Sort                                 100             1     31.215 us
std::stable_sort Sort                          100             1    150.252 us
-------------------------------------------------------------------------------
```

## Dependencies
A C++ compiler that supports C++17.  See [cppreference.com][cppreference.com] to see which features are supported by each compiler.
The following compilers should work:
  * [gcc 7+][gcc]
  * [clang 6+][clang]
  The minimum compiler version is 19.15; this version ships with version 15.8 of the IDE. 

[Conan][conan] - it's recommended that you install using [pip][pip]

[CMake 3.15+][cmake]

## Build Instructions

### Make a build directory

```bash
$ mkdir build && cd build
```

### Configure your build

To configure the project and write makefiles, you could use `cmake` with a
bunch of command line options. The easier option is to run cmake interactively,
with the Cmake Curses Dialog Command Line tool:  

```bash
$ ccmake ..
```

Once `ccmake` has finished setting up, press 'c' to configure the project, 
press 'g' to generate, and 'q' to quit.

### Build
Once you have selected all the options you would like to use, you can build the 
project:

```bash
$ cmake --build .   # build all targets
```

### Build using an alternate compiler

Conan and CMake use the environment variables CC and CXX to decide which 
compiler to use. If you don't set these variables yourself, the system 
default compiler will be used.

Be aware that CMake will detect which compiler was used to build each of the 
Conan targets. 
If you build all of your Conan targets with one compiler, and then build your 
CMake targets with a different compiler, the project may fail to build. 

To build using clang, you can use these commands:

```bash
$ CC=clang CXX=clang++ ccmake ..
$ CC=clang CXX=clang++ cmake --build .
```

## Running tests

After building to run the unit-tests

```bash
$ cd build
$ ctest
```

## Running benchmarks

Two benchmarks are used here one is using [catch2]() framework and another using [google
benchmark](),

### Running Catch2 Benchmark

```bash
$ cd build/bin
$ ./benchmark_catch --size=1000 
```

The command output will look like below

```bash
Dataset size is set as: 1000

-------------------------------------------------------------------------------
Benchmark random data
-------------------------------------------------------------------------------
benchmark name                                  samples       iterations    estimated
                                                mean          low mean      high mean
                                                std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Bubble Sort                                               100             1    62.3915 ms
                                                   500.924 us    498.744 us    503.896 us
                                                    12.897 us     10.065 us     19.631 us

Selection Sort                                            100             1    61.6541 ms
                                                   503.346 us    500.454 us    508.824 us
                                                    19.579 us     10.914 us     32.169 us

std::sort Sort                                            100             1     30.337 ms
                                                    36.249 us     35.664 us     37.697 us
                                                     4.197 us        564 ns      7.754 us

std::stable_sort Sort                                     100             1    29.7788 ms
                                                    34.723 us     34.645 us     34.802 us
                                                       398 ns        350 ns        461 ns


-------------------------------------------------------------------------------
Benchmark sorted (ascending) data
-------------------------------------------------------------------------------
benchmark name                                  samples       iterations    estimated
                                                mean          low mean      high mean
                                                std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Bubble Sort                                               100             1    27.6108 ms
                                                       973 ns        962 ns        999 ns
                                                        83 ns         47 ns        165 ns

Selection Sort                                            100             1    32.2752 ms
                                                       972 ns        962 ns        994 ns
                                                        72 ns         40 ns        143 ns

std::sort Sort                                            100             1    32.0701 ms
                                                      1.56 us      1.547 us      1.623 us
                                                       126 ns          9 ns        300 ns

std::stable_sort Sort                                     100             1     32.149 ms
                                                      3.37 us      3.354 us      3.426 us
                                                       134 ns         43 ns        303 ns


-------------------------------------------------------------------------------
Benchmark sorted (descending) data
-------------------------------------------------------------------------------
benchmark name                                  samples       iterations    estimated
                                                mean          low mean      high mean
                                                std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Bubble Sort                                               100             1    78.8413 ms
                                                   647.712 us    647.084 us    648.826 us
                                                     4.181 us      2.632 us      6.281 us

Selection Sort                                            100             1    74.8978 ms
                                                   650.134 us    637.343 us    682.168 us
                                                    94.453 us     24.225 us    168.523 us

std::sort Sort                                            100             1    36.0463 ms
                                                     3.589 us      3.379 us      4.121 us
                                                     1.498 us        154 ns      2.768 us

std::stable_sort Sort                                     100             1    32.3432 ms
                                                    19.657 us     19.314 us     21.275 us
                                                     3.222 us         52 ns      7.671 us


===============================================================================
test cases: 3 | 3 passed
assertions: - none -
```

### Running google benchmark

```bash
cd build/bin
./benchmark_googlebench
```

The output will look like

```bash
Running ./benchmark_googlebench
Run on (4 X 2300 MHz CPU s)
CPU Caches:
  L1 Data 32K (x2)
  L1 Instruction 32K (x2)
  L2 Unified 262K (x2)
  L3 Unified 4194K (x1)
Load Average: 2.26, 2.32, 2.13
-----------------------------------------------------------------------
Benchmark                             Time             CPU   Iterations
-----------------------------------------------------------------------
BM_BaseInt/65536                1104402 ns      1100765 ns          614
BM_SortInt/65536                4910653 ns      4886486 ns          144
BM_StableSortInt/65536          5332557 ns      5304077 ns          130
BM_BubbleSortInt/65536       5955655641 ns   5921828000 ns            1
BM_SelectionSortInt/65536    5602074163 ns   5572168000 ns            1
BM_BaseStruct/65536             1124900 ns      1120069 ns          624
BM_SortStruct/65536             4983121 ns      4973862 ns          138
BM_StableSortStruct/65536       5638990 ns      5629844 ns          122
BM_BubbleSortStruct/65536    7141038223 ns   7104419000 ns            1
BM_SelectionSortStruct/65536 1367835150 ns   1364836000 ns            1

```

## Troubleshooting
If you encounter any issue when trying to build the cmake project, check the
[troubleshooting][troubleshoot] section.

## Contributing
Feedback and feature requests are appreciated. Bug reports and pull requestsare very welcome.
Check the [Contributing Guidelines][ contributing] for how to write a feature request, post an issue and/or submit a pull request.

## License
Sorting is licensed under the [MIT license][license].  Copyright (c) 2020 Sridhar Nagarajan.

## Testing frameworks

[Catch2 tutorial][catch2]

## Benchmarking frameworks

[Catch2 benmarking tutorial][catch2-benchmark]

[Google Benchmark][google-benchmark]


[cppreference.com]: https://en.cppreference.com/w/cpp/compiler_support
[gcc]: https://gcc.gnu.org/
[clang]: https://clang.llvm.org/
[conan]: https://conan.io/
[pip]: https://pip.pypa.io/en/stable/
[cmake]: https://cmake.org/
[catch2]: https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md
[catch2-benchmark]: https://github.com/catchorg/Catch2/blob/master/docs/benchmarks.md
[google-benchmark]: https://github.com/google/benchmark#usage
[troubleshoot]: ./TROUBLESHOOTING.md
[contributing]: ./CONTRIBUTING.md
[license]: ./LICENSE

