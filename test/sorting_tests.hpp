#ifndef __SORTING_TESTS_HPP
#define __SORTING_TESTS_HPP

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

struct TestData {
 public:
  explicit TestData(int k, std::string s) : m_key(k), m_data(std::move(s)){};
  bool operator<(const TestData &x) const { return m_key < x.m_key; }
  bool operator==(const TestData &x) const { return m_key == x.m_key; }
  bool operator!=(const TestData &x) const { return !(m_key == x.m_key); }
  [[nodiscard]] int key() const { return m_key; }
  [[maybe_unused]] [[nodiscard]] std::string data() const { return m_data; }

 private:
  int m_key;
  std::string m_data;
};

}  // namespace sri

#endif
