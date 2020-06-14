#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_ENABLE_BENCHMARKING

#include <algorithm>
#include <catch2/catch.hpp>
#include <iostream>
#include <random>
#include <sorting.hpp>
#include <unordered_map>
#include <vector>
#include <iostream>

const int default_dataset_size = 10000;
int num_elements = default_dataset_size;

TEST_CASE("Benchmark random data", "[benchmark][random_data]") {
  std::random_device rd;
  std::mt19937 engine(rd());
  std::uniform_int_distribution dist;

  BENCHMARK_ADVANCED("Bubble Sort")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = 0; elm < static_cast<int>(num_elements); ++elm) {
        data[run].push_back(dist(engine));
      }
    }
    meter.measure([&data](int i) {
      sri::bubble_sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("Selection Sort")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = 0; elm < static_cast<int>(num_elements); ++elm) {
        data[run].push_back(dist(engine));
      }
    }
    meter.measure([&data](int i) {
      sri::selection_sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("std::sort Sort")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = 0; elm < static_cast<int>(num_elements); ++elm) {
        data[run].push_back(dist(engine));
      }
    }
    meter.measure([&data](int i) {
      std::sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("std::stable_sort Sort")
  (Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = 0; elm < static_cast<int>(num_elements); ++elm) {
        data[run].push_back(dist(engine));
      }
    }
    meter.measure([&data](int i) {
      std::stable_sort(data[i].begin(), data[i].end());
      return data;
    });
  };
}

TEST_CASE("Benchmark sorted (ascending) data", "[benchmark][sorted_data]") {
  BENCHMARK_ADVANCED("Bubble Sort")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = 0; elm < static_cast<int>(num_elements); ++elm) {
        data[run].push_back(elm);
      }
    }
    meter.measure([&data](int i) {
      sri::bubble_sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("Selection Sort")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = 0; elm < static_cast<int>(num_elements); ++elm) {
        data[run].push_back(elm);
      }
    }
    meter.measure([&data](int i) {
      sri::selection_sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("std::sort Sort")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = 0; elm < static_cast<int>(num_elements); ++elm) {
        data[run].push_back(elm);
      }
    }
    meter.measure([&data](int i) {
      std::sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("std::stable_sort Sort")
  (Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = 0; elm < static_cast<int>(num_elements); ++elm) {
        data[run].push_back(elm);
      }
    }
    meter.measure([&data](int i) {
      std::stable_sort(data[i].begin(), data[i].end());
      return data;
    });
  };
}

TEST_CASE("Benchmark sorted (descending) data", "[benchmark][sorted_data]") {
  BENCHMARK_ADVANCED("Bubble Sort")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = static_cast<int>(num_elements); elm > 0; --elm) {
        data[run].push_back(elm);
      }
    }
    meter.measure([&data](int i) {
      sri::bubble_sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("Selection Sort")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = static_cast<int>(num_elements); elm > 0; --elm) {
        data[run].push_back(elm);
      }
    }
    meter.measure([&data](int i) {
      sri::selection_sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("std::sort Sort")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = static_cast<int>(num_elements); elm > 0; --elm) {
        data[run].push_back(elm);
      }
    }
    meter.measure([&data](int i) {
      std::sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("std::stable_sort Sort")
  (Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = static_cast<int>(num_elements); elm > 0; --elm) {
        data[run].push_back(elm);
      }
    }
    meter.measure([&data](int i) {
      std::stable_sort(data[i].begin(), data[i].end());
      return data;
    });
  };
}

int main(int argc, char* argv[]) {
  Catch::Session session;  // There must be exactly one instance


  // Build a new parser on top of Catch's
  using namespace Catch::clara;
  auto cli =
      session.cli() | Opt(num_elements, "num_elements")["--size"](
                          "How many elements to use for running the test");

  // Now pass the new composite back to Catch so it uses that
  session.cli(cli);

  // Let Catch (using Clara) parse the command line
  int returnCode = session.applyCommandLine(argc, argv);
  if (returnCode != 0) {
    return returnCode;
  }

  std::cout << "Dataset size is set as: " <<  num_elements << std::endl;
  return session.run();
}
