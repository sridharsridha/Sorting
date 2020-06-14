#define CATCH_CONFIG_MAIN

#include <algorithm>
#include <catch2/catch.hpp>
#include <iostream>
#include <sorting.hpp>
#include <vector>

TEST_CASE("Sorting test random data", "[sorting_tests.random_data]") {
  using Catch::Matchers::Equals;
  std::vector<int> unsorted{4, 7, 9, 1, 2, 3, 8, 6, 5, 0};
  std::vector<int> sorted{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  SECTION("Bubble sort random data") {
    sri::bubble_sort(unsorted.begin(), unsorted.end());
    REQUIRE_THAT(unsorted, Equals(sorted));
  }
  SECTION("Selection sort random data") {
    sri::selection_sort(unsorted.begin(), unsorted.end());
    REQUIRE_THAT(unsorted, Equals(sorted));
  }
}

TEST_CASE("Sorting test sorted (assending order) data", "[sorting_tests.sorted_data.ascending]") {
  using Catch::Matchers::Equals;
  std::vector<int> sorted{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto actual = sorted;
  SECTION("Bubble sort") {
    sri::bubble_sort(actual.begin(), actual.end());
    REQUIRE_THAT(actual, Equals(sorted));
  }
  SECTION("Selection sort") {
    sri::bubble_sort(actual.begin(), actual.end());
    REQUIRE_THAT(actual, Equals(sorted));
  }
}

TEST_CASE("Sorting test sorted (descending order) data", "[sorting_tests.sorted_data.descending]") {
  using Catch::Matchers::Equals;
  std::vector<int> sorted{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  auto actual = sorted;
  SECTION("Bubble sort") {
    sri::bubble_sort(actual.begin(), actual.end(), std::greater<>());
    REQUIRE_THAT(actual, Equals(sorted));
  }
  SECTION("Selection sort") {
    sri::bubble_sort(actual.begin(), actual.end(), std::greater<>());
    REQUIRE_THAT(actual, Equals(sorted));
  }
}

TEST_CASE("Sorting unexpected data", "[sorting_tests.sorted_data.empty_case]") {
  using Catch::Matchers::Equals;
  std::vector<int> empty;
  std::vector<int> actual;
  SECTION("Bubble sort sorted empty data") {
    sri::bubble_sort(actual.begin(), actual.end());
    REQUIRE_THAT(actual, Equals(empty));
  }
  SECTION("Selection sort sorted empty data") {
    sri::bubble_sort(actual.begin(), actual.end());
    REQUIRE_THAT(actual, Equals(empty));
  }
}

