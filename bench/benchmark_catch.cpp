#include "sorting_helper.hpp"
#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_ENABLE_BENCHMARKING

#include <algorithm>
#include <catch2/catch.hpp>
#include <iostream>
#include <random>
#include <sorting.hpp>
#include <unordered_map>
#include <vector>

#include "benchmark_helper.hpp"

const int default_dataset_size = 10000;
int num_elements = default_dataset_size;

TEST_CASE("Benchmark random data", "[benchmark][random_data]") {
  sri::RandomNumbers random;

  BENCHMARK_ADVANCED("std::sort (Quick sort)")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = 0; elm < num_elements; ++elm) {
        data[run].push_back(random());
      }
    }
    meter.measure([&data](int i) {
      std::sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("std::stable_sort (Merge sort)")
  (Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = 0; elm < num_elements; ++elm) {
        data[run].push_back(random());
      }
    }
    meter.measure([&data](int i) {
      std::stable_sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("Bubble Sort")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = 0; elm < num_elements; ++elm) {
        data[run].push_back(random());
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
      for (auto elm = 0; elm < num_elements; ++elm) {
        data[run].push_back(random());
      }
    }
    meter.measure([&data](int i) {
      sri::selection_sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("Insertion Sort")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = 0; elm < num_elements; ++elm) {
        data[run].push_back(random());
      }
    }
    meter.measure([&data](int i) {
      sri::insertion_sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("Merge Sort")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = 0; elm < num_elements; ++elm) {
        data[run].push_back(random());
      }
    }
    meter.measure([&data](int i) {
      sri::merge_sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("Iterative Merge Sort")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = 0; elm < num_elements; ++elm) {
        data[run].push_back(random());
      }
    }
    meter.measure([&data](int i) {
      sri::merge_sort_i(data[i].begin(), data[i].end());
      return data;
    });
  };

}

TEST_CASE("Benchmark sorted (ascending) data", "[benchmark][sorted_data]") {

  BENCHMARK_ADVANCED("std::sort (Quick Sort)")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = 0; elm < num_elements; ++elm) {
        data[run].push_back(elm);
      }
    }
    meter.measure([&data](int i) {
      std::sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("std::stable_sort (Merge Sort)")
  (Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = 0; elm < num_elements; ++elm) {
        data[run].push_back(elm);
      }
    }
    meter.measure([&data](int i) {
      std::stable_sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("Bubble Sort")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = 0; elm < num_elements; ++elm) {
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
      for (auto elm = 0; elm < num_elements; ++elm) {
        data[run].push_back(elm);
      }
    }
    meter.measure([&data](int i) {
      sri::selection_sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("Insertion Sort")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = 0; elm < num_elements; ++elm) {
        data[run].push_back(elm);
      }
    }
    meter.measure([&data](int i) {
      sri::insertion_sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("Merge Sort")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = 0; elm < num_elements; ++elm) {
        data[run].push_back(elm);
      }
    }
    meter.measure([&data](int i) {
      sri::merge_sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("Iterative merge Sort")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = 0; elm < num_elements; ++elm) {
        data[run].push_back(elm);
      }
    }
    meter.measure([&data](int i) {
      sri::merge_sort_i(data[i].begin(), data[i].end());
      return data;
    });
  };

}

TEST_CASE("Benchmark sorted (descending) data", "[benchmark][sorted_data]") {

  BENCHMARK_ADVANCED("std::sort (Quick Sort)")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = num_elements; elm > 0; --elm) {
        data[run].push_back(elm);
      }
    }
    meter.measure([&data](int i) {
      std::sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("std::stable_sort (Merge Sort)")
  (Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = num_elements; elm > 0; --elm) {
        data[run].push_back(elm);
      }
    }
    meter.measure([&data](int i) {
      std::stable_sort(data[i].begin(), data[i].end());
      return data;
    });
  };
  BENCHMARK_ADVANCED("Bubble Sort")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = num_elements; elm > 0; --elm) {
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
      for (auto elm = num_elements; elm > 0; --elm) {
        data[run].push_back(elm);
      }
    }
    meter.measure([&data](int i) {
      sri::selection_sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("Insertion Sort")(Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = num_elements; elm > 0; --elm) {
        data[run].push_back(elm);
      }
    }
    meter.measure([&data](int i) {
      sri::insertion_sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("Merge Sort")
  (Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = num_elements; elm > 0; --elm) {
        data[run].push_back(elm);
      }
    }
    meter.measure([&data](int i) {
      sri::merge_sort(data[i].begin(), data[i].end());
      return data;
    });
  };

  BENCHMARK_ADVANCED("Iterative merge Sort")
  (Catch::Benchmark::Chronometer meter) {
    // setup data for this run
    std::unordered_map<int, std::vector<int>> data;
    for (auto run = 0; run < meter.runs(); ++run) {
      for (auto elm = num_elements; elm > 0; --elm) {
        data[run].push_back(elm);
      }
    }
    meter.measure([&data](int i) {
      sri::merge_sort_i(data[i].begin(), data[i].end());
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

  std::cout << "Dataset size is set as: " << num_elements << std::endl;
  return session.run();
}
