#include <benchmark/benchmark.h>

#include <algorithm>
#include <random>
#include <sorting.hpp>
#include <vector>

#define SIZE 1024 << 6

static void BM_BaseInt(benchmark::State &state) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist;

  for (auto _ : state) {
    std::vector<int> v;
    v.reserve(static_cast<size_t>(state.range(0)));
    for (size_t i = 0; i < static_cast<size_t>(state.range(0)); i++) {
      v.push_back(dist(mt));
    }
  }
}
BENCHMARK(BM_BaseInt)->Arg(SIZE);

static void BM_SortInt(benchmark::State &state) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist;

  for (auto _ : state) {
    std::vector<int> v;
    v.reserve(static_cast<size_t>(state.range(0)));
    for (size_t i = 0; i < static_cast<size_t>(state.range(0)); i++) {
      v.push_back(dist(mt));
    }
    std::sort(v.begin(), v.end());
  }
}
BENCHMARK(BM_SortInt)->Arg(SIZE);

static void BM_StableSortInt(benchmark::State &state) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist;

  for (auto _ : state) {
    std::vector<int> v;
    v.reserve(static_cast<size_t>(state.range(0)));
    for (size_t i = 0; i < static_cast<size_t>(state.range(0)); i++) {
      v.push_back(dist(mt));
    }
    std::stable_sort(v.begin(), v.end());
  }
}
BENCHMARK(BM_StableSortInt)->Arg(SIZE);

static void BM_BubbleSortInt(benchmark::State &state) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist;

  for (auto _ : state) {
    std::vector<int> v;
    v.reserve(static_cast<size_t>(state.range(0)));
    for (size_t i = 0; i < static_cast<size_t>(state.range(0)); i++) {
      v.push_back(dist(mt));
    }
    sri::bubble_sort(v.begin(), v.end());
  }
}
BENCHMARK(BM_BubbleSortInt)->Arg(SIZE);

static void BM_SelectionSortInt(benchmark::State &state) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist;

  for (auto _ : state) {
    std::vector<int> v;
    v.reserve(static_cast<size_t>(state.range(0)));
    for (size_t i = 0; i < static_cast<size_t>(state.range(0)); i++) {
      v.push_back(dist(mt));
    }
    sri::selection_sort(v.begin(), v.end());
  }
}
BENCHMARK(BM_SelectionSortInt)->Arg(SIZE);

struct S {
  int key;
  int arr[4];
};

static void BM_BaseStruct(benchmark::State &state) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist;

  for (auto _ : state) {
    std::vector<S> v;
    v.reserve(static_cast<size_t>(state.range(0)));
    for (size_t i = 0; i < static_cast<size_t>(state.range(0)); i++) {
      v.push_back({dist(mt), {1}});
    }
  }
}
BENCHMARK(BM_BaseStruct)->Arg(SIZE);

static void BM_SortStruct(benchmark::State &state) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist;

  for (auto _ : state) {
    std::vector<S> v;
    v.reserve(static_cast<size_t>(state.range(0)));
    for (size_t i = 0; i < static_cast<size_t>(state.range(0)); i++) {
      v.push_back({dist(mt), {1}});
    }
    std::sort(v.begin(), v.end(),
              [](const S &a, const S &b) { return a.key < b.key; });
  }
}
BENCHMARK(BM_SortStruct)->Arg(SIZE);

static void BM_StableSortStruct(benchmark::State &state) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist;

  for (auto _ : state) {
    std::vector<S> v;
    v.reserve(static_cast<size_t>(state.range(0)));
    for (size_t i = 0; i < static_cast<size_t>(state.range(0)); i++) {
      v.push_back({dist(mt), {1}});
    }

    std::stable_sort(v.begin(), v.end(),
                     [](const S &a, const S &b) { return a.key < b.key; });
  }
}
BENCHMARK(BM_StableSortStruct)->Arg(SIZE);

static void BM_BubbleSortStruct(benchmark::State &state) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist;

  for (auto _ : state) {
    std::vector<S> v;
    v.reserve(static_cast<size_t>(state.range(0)));
    for (size_t i = 0; i < static_cast<size_t>(state.range(0)); i++) {
      v.push_back({dist(mt), {1}});
    }
    sri::bubble_sort(v.begin(), v.end(),
                     [](const S &a, const S &b) { return a.key < b.key; });
  }
}
BENCHMARK(BM_BubbleSortStruct)->Arg(SIZE);

static void BM_SelectionSortStruct(benchmark::State &state) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist;

  for (auto _ : state) {
    std::vector<S> v;
    v.reserve(static_cast<size_t>(state.range(0)));
    for (size_t i = 0; i < static_cast<size_t>(state.range(0)); i++) {
      v.push_back({dist(mt), {1}});
    }
    sri::selection_sort(v.begin(), v.end(),
                        [](const S &a, const S &b) { return a.key < b.key; });
  }
}
BENCHMARK(BM_SelectionSortStruct)->Arg(SIZE);

BENCHMARK_MAIN();
