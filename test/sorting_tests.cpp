#define CATCH_CONFIG_MAIN

#include <algorithm>
#include <catch2/catch.hpp>
#include <random>
#include <sorting.hpp>
#include <vector>

#include "sorting_tests.hpp"

TEST_CASE("Sorting test sorted (ascending order) data",
          "[sorting_tests.sorted_data.ascending]") {
  using Catch::Matchers::Equals;
  auto size = GENERATE(0, 1, 2, 5, 100);

  std::vector<int> sorted(static_cast<std::vector<int>::size_type>(size));
  std::iota(sorted.begin(), sorted.end(), 0);

  auto actual = sorted;
  SECTION("Bubble sort") {
    sri::bubble_sort(actual.begin(), actual.end());
    REQUIRE_THAT(actual, Equals(sorted));
  }
  SECTION("Selection sort") {
    sri::bubble_sort(actual.begin(), actual.end());
    REQUIRE_THAT(actual, Equals(sorted));
  }
  SECTION("Insertion sort") {
    sri::insertion_sort(actual.begin(), actual.end());
    REQUIRE_THAT(actual, Equals(sorted));
  }
}

TEST_CASE("Sorting test sorted (descending order) data",
          "[sorting_tests.sorted_data.descending]") {
  using Catch::Matchers::Equals;
  auto size = GENERATE(0, 1, 2, 5, 100);

  std::vector<int> sorted(static_cast<std::vector<int>::size_type>(size));
  std::for_each(sorted.begin(), sorted.end(),
                [i = size](int& x) mutable { x = i--; });

  auto actual = sorted;
  SECTION("Bubble sort") {
    sri::bubble_sort(actual.begin(), actual.end(), std::greater<>());
    REQUIRE_THAT(actual, Equals(sorted));
  }
  SECTION("Selection sort") {
    sri::bubble_sort(actual.begin(), actual.end(), std::greater<>());
    REQUIRE_THAT(actual, Equals(sorted));
  }
  SECTION("Insertion sort") {
    sri::insertion_sort(actual.begin(), actual.end(), std::greater<>());
    REQUIRE_THAT(actual, Equals(sorted));
  }
}

TEST_CASE("Sorting test random data", "[sorting_tests.random_data]") {
  using Catch::Matchers::Equals;
  auto size = GENERATE(0, 1, 2, 5, 100);

  std::vector<int> unsorted(static_cast<std::vector<int>::size_type>(size));
  std::generate(unsorted.begin(), unsorted.end(), sri::RandomNumbers());
  std::vector<int> sorted(unsorted);
  std::sort(sorted.begin(), sorted.end());

  SECTION("Bubble sort random data") {
    sri::bubble_sort(unsorted.begin(), unsorted.end());
    REQUIRE_THAT(unsorted, Equals(sorted));
  }
  SECTION("Selection sort random data") {
    sri::selection_sort(unsorted.begin(), unsorted.end());
    REQUIRE_THAT(unsorted, Equals(sorted));
  }
  SECTION("Insertion sort random data") {
    sri::insertion_sort(unsorted.begin(), unsorted.end());
    REQUIRE_THAT(unsorted, Equals(sorted));
  }
}

struct TestData {
 public:
  explicit TestData(int k, std::string s) : m_key(k), m_data(std::move(s)){};
  bool operator<(const TestData& x) const { return m_key < x.m_key; }
  bool operator==(const TestData& x) const { return m_key == x.m_key; }
  bool operator!=(const TestData& x) const { return !(m_key == x.m_key); }
  [[nodiscard]] int key() const { return m_key; }
  [[maybe_unused]] [[nodiscard]] std::string data() const { return m_data; }

 private:
  int m_key;
  std::string m_data;
};

TEST_CASE("Sorting test struct data", "[sorting_tests.struct_data]") {
  using Catch::Matchers::Equals;
  auto size = GENERATE(0, 1, 2, 5, 100);
  std::random_device rd;
  std::mt19937 engine(rd());
  std::uniform_int_distribution<int> dist;

  std::vector<TestData> unsorted;
  unsorted.reserve(static_cast<std::vector<TestData>::size_type>(size));
  for (auto i = 0; i < size; i++) {
    unsorted.emplace_back(dist(engine), "hello");
  }
  std::vector<TestData> sorted(unsorted);
  std::sort(sorted.begin(), sorted.end());

  SECTION("Bubble sort random data") {
    sri::bubble_sort(unsorted.begin(), unsorted.end());
    REQUIRE_THAT(unsorted, Equals(sorted));
  }
  SECTION("Selection sort random data") {
    sri::selection_sort(unsorted.begin(), unsorted.end());
    REQUIRE_THAT(unsorted, Equals(sorted));
  }
  SECTION("Insertion sort random data") {
    sri::insertion_sort(unsorted.begin(), unsorted.end());
    REQUIRE_THAT(unsorted, Equals(sorted));
  }
}
