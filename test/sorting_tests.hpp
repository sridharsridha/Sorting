#ifndef __SORTING_TESTS_HPP
#define __SORTING_TESTS_HPP

#include <sorting_helper.hpp>

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

#endif
