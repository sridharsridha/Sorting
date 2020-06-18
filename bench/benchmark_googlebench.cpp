#include <benchmark/benchmark.h>

#include <algorithm>
#include <numeric>
#include <sorting.hpp>
#include <vector>

#include "benchmark_googlebench.hpp"

#define SIZE 10000

// ---------------------------------------------------------------------------------
// Random Data test
// ---------------------------------------------------------------------------------

BENCHMARK_DEFINE_F(RandomFixture, std_sort)
(benchmark::State &st)
{
  for (auto _ : st) {
    std::sort(m_unsorted.begin(), m_unsorted.end());
  }
}
BENCHMARK_DEFINE_F(RandomFixture, std_stable_sort)
(benchmark::State &st)
{
  for (auto _ : st) {
    std::stable_sort(m_unsorted.begin(), m_unsorted.end());
  }
}
BENCHMARK_DEFINE_F(RandomFixture, bubble_sort)
(benchmark::State &st)
{
  for (auto _ : st) {
    sri::bubble_sort(m_unsorted.begin(), m_unsorted.end());
  }
}
BENCHMARK_DEFINE_F(RandomFixture, selection_sort)
(benchmark::State &st)
{
  for (auto _ : st) {
    sri::selection_sort(m_unsorted.begin(), m_unsorted.end());
  }
}
BENCHMARK_DEFINE_F(RandomFixture, insertion_sort)
(benchmark::State &st)
{
  for (auto _ : st) {
    sri::insertion_sort(m_unsorted.begin(), m_unsorted.end());
  }
}
BENCHMARK_DEFINE_F(RandomFixture, merge_sort)
(benchmark::State &st)
{
  for (auto _ : st) {
    sri::merge_sort(m_unsorted.begin(), m_unsorted.end());
  }
}
BENCHMARK_DEFINE_F(RandomFixture, iterative_merge_sort)
(benchmark::State &st)
{
  for (auto _ : st) {
    sri::merge_sort_i(m_unsorted.begin(), m_unsorted.end());
  }
}

BENCHMARK_REGISTER_F(RandomFixture, std_sort)->Arg(SIZE);
BENCHMARK_REGISTER_F(RandomFixture, std_stable_sort)->Arg(SIZE);
BENCHMARK_REGISTER_F(RandomFixture, bubble_sort)->Arg(SIZE);
BENCHMARK_REGISTER_F(RandomFixture, selection_sort)->Arg(SIZE);
BENCHMARK_REGISTER_F(RandomFixture, insertion_sort)->Arg(SIZE);
BENCHMARK_REGISTER_F(RandomFixture, merge_sort)->Arg(SIZE);
BENCHMARK_REGISTER_F(RandomFixture, iterative_merge_sort)->Arg(SIZE);

// ---------------------------------------------------------------------------------
// Sorted Ascending Data test
// ---------------------------------------------------------------------------------

BENCHMARK_DEFINE_F(AscendingFixture, std_sort)
(benchmark::State &st)
{
  for (auto _ : st) {
    std::sort(m_unsorted.begin(), m_unsorted.end());
  }
}
BENCHMARK_DEFINE_F(AscendingFixture, std_stable_sort)
(benchmark::State &st)
{
  for (auto _ : st) {
    std::stable_sort(m_unsorted.begin(), m_unsorted.end());
  }
}
BENCHMARK_DEFINE_F(AscendingFixture, bubble_sort)
(benchmark::State &st)
{
  for (auto _ : st) {
    sri::bubble_sort(m_unsorted.begin(), m_unsorted.end());
  }
}
BENCHMARK_DEFINE_F(AscendingFixture, selection_sort)
(benchmark::State &st)
{
  for (auto _ : st) {
    sri::selection_sort(m_unsorted.begin(), m_unsorted.end());
  }
}
BENCHMARK_DEFINE_F(AscendingFixture, insertion_sort)
(benchmark::State &st)
{
  for (auto _ : st) {
    sri::insertion_sort(m_unsorted.begin(), m_unsorted.end());
  }
}
BENCHMARK_DEFINE_F(AscendingFixture, merge_sort)
(benchmark::State &st)
{
  for (auto _ : st) {
    sri::merge_sort(m_unsorted.begin(), m_unsorted.end());
  }
}
BENCHMARK_DEFINE_F(AscendingFixture, iterative_merge_sort)
(benchmark::State &st)
{
  for (auto _ : st) {
    sri::merge_sort_i(m_unsorted.begin(), m_unsorted.end());
  }
}

BENCHMARK_REGISTER_F(AscendingFixture, std_sort)->Arg(SIZE);
BENCHMARK_REGISTER_F(AscendingFixture, std_stable_sort)->Arg(SIZE);
BENCHMARK_REGISTER_F(AscendingFixture, bubble_sort)->Arg(SIZE);
BENCHMARK_REGISTER_F(AscendingFixture, selection_sort)->Arg(SIZE);
BENCHMARK_REGISTER_F(AscendingFixture, insertion_sort)->Arg(SIZE);
BENCHMARK_REGISTER_F(AscendingFixture, merge_sort)->Arg(SIZE);
BENCHMARK_REGISTER_F(AscendingFixture, iterative_merge_sort)->Arg(SIZE);

// ---------------------------------------------------------------------------------
// Sorted Descending Data test
// ---------------------------------------------------------------------------------

BENCHMARK_DEFINE_F(DesceningFixture, std_sort)
(benchmark::State &st)
{
  for (auto _ : st) {
    std::sort(m_unsorted.begin(), m_unsorted.end());
  }
}
BENCHMARK_DEFINE_F(DesceningFixture, std_stable_sort)
(benchmark::State &st)
{
  for (auto _ : st) {
    std::stable_sort(m_unsorted.begin(), m_unsorted.end());
  }
}
BENCHMARK_DEFINE_F(DesceningFixture, bubble_sort)
(benchmark::State &st)
{
  for (auto _ : st) {
    sri::bubble_sort(m_unsorted.begin(), m_unsorted.end());
  }
}
BENCHMARK_DEFINE_F(DesceningFixture, selection_sort)
(benchmark::State &st)
{
  for (auto _ : st) {
    sri::selection_sort(m_unsorted.begin(), m_unsorted.end());
  }
}
BENCHMARK_DEFINE_F(DesceningFixture, insertion_sort)
(benchmark::State &st)
{
  for (auto _ : st) {
    sri::insertion_sort(m_unsorted.begin(), m_unsorted.end());
  }
}
BENCHMARK_DEFINE_F(DesceningFixture, merge_sort)
(benchmark::State &st)
{
  for (auto _ : st) {
    sri::merge_sort(m_unsorted.begin(), m_unsorted.end());
  }
}
BENCHMARK_DEFINE_F(DesceningFixture, iterative_merge_sort)
(benchmark::State &st)
{
  for (auto _ : st) {
    sri::merge_sort_i(m_unsorted.begin(), m_unsorted.end());
  }
}

BENCHMARK_REGISTER_F(DesceningFixture, std_sort)->Arg(SIZE);
BENCHMARK_REGISTER_F(DesceningFixture, std_stable_sort)->Arg(SIZE);
BENCHMARK_REGISTER_F(DesceningFixture, bubble_sort)->Arg(SIZE);
BENCHMARK_REGISTER_F(DesceningFixture, selection_sort)->Arg(SIZE);
BENCHMARK_REGISTER_F(DesceningFixture, insertion_sort)->Arg(SIZE);
BENCHMARK_REGISTER_F(DesceningFixture, merge_sort)->Arg(SIZE);
BENCHMARK_REGISTER_F(DesceningFixture, iterative_merge_sort)->Arg(SIZE);
