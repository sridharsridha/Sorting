#include <benchmark/benchmark.h>

#include <algorithm>
#include <sorting.hpp>
#include <vector>

#include "benchmark_helper.hpp"

#define SIZE 10000

// ---------------------------------------------------------------------------------
// Random Data test
// ---------------------------------------------------------------------------------
static void std_sort(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> unsorted(
        static_cast<std::vector<int>::size_type>(state.range(0)));
    std::generate(unsorted.begin(), unsorted.end(), sri::RandomNumbers());
    std::sort(unsorted.begin(), unsorted.end());
  }
}

static void std_stable_sort(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> unsorted(
        static_cast<std::vector<int>::size_type>(state.range(0)));
    std::generate(unsorted.begin(), unsorted.end(), sri::RandomNumbers());
    std::stable_sort(unsorted.begin(), unsorted.end());
  }
}

static void bubble_sort(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> unsorted(
        static_cast<std::vector<int>::size_type>(state.range(0)));
    std::generate(unsorted.begin(), unsorted.end(), sri::RandomNumbers());
    sri::bubble_sort(unsorted.begin(), unsorted.end());
  }
}

static void selection_sort(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> unsorted(
        static_cast<std::vector<int>::size_type>(state.range(0)));
    std::generate(unsorted.begin(), unsorted.end(), sri::RandomNumbers());
    sri::selection_sort(unsorted.begin(), unsorted.end());
  }
}

static void insertion_sort(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> unsorted(
        static_cast<std::vector<int>::size_type>(state.range(0)));
    std::generate(unsorted.begin(), unsorted.end(), sri::RandomNumbers());
    sri::insertion_sort(unsorted.begin(), unsorted.end());
  }
}

static void merge_sort(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> unsorted(
        static_cast<std::vector<int>::size_type>(state.range(0)));
    std::generate(unsorted.begin(), unsorted.end(), sri::RandomNumbers());
    sri::merge_sort(unsorted.begin(), unsorted.end());
  }
}

static void iterative_merge_sort(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> unsorted(
        static_cast<std::vector<int>::size_type>(state.range(0)));
    std::generate(unsorted.begin(), unsorted.end(), sri::RandomNumbers());
    sri::merge_sort_i(unsorted.begin(), unsorted.end());
  }
}

BENCHMARK(std_sort)->Arg(SIZE);
BENCHMARK(std_stable_sort)->Arg(SIZE);
BENCHMARK(bubble_sort)->Arg(SIZE);
BENCHMARK(selection_sort)->Arg(SIZE);
BENCHMARK(insertion_sort)->Arg(SIZE);
BENCHMARK(merge_sort)->Arg(SIZE);
BENCHMARK(iterative_merge_sort)->Arg(SIZE);

// ---------------------------------------------------------------------------------
// Sorted Ascending Data test
// ---------------------------------------------------------------------------------
static void std_sort_sorted_ascending(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> sorted(static_cast<size_t>(state.range(0)));
    std::iota(sorted.begin(), sorted.end(), 0);
    std::sort(sorted.begin(), sorted.end());
  }
}

static void std_stable_sort_sorted_ascending(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> sorted(static_cast<size_t>(state.range(0)));
    std::iota(sorted.begin(), sorted.end(), 0);
    std::stable_sort(sorted.begin(), sorted.end());
  }
}

static void bubble_sort_sorted_ascending(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> sorted(static_cast<size_t>(state.range(0)));
    std::iota(sorted.begin(), sorted.end(), 0);
    sri::bubble_sort(sorted.begin(), sorted.end());
  }
}

static void selection_sort_sorted_ascending(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> sorted(static_cast<size_t>(state.range(0)));
    std::iota(sorted.begin(), sorted.end(), 0);
    sri::selection_sort(sorted.begin(), sorted.end());
  }
}

static void insertion_sort_sorted_ascending(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> sorted(static_cast<size_t>(state.range(0)));
    std::iota(sorted.begin(), sorted.end(), 0);
    sri::insertion_sort(sorted.begin(), sorted.end());
  }
}

static void merge_sort_sorted_ascending(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> sorted(static_cast<size_t>(state.range(0)));
    std::iota(sorted.begin(), sorted.end(), 0);
    sri::merge_sort(sorted.begin(), sorted.end());
  }
}

static void iterative_merge_sort_sorted_ascending(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> sorted(static_cast<size_t>(state.range(0)));
    std::iota(sorted.begin(), sorted.end(), 0);
    sri::merge_sort_i(sorted.begin(), sorted.end());
  }
}

BENCHMARK(std_sort_sorted_ascending)->Arg(SIZE);
BENCHMARK(std_stable_sort_sorted_ascending)->Arg(SIZE);
BENCHMARK(bubble_sort_sorted_ascending)->Arg(SIZE);
BENCHMARK(selection_sort_sorted_ascending)->Arg(SIZE);
BENCHMARK(insertion_sort_sorted_ascending)->Arg(SIZE);
BENCHMARK(merge_sort_sorted_ascending)->Arg(SIZE);
BENCHMARK(iterative_merge_sort_sorted_ascending)->Arg(SIZE);

// ---------------------------------------------------------------------------------
// Sorted Descending Data test
// ---------------------------------------------------------------------------------
static void std_sort_sorted_descending(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> sorted(static_cast<size_t>(state.range(0)));
    std::for_each(
        sorted.begin(), sorted.end(),
        [i = state.range(0)](int &x) mutable { x = static_cast<int>(i--); });
    std::sort(sorted.begin(), sorted.end());
  }
}

static void std_stable_sort_sorted_descending(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> sorted(static_cast<size_t>(state.range(0)));
    std::for_each(
        sorted.begin(), sorted.end(),
        [i = state.range(0)](int &x) mutable { x = static_cast<int>(i--); });
    std::stable_sort(sorted.begin(), sorted.end());
  }
}

static void bubble_sort_sorted_descending(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> sorted(static_cast<size_t>(state.range(0)));
    std::for_each(
        sorted.begin(), sorted.end(),
        [i = state.range(0)](int &x) mutable { x = static_cast<int>(i--); });
    sri::bubble_sort(sorted.begin(), sorted.end());
  }
}

static void selection_sort_sorted_descending(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> sorted(static_cast<size_t>(state.range(0)));
    std::for_each(
        sorted.begin(), sorted.end(),
        [i = state.range(0)](int &x) mutable { x = static_cast<int>(i--); });
    sri::selection_sort(sorted.begin(), sorted.end());
  }
}

static void insertion_sort_sorted_descending(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> sorted(static_cast<size_t>(state.range(0)));
    std::for_each(
        sorted.begin(), sorted.end(),
        [i = state.range(0)](int &x) mutable { x = static_cast<int>(i--); });
    sri::insertion_sort(sorted.begin(), sorted.end());
  }
}

static void merge_sort_sorted_descending(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> sorted(static_cast<size_t>(state.range(0)));
    std::for_each(
        sorted.begin(), sorted.end(),
        [i = state.range(0)](int &x) mutable { x = static_cast<int>(i--); });
    sri::merge_sort(sorted.begin(), sorted.end());
  }
}

static void iterative_merge_sort_sorted_descending(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> sorted(static_cast<size_t>(state.range(0)));
    std::for_each(
        sorted.begin(), sorted.end(),
        [i = state.range(0)](int &x) mutable { x = static_cast<int>(i--); });
    sri::merge_sort_i(sorted.begin(), sorted.end());
  }
}

BENCHMARK(std_sort_sorted_descending)->Arg(SIZE);
BENCHMARK(std_stable_sort_sorted_descending)->Arg(SIZE);
BENCHMARK(bubble_sort_sorted_descending)->Arg(SIZE);
BENCHMARK(selection_sort_sorted_descending)->Arg(SIZE);
BENCHMARK(insertion_sort_sorted_descending)->Arg(SIZE);
BENCHMARK(merge_sort_sorted_descending)->Arg(SIZE);
BENCHMARK(iterative_merge_sort_sorted_descending)->Arg(SIZE);

