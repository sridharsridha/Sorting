#ifndef __BENCHMARK_GOOGLEBENCH_HELPER_HPP
#define __BENCHMARK_GOOGLEBENCH_HELPER_HPP

#include <benchmark/benchmark.h>
#include <sorting_helper.hpp>

#include <type_traits>


class RandomFixture : public benchmark::Fixture
{
public:
  void SetUp(const ::benchmark::State &state)
  {
    m_unsorted.reserve(static_cast<std::vector<int>::size_type>(state.range(0)));
    for (auto i = 0; i < state.range(0); ++i) {
      m_unsorted.push_back(random_number_generator());
    }
  }
  void TearDown(const ::benchmark::State & /*state*/)
  {
    assert(std::is_sorted(m_unsorted.cbegin(), m_unsorted.cend()));
  }

  std::vector<int> m_unsorted;

private:
  sri::RandomNumbers random_number_generator;
};

class AscendingFixture : public benchmark::Fixture
{
public:
  void SetUp(const ::benchmark::State &state)
  {
    m_unsorted.reserve(static_cast<std::vector<int>::size_type>(state.range(0)));
    for (auto i = 0; i < static_cast<int>(state.range(0)); ++i) {
      m_unsorted.push_back(i);
    }
  }
  void TearDown(const ::benchmark::State & /*state*/)
  {
    assert(std::is_sorted(m_unsorted.cbegin(), m_unsorted.cend()));
  }
  std::vector<int> m_unsorted;
};

class DesceningFixture : public benchmark::Fixture
{
public:
  void SetUp(const ::benchmark::State &state)
  {
    m_unsorted.reserve(static_cast<std::vector<int>::size_type>(state.range(0)));
    for (auto i = static_cast<int>(state.range(0)); i > 0; --i) {
      m_unsorted.push_back(i);
    }
  }
  void TearDown(const ::benchmark::State & /*state*/)
  {
    assert(std::is_sorted(m_unsorted.cbegin(), m_unsorted.cend()));
  }
  std::vector<int> m_unsorted;
};

#endif
