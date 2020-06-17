#ifndef __SORTING_HELPER_HPP
#define __SORTING_HELPER_HPP

#include <random>

namespace sri {

class RandomNumbers {
 public:
  RandomNumbers(int low, int high)
      : random_engine_{std::random_device{}()}, distribution_{low, high} {}
  RandomNumbers() : random_engine_{std::random_device{}()}, distribution_{} {}
  int operator()() { return distribution_(random_engine_); }

 private:
  std::mt19937 random_engine_;
  std::uniform_int_distribution<int> distribution_;
};

}  // namespace sri

#endif
